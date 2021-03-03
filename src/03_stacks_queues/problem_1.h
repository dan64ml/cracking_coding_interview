/*******************************************************************************
 * Реализовать 3 стека поверх одного одномерного массива.
 *******************************************************************************/

#include <vector>
#include <stdexcept>
#include <numeric>
#include <cmath>
#include <cassert>

namespace ch03 {

// Очевидное решение - разделить массив на три части и сделать поверх них три стека.
// Минус - неоптимальное использование памяти. Несомненный плюс - скорость работы. 
// Сложность всех операций O(1).
// Другой вариант - при необходимости двигать стеки для оптимального использования памяти.
// Минус - ужасная производительность. При некоторых условиях сложность push() O(N).
// Остальные операции остаются O(1). 
template <class T = int>
class FixedStack {
    private:
        const int kStackNumber = 3;
    public:
        FixedStack(size_t size) : size_(size), vec_(size * kStackNumber),
                                stack_size_(kStackNumber, 0) {
        }

        T pop(int s) {
            if (stack_size_[s] == 0) {
                throw std::runtime_error("pop()");
            }

            int idx = stack_size_[s];
            --stack_size_[s];
            return vec_[s * size_ + idx - 1];
        }

        void push(int s, T elem) {
            if (stack_size_[s] >= size_) {
                throw std::runtime_error("push()");
            }

            vec_[s * size_ + stack_size_[s]] = elem;
            ++stack_size_[s];
        }

        T peek(int s) {
            if (stack_size_[s] == 0) {
                throw std::runtime_error("peek()");
            }

            return vec_[s * size_ + stack_size_[s] - 1];
        }

        bool isEmpty(int s) {
            return !stack_size_[s];
        }

    private:
        int size_;
        std::vector<T> vec_;
        std::vector<int> stack_size_;
};

// Задача на аккуратную реализацию. Особенно операции с кольцевым буфером. Возможно, есть
// смысл реализовать кольцевой буфер отдельным классом. Код едва ли будет красивее, но его
// можно будет лучше покрыть тестами.
// Можно улучшить алгоритм выбора стека для перемещения, минимизируя объем перемещаемых данных,
// но асимптотика push() останется O(N).
template <class T = int>
class DynamicStack {
    private:
        const int kStackNumber = 3;
    public:
        DynamicStack(int total_size) : total_size_(total_size), vec_(total_size),
                    stack_start_(kStackNumber), stack_size_(kStackNumber, 0) {
            int len = total_size_ / 3;
            for (int i = 0; i < kStackNumber; ++i) {
                stack_start_[i] = len * i;
            }
        }

        T pop(int s) {
            if (isEmpty(s)) {
                throw std::runtime_error("pop()");
            }

            int idx = TopElementIndex(s);
            --stack_size_[s];
            return vec_[idx];
        }

        void push(int s, T elem) {
            if (IsStackFull(s) && !RebuildStack(s)) {
                throw std::runtime_error("No free space");
            }

            vec_[FirstFreeIndex(s)] = elem;
            ++stack_size_[s];
        }

        T peek(int s) {
            if (isEmpty(s)) {
                throw std::runtime_error("peek()");
            }

            return vec_[TopElementIndex(s)];
        }

        bool isEmpty(int s) { return !stack_size_[s]; }

    private:
        // Можно придумать кучу стратегий переупорядочивания стеков.
        // Реализуем следующую: если нужно место, двигаем стек спереди на половину
        // возможного расстояния. Если это невозможно, двигаем сам стек назад.
        bool RebuildStack(int s) {
            int move_distance = CanMoveForward(NextStack(s));
            if (move_distance) {
                MoveForward(NextStack(s), move_distance);
            } else {
                move_distance = CanMoveBackward(s);
                if (!move_distance) {
                    return false;
                }

                MoveBackward(s, move_distance);
            }

            return true;
        }

        bool IsStackFull(int s) {
            int next_stack = stack_start_[NextStack(s)];
            int stack_top = FirstFreeIndex(s);

            return (stack_top == next_stack) ? true : false;
        }

        int CanMoveForward(int s) {
            int top = FirstFreeIndex(s);
            int next_stack = stack_start_[NextStack(s)];

            int space;
            if (top == next_stack) {
                space = 0;
            } else if (next_stack > top) {
                space = next_stack - top;
            } else {
                space = total_size_ + next_stack - top;
            }

            return std::ceil(space / 2.);
        }

        int CanMoveBackward(int s) {
            int prev_top = FirstFreeIndex(PrevStack(s));
            int start = stack_start_[s];

            int space;
            if (prev_top == start) {
                space = 0;
            } else if (prev_top < start) {
                space = start - prev_top;
            } else {
                space = total_size_ - prev_top + start;
            }

            return std::ceil(space / 2.);
        }

        void MoveForward(int s, int dist) {
            int source = TopElementIndex(s);
            int dest = IncIndex(source, dist);

            for (int i = 0; i < stack_size_[s]; ++i) {
                vec_[dest] = vec_[source];
                source = PrevIndex(source);
                dest = PrevIndex(dest);
            }

            stack_start_[s] = IncIndex(stack_start_[s], dist);
        }

        void MoveBackward(int s, int dist) {
            int source = stack_start_[s];
            int dest = DecIndex(source, dist);

            for (int i = 0; i < stack_size_[s]; ++i) {
                vec_[dest] = vec_[source];
                dest = NextIndex(dest);
                source = NextIndex(source);
            }

            stack_start_[s] = DecIndex(stack_start_[s], dist);
        }

        // Для итерации по кольцевому буферу
        int NextIndex(int idx) { return (idx + 1) % total_size_; }
        int PrevIndex(int idx) { return (idx == 0) ? total_size_ - 1 : idx - 1; }
        int IncIndex(int idx, int delta) { return (idx + delta) % total_size_; }
        int DecIndex(int idx, int delta) { return (idx >= delta) ? idx - delta : total_size_ + idx - delta; }
        // Верхушка стека
        int TopElementIndex(int s) { return (stack_start_[s] + stack_size_[s] - 1) % total_size_; }
        int FirstFreeIndex(int s) { return (stack_start_[s] + stack_size_[s]) % total_size_; }
        // Стеки
        int NextStack(int s) { return (s + 1) % kStackNumber; }
        int PrevStack(int s) { return (s == 0) ? kStackNumber - 1 : s - 1; }

    private:
        int total_size_;
        std::vector<T> vec_;
        std::vector<int> stack_start_;
        std::vector<int> stack_size_;
};

} // namespace ch03
