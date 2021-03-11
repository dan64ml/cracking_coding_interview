/*********************************************************************************
 * Бинарное дерево поиска создано последовательной вставкой каждого элемента массива.
 * Для заданного дерева с разными элементами вывести все возможные массивы, которые
 * приведут к созданию этого дерева.
 ********************************************************************************/

#include "chapter_4.h"

#include <vector>
#include <algorithm>

using namespace std;

namespace ch04 {

void MixHelper(const vector<int>& a, const vector<int>& b, size_t ai, size_t bi, 
                vector<int>& current, vector<vector<int>>& result) {
    if (ai == a.size() && bi == b.size()) {
        result.push_back(current);
        return;
    }

    if (ai < a.size()) {
        current.push_back(a[ai]);
        MixHelper(a, b, ai + 1, bi, current, result);
        current.pop_back();
    }

    if (bi < b.size()) {
        current.push_back(b[bi]);
        MixHelper(a, b, ai, bi + 1, current, result);
        current.pop_back();
    }
}

// Смешивает две последовательности не меняя порядка элементов.
// Классическая рекурсия: на каждом шаге мы можем взять очередной элемент
// либо из одной, либо из другой последовательности. Получается что-то
// типа бинарного дерева: a1a2 a1b1 b1a1 b1b2... Рекурсия останавливается
// когда выбраны все элементы обеих последовательностей. В этот момент мы
// получаем очередное решение.
vector<vector<int>> Mix(const vector<int>& a, const vector<int>& b) {
    vector<vector<int>> result;
    vector<int> current;

    MixHelper(a, b, 0, 0, current, result);

    return result;
}

void InsertFirst(vector<vector<int>>& vec, int value) {
    for (auto& elem : vec) {
        elem.insert(begin(elem), value);
    }
}


// Форма дерева поиска сильно зависит от порядка добавления элементов.
// Для сохранения формы важно, чтобы "верхние" узлы добавлялись раньше
// зависящих от них нижних. При этом ПОРЯДОК добавления зависящих узлов,
// или узлов НЕ зависящих, значения не имеет. Например: 10-42-100. Узлы
// 10 и 100 зависят от 42 и добавляться должны строго ПОСЛЕ 42. А вот
// порядок добавления значения не имеет. Ещё: 5-10-42-100. Узел 5 зависит
// от 10 (и рекурсивно) от 42. А вот от узла 100 не зависит никак. Поэтому
// 100 может быть добавлен в любой момент после 42.
// Отсюда вытекает следующая рекурсия: для каждого узла исходного дерева
// формируем все допустимые последовательности значений, используя 
// последовательности левого и правого поддерева. А именно, значение узла
// должно стоять в начале каждой последовательности, а из каждой пары последовательностей
// левой и правой веток надо сгенерировать все возможные перестановки. Важно, чтобы
// перестановки СОХРАНЯЛИ порядок следования значений в своей последовательности.
// Пример: {a1, a2} {b1, b2} => {a1, b1, b2, a1}, но не {a2, b1, b2, a1}.
// Базовый случай рекурсии - лист. Даёт единственную перестановку {{key}}
vector<vector<int>> GetSequences(Node* root) {
    if (!root) {
        return {};
    }

    auto l_seq = GetSequences(root->left);
    auto r_seq = GetSequences(root->right);

    if (l_seq.size() == 0 && r_seq.size() == 0) {
        return {{root->key}};
    } else if (r_seq.size() == 0) {
        InsertFirst(l_seq, root->key);
        return l_seq;
    } else if (l_seq.size() == 0) {
        InsertFirst(r_seq, root->key);
        return r_seq;
    }

    vector<vector<int>> ret;
    for (auto l : l_seq) {
        for (auto r : r_seq) {
            auto lr_mix = Mix(l, r);
            InsertFirst(lr_mix, root->key);
            move(begin(lr_mix), end(lr_mix), back_inserter(ret));
        }
    }

    return ret;
}

} // namespace ch04
