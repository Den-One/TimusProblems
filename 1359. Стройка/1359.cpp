/*
 *  Operating Time:   0.062 sec.
 *  Allocated Memory: 376 КБ
 *  Time Complexity:  O(m * n)
 *  Space Complexity: O(n)
 */


#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::numeric_limits;
using std::sqrt;
using std::min;
using std::cin;
using std::cout;

using ld = long double;
using table_t = vector<vector<ld>>;

void upd(int Y, int y, int X, int x, table_t& array) {
    int dy = Y - y, dx = X - x, d2 = dx * dx + dy * dy;
    ld b = 2 * sqrt(2 * 10 * y * d2) / (dy * 10);
    ld c = -2.0l * (d2) / (dy * 10);
    array[X][Y] = min(array[X][Y], array[x][y] - b / 2 + sqrt(b * b / 4 - c));
}

void update(int n, int m, int Y, int X, int y, int x, table_t& array) {
    if (Y > m || X > n) {
        return;
    }
    if (y < Y) {
        upd(Y, y, X, x, array);
        update(n, m, Y, X, y + 1, x, array);
    }
    else {
        if (x < X) {
            upd(Y, y, X, x, array);
            update(n, m, Y, X, 0, x + 1, array);
        }
        else {
            update(n, m, Y + 1, 0, 0, 0, array);
        }
    }
}

int main() {
    const int MAX_VALUE = 51;
    table_t array(MAX_VALUE, vector<ld>(MAX_VALUE, numeric_limits<ld>::max()));
    array[0][0] = 0;

    int n, m;
    cin >> n >> m;
    for (int Y = 1; Y <= m; Y++) {
        for (int X = 0; X <= n; X++) {
            update(n, m, Y, X, 0, 0, array);
        }
    }

    cout << array[n][m];
}