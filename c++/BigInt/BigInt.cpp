#include "BigInt.h"

void BigInt::remove_lead_zero() {
    while (this->digits.size() > 1 and this->digits.back() == 0)
        this->digits.pop_back();
    if (this->digits.size() == 1 and this->digits[0] == 0)
        this->_is_negative = false;
}

BigInt::BigInt() {
    this->_is_negative = false;
}

BigInt::BigInt(int c) {
    c < 0 ? this->_is_negative = true : this->_is_negative = false;
    c = std::abs(c);
    do {
        this->digits.push_back(c % BigInt::BASE);
        c /= BigInt::BASE;
    } while (c > 0);
}

BigInt::BigInt(std::string str) {
    if (str.size() == 0)this->_is_negative = false;
    else
    {
        if (str[0] == '-')
        {
            this->_is_negative = true;
            str = str.substr(1);
        }
        else {
            this->_is_negative = false;
        }

        for (ll i = str.size(); i > 0; i -= 9)
        {
            if (i < 9)
                this->digits.push_back(atoi(str.substr(0, i).c_str()));
            else
                this->digits.push_back(atoi(str.substr(i - 9, 9).c_str()));

        }
        this->remove_lead_zero();
    }
}

BigInt::BigInt(const BigInt& value) {
    this->digits = value.digits;
    this->_is_negative = value._is_negative;
}

/*BigInt::~BigInt() {
    std::cout<<*this<<"  is DELETED\n";
}*/

BigInt::operator int() const {
    BigInt big_int_max(INT_MAX);
    BigInt result = (*this % big_int_max);
    int answer = result.digits[0];
    return answer;
}

BigInt::operator std::string() const {
    std::stringstream ss;
    ss << (*this);
    return ss.str();
}

size_t BigInt::size() const {
    size_t result = sizeof(this->digits);
    return result;
}

std::ostream& operator <<(std::ostream& os, const BigInt& result) {
    if (result.digits.empty())os << 0;
    else
    {
        if (result._is_negative)os << '-';
        for (ll i = result.digits.size() - 1; i >= 0; i--)
            os << result.digits[i];
    }
    return os;
}

bool operator ==(const BigInt& left, const BigInt& right) {
    if (left._is_negative != right._is_negative)return false;

    if (left.digits.empty())
    {
        if (right.digits.empty() or right.digits.size() == 1 and right.digits[0] == 0)return true;
        else return false;
    }

    if (right.digits.empty())
    {
        if (left.digits.empty() or left.digits.size() == 1 and left.digits[0] == 0)return true;
        else return false;
    }
    if (left.digits.size() != right.digits.size())return false;
    for (ll i = 0; i < left.digits.size(); ++i)if (left.digits[i] != right.digits[i])return false;
    return true;
}

bool operator <(const BigInt& left, const BigInt& right) {
    if (left == right)return false;
    if (left._is_negative) {
        if (right._is_negative)return((-right) < (-left));
        else return true;
    }
    else if (right._is_negative)return false;
    else
    {
        if (left.digits.size() != right.digits.size())
            return left.digits.size() < right.digits.size();
        else
        {
            for (ll i = left.digits.size() - 1; i >= 0; --i)
            {
                if (left.digits[i] != right.digits[i])
                    return left.digits[i] < right.digits[i];
            }
            return false;
        }
    }
}

bool operator >(const BigInt& left, const BigInt& right) {
    return !(left <= right);
}

bool operator !=(const BigInt& left, const BigInt& right) {
    return !(left == right);
}

bool operator <=(const BigInt& left, const BigInt& right) {
    return (left < right or left == right);
}

bool operator >=(const BigInt& left, const BigInt& right) {
    return !(left < right);
}

BigInt& BigInt::operator =(const BigInt& value) {
    if (this == &value)
        return *this;
    this->_is_negative = value._is_negative;
    this->digits = value.digits;
    return *this;
}

BigInt& BigInt::operator +=(const BigInt& value) {
    return *this = (*this + value);
}

BigInt& BigInt::operator -=(const BigInt& value) {
    return *this = (*this - value);
}

BigInt& BigInt::operator *=(const BigInt& value) {
    return *this = (*this * value);
}

BigInt& BigInt::operator /=(const BigInt& value) {
    return *this = (*this / value);
}

BigInt& BigInt::operator %=(const BigInt& value) {
    return *this = (*this % value);
}

BigInt& BigInt::operator ^=(const BigInt& value) {
    return *this = (*this ^ value);
}

BigInt& BigInt::operator &=(const BigInt& value) {
    return *this = (*this & value);
}

BigInt& BigInt::operator |=(const BigInt& value) {
    return *this = (*this | value);
}

BigInt BigInt::operator ~() const {
    std::string res = to_binary(*this);
    while (res.size() % 8 != 0)res += '0';

    for (ll i = res.size() - 1; i >= 0; --i)
    {
        if (res[i] == '0')res[i] = '1';
        else res[i] = '0';
    }
    BigInt result(0), step(1);
    for (ll i = 0; i < res.size(); ++i)
    {
        if (res[i] == '1')result += step;
        step *= 2;
    }
    return result;
}

const BigInt BigInt::operator +() const {
    return BigInt(*this);
}

const BigInt BigInt::operator -() const {
    BigInt copy(*this);
    copy._is_negative = !copy._is_negative;
    return copy;
}

const BigInt BigInt::operator ++() {
    return (*this += 1);
}

const BigInt BigInt::operator ++(int) {
    BigInt one(1);
    *this += 1;
    return *this - one;
}

const BigInt BigInt::operator --() {
    return (*this -= 1);
}

const BigInt BigInt::operator --(int) {
    BigInt one(1);
    *this -= 1;
    return *this + one;
}

const BigInt operator +(const BigInt& left, const BigInt& right) {
    if (left._is_negative)
    {
        if (right._is_negative)return -(-left + (-right));
        else return right - (-left);
    }
    else if (right._is_negative)return (left - (-right));

    int ost = 0;
    BigInt result;
    result._is_negative = left._is_negative;
    result.digits = left.digits;

    for (ll i = 0; i < std::max(result.digits.size(), right.digits.size()) or ost != 0; ++i)
    {
        if (i == result.digits.size())result.digits.push_back(0);
        result.digits[i] += ost + (i < right.digits.size() ? right.digits[i] : 0);
        ost = result.digits[i] >= BigInt::BASE;
        if (ost != 0)result.digits[i] -= BigInt::BASE;
    }
    return result;
}

const BigInt operator -(const BigInt& left, const BigInt& right)
{
    if (right._is_negative)return left + (-right);
    else if (left._is_negative)return -(-left + right);
    else if (left < right)return -(right - left);
    int ost = 0;

    BigInt result;
    result._is_negative = left._is_negative;
    result.digits = left.digits;

    for (ll i = 0; i < right.digits.size() or ost != 0; i++)
    {
        result.digits[i] -= ost + (i < right.digits.size() ? right.digits[i] : 0);
        ost = (result.digits[i] < 0);
        if (ost != 0)result.digits[i] += BigInt::BASE;
    }
    result.remove_lead_zero();
    return result;
}

const BigInt operator *(const BigInt& left, const BigInt& right)
{
    BigInt result;
    result.digits.resize(left.digits.size() + right.digits.size());
    for (ll i = 0; i < left.digits.size(); ++i)
    {
        ll ost = 0;
        for (ll l = 0; l < right.digits.size() or ost != 0; ++l)
        {
            ll current = result.digits[i + l] + ((ll)left.digits[i]) * (l < right.digits.size() ? right.digits[l] : 0) + ost;
            result.digits[i + l] = (current % BigInt::BASE);
            ost = current / BigInt::BASE;
        }
    }
    result._is_negative = (left._is_negative != right._is_negative);
    result.remove_lead_zero();
    return result;
}

void BigInt::value_shift() {
    if (this->digits.size() == 0)
    {
        this->digits.push_back(0);
        return;
    }
    this->digits.push_back(this->digits[this->digits.size() - 1]);
    for (ll i = this->digits.size() - 2; i > 0; --i)
    {
        this->digits[i] = this->digits[i - 1];
    }
    this->digits[0] = 0;
}

const BigInt operator /(const BigInt& left, const BigInt& right) {
    BigInt zero(0);
    if (right == zero) {
        std::cout << "NOOOOO\n";
        return 0;
    }
    BigInt result, current, del;
    del = right;
    del._is_negative = false;

    result._is_negative = left._is_negative != right._is_negative;
    result.digits.resize(left.digits.size());

    for (ll i = left.digits.size() - 1; i >= 0; --i)
    {
        current.value_shift();
        current.digits[0] = left.digits[i];
        current.remove_lead_zero();

        ll x, l = 0, r = BigInt::BASE;

        while (l <= r)
        {
            ll m = (l + r) / 2;
            BigInt BigM(m);
            BigInt now = del * BigM;
            if (current >= now)
            {
                x = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        result.digits[i] = x;
        BigInt BigX(x);
        current = current - del * BigX;
    }
    result.remove_lead_zero();
    return result;
}

const BigInt operator %(const BigInt& left, const BigInt& right)
{
    BigInt result = left - (left / right) * right;
    if (result._is_negative)result += right;
    return result;
}

std::string to_binary(const BigInt& value) {
    BigInt zero(0), two(2);
    std::string result = "";
    BigInt copy(value);

    while (copy != zero)
    {
        if ((copy % two) != zero)result += '1';
        else result += '0';
        copy /= 2;
    }
    return result;
}

const BigInt operator ^(const BigInt& var1, const BigInt& var2) {
    BigInt result(0);

    std::string left = to_binary(var1);
    std::string right = to_binary(var2);
    if (left.size() > right.size())std::swap(left, right);

    for (ll i = right.size() - 1; i >= 0; --i)
    {
        result *= 2;
        if (i >= left.size() or left[i] != right[i])
        {
            if (i >= left.size()) {
                if (right[i] == '1')
                    result += 1;
            }
            else if (left[i] != right[i])result += 1;
        }
    }
    return result;
}

const BigInt operator &(const BigInt& var1, const BigInt& var2) {
    BigInt result(0);

    std::string left, right;
    left = to_binary(var1);
    right = to_binary(var2);
    if (left.size() > right.size())std::swap(left, right);

    for (ll i = left.size() - 1; i >= 0; --i)
    {
        result *= 2;
        if (left[i] == '1' and right[i] == '1')
            result += 1;
    }
    return result;
}

const BigInt operator |(const BigInt& var1, const BigInt& var2) {
    BigInt result(0);

    std::string left = to_binary(var1), right = to_binary(var2);
    if (left.size() > right.size())swap(left, right);

    for (ll i = right.size() - 1; i >= 0; --i)
    {
        result *= 2;
        if (i >= left.size()) { if (right[i] == '1')result += 1; }
        else if (left[i] == '1' or right[i] == '1')result += 1;
    }
    return result;
}
