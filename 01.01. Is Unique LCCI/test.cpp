#include "test.hpp"
using namespace std;

int main() {
    string str;
    int k;
    auto input = ReadInputFile("01.01. Is Unique LCCI\\test.txt");
    str = input[0];

    Solution sl;
    PrintResultBool(sl.isUnique(str));
    system("pause");
    return 0;
}