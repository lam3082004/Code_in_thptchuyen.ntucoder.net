// Một số nguyên dương K được gọi là số phản nguyên tố nếu d(x) < d(K) với mọi số nguyên dương
// x thuộc đoạn [1, K − 1] (kí hiệu d(a) là số lượng ước nguyên dương của một số nguyên dương a).
// Yêu cầu: Cho trước một số nguyên dương N, hãy tìm số phản nguyên tố lớn nhất mà không lớn
// hơn N.
// Dữ liệu
// • Gồm một dòng duy nhất chứa số nguyên dương N (N ≤ 1018).
// Kết quả
// • In ra số phản nguyên tố lớn nhất không vượt quá N
//KNSB
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void Init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const ll P[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int res = 0;
ll n;
ll F[1000001];

void bk(int p, int k, ll s, int T)
{
    if (s > n)
        return;
    F[T] = min(F[T], s);
    res = max(res, T);
    ll t = s;
    for (int d = 0; t <= n / P[p] && d < k;)
    {
        ++d;
        t *= P[p];
        bk(p + 1, d, t, T * (d + 1));
    }
}

void Solve()
{
    for (int i = 1; i <= 1000000; ++i)
        F[i] = 1e18;
    cin >> n;
    bk(0, 100, 1, 1);
    cout << F[res];
}

int main()
{
    Init();
    Solve();
}
