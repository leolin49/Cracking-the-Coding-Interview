#include "bits/stdc++.h"

std::vector<int> StringVector2IntVector(std::vector<std::string> vet) {
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
    auto res = StringVector2IntVector(arr);
    return res;
}

std::vector<std::vector<int>> String2Vector2D(std::string str) {
    // std::regex e("^\\[(\\[([\\d],)+[0-9]\\],)+\\[([\\d],)+[0-9]\\]\\]$");
    // [[1,2,3],[4,5,6],[7,8,9]]
    str.insert(str.size() - 1, ",");
    // [[1,2,3],[4,5,6],[7,8,9],]
    str = str.substr(1, str.length() - 2);
    // [1,2,3],[4,5,6],[7,8,9],
    std::regex e("(\\[([\\d]+,)+[\\d]+\\],)");
    std::sregex_iterator pos(str.cbegin(), str.cend(), e);
    // std::smatch m;
    std::sregex_iterator end;
    if (pos == end) {
        std::cout << "regex match failed!" << std::endl;
        return {};
    }
    std::vector<std::vector<int>> res;
    for (; pos != end; ++pos) {
        std::cout << "Matched: " << pos->str(0) << std::endl;
        std::cout << "user name: " << pos->str(1) << std::endl;
        std::cout << "domain: " << pos->str(2) << std::endl;
        std::string arrStr = pos->str(0);
        arrStr = arrStr.substr(0, arrStr.size() - 1);
        res.emplace_back(String2Vector(arrStr));
    }
    return res;
}

std::vector<std::string> ReadInputFile(std::string path="./test.txt") {
    std::ifstream file(path);
    std::string temp;
    if (!file.is_open()) {
        std::cout << "read file error" << std::endl;
        return {};
    }
    std::vector<std::string> res;
    while (getline(file, temp)) {
        res.push_back(temp);
    }
    file.close();
    return res;
}

void PrintResultBool(bool res) {
    if (res) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
}

template<class T>
void PrintMatrix(std::vector<std::vector<T>> matrix) {
    for (auto arr : matrix) {
        for (auto val : arr) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}