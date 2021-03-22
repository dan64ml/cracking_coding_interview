/*********************************************************************************
 * Дано логическое выражение, построенное из символов 0, 1, &, |, ^ и требуемый
 * результат: true или false. Подсчитать количество вариантов расстановки скобок,
 * при котором выражение равно требуемому результату.
 ********************************************************************************/

#include "chapter_8.h"

#include <vector>
#include <algorithm>

using namespace std;

namespace ch08 {

// Самым сложным оказалось понять условие задачи: оно подразумевает, что операции
// по сути не имеют приоритетов и порядок вычисления ПОЛНОСТЬЮ определяется скобками.
// Т.е. нельзя поставить, например, только одну пару скобок. Такая постановка задачи
// сильно упрощает решение: мы просто рекурсивно перебираем все варианты расстановки
// скобок, спускаясь до отдельного 0 или 1. Ну и считаем количество вариантов для
// каждой операции в соответствии с таблицой истинности.
// Здесь - неоптимизированное решение. Оптимизация очевидна: CountEval() зависит от
// двух параметров. Делаем из них ключ и кладем в unordered_map<key, count>. Лень писать...
int CountEval(string str, bool result) {
    if (str.length() == 1) {
        bool value = str == "1";
        return (result == value) ? 1 : 0;
    }

    int total_num = 0;
    for (size_t i = 1; i < str.length(); i += 2) {
        int left_true = CountEval(str.substr(0, i), true);
        int left_false = CountEval(str.substr(0, i), false);
        int right_true = CountEval(str.substr(i + 1), true);
        int right_false = CountEval(str.substr(i + 1), false);

        int total = (left_true + left_false) * (right_true + right_false);

        int total_true = 0;
        if (str[i] == '&') {
            total_true = left_true * right_true;
        } else if (str[i] == '^') {
            total_true = left_true * right_false + left_false * right_true;
        } else if (str[i] == '|') {
            total_true = left_true * right_true + left_true * right_false +
                left_false * right_true;
        }

        total_num += result ? total_true : total - total_true;
    }

    return total_num;
}

} // namespace ch08
