/*
 *  Operating Time:   0.015 sec.
 *  Allocated Memory: 300 КБ
 *  Time Complexity:  O(n + m)
 *  Space Complexity: O(n + m)
 */

#include <iostream>
#include <vector>

const long long CAR_LENGTH = 5;
const long long ROAD_LENGTH_MAX = 10'006;
const long long CROSS_ROAD_DISTANCE = 8;

void drawCarLength(std::vector<bool>& arr, long long pos) {
    for (long long i = pos; i < pos + CAR_LENGTH; ++i) {
        if (i >= 0) {
            arr[i] = true;
        }
    }
}

bool forwardCheck(std::vector<bool>& arr, long long pos) {
    for (long long i = pos; i < pos + CROSS_ROAD_DISTANCE; ++i) {
        if (arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<bool> roadLine(ROAD_LENGTH_MAX, false);

    long long n;
    std::cin >> n;
    for (long long i = 0; i < n; ++i) {
        long long carStart;
        std::cin >> carStart;
        drawCarLength(roadLine, carStart);
    }

    long long m;
    std::cin >> m;
    for (long long i = 0; i < m; ++i) {
        long long carStart;
        std::cin >> carStart;
        drawCarLength(roadLine, carStart - 8);
    }

    for (long long i = 0; i < ROAD_LENGTH_MAX; ++i) {
        if (forwardCheck(roadLine, i)) {
            if (i == 0) {
                std::cout << 0.0;
                return 0;
            }
            else {
                std::cout << double(i * 0.18);
                return 0;
            }
        }
    }
}