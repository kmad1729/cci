#pragma once
#include <stack>

template <class T>
class StackWithMin: public std::stack<T> {
    private:
        std::stack<T> min_val_stack;

    public:
        void push(const T& t) {
            if(min_val_stack.empty()) {
                min_val_stack.push(t);
            } else {
                T min_val = min_val_stack.top();
                if(t < min_val)
                    min_val_stack.push(t);
            }
            std::stack<T>::push(t);
        }

        void pop() {
            if(!min_val_stack.empty()) {
                T ret_val = std::stack<T>::top();
                T min_val = min_val_stack.top();
                std::stack<T>::pop();

                if(ret_val == min_val && !std::stack<T>::empty() &&
                        min_val != std::stack<T>::top())
                    min_val_stack.pop();
            } else {
                std::stack<T>::pop();
            }
        }

        const T& min() const {
            return min_val_stack.top();
        }

};

