#pragma once
#include "vec.h"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cctype>

class Str {

    friend std::istream& operator>>(std::istream&, Str&);
    public: 
        typedef Vec<char>::size_type size_type; 
        size_type size() const {return data.size();}

        char& operator[] (size_type i) {return data[i];}
        const char& operator[] (size_type i) const { return data[i];}

        Str() { };
        Str(size_type n, const char& c) : data(n, c) { }

        Str(const char* cp) 
        { std::copy(cp, cp + std::strlen(cp), std::back_inserter(data)); }

        template <class In>
            Str(In b, In e) 
            { std::copy(b, e, std::back_inserter(data)); }

        Str& operator+=(const Str& s) {
            std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
            return *this;
        }


    private:
        Vec<char> data;
};

Str operator+(const Str& s1, const Str& s2)
{
    Str r = s1;
    r += s2;
    return r;
}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
    for(Str::size_type i = 0; i < s.size(); i++) {
        os << s[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, Str& s)
{
    s.data.clear();
    char c;
    while(is.get(c) && std::isspace(c));

    if(is) {
        do {
            s.data.push_back(c);
        } while(is.get(c) && !isspace(c));
    }

    if(is) {
        is.unget();
    }
    return is;
}
