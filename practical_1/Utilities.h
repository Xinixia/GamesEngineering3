#pragma once

#include <string>

using namespace std;

class Utilities
{
public:
    
    static inline bool IsInteger(const std::string& s)
    {
        if (s.empty()
            || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
        {
            return false;
        }

        char* p;
        strtol(s.c_str(), &p, 10);
        return (*p == 0);
    }

};