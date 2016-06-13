#include "min_heap.h"
#include <vector>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

int main()
{
    int nums[] = {14, 5, 9, 6, 3, 1, 12, 31};
    size_t nums_len = sizeof(nums) / sizeof(nums[0]);
    vector<int> v(nums, nums + nums_len);
    string delim = '\n' + string(20, '#') + '\n';

    cout << "inp_vector --> " << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << delim;

    size_t i = 0;
    cout << "after min-heapify ing v at index " << i  << "--> " << endl;
    min_heapify(v, i);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << delim;

    cout  << "after building min heap -->" << endl;
    build_min_heap(v);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << delim;
}
