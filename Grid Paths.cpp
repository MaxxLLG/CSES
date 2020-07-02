#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
using namespace std;
#define ll long long

ll w = 0, steps = 0;
bool v[7][7];
int reserved[49];

void solve(ll r, ll c) {
    if (r == 6 && c == 0) {
        if (steps == 48) w++;
        return;
    }
    bool t = v[r][c] || (
            (
                    c > 0 && c < 6 && !v[r][c + 1] && !v[r][c - 1] &&
                    ((r == 0 && v[r + 1][c]) || (r == 6 && v[r - 1][c]))) || (
                    r > 0 && r < 6 && !v[r + 1][c] && !v[r - 1][c] &&
                    ((c == 0 && v[r][c + 1]) || (c == 6 && v[r][c - 1]))))
             || (r > 0 && r < 6 && c > 0 && c < 6 && v[r - 1][c] && v[r + 1][c] && !v[r][c - 1] && !v[r][c + 1])
             || (r > 0 && r < 6 && c > 0 && c < 6 && v[r][c - 1] && v[r][c + 1] && !v[r - 1][c] && !v[r + 1][c]);
    if (t) return;
    v[r][c] = true;
    if (reserved[steps] != -1) {

        switch (reserved[steps]) {
            case 0:
                if (r > 0 && !v[r - 1][c]) {
                    steps++;
                    solve(r - 1, c);
                    steps--;
                }
                break;
            case 2:
                if (r < 6 && !v[r + 1][c]) {
                    steps++;
                    solve(r + 1, c);
                    steps--;
                }
                break;
            case 3:
                if (c > 0 && !v[r][c - 1]) {
                    steps++;
                    solve(r, c - 1);
                    steps--;
                }
                break;
            case 1:
                if (c < 6 && !v[r][c + 1]) {
                    steps++;
                    solve(r, c + 1);
                    steps--;
                }
                break;

        }
        v[r][c] = false;

        return;
    }
    if (r > 0 && !v[r - 1][c]) {
        steps++;
        solve(r - 1, c);
        steps--;
    }
    if (r < 6 && !v[r + 1][c]) {
        steps++;
        solve(r + 1, c);
        steps--;
    }
    if (c > 0 && !v[r][c - 1]) {
        steps++;
        solve(r, c - 1);
        steps--;
    }
    if (c < 6 && !v[r][c + 1]) {
        steps++;
        solve(r, c + 1);
        steps--;
    }
    v[r][c] = false;
}

int main() {

    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '?') reserved[i] = -1;
        else if (str[i] == 'U') reserved[i] = 0;
        else if (str[i] == 'R') reserved[i] = 1;
        else if (str[i] == 'D') reserved[i] = 2;
        else if (str[i] == 'L') reserved[i] = 3;
    }
    solve(0, 0);
    cout << w;
    return 0;
}
