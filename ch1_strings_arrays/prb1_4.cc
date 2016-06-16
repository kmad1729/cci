//check if 2 strings are anagrams or not

#include <map>
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

bool are_anagrams(const string& s1, const string& s2) {
    map<char, size_t> m1;
    map<char, size_t> m2;

    typedef string::size_type str_sz;

    for(str_sz i = 0; i < s1.size(); i++) {
        if(!isspace(s1[i]))
            m1[s1[i]]++;
    }

    for(str_sz i = 0; i < s2.size(); i++) {
        if(!isspace(s2[i]))
            m2[s2[i]]++;
    }

    return m1 == m2;
}

int main() {
    string s1 = "o draconian devil";
    string s2 = "leonardo da vinci";
    string s3 = "leonardo";
    string delim = string(20, '#') + '\n';

    cout << "checking if " << endl << 
        "(" << s1 << ")" << endl << 
        "(" << s2 << ")" << endl <<  "are anagrams -->" << endl;
    cout << are_anagrams(s1, s2) << endl;
    cout << "1 <-- expected" << endl;

    cout << delim;
    cout << "checking if " << endl << 
        "(" << s1 << ")" << endl << 
        "(" << s3 << ")" << endl <<  "are anagrams -->" << endl;
    cout << are_anagrams(s1, s3) << endl;
    cout << "0 <-- expected" << endl;
    cout << delim;
}
