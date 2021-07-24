// // Bạn được cho một dãy số gồm N phần tử nguyên dương
// [1],
// [2], ...
// [
// ]. Bạn được phép
// thay đổi bất kì phần tử nào thành một giá trị nguyên dương khác mà bạn muốn. Nhiệm vụ của
// bạn là phải tìm số lần thay đổi ít nhất các phần tử sao cho dãy số thu được là dãy số tăng dần
// (
// [1] <
// [2] <. . <
// [
// ]).

// Dữ liệu đầu vào:
//  Dòng đầu số nguyên dương N – số lượng phần tử của dãy số.
//  Dòng sau gồm N số nguyên dương, số thứ
// là giá trị
// [
// ].

// Dữ liệu đầu ra:
//  Số nguyên dương duy nhất là kết quả của bài toán.
// Giới hạn:
// 
// ≤ 10
//  0 <
// [
// ] ≤ 10
// .

//  50%
// ó
// ≤ 1000.
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e6 + 5;
const int mod = 1e9 + 7;
int a[nmax], n, dq[nmax], sz;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] -= i;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] >= 0)
        {
            if (a[i] >= dq[sz])
                dq[++sz] = a[i];
            else
            {
                int l = 0, r = sz, res = -1;
                while (l <= r)
                {
                    int mid = l + r >> 1;
                    if (a[i] >= dq[mid])
                    {
                        res = mid;
                        l = mid + 1;
                    }
                    else
                        r = mid - 1;
                }
                if (res >= 0)
                    dq[res + 1] = a[i];
            }
        }
    cout << n - sz;
}
