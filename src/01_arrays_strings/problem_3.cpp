/*************************************************************************
 * Напишите метод, заменяющий все пробелы в строке символами "%20". Длина
 * строки позволяет сохранить дополнительные символы и заранее известна
 * фактическая длина строки.
 *************************************************************************/

#include <string>

using namespace std;

namespace ch01 {

// Единственная хитрость - начать с конца строки. O(size()).
void replace_spaces(string& str, int size) {
    int to_idx = str.size() - 1;
    //int from_idx = size - 1;

    for (int from_idx = size - 1; from_idx >= 0; --from_idx) {
        if (str[from_idx] == ' ') {
            str[to_idx--] = '0';
            str[to_idx--] = '2';
            str[to_idx--] = '%';
        } else {
            str[to_idx--] = str[from_idx];
        }
    }
}

} // namespace ch01
