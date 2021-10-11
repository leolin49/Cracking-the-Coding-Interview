#include "test.h"
using namespace std;

int main() {
    string input;
    int k;
    cin >> input >> k;
    auto vet = String2Vector(input);
    
    ListNode* head = Vector2List(vet);
    Solution sl;
    cout << sl.kthToLast(head, k) << endl;
    system("pause");
    return 0;
}