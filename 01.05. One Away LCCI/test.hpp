#include "bits/stdc++.h"
#include "../include/helper.hpp"
using namespace std;

/**
 * 字符串比较
 * 时间复杂度 O(n)
 * 空间复杂度 O(1)
 */
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int lenf = first.length();
        int lens = second.length();
        if (abs(lenf - lens) >= 2) {
            return false;
        }
        int m = min(lenf, lens);
        for (int i = 0; i < m; i++) {
            if (first[i] != second[i]) {
                if (lenf == lens) {
                    return first.substr(i + 1) == second.substr(i + 1);
                } else if (lenf > lens) {
                    return first.substr(i + 1) == second.substr(i);
                } else {
                    return first.substr(i) == second.substr(i + 1);
                }
            }
        }
        return true;
    }
};

/**
 * 二维dp
 * 时间复杂度 O(n*m)
 * 空间复杂度 O(n*m)
 */
class Solution_2 {
public:
    bool oneEditAway(string first, string second) {
        int lenf = first.length();
        int lens = second.length();
        if (abs(lenf - lens) >= 2) {
            return false;
        }
        vector<vector<int>> dp(lens + 1, vector<int>(lenf + 1, 0));
        dp[0][0] = 0;
        for (int i = 1; i <= lens; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= lenf; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= lens; i++) {
            for (int j = 1; j <= lenf; j++) {
                if (second[i - 1] == first[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[lens][lenf] <= 1;
    }
};

/**
 * 二维dp优化成一维dp
 * 时间复杂度 O(n*m)
 * 空间复杂度 O(n) 或 O(m)
 */
class Solution_3 {
public:
    bool oneEditAway(string first, string second) {
        int lenf = first.length();
        int lens = second.length();
        if (abs(lenf - lens) >= 2) {
            return false;
        }
        vector<int> dp(lenf + 1);
        for (int j = 0; j <= lenf; j++) {
            dp[j] = j;
        }
        for (int i = 1; i <= lens; i++) {
            dp[0] = i;
            int pre = i - 1;    // 二维中的dp[i-1][j-1]
            for (int j = 1; j <= lenf; j++) {
                int tmp = pre;
                pre = dp[j];
                if (second[i - 1] == first[j - 1]) {
                    dp[j] = tmp;
                } else {
                    dp[j] = min(tmp, min(dp[j], dp[j - 1])) + 1;
                }
            }
        }
        return dp[lenf] <= 1;
    }
};