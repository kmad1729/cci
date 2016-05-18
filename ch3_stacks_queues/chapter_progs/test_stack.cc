#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "stack.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::domain_error;

int main()
{
    Stack<string> my_stack;

    try {
        cout << "trying to pop empty stack" << endl;
        my_stack.pop();
    } catch (domain_error e) {
        cerr << e.what() << endl;
    }
    
    cout << "is my_stack empty? " << my_stack.is_empty() << endl;

    my_stack.push("Katori");
    my_stack.push("Plate");
    my_stack.push("spoon");
    my_stack.push("Jaadi");
    string tp = my_stack.pop();
    
    cout << "top of the stack = " << tp << endl;
    my_stack.push("spoon");

    cout << "is my_stack empty? " << my_stack.is_empty() << endl;
    cout << "stack popped = " << my_stack.pop() << endl;
    cout << "stack popped = " << my_stack.pop() << endl;
    cout << "stack popped = " << my_stack.pop() << endl;
    cout << "stack popped = " << my_stack.pop() << endl;

    cout << "is my_stack empty? " << my_stack.is_empty() << endl;


}
