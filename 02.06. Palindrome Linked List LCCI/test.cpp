#include "test.hpp"
using namespace std;

int main() {
    string str;
    auto input = ReadInputFile("02.06. Palindrome Linked List LCCI\\test.txt");
    str = input[0];
    auto vet = String2Vector(str);
    ListNode* head = Vector2List(vet);

    Solution_3 sl;
    PrintResultBool(sl.isPalindrome(head));
    system("pause");
    return 0;
}