/*
 *  Operating Time:   0.109 sec.
 *  Allocated Memory: 2 420 KB
 *  Time Complexity:  O(n)
 *  Space Complexity: O(n)
 */

#include <iostream>
#include <set>

int main() {
    // '1' position in the "1101001000" line, starts with 0
    std::set<int> positions;

    long long change = 0;
    for (int i = 0; change < INT_MAX; ++i) {
        change += i; // 0, 1, 3, 6, 10 ....
        positions.insert(change);
    }

    std::string result;
    int n, buffer;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> buffer;
        // if position (starts with 1) was inserted in the set, save "1 "
        if (positions.find(buffer - 1) != positions.end()) {
            result += "1 ";
        }
        else {
            result += "0 ";
        }
    }

    std::cout << result;
}