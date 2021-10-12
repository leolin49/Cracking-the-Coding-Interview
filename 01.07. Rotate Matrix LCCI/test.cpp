#include "test.hpp"
using namespace std;

int main() {
    string str;
    int k;
    auto input = ReadInputFile("01.07. Rotate Matrix LCCI\\test.txt");

    auto vet = String2Vector2D(input[0]);
    Solution_2 sl;
    PrintMatrix(vet);
    sl.rotate(vet);
    PrintMatrix(vet);
    system("pause");
}