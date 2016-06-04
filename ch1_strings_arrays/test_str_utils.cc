//tests to check functions in str_utils
#include "str_utils.h"
#include <iostream>
#include <string>

using namespace std;

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
    };

    char* null_str = NULL;

    int test_strs_count = sizeof(test_strs) / sizeof(test_strs[0]);

    for(int i = 0; i < test_strs_count; i++) {
        cout << "test str [" << i << "] = (" << 
            test_strs[i] << ")" << endl;
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
