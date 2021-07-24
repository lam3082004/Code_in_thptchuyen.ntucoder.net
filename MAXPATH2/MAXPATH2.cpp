// ĐƯỜNG ĐI CÓ TỔNG LỚN NHẤT
//     Trên một lưới ô vuông kích thước
// × có
//         ô chứa số nguyên dương,
//     các ô còn lại không chứa số(có

//                                     thể coi là chứa số 0)
//         .Ta cần tìm một hành trình từ ô(1, 1) đến ô(
//             , ) thỏa mãn :

//  Từ ô(, ) chỉ có thể đi đến ô(+1, ) hoặc ô(,
//                                              +1)

//  Tổng giá trị các ô đi qua là lớn nhất
//     Input :
//  Dòng đầu gồm ba số
//     ,
//     ,

//  dòng tiếp theo là bộ ba số
//     ,
//     ,
//     có nghĩa là ô(
//         , ) chứa số(0 < < 10)

//         (Ô(1, 1) và ô(
//             , ) không chứa số)

//             Output :
//  Một số duy nhất là kết quả bài toán
#include <bits/stdc++.h>
using namespace std;
void LSH()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("THPT.INP", "r", stdin);
    freopen("THPT.OUT", "w", stdout);
#endif // ONLINE_JUDGE LSHH
}
struct st
{
    int x, y, val;
};
long long cmp(st a, st b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
long long n, ans = -1e18, t[1000005], k, b[1000005];
st a[1000005];
int getBIT(int m)
{
    long long res = 0;
    for (; m > 0; m -= m & -m)
        res = max(res, t[m]);
    return res;
}
void updateBIT(int m, long long value)
{
    for (; m <= 1000005; m += m & -m)
        t[m] = max(t[m], value);
}
long long m;
void solve()
{
    cin >> m >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> a[i].x >> a[i].y >> a[i].val;
    }
    sort(a + 1, a + k + 1, cmp);
    for (int i = 1; i <= k; ++i)
    {
        b[i] = getBIT(a[i].y) + a[i].val;
        updateBIT(a[i].y, b[i]);
        ans = max(ans, b[i]);
    }
    cout << ans;
}
int main()
{
    LSH();
    solve();
}
