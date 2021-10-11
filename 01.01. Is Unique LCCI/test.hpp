#include "bits/stdc++.h"
#include "../include/helper.hpp"
using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        unordered_set<char> uoset;
        for (const char& ch : astr) {
            if (uoset.find(ch) != uoset.end()) {
                return false;
            }
            uoset.insert(ch);
        }
        return true;
    }
};

class Solution_2 {
public:
    bool isUnique(string astr) {
        int mask = 0;
        for (char ch : astr) {
            int idx = ch - 'a';
            if ((mask & (1 << idx)) != 0) {
                return false;
            } else {
                mask |= (1 << idx);
            }
        }
        return true;
    }
};