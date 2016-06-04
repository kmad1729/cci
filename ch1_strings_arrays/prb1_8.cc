#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char main_string[] = "merabharatmahaan";
    size_t str_len = strlen(main_string);
    char sub_str1[] = "mahaan";
    char sub_str2[] = "bharat";
    char sub_str3[] = "mera";
    char non_sub_str1[] = "athadu";

    cout << "length of main string = " << strlen(main_string) << endl;
    cout << "(" << sub_str1 << ") occurs in string (" << main_string
        << ") at: " << 
        strstr(main_string, sub_str1) - main_string << endl;

    cout << "(" << sub_str2 << ") occurs in string (" << main_string
        << ") at: " << 
        strstr(main_string, sub_str2) - main_string << endl;

    cout << "(" << sub_str3 << ") occurs in string (" << main_string
        << ") at: " << 
        strstr(main_string, sub_str3) - main_string << endl;


    cout << "(" << non_sub_str1 << ") occurs in string (" << main_string
        << ") at: " << 
        strstr(non_sub_str1, sub_str1) - main_string << endl;

}
