/*********************************************************************************
 * Написать метод генерации всех перестановок строки. Символы могут повторяться, 
 * но дубликатов перестановок быть не должно.
 ********************************************************************************/

#include "chapter_8.h"

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

namespace ch08 {

void UPHelper(const string& str, vector<bool>& is_free, vector<string>& result, string& ps) {
    if (str.size() == ps.size()) {
        result.push_back(ps);
        return;
    }

    unordered_set<char> dbl;

    for (size_t i = 0; i < str.size(); ++i) {
        if (is_free[i] && dbl.count(str[i]) == 0) {
            dbl.insert(str[i]);
            is_free[i] = false;
            ps.push_back(str[i]);

            UPHelper(str, is_free, result, ps);

            is_free[i] = true;
            ps.pop_back();
        }
    }
}

// Брутфорс с фильтрацией через сет или мапу рассматривать не будем.
// Можно рекурсивно (см. предыдущую задачу) ставить в каждую позицию
// свободные символы. Чтобы избежать повторов достаточно отсекать ветки
// рекурсии с уже использованными в этой позиции символами. Отлично
// подойдет unordered_set. Такая реализация потребует до O(n^2) памяти
// и O(n!) времени.
vector<string> UniquePermutation(const string& str) {
    vector<string> result;
    vector<bool> is_free(str.size(), true);
    string ps;

    UPHelper(str, is_free, result, ps);

    return result;
}

} // namespace ch08
