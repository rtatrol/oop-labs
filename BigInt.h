#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

typedef long long ll;
class BigInt
{
    static const int BASE = 1e9;
    bool _is_negative;
    std::vector<int> digits;
    void remove_lead_zero();

public:
    BigInt();
    BigInt(int);
    BigInt(std::string); // бросать исключение std::invalid_argument при ошибке CHEVO??
    BigInt(const BigInt&);
    /*~BigInt();*/

    operator int() const;
    operator std::string() const;
    size_t size() const;

    friend std::ostream& operator <<(std::ostream&, const BigInt&);
    friend bool operator ==(const BigInt&, const BigInt&);
    friend bool operator <(const BigInt&, const BigInt&);
    friend bool operator >(const BigInt&, const BigInt&);
    friend bool operator !=(const BigInt&, const BigInt&);
    friend bool operator <=(const BigInt&, const BigInt&);
    friend bool operator >=(const BigInt&, const BigInt&);

    BigInt& operator =(const BigInt&);
    BigInt& operator +=(const BigInt&);
    BigInt& operator -=(const BigInt&);
    BigInt& operator *=(const BigInt&);
    BigInt& operator /=(const BigInt&);
    BigInt& operator %=(const BigInt&);
    BigInt& operator ^=(const BigInt&);
    BigInt& operator &=(const BigInt&);
    BigInt& operator |=(const BigInt&);

    BigInt operator ~() const;
    const BigInt operator +()const;
    const BigInt operator -()const;
    const BigInt operator ++();
    const BigInt operator ++(int);
    const BigInt operator --();
    const BigInt operator --(int);

    friend const BigInt operator +(const BigInt&, const BigInt&);
    friend const BigInt operator -(const BigInt&, const BigInt&);
    friend const BigInt operator *(const BigInt&, const BigInt&);
    void value_shift();
    friend const BigInt operator /(const BigInt&, const BigInt&);
    friend const BigInt operator %(const BigInt&, const BigInt&);
    friend const BigInt operator ^(const BigInt&, const BigInt&);
    friend const BigInt operator &(const BigInt&, const BigInt&);
    friend const BigInt operator |(const BigInt&, const BigInt&);

};
std::string to_binary(const BigInt& value);
