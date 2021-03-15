#ifndef CHAPTER_5_H_
#define CHAPTER_5_H_

#include <cstdint>
#include <string>

namespace ch05 {

uint32_t InsertNumber(uint32_t n, uint32_t m, int i, int j);
std::string NumToBinary(double num);
int FindMaxSequence(uint num);
uint GetNext(uint num);
uint GetPrev(uint num);
int BitsForChange(int a, int b);
int SwapEvenOdd(int num);

} // namespace ch05

#endif // CHAPTER_5_H_