/*********************************************************************************
 * Написать рекурсивную функцию умножения двух положительных целых чисел. Допустимы
 * операции сложения, вычитания и сдвига.
 ********************************************************************************/

#include "chapter_8.h"

#include <vector>

using namespace std;

namespace ch08 {

int MultHelper(int num, int scale) {
    if (scale == 1) {
        return num;
    }

    return (MultHelper(num, scale >> 1) << 1) + num * (scale % 2);
}

// В целом совсем нехитрая рекурсия... O(lg(Scale)
int Mult(int num1, int num2) {
    if (num1 < num2) {
        swap(num1, num2);
    }
    if (num2 == 0) {
        return 0;
    }

    return MultHelper(num1, num2);
}

} // namespace ch08
