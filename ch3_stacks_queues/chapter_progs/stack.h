#pragma once
#define STACKSIZE 2
#include <algorithm>
#include <stdexcept>


template <class T>
class Stack {
    public:
        Stack() {
            stack_size = STACKSIZE;
            data = new T[stack_size];
            top_index = 0;
        }

        ~Stack() {
            delete[] data;
        }

        bool is_empty() {
            return top_index == 0;
        }

        void push(const T& t) {
            //check if stack reached its limit
            if(top_index == stack_size) {
                size_t new_size = 2 * stack_size;
                T* new_data = new T[new_size];
                std::copy(data, data + stack_size, new_data);

                delete[] data;

                stack_size = new_size;
                data = new_data;

            }
            data[top_index++] = T(t);
        }

        T& pop() {
            if(is_empty())
                throw std::domain_error("stack is empty!");
            T& return_elem = data[top_index - 1];
            top_index--;
            return return_elem;
        }


    private:
        T* data;
        int stack_size;
        int top_index;
};
