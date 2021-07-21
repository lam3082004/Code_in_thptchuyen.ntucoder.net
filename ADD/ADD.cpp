// Cho một số nguyên dương
// n
// , có bao nhiêu cách chọn
// k
//  số nguyên không âm bé hơn hoặc bằng
// n
//  có tổng bằng
// n
// ?
// (
// 1
// ≤
// n
// ,
// k
// ≤
// 300
// )
// . Ví dụ
// n
// =
// 20
//  và
// k
// =
// 2
// , chúng ta có 21 cách:
// 0
// +
// 20
// ,
// 1
// +
// 19
// ,
// 2
// +
// 18
// ,
// 3
// +
// 17
// ,
// .
// .
// .
// ,
// 20
// +
// 0.

// INPUT

// Một dòng chứa 2 số nguyên dương
// n
// ,
// k
// .

// OUTPUT

// In ra kết quả module
// 10
// 9
// +
// 7

// Ví dụ
#include <bits/stdc++.h>
using namespace std;

#define el cout << "\n"
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define maxn
#define MOD 1000000007
int n, k, f[302][302];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    f[0][0] = 1;
    f1(j, k) for (int i = 0; i <= n; i++)
    {
        for (int x = 0; x <= i; x++)
            f[j][i] = (f[j][i] + f[j - 1][i - x]) % MOD;
    }
    cout << f[k][n];
    return 0;
}
