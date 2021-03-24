#include <iostream>

using namespace std;


template <typename T, int max_size>
class Stack {
    private:
    T stack_[max_size];
    size_t top_;
    public:
        Stack(): top_(0) {};
        void push(const T&);
        T pop();
        const T peek() const;
};

template<typename T, int max_size>
void Stack<T, max_size >::push(const T& new_elem){
    if (top_ >= max_size) {
        throw overflow_error("Stack overflow!");
    } else {
        stack_[top_++] = new_elem;
    }
};

template <typename T, int max_size>
T Stack<T, max_size>::pop() {
    if (0 == top_) 
        throw underflow_error("Underflow!");
    else {
        return stack_[--top_];
    }
}

template <typename T, int max_size>
const T Stack<T, max_size>::peek() const {
    return stack_[top_];
};


int main () {


    Stack<int, 10> stack;
    for (int i = 0; i < 10; i++) {
        stack.push(i+5);
    }
    for (int i = 0; i < 10; i++) {
        cout << stack.pop() << endl;
    }

    Stack<char, 26> stack_;
    for (char i = 'a'; i <= 'z'; i++) {
        stack_.push(i);
    }
    for (int i = 0 ; i < 26; i++) {
        cout << stack_.pop() << endl;
    }

    return 0;
}