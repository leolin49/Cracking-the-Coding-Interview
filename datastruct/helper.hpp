#include "bits/stdc++.h"

std::vector<int> StringVector2T(std::vector<std::string> vet) {
    std::stringstream ss;
    std::vector<int> res;
    for (const auto& val : vet) {
        ss << val;
        int num;
        ss >> num;
        ss.clear();
        res.push_back(num);
    }
    return res;
}

std::vector<std::string> Split(std::string str, std::string pattern) {
    std::string::size_type pos;
    std::vector<std::string> res;
    str += pattern;

    int size = str.size();
    int plen = pattern.size();
    int i = 0;
    while (i < size) {
        pos = str.find(pattern, i);
        if (pos == str.npos) {
            break;
        }
        std::string s = str.substr(i, pos - i);
        res.push_back(s);
        i = pos + plen;
    }
    return res;
}

std::vector<int> String2Vector(std::string str) {
    // [1,2,3,4,5]
    int len = str.length();
    auto arr = Split(str.substr(1, len - 2), ",");
    auto res = StringVector2T(arr);
    return res;
}
