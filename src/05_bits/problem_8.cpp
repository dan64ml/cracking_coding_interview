/*********************************************************************************
 * Написать функцию рисования горизонтальных линий в монохромном фреймбуфере, заданном
 * одномерным массивом
 ********************************************************************************/

#include "chapter_5.h"

#include <vector>
#include <cstddef>

using namespace std;

namespace ch05 {

void plot(vector<byte>& fb, int width, int x, int y) {
    int row_offset = y * (width / 8);
    int col_offset = x / 8;
    int bit_number = 7 - (x % 8);

    fb[row_offset + col_offset] |= static_cast<byte>(0x1 << bit_number);
}

// Как обычно, есть простое решение и есть быстрое. Это простое. Выносим
// в отдельную функцию рисование точки и в цикле рисуем точку. Из плюсов -
// можно вспомнить брезенхейма и рисовать любые линии.
void DrawLine(vector<byte>& fb, int width, int x1, int x2, int y) {
    if (x1 > x2) {
        swap(x1, x2);
    }

    for (int i = x1; i <= x2; ++i) {
        plot(fb, width, i, y);
    }
}

// Это быстрое - работаем не побитно, а с байтами. Особый случай, когда
// вся линия попадает в один байт...
void DrawLine2(vector<byte>& fb, int width, int x1, int x2, int y) {
    if (x1 > x2) {
        swap(x1, x2);
    }

    int row_offset = y * (width / 8);

    int x1_byte = x1 / 8;
    int x2_byte = x2 / 8;

    int x1_bit = 7 - (x1 % 8);
    int x2_bit = 7 - (x2 % 8);

    byte sb1 = static_cast<byte>((0x1 << (x1_bit + 1)) - 1);
    byte sb2 = ~static_cast<byte>((0x1 << x2_bit) - 1);

    if (x1_byte == x2_byte) {
        byte mask = sb1 & sb2;
        fb[row_offset + x1_byte] |= mask;
    } else {
        fb[row_offset + x1_byte] |= sb1;
        fb[row_offset + x2_byte] |= sb2;

        for (int i = x1_byte + 1; i < x2_byte; ++i) {
            fb[row_offset + i] = byte(0xFF);
        }
    }
}

} // namespace ch05
