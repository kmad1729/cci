#pragma once

#include <memory>
#include <algorithm>

template <class T>
class Vec {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;
        typedef T& reference_type;
        typedef const T& const_reference;

        //constructor, destructor, assignment operator
        Vec() {create();}
        explicit Vec(size_type n, const T& t = T()) {create(n, t);}
        Vec(const Vec& v) {create(v.begin(), v.end());}
        Vec& operator=(const Vec&);
        ~Vec() {uncreate();}

        //other functions
        size_type size() const {return avail - data;}
        void push_back(const T& t) {
            if(avail == limit)
                grow();
            unchecked_append(t);
        }

        T& operator[](size_type i) {return data[i];}
        const T& operator[](size_type i) const {return data[i];}

        iterator begin() {return data;}
        const_iterator begin() const {return data;}

        iterator end() {return avail;}
        const_iterator end() const {return avail;}

        void clear() {uncreate();}

    private:
        iterator data;
        iterator avail;
        iterator limit;
        std::allocator<T> alloc;

        void create();
        void create(size_type, const T&);
        void create(const_iterator, const_iterator);

        void uncreate();

        void grow();
        void unchecked_append(const T&);
        
};

template class Vec<int>;
template class Vec<char>;
