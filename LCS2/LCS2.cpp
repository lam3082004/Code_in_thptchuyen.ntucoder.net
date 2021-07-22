// Cho hai xâu
// S
//  và
// T
//  chỉ gồm các chữ cái in thường. Tìm độ dài xâu con chung dài nhất (Subsequence) của hai xâu
// S
//  và
// T

// Dữ liệu vào:

// Dòng đầu tiên chứa xâu
// S
// Dòng thứ hai chứa xâu
// T
// Kết quả: In ra một số nguyên dương duy nhất là độ dài xâu con chung dài nhất của
// S
//  và
// T
// .

// Ràng buộc:

// Subtask 1 (50%):
// |
// S
// |
// ,
// |
// T
// |
// ≤
// 5.10
// 3
// Subtask 2 (50%):
// |
// S
// |
// ≤
// 10
// 6
// ,
// |
// T
// |
// ≤
// 5.10
// 3
// Ví dụ
// Input:

// abcdefghixyz
// abcxdefyghiz
// Output:

// 10

// Giải thích: Đó là xâu abcdefghiz
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;
const int M = 5e3 + 1;

int nxt[N][26], f[M][2], n, m;

int main(int argc, char const *argv[])
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    n = s.length(), m = t.length();
    for (int i = 0; i < 26; ++i)
        nxt[n][i] = nxt[n + 1][i] = n;
    for (int i = n; i > 0; --i)
        for (auto j = 0; j < 26; ++j)
            if (s[i - 1] - 'a' == j)
                nxt[i - 1][j] = i - 1;
            else
                nxt[i - 1][j] = nxt[i][j];

    for (int j = 0; j < m; ++j)
        f[j][0] = -1;
    f[0][1] = nxt[0][t[0] - 'a'];
    int z = 1, res = 0;
    for (int k = 0; k < m; ++k)
    {
        if (k > 0)
            f[k][z] = nxt[f[k - 1][z ^ 1] + 1][t[k] - 'a'];
        for (int i = k + 1; i < m; ++i)
        {
            f[i][z] = min(f[i - 1][z], nxt[f[i - 1][z ^ 1] + 1][t[i] - 'a']);
        }
        if (f[m - 1][z] < n)
            res = k + 1;
        z ^= 1;
    }
    cout << res << endl;
    cout << "hahahahahaha" << endl;
    return 0;
}
