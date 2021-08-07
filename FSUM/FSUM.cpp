// Với một dãy số p bất kì gồm k phần tử, ta định nghĩa hàm f(p) như sau:
// • Nếu k = 1 thì f(p) = 0
// • Ngược lại, f(p) là giá trị l
// |pi−pj |
// j−i
// m
// lớn nhất với mọi 1 ≤ i < j ≤ k.

// Cho một dãy số a gồm n phần tử. Hãy tính:

// S =
// Xn
// l=1
// Xn
// r=l
// f(a[l..r])

// Với a[l..r] là dãy con gồm các phần tử từ vị trí l đến vị trí r của a.
// Dữ liệu
// • Dòng đầu tiên gồm số nguyên n (1 ≤ n ≤ 200000) - số phần tử của dãy a.
// • Dòng thứ hai gồm n số nguyên a1, a2, . . . , an (1 ≤ ai ≤ 108

// ) - các phần tử của dãy a.

// Kết quả
// • In ra giá trị S cần tìm.
#include <bits/stdc++.h>
using namespace std;
const int nmax = 5e5 + 5;
long long n, f[nmax], a[nmax], R[nmax], L[nmax], ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("FSUM.inp","r",stdin);
    //freopen("FSUM.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        f[i] = abs(a[i] - a[i + 1]);
    for (int i = 1; i < n; i++)
    {
        L[i] = i - 1;
        while (L[i] > 0 && f[i] > f[L[i]])
            L[i] = L[L[i]];
    }
    for (int i = n - 1; i > 0; i--)
    {
        R[i] = i + 1;
        while (R[i] < n && f[i] >= f[R[i]])
            R[i] = R[R[i]];
    }
    for (int i = 1; i < n; i++)
        ans += f[i] * (i - L[i]) * (R[i] - i);
    cout << ans << '\n';
}
