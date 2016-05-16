#include "str.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    Str s1("hello");

    cout << "s1 = (" << s1 << ")" << endl;
    cout << "please enter your name: ";
    Str name;
    cin >> name;

    cout << "Hello " +  name + "!" << endl;
}
