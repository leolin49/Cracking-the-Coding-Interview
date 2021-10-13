#include "test.hpp"
using namespace std;

int main() {
    string str;
    int k;
    auto input = ReadInputFile("01.08. Zero Matrix LCCI\\test.txt");

    auto vet = String2Vector2D(input[0]);
    Solution sl;
    PrintMatrix(vet);
    sl.setZeroes(vet);
    PrintMatrix(vet);
    system("pause");
}