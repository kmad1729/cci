//this program tests stack_with_min.h 
//stack_min_fast does push, pop and min operations in O(1)

#include "stack_with_min.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string delim = string(20, '#') + '\n';

    cout << "creating a stack with fast min" << endl;

    StackWithMin<int> s;

    cout << "s.empty()? " << s.empty() << endl;

    int n = 3;

    cout << "pushing " << n << " to the top" << endl;
    s.push(n);
    cout << "min val on stack till now = " << s.min() << endl;

    cout << "pushing " << n << " to the top" << endl;
    s.push(n);
    cout << "min val on stack till now = " << s.min() << endl;

    n = 2;
    cout << "pushing " << n << " to the top" << endl;
    s.push(n);
    cout << "min val on stack till now = " << s.min() << endl;

    cout << "s.empty()? " << s.empty() << endl;

    n = 18;
    cout << "pushing " << n << " to the top" << endl;
    s.push(n);
    cout << "min val on stack till now = " << s.min() << endl;

    n = -42;
    cout << "pushing " << n << " to the top" << endl;
    s.push(n);
    cout << "min val on stack till now = " << s.min() << endl;

    n = 42;
    cout << "pushing " << n << " to the top" << endl;
    s.push(n);
    cout << "min val on stack till now = " << s.min() << endl;

    cout << delim;
    while(!s.empty()) {
        cout << setw(5) << s.top() << " | " << setw(5) << s.min() << endl;
        s.pop();
    }

    cout << delim;
    cout << "s.empty()? " << s.empty() << endl;

}

