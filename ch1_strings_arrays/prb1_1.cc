//check if string has duplicate chars

#include <iostream>
#include <cstring>
#include <string>
#include <set>

using namespace std;

bool has_dup_chars1(char* s)
{
    set<char> char_set;
    for(size_t i = 0; i < strlen(s); i++) {
        if(char_set.find(s[i]) != char_set.end()) return true;
        char_set.insert(s[i]);
    }
    return false;
}

bool has_dup_chars2(char *s)
{
    int char_set = 0;
    for(size_t i = 0; i < strlen(s); i++) {
        int char_bit = s[i] - 'a';
        if((char_set >> char_bit) & 1)
            return true;
        char_set |= (1 << char_bit);
    }
    return false;
}

int main()
{
    char s[100];

    string delim = string(20, '#') + '\n';
    strcpy(s, "abbcde");

    cout << "(" << s << ") has dup chars --> " << endl;
    cout << has_dup_chars1(s) << endl;
    cout << has_dup_chars2(s) << endl;
    cout << "1 <-- expected" << endl;

    cout << delim;

    strcpy(s, "abcd");
    cout << "(" << s << ") has dup chars --> " << endl;
    cout << has_dup_chars1(s) << endl;
    cout << has_dup_chars2(s) << endl;
    cout << "0 <-- expected" << endl;

    cout << delim;

    strcpy(s, "");
    cout << "(" << s << ") has dup chars --> " << endl;
    cout << has_dup_chars1(s) << endl;
    cout << has_dup_chars2(s) << endl;
    cout << "0 <-- expected" << endl;

    cout << delim;

    strcpy(s, "aaaa");
    cout << "(" << s << ") has dup chars --> " << endl;
    cout << has_dup_chars1(s) << endl;
    cout << has_dup_chars2(s) << endl;
    cout << "1 <-- expected" << endl;
}
