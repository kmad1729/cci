#pragma once
#include <cstring>

//return index of first occurance of needle in haystack
// -1 otherwise

int get_first_index(const char* haystack, const char* needle)
{
    const char *result_ptr = std::strstr(haystack, needle);
    return result_ptr == NULL? -1: result_ptr - haystack;
}



