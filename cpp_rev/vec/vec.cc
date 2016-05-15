#include <memory>
#include <algorithm>
#include <cstdlib>
#include "vec.h"
#include <iostream>

using std::allocator;
using std::copy;
using std::uninitialized_fill;
using std::uninitialized_copy;
using std::max;

template <class T>
void Vec<T>::create() {
    data = avail= limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& t)
{
    data = alloc.allocate(n);
    avail = limit = data + n;
    uninitialized_fill(data, avail, t);
}

template <class T>
void Vec<T>::create(const_iterator b, const_iterator e)
{
    data = alloc.allocate(e - b);
    avail = limit = uninitialized_copy(b, e, data);
}

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    if(this != &rhs) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <class T>
void Vec<T>::uncreate()
{
    if(data) {
        iterator it = avail;
        it--;
        while(it != data) {
            alloc.destroy(it);
            --it;
        }
        alloc.deallocate(data, limit - data);
    }

    data = limit = avail = 0;
}

template <class T>
void Vec<T>::grow()
{
    size_type new_sz = max(std::ptrdiff_t(1), 2 * (limit - data));
    iterator new_data = alloc.allocate(new_sz);
    iterator new_avail = uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_sz;
}

template <class T>
void Vec<T>::unchecked_append(const T& t)
{
    alloc.construct(avail++, t);
}
