#include <cstring>
#include <iostream>
#include <cctype>

using std::cout;
using std::endl;
using std::strlen;
using std::isspace;

char* substitute_spaces(const char* s)
{
    size_t num_spaces = 0;
    for(size_t i = 0; i < strlen(s); i++) {
        if(isspace(s[i]))
            num_spaces++;
    }

    char* ret_string = new char[strlen(s) + 2 * num_spaces + 1];
    size_t ret_str_ind = 0;
    for(size_t i = 0; i < strlen(s); i++) {
        if(isspace(s[i])) {
            ret_string[ret_str_ind++] = '%';
            ret_string[ret_str_ind++] = '2';
            ret_string[ret_str_ind++] = '0';
        } else {
            ret_string[ret_str_ind++] = s[i];
        }
    }
    ret_string[ret_str_ind] = '\0';
    return ret_string;
}

int main() {
    char s[] = "a b  c d";
    cout << "s --> " << endl << "(" << s << ")" << endl;
    char* substitute_str = substitute_spaces(s);
    cout << "substitute spaces with %20 --> " << endl;
    cout << "(" << substitute_str << ")" << endl;
}
