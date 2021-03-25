/*********************************************************************************
 * Дан поток целых чисел. Периодически требуется находить ранг произвольного числа.
 * Реализовать операцию Track(int) обрабатывающую новое число и GetRank(int) 
 * возвращающую ранг числа.
 ********************************************************************************/

#include "chapter_10.h"

#include <vector>

using namespace std;

namespace ch10 {

// В целом на выбор правильного решения влияет частота вызова Track(int) и GetRank(int).
// Если добавляют много а спрашивают редко брутфорс рулит: за О(1) добавляем числа в 
// обычный вектор и за O(N) ищем ранг нужного числа.
// Если спрашивают и добавляют примерно одинаково, реализуем обе операции за O(lgN).
// Расширяем узлы дерева поиска количеством узлов слева и справа. Также добавляем 
// счетчик повторов значения самого узла. Эти значения элементарно корректируются при 
// каждой вставке.
void Tracker::Track(int number) {
    if (!root_) {
        root_ = new TrNode(number);
        return;
    }

    auto cur = root_;
    auto parent = root_;

    while (cur) {
        parent = cur;
        if (cur->value == number) {
            cur->my_count++;
            return;
        } else if (cur->value > number) {
            cur->l_count++;
            cur = cur->left;
        } else {
            cur->r_count++;
            cur = cur->right;
        }
    }

    if (parent->value > number) {
        parent->left = new TrNode(number);
    } else {
        parent->right = new TrNode(number);
    }
}

// Поиск ранга тоже не очень сложен и производится вместе с поиском числа в дереве.
// Самое сложное - правильно вычислять ранг потомка на основе ранга родителя.
// PS!!!! Сложность для данной реализации O(lgN) для сбалансированного дерева.
int Tracker::GetRank(int number) {
    if (!root_) {
        return -1;
    }

    int rank = root_->l_count + root_->my_count - 1;
    auto cur = root_;

    while (true) {
        if (cur->value == number) {
            return rank;
        } else if (cur->value > number) {
            if (!cur->left) {
                break;
            }
            rank = rank - cur->left->r_count - cur->my_count;
            cur = cur->left;
        } else {
            if (!cur->right) {
                break;
            }
            rank = rank + cur->right->l_count + cur->right->my_count;
            cur = cur->right;
        }
    }

    return -1;
}

Tracker::~Tracker() {
    DtorHelper(root_);
}

void Tracker::DtorHelper(TrNode* node) {
    if (!node) {
        return;
    }

    DtorHelper(node->left);
    DtorHelper(node->right);
    delete node;
}

} // namespace ch10
