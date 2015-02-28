#include "string.h"
#include <stdio.h>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

namespace jia {

    String::String():_len(0),_p(NULL) {}

    //1.str is null or ""
    String::String(const char *str) {
        if (str == NULL || strlen(str) == 0) {
            _len = 0;
            _p = NULL;
        } else {
            _len = strlen(str);
            _p = new char[_len+1];
            memcpy(_p, str, _len+1);
        }
    }

    //1.str is empty
    String::String(const String& str) {
        if (str.empty()) {
            _len = 0;
            _p = NULL;
        } else {
            _len = str._len;
            _p = new char[_len+1];
            memcpy(_p, str._p, _len+1);
        }
    }

    //1.str is empty
    //2.str is the same as *this
    String& String::operator=(const String& str) {
        if (&str == this) 
            return *this;

        if (str.empty()) {
            _len = 0;
            _p = NULL;
        } else {
            _len = str._len;
            char *temp = new char[_len+1];
            memcpy(temp, str._p, _len+1);

            if (_p != NULL) 
                delete[] _p;
            _p = temp;
        }

        return *this;
    }

    //1.str is null or ""
    //2.str is a address between _p and _p+_len
    String& String::operator=(const char* str) {
        if (str == NULL || strlen(str) == 0) {
            _len = 0;
            _p = NULL;
        } else {
            _len = strlen(str);
            char *temp = new char[_len+1];
            memcpy(temp, str, _len+1);

            if (_p != NULL) delete[] _p;
            _p = temp;
        }

        return *this;
    }

    String::~String() {
        if (_p != NULL)  delete[] _p;
    }

    String::size_type String::length() const {
        return _len;
    }

    char& String::operator[](size_type index) {
        return _p[index];
    }

    char& String::at(size_type index) {
        if (index < 0 || index >= _len) {
            throw std::out_of_range("String::operator[]");
        }

        return _p[index];
    }

    void String::clear() {
        if (_p != NULL) delete[] _p;
        _len = 0;
        _p = NULL;
    }

    bool String::empty() const {
        return _len == 0;
    }

    String String::substr(size_type start, size_type length) const {
        if (start < 0 || start >= _len) 
            return String();

        if (length < 0) return String();

        if (start + length > _len) length = _len-start;

        String s;
        s._len = length;
        s._p = new char[s._len+1];
        memcpy(s._p, _p+start, length);
        s._p[s._len] = 0;
        return s;
    }

    String& String::operator+=(const String& str) {
        if (str.empty()) return *this;

        size_type size = _len+str._len;
        char *temp = new char[size+1];
        if (_p != NULL) 
            memcpy(temp, _p, _len);

        memcpy(temp+_len, str._p, str._len);
        temp[size] = 0;
        _len = size;

        if (_p != NULL) 
            delete[] _p;
        _p = temp;

        return *this;
    }

    String operator+(const String& left, const String& right) {
        String result;

        result._len = left._len + right._len;

        if (result._len == 0) {
            result._p = NULL;
        } else {
            result._p = new char[result._len+1];

            if (left._len != 0)
                memcpy(result._p, left._p, left._len);
            if (right._len != 0)
                memcpy(result._p+left._len, right._p, right._len);

            result._p[result._len] = 0;
        }

        return result;
    }

    bool operator==(const String& left, const String& right) {
        if (left.empty() && right.empty()) 
            return true;

        if (left.empty() || right.empty())
            return false;

        if (left.length() != right.length())
            return false;

        return !strcmp(left._p, right._p);
    }

    std::ostream& operator<<(std::ostream& os, const String& str) {
        if (str._p != NULL)
            os << str._p;

        return os;
    }

    std::istream& operator>>(std::istream& is, String& str) {
        #define MAX_SIZE 1024
        char buff[MAX_SIZE];

        is >> buff;

        str = buff;
        return is;
    }

}
