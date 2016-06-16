//given isSubStr function check is s1 is rotation of s2
#include <cstring>
#include <iostream>
#include "str_utils.h"

#define STR_MAX_SIZE 100

using namespace std;

bool is_rotation(char *rotated_str, char* main_str)
{
    char big_str[2 * strlen(rotated_str)];
    strcpy(big_str, rotated_str);
    strcpy(big_str + strlen(rotated_str), rotated_str);
    return get_first_index(big_str, main_str) != -1;
}

int main()
{
    char main_string[STR_MAX_SIZE] = "batman";
    char rot1[STR_MAX_SIZE] = "manbat";
    char rot2[STR_MAX_SIZE] = "fooman";
    char rot3[STR_MAX_SIZE] = "batman";

    cout << "is (" << rot1 << ") rotation of (" << main_string
        << ") ? " << is_rotation(rot1, main_string) << endl;

    cout << "is (" << rot2 << ") rotation of (" << main_string
        << ") ? " << is_rotation(rot2, main_string) << endl;

    cout << "is (" << rot3 << ") rotation of (" << main_string
        << ") ? " << is_rotation(rot3, main_string) << endl;
}
