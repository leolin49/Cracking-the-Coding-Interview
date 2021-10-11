#include "test.hpp"
using namespace std;

int main() {
    string str;
    int k;
    auto input = ReadInputFile("02.02. Kth Node From End of List LCCI\\test.txt");
    str = input[0];
    k = atoi(input[1].c_str());
    auto vet = String2Vector(str);
    
    ListNode* head = Vector2List(vet);
    Solution sl;
    cout << sl.kthToLast(head, k) << endl;
    system("pause");
    return 0;
}