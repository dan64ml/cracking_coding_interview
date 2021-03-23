/*********************************************************************************
 * Имеется структура данных с быстрым доступом к элементам по индексу, но без метода
 * определения длины. При обращении к индексу несуществующего элемента возвращается -1.
 * Структура хранит отсортированные положительные числа. Написать метод поиска индекса
 * заданного элемента.
 ********************************************************************************/

#include "chapter_10.h"

#include <vector>

using namespace std;

namespace ch10 {

// В целом опять про бинарный поиск. Для поиска правой границы
// кратно двум двигаем правый индекс. Это дает логарифмическое время
// поиска границы. Далее обычный бинарный поиск с доппроверкой элементов
// на -1.
int SearchInListy(const vector<int>& lst, int number) {
    if (lst[0] == -1) {
        return -1;
    }

    int left = 0;
    int right = 0;
    while (true) {
        right = (right == 0) ? 1 : right * 2;
        if (lst[right] == -1 || lst[right] > number) {
            break;
        } else if (lst[right] == number) {
            return right;
        } else {
            left = right;
        }
    }

    while (left <= right) {
        int mid = (left + right) / 2;
        if (lst[mid] == number) {
            return mid;
        } else if (lst[mid] == -1 || lst[mid] > number) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

} // namespace ch10
