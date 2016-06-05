//tests to check functions in str_utils
#include "str_utils.h"
#include <iostream>
#include <string>

using namespace std;

void print_str(const char* s) {
    if(s == NULL) 
        cout << "NULL";
    else
        cout << s;

}

int main()
{
    string delim  = string(20, '#') + '\n';

    const char *test_strs[] = {
        "", // empty_str
        "abcd", // even_str
        "abcde", //odd_str
        "a", //small_str
        " ", //blank_str
        "\n", //new line string
        "NULL"
    };

    int rotate_ind[] = {
        0,
        2,
        4,
        0,
        0,
        0,
        1
    };



    int test_strs_count = sizeof(test_strs) / sizeof(test_strs[0]);
    char* rotated_str = NULL;

    for(int i = 0; i < test_strs_count; i++) {
        cout << "test str [" << i << "] = (";
        print_str(test_strs[i]);
        cout << ")" << endl;

        rotated_str = rotate_str(test_strs[i], rotate_ind[i]);
        cout << "rotated string at index " << rotate_ind[i] << "--> (";
        print_str(rotated_str);
        cout << ")" << endl;
    }

    cout << delim;
    cout << "testing get_first_index function -->" << endl;
    char main_string[] = "merabharatmahaan";
    size_t str_len = strlen(main_string);
    char sub_str1[] = "mahaan";
    char sub_str2[] = "bharat";
    char sub_str3[] = "mera";
    char non_sub_str1[] = "athadu";

    cout << "length of main string = " << str_len << endl;
    cout << "(" << sub_str1 << ") occurs in string (" << main_string
        << ") at: " << 
        get_first_index(main_string, sub_str1)<< endl;

    cout << "(" << sub_str2 << ") occurs in string (" << main_string
        << ") at: " << 
        get_first_index(main_string, sub_str2)<< endl;

    cout << "(" << sub_str3 << ") occurs in string (" << main_string
        << ") at: " << 
        get_first_index(main_string, sub_str3)<< endl;


    cout << "(" << non_sub_str1 << ") occurs in string (" << main_string
        << ") at: " << 
        get_first_index(main_string, non_sub_str1) << endl;
    cout << delim;

}
