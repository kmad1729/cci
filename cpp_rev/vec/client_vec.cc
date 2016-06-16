#include "vec.h"
#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>

using std::copy;
using std::ostream_iterator;

using std::cout;
using std::endl;

int main()
{
    Vec<int> v1;
    for(int i = 1; i < 101; i++)
        v1.push_back(i * 2);

    //printing vec using iterators
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    //Vec<char> v2(20, '#');
    //copy(v2.begin(), v2.end(), ostream_iterator<char>(cout, ""));
}
