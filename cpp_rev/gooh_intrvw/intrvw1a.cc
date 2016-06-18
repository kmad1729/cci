#include <iostream>
/*
what does the following code do?
 bool fun(unsigned int n) {
   return !(n & (n - 1));
}

Ans -> it tells whether n is a power of 2 or 0
*/

using namespace std;

bool is_2_pow(unsigned int n) {
    return !(n & (n - 1));
}

int main()
{
    unsigned int i = 0;
    bool expected = true;
    
    for( i = 0; i < 6; i++) {
        if(i == 0 || i == 1 || i == 2 || i == 4)
            expected = true;
        else
            expected = false;
        cout << "is " << i << " a power of 2? " << endl
            << " expected " <<  expected << endl
            << " found    " << is_2_pow(i) << endl;
    }

}
