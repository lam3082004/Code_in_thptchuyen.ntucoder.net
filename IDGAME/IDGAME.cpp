// Trò chơi IDGAME là trò chơi trên một dãy số nguyên 𝑎1, 𝑎2, … , 𝑎𝑛. Mỗi lượt người chơi được
// thực hiện thao tác chọn hai phần tử 𝑖,𝑗 (1 ≤ 𝑖 ≠ 𝑗 ≤ 𝑛) rồi tăng 𝑎𝑖
// lên 1 và giảm 𝑎𝑗 đi 1. Với một
// số nguyên 𝐷 cho trước, người chơi cần tìm cách biến đổi dãy số ban đầu thành một dãy số mới mà
// chênh lệch giữa hai phần tử bất kì trong dãy mới không vượt quá 𝐷 với số thao tác là ít nhất.
// Yêu cầu: Cho dãy số nguyên 𝑎1, 𝑎2, … , 𝑎𝑛 và 𝑇 số nguyên dương 𝐷1,𝐷2, … ,𝐷𝑇. Với mỗi 𝑇𝑠 (1 ≤
// 𝑠 ≤ 𝑇) hãy tính số thao tác ít nhất để biến đổi dãy số ban đầu thành một dãy số mới mà chênh lệch
// giữa hai phần tử bất kì trong dãy mới không vượt quá 𝐷𝑠
// .
// Input
// - Dòng đầu chứa hai số nguyên dương 𝑛, 𝑇;
// - Dòng thứ hai gồm 𝑛 số nguyên 𝑎1, 𝑎2, … , 𝑎𝑛.
// - Dòng thứ ba gồm 𝑇 số nguyên dương 𝐷1,𝐷2, … , 𝐷𝑇.
// Output
// - Gồm 𝑇 dòng, dòng thứ 𝑠 (1 ≤ 𝑠 ≤ 𝑇) chứa một số nguyên là thao tác ít nhất cần thực hiện
// tương ứng với trường hợp 𝑇𝑠
// .
#include <bits/stdc++.h>
using namespace std;
const int nmax = 5e6 + 1;
const long long oo = 1e13 + 7;
int t, n, a[nmax], dem[nmax];
long long f[nmax], p[nmax];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += 1000000;
        dem[a[i]]++;
    }
    for (int i = 0; i <= 2000000; i++)
        f[i] = oo;
    sort(a + 1, a + n + 1);
    int l = a[1], r = a[n];
    long long k = 0;
    while (l <= r)
    {
        f[r - l] = k;
        int minn = min(dem[l], dem[r]);
        k += minn;
        dem[l] -= minn;
        dem[r] -= minn;
        dem[l + 1] += minn;
        dem[r - 1] += minn;
        if (l >= r - 1)
            break;
        if (dem[l] == 0)
            l++;
        if (dem[r] == 0)
            r--;
    }
    p[0] = f[0];
    for (int i = 1; i <= 2000000; i++)
        p[i] = min(p[i - 1], f[i]);
    while (t--)
    {
        int d;
        cin >> d;
        cout << p[d] << '\n';
    }
}
