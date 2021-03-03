/**************************************************************************
 * Напишите метод сжатия строки с использованием счетчика повторяющихся 
 * символов. Если сжатая строка на становится короче, вернуть исходную строку.
 **************************************************************************/
#include "chapter_1.h"

#include <string>

using namespace std;

namespace ch01 {

// Сама задача тривиальна. Интересной может быть оптимизация работы со строками.
// Конкатенацию можно заменить на работу со stringstream или посимвольно конструировать
// сжатую строку. В любом случае оптимальный вариант неочевиден, надо измерять...
string compress(const string& str) {
    if (str.size() < 2) {
        return str;
    }

    string::value_type letter = str[0];
    int counter = 1;

    string result;

    for (size_t i = 1; i < str.size(); ++i) {
        if (str[i] == letter) {
            ++counter;
        } else {
            result.push_back(letter);
            result += to_string(counter);

            letter = str[i];
            counter = 1;
        }
    }

    result.push_back(letter);
    result += to_string(counter);

    return (result.size() < str.size() ? result : str);
}

} // namespace ch01
