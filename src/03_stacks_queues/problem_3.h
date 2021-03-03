/*******************************************************************************
 * Реализовать стек содержащий динамический набор стеков фиксированного размера.
 * При заполнении очередного подстека создается новый, при освобождении - удаляется.
 * Дополнительно реализовать метод popAt(int stack), который возращяет данные из
 * указанного подстека
 *******************************************************************************/

#include <stack>
#include <vector>
#include <stdexcept>

using namespace std;

namespace ch03 {

// На реализацию класса сильно влияют требования к методу popAt(int stack).
// Здесь он просто изымает данные из указанного подстека и удаляет его, если
// он пуст. Сложность push() амортизированная O(1), popAt() - O(N/stack_size).
// остальные операции O(1).
template<class T = int>
class SetOfStack {
    public:
        SetOfStack(int stack_size) : stack_size_(stack_size) {}

        void push(T elem) {
            if (static_cast<int>(data_.back().size()) == stack_size_) {
                data_.push_back(stack<T>());
            }

            data_.back().push(elem);
        }

        T pop() {
            if (data_.back().empty()) {
                throw runtime_error("stack is empty");
            }

            T elem = data_.back().top();
            data_.back().pop();
            if (data_.back().size() == 0 && data_.size() != 1) {
                data_.pop_back();
            }

            return elem;
        }

        T peek() {
            if (data_.back().empty()) {
                throw runtime_error("stack is empty");
            }

            return data_.back().top();
        }

        T popAt(int s) {
            if (s >= static_cast<int>(data_.size())) {
                throw runtime_error("invalid index");
            }
            if (data_[s].empty()) {
                throw runtime_error("stack is empty");
            }

            T elem = data_[s].top();
            data_[s].pop();

            if (data_[s].empty() && data_.size() != 1) {
                auto it = next(begin(data_), s);
                data_.erase(it);
            }

            return elem;
        }

        bool empty() { return data_.back().empty(); }
    private:
        int stack_size_;
        vector<stack<T>> data_ {1};
};


// Другая реализация popAt(). Здесь место извлеченного из подстека элемента
// заполняется элементом из следующего подстека с полным сдвигом данных.
// Логично организовать такую структуру над вектором. Сложность popAt() - O(N).
// Остальные операции O(1).
template<class T = int>
class SetOfStack2 {
    public:
        SetOfStack2(int stack_size) : stack_size_(stack_size) {}

        void push(T elem) {
            data_.push_back(elem);
        }

        T pop() {
            if (data_.empty()) {
                throw runtime_error("stack is empty");
            }

            T ret = data_.back();
            data_.pop_back();
            return ret;
        }

        T peek() {
            if (data_.empty()) {
                throw runtime_error("stack is empty");
            }

            return data_.back();
        }

        T popAt(int s) {
            int num = data_.size() / stack_size_;
            if (s > num) {
                throw runtime_error("invalid index");
            }

            T ret;
            if (num == s) {
                ret = data_.back();
                data_.pop_back();
            } else {
                int idx = (s + 1) * stack_size_ - 1;
                ret = data_[idx];
                auto it = next(begin(data_), idx);
                data_.erase(it);
            }

            return ret;
        }

        bool empty() { return data_.empty(); }

    private:
        int stack_size_;
        vector<T> data_;
};

} // namespace ch03
