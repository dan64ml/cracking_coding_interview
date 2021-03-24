/*********************************************************************************
 * Дан массив с числами от 1 до не более 32000. Массив может содержать дубликаты.
 * Вывести все дкбликаты используя не более 4К памяти.
 ********************************************************************************/

#include "chapter_10.h"

#include <vector>
#include <ostream>
#include <array>

using namespace std;

namespace ch10 {

template<int Size>
class BitVector {
    private:
        array<uint8_t, Size> data_ = {};

    public:
        BitVector() = default;

        bool GetBit(int idx) {
            int byte_num = idx / 8;
            int bit_num = idx % 8;
            return data_[byte_num] & (0x1 << bit_num);
        }

        void SetBit(int idx) {
            int byte_num = idx / 8;
            int bit_num = idx % 8;
            data_[byte_num] |= (0x1 << bit_num);
        }
};

// 4К памяти и максимальное число 32000 очень намекают на битовый вектор.
// Здесь очень простой битовый велосипед, хотя просится std::bitset().
void DisplayDublicates(ostream& os, const vector<int>& vec) {
    BitVector<4096> bv;

    for (auto e : vec) {
        if (bv.GetBit(e)) {
            os << e << ',';
        } else {
            bv.SetBit(e);
        }
    }
}

} // namespace ch10
