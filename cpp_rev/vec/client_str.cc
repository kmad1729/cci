#include "str.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    Str s1("hello");
    Str delim(20, '#');

    delim = "\n" + delim;

    cout << "s1 = (" << s1 << ")" << endl;
    cout << "please enter your name: ";
    Str name;
    cin >> name;

    cout << "Hello " +  name + "!" << endl;

    Vec<char> vowels;
    vowels.push_back('a');
    vowels.push_back('e');
    vowels.push_back('i');
    vowels.push_back('o');
    vowels.push_back('u');

    cout << delim << endl;
    cout << "building a vowel string!" << endl;
    Str vowel_str(vowels.begin(), vowels.end());

    cout << "vowel_str --> " << endl;
    cout << vowel_str << endl;
    cout << delim << endl;

}
