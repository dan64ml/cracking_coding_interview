/*********************************************************************************
 * Дан массив целых чисел. Пиком называется элемент больший соседних или равный им.
 * Впадиной - меньший или равный. Отсортировать массив так, чтобы пики и впадины
 * чередовались.
 ********************************************************************************/

#include "chapter_10.h"

#include <vector>

using namespace std;

namespace ch10 {

// Первая мысль - отсортировать и поменять местами четных и нечетных соседей. O(NlgN).
// Можно действовать хитрее: пусть нечетные индексы будут пиками. Проходим по всем пикам.
// Для каждого пика рассматриваем его и соседей. На место пика ставим самое большое из них
// число. Левым соседом ставим НАИМЕНЬШЕЕ. Это важно: рассматривая следующий пик мы должны
// сохранить предыдущий. Следуя этому правилу мы либо оставим общий элемент прежним (если
// он самый маленький), либо заменим на меньший и сохраним предыдущий пик. Последний пик
// может потребовать особой обработки (если нет правого соседа). O(N).
void HillSort(vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); i += 2) {
        if (i + 1 == vec.size() && vec[i] < vec[i - 1]) {
            swap(vec[i], vec[i - 1]);
        } else {
            if (vec[i] < vec[i - 1]) {
                swap(vec[i], vec[i - 1]);
            }
            if (vec[i] < vec[i + 1]) {
                swap(vec[i], vec[i + 1]);
            }
            if (vec[i - 1] > vec[i + 1]) {
                swap(vec[i - 1], vec[i + 1]);
            }
        }
    }
}

} // namespace ch10
