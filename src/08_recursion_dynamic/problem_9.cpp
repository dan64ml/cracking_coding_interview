/*********************************************************************************
 * Написать метод генерации всех комбинаций круглых скобок (дано N пар) 
 ********************************************************************************/

#include "chapter_8.h"

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

namespace ch08 {

void GPHelper(int left, int right, vector<string>& result, string& gp) {
    if (!left && !right) {
        result.push_back(gp);
        return;
    }

    if (left) {
        gp.push_back('(');
        GPHelper(left - 1, right, result, gp);
        gp.pop_back();
    }

    if (right && right > left) {
        gp.push_back(')');
        GPHelper(left, right - 1, result, gp);
        gp.pop_back();
    }
}

// Условие корректности - количество левых скобок в любом месте комбинации не
// меньше количества правых. Брутфорс - сгенерировать все перестановки и выкинуть
// некорректные комбинации.
// Эффективней отсекать некоректные комбинации на этапе генерации. Простая рекурсия:
// в очередной позиции мы можем поставить ( если они еще не израсходованы или ), если
// их меньше, чем (.
vector<string> GenerateParentheses(int num) {
    vector<string> result;
    string gp;

    GPHelper(num, num, result, gp);

    return result;
}

} // namespace ch08
