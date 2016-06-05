#pragma once
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <algorithm>

using namespace std;

//return index of first occurance of needle in haystack
// -1 otherwise

int get_first_index(const char* haystack, const char* needle)
{
    const char *result_ptr = std::strstr(haystack, needle);
    return result_ptr == NULL? -1: result_ptr - haystack;
}

void reverse_str(char* s, int start_ind, int len_str)
{
    //reverse the characters in the string between
    //[start_ind, len_str)
    while(start_ind < len_str - 1) {
        swap(s[start_ind], s[len_str - 1]);
        start_ind++;
        len_str--;
    }
}

char* rotate_str(const char* s, size_t index)
{
    size_t len = strlen(s);
    char* result = new char[len + 1];
    if(len < 2) {
        strcpy(result, s);
    } else {
        assert(index >= 0);
        assert(index <strlen(s));
        strcpy(result, s);
        reverse_str(result, 0, index);
        reverse_str(result, index, len);
        reverse_str(result, 0, len);
    }
    return result;
}


