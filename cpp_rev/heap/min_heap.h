#pragma once
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
void min_heapify(vector<T>& v, size_t i)
{
    size_t left_ind = 2 * i + 1;
    size_t right_ind = 2 * i + 2;
    size_t min_ind = i;

    if(left_ind < v.size())
        if(v[left_ind] < v[min_ind])
            min_ind = left_ind;

    if(right_ind < v.size())
        if(v[right_ind] < v[min_ind])
            min_ind = right_ind;

    if(min_ind != i) {
        swap(v[min_ind], v[i]);
        min_heapify(v, min_ind);
    }
}

template<class T>
void build_min_heap(vector<T>& v)
{
    int i = v.size() / 2;
    while(i >= 0)
        min_heapify(v, i--);
}
