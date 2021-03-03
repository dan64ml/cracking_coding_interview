/*********************************************************************************
 * Написать класс MyQueue, который реализует очередь с использованием двух стеков.
 ********************************************************************************/

#include <stack>
#include <stdexcept>

using namespace std;

namespace ch03 {

// Чудес не бывает - в стеке доступен только последний элемент. Чтобы достать первый
// все содержимое придется переложить в другой стек. Возможна оптимизация: при первом 
// обращении к началу очереди переложить все содержимое придется. Далее добавляемые
// элементы можно класть в освободившийся стек, а для remove()/peek() использовать 
// второй стек, пока он не опустеет. Далее опять переложить все элементы. 
// Сложность add() O(1), сложность remove()/peek() - амортизированная O(1).
template<class T>
class MyQueue {
    public:
        MyQueue() = default;

        void add(T elem) {
            in_.push(elem);
        }

        T peek() {
            if (empty()) {
                throw runtime_error("stack is empty");
            }
            if (out_.empty()) {
                in_to_out();
            }
            return out_.top();
        }

        T remove() {
            T ret = peek();
            out_.pop();
            return ret;
        }

        bool empty() { return in_.empty() && out_.empty(); }

    private:
        void in_to_out() {
            while (!in_.empty()) {
                out_.push(in_.top());
                in_.pop();
            }
        }

    private:
        stack<T> in_;
        stack<T> out_;
};

} // namespace ch03
