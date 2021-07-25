// Cho bảng 3 × n và dãy K gồm n phần tử
// Yêu cầu: Đếm số cách đặt nhiều nhất các quân mã lên bảng sao cho không có hai quân mã nào ăn
// được nhau và không được đặt ở ô (Ki
// , i)
// Nếu Ki = 0 thì cột i không bị cấm ô nào
// Input:
//  Dòng đầu tiên là số n (1 ≤ n ≤ 100)
//  Dòng tiếp theo gồm n số Ki

// (0 ≤ Ki ≤ 3)

// Output:
//  Một dòng là số quân mã tối đa có thể đặt và số cách đặt
#include <bits/stdc++.h>
using namespace std;
const int nmax = 205;
const int oo = 1e9 + 7;
int f[nmax][520], n, k[nmax], x[6][6], s[nmax][520];
bool vs[nmax][nmax];
bool check(int p, int k)
{
    int m = k;
    for (int i = 3; i >= 1; i--)
    {
        x[i][1] = k % 2;
        k /= 2;
    }
    for (int i = 3; i >= 1; i--)
    {
        x[i][2] = k % 2;
        k /= 2;
    }
    for (int i = 3; i >= 1; i--)
    {
        x[i][3] = k % 2;
        k /= 2;
    }
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (x[i][j])
                if (vs[i][p - 3 + j] || x[i + 1][j + 2] || x[i + 2][j + 1] || x[i - 1][j + 2] || x[i + 2][j - 1])
                    return false;
    return true;
}
int dem(int k)
{
    int ans = 0;
    for (int i = 1; i <= 6; i++)
        k /= 2;
    for (int i = 1; i <= 3; i++)
    {
        ans += k % 2;
        k /= 2;
    }
    return ans;
}
int dem2(int k)
{
    int ans = 0;
    for (int i = 1; i <= 9; i++)
    {
        ans += k % 2;
        k /= 2;
    }
    return ans;
}
void up(int i, int k)
{
    for (int t = 0; t <= 7; t++)
    {
        int res = t, p = k % (1 << 6);
        for (int z = 1; z <= 3; z++)
        {
            p = p * 2 + (res % 2);
            res /= 2;
        }
        if (check(i, k) && check(i - 1, p))
        {
            if (f[i][k] == f[i - 1][p] + dem(k))
                s[i][k] += s[i - 1][p];
            if (f[i][k] < f[i - 1][p] + dem(k))
            {
                f[i][k] = f[i - 1][p] + dem(k);
                s[i][k] = s[i - 1][p];
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        vs[k[i]][i] = 1;
    }
    if (n == 1)
    {
        if (k[1] >= 1 && k[1] <= 3)
            cout << 2 << ' ' << 1;
        else
            cout << 3 << ' ' << 1;
        return 0;
    }
    if (n <= 2)
    {
        int ans = 0, ans2 = 0;
        for (int i = 0; i <= 63; i++)
            if (check(2, i))
            {
                if (ans == dem2(i))
                    ans2++;
                if (ans < dem2(i))
                {
                    ans = dem2(i);
                    ans2 = 1;
                }
            }
        cout << ans << ' ' << ans2 << '\n';
        return 0;
    }
    for (int i = 0; i <= 511; i++)
        if (check(3, i))
        {
            f[3][i] = dem2(i);
            s[3][i] = 1;
        }
    for (int i = 4; i <= n; i++)
        for (int k = 0; k <= 511; k++)
            up(i, k);
    int ans = 0, ans2 = 0;
    for (int k = 0; k <= 511; k++)
    {
        if (ans == f[n][k])
        {
            ans2 += s[n][k];
        }
        if (ans < f[n][k])
        {
            ans = f[n][k];
            ans2 = s[n][k];
        }
    }
    cout << ans << ' ' << ans2;
}
