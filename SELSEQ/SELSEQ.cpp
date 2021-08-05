// Cho dãy các số nguyên a1, a2, …, an. Hãy chọn các số hạng của dãy sao cho:
// - Không được chọn hai số hạng kề nhau.
// - Tổng các số hạng được chọn là lớn nhất.
// Dữ liệu cho trong file SELSEQ.INP như sau:
//  Dòng đầu ghi số nguyên dương n (n ≤ 106) là số số hạng của dãy.
//  Dòng tiếp theo ghi n số nguyên a1, a2, … , an (|ai| ≤ 106).
// Kết quả ghi ra file SELSEQ.OUT gồm một số nguyên s là tổng của các số hạng được chọn.
#include <bits/stdc++.h>
#define ll long long
#define nmax 1000005
#define fo(i, a, b) for (int i = a; i <= b; i++)
ll n, a[nmax], b[nmax];
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
    {
        cin >> a[i];
        b[i] = max(b[i - 1], b[i - 2] + a[i]);
    }
    cout << b[n];
}
