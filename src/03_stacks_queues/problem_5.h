/*********************************************************************************
 * Написать программу сортировки стека. Наименьший элемент должен оказаться на 
 * вершине стека. Можно использовать дополнительный стек, другие структуры данный
 * не допустимы.
 ********************************************************************************/

#include <stack>
#include <stdexcept>

using namespace std;

namespace ch03 {

// Во втором стеке выкладываем элементы в обратном порядке. Для этого снимаем в основном
// стеке верхний элемент, перекладываем из второго стека в основной все элементы, большие
// верхнего элемента. Кладем верхний, возвращаем бОльшие элементы. Далее по индукции...
// Сложность O(N^2), память O(N).
template<class T>
void sort_stack(stack<T>& s) {
    stack<T> extra;

    while (!s.empty()) {
        T elem = s.top();
        s.pop();

        int count = 0;
        while (!extra.empty() && extra.top() > elem) {
            s.push(extra.top());
            extra.pop();
            ++count;
        }

        extra.push(elem);

        while (count--) {
            extra.push(s.top());
            s.pop();
        }
    }

    while (!extra.empty()) {
        s.push(extra.top());
        extra.pop();
    }
}

} // namespace ch03
