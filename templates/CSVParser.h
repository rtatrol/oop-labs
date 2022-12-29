#ifndef TEMPLATES_CSVPARSER_H
#define TEMPLATES_CSVPARSER_H

#include <fstream>
#include "TupleUtils.h"

typedef long long ll;

template<typename ... Args>
class CSVParser {
private:
    std::ifstream input;
    size_t offset;
    int FileLength = -1;
    char fieldSeparator = '\"';
    char columnSeparator = ',';
    char lineSeparator = '\n';


    template<typename _CharT, typename _Traits, typename _Alloc>
    void getLine(std::basic_istream<_CharT, _Traits> &is, std::basic_string<_CharT, _Traits, _Alloc> &str) {
        str.clear();
        char c;
        while (is.get(c)) {
            if (c == lineSeparator)
                break;
            str.push_back(c);
        }
    }

    int getLength() {
        if (FileLength == -1) {
            input.clear();
            input.seekg(0, std::ios::beg);

            std::string buf;
            while (std::getline(input, buf))FileLength++;

            input.clear();
            input.seekg(0, std::ios::beg);
        }
        return FileLength;
    }


    class CSVIterator {
    private:
        std::string buffer;
        std::ifstream &input;
        size_t index;
        CSVParser<Args...> &parent;
        bool isEnd = false;

        friend class CSVParser;

    public:
        CSVIterator(std::ifstream &ifs, size_t index, CSVParser<Args...> &parent) : index(index), parent(parent),
                                                                                    input(ifs) {
            for (int i = 0; i < index - 1; i++, parent.getLine(input, buffer));
            parent.getLine(input, buffer);
        }

        CSVIterator operator++() {
            if (index < parent.FileLength) {
                index++;
                input.clear();
                input.seekg(0, std::ios::beg);

                for (int i = 0; i < index - 1; i++, parent.getLine(input, buffer));
                parent.getLine(input, buffer);
            } else {
                buffer = "";
                isEnd = true;
            }
        }

        bool operator==(const CSVIterator &dif) const {
            return (this->isEnd == dif.isEnd and this->buffer == dif.buffer and this->index == dif.index);
        }

        bool operator!=(const CSVIterator &dif) const {
            return !(*this == dif);
        }

        std::tuple<Args...> operator*() {
            return parent.parse_line(buffer, index);
        }
    };

public:
    CSVParser(std::ifstream &ifs, size_t offset) {
        if (!ifs.is_open())
            throw std::invalid_argument("Can`t open file\n");
        if (offset >= getLength())
            throw std::invalid_argument("too long offset>file.size\n");
        if (offset < 0)
            throw std::invalid_argument("bad offset<0\n");
    }

    void setSeparators(char newField, char newColumn, char newLine) {
        fieldSeparator = newField;
        columnSeparator = newColumn;
        lineSeparator = newLine;
    }

    CSVIterator begin() {
        CSVIterator start(input, offset + 1, *this);//here try just offset without 1
        return start;
    }

    CSVIterator end() {
        CSVIterator end(input, 1, *this);
        end.isEnd = true;
        end.buffer = "";
        end.index = getLength();
        return end;
    }

    std::vector<std::string> read_line(std::string &line, int lineIndex) {
        std::vector<std::string> tableVec = {""};
        size_t vecIndex = 0;
        size_t prevSep = 0;
        bool isScreen = false;
        for (ll i = 0; i < line.size(); i++) {
            char now = line[i];
            if (now == columnSeparator and !isScreen) {
                tableVec[vecIndex] = line.substr(prevSep, i - prevSep);
                vecIndex++;
                prevSep = i + 1;
                tableVec.emplace_back("");
            }

            if (now == fieldSeparator and !isScreen)isScreen = true;
            if (now == fieldSeparator and isScreen) {
                tableVec[vecIndex] = line.substr(prevSep + 1, i - prevSep - 1);
                vecIndex++;
                tableVec.emplace_back("");
                isScreen = false;
                if (i != line.size() - 1) {
                    if (line[i + 1] != columnSeparator)
                        throw std::invalid_argument("Bad separation on " + std::to_string(lineIndex) + "\n");
                }
                i++;
                prevSep = i + 1;
            }
            if (now == lineSeparator and !isScreen) {
                tableVec[vecIndex].push_back(now);
                break;
            }
        }
        return tableVec;
    }

    std::tuple<Args...> parse_line(std::string &line, int lineIndex) {
        size_t size = sizeof...(Args);
        if (line.empty())
            throw std::invalid_argument("Line is empty " + std::to_string(lineIndex) + "\n");
        std::tuple<Args...> tableLine;
        std::vector<std::string> tableVec = read_line(line, lineIndex);

        if (tableVec.size() != size)
            throw std::invalid_argument("wrong size in line " + std::to_string(lineIndex) + "\n");

        auto iter = tableVec.begin();
        tupleUtils::parse<Args...>(tableLine, iter);
        return tableLine;
    }
};

#endif //TEMPLATES_CSVPARSER_H
