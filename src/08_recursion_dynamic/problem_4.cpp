/*********************************************************************************
 * Написать метод, возвращающий все подмножества заданного множества. 
 ********************************************************************************/

#include "chapter_8.h"

#include <vector>

using namespace std;

namespace ch08 {

void GSHelper(const vector<char>& vec, vector<string>& result, string& str, int idx) {
    if (idx == vec.size()) {
        result.push_back(str);
        return;
    }

    GSHelper(vec, result, str, idx + 1);
    str.push_back(vec[idx]);
    GSHelper(vec, result, str, idx + 1);
    str.pop_back();
}

// Подмножество это когда некоторые элементы исходного множества присутствуют,
// а некоторые нет. Нужно перебрать все такие комбинации. Самое простое - использовать
// двоичное представление числа как маску: 0 - элемент отсутствует, 1 - наоборот.
// Основная проблема - разрядность. В задаче нет ограничения на размер исходного множества.
// Второй вариант - рекурсия. Берем каждый элемент множества и либо вставляем его, или нет.
// Листья дерева рекурсии - искомые подмножества.
vector<string> GenerateSubsets(const vector<char>& vec) {
    vector<string> result;
    string str;

    GSHelper(vec, result, str, 0);

    return result;
}

} // namespace ch08
