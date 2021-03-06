/*******************************************************************************
 * Реализовать стек с функцией min(). Сложность всех операций должна быть O(1).
 *******************************************************************************/

#include <stack>

using namespace std;

namespace ch03 {

// Ограничение по сложности операций исключает поиск в существующих данных, следовательно
// придется хранить минимумы в доппамяти. В нашем случае удобено второй стек. Для каждого
// push() сравниваем новое значение и содержимое стека минимумов. Если новый элемент меньше
// или РАВЕН минимуму - кладем в стек. Для pop() удаляем элемент из стека минимумов если он
// равен извлекаемому значению. Сложность O(1), память O(N).
template <class T>
class MinStack {
    public:
        MinStack() = default;

        void push(T elem) {
            data_.push(elem);
            if (min_elem_.empty() || min_elem_.top() >= elem) {
                min_elem_.push(elem);
            }
        }

        T pop() {
            T ret = data_.top();
            data_.pop();

            if (ret == min_elem_.top()) {
                min_elem_.pop();
            }

            return ret;
        }

        T peek() { return data_.top(); }
        T min() { return min_elem_.top(); }

    private:
        stack<T> data_;
        stack<T> min_elem_;
};

} // namespace ch03
