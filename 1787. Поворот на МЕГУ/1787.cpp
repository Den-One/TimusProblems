/*
 *  Operating Time:   0.015 sec.
 *  Allocated Memory: 284 КБ
 *  Time Complexity:  O(n)
 *  Space Complexity: O(1)
 */

#include <vector>
#include <iostream>
#include <unordered_set>

int main() {
    size_t cars = 0, nMinutes = 0, counter = 0;
    std::cin >> cars >> nMinutes;

    for (size_t i = 0; i < nMinutes; ++i) {
        size_t buffer;
        std::cin >> buffer;

        counter += buffer;

        (cars > counter) ? counter = 0 : counter -= cars;
    }

    std::cout << counter;

    return 0;
}