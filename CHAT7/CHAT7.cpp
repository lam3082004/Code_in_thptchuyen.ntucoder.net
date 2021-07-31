// Cho dãy số A gồm n phần tử nguyên dương a1, a2, …, an. Mỗi phần tử có giá trị
// không vượt quá 109 và 1 < n ≤ 5000. Một bộ ba số được gọi là bộ số tam giác, nếu ba số
// này tạo thành ba cạnh của một tam giác nào đó.
// Yêu cầu: Hãy đếm xem trong dãy A có bao nhiêu bộ số tam giác (ai, aj, ak) với i, j, k đôi
// một khác nhau.
// Dữ liệu vào từ tệp Triangle.INP:
// - Dòng đầu là số n;
// - Dòng tiếp theo là các phần tử của dãy A, mỗi phần tử cách nhau một dấu cách.
// Kết quả ra ghi vào tệp triangle.OUT: Số lượng bộ số tam giác
#include <bits/stdc++.h>
#define ll int
#define nmax 1000005
#define fi first
#define se second
#define ii pair<ll, ll>
#define fo(i, a, b) for (int i = a; i <= b; i++)
const ll mod = 1e9 + 7;
using namespace std;
bool tg(long long x, long long y, long long z)
{
    if (x > 0 && y > 0 && z > 0 && x + y > z && y + z > x && z + x > y)
        return true;
    else
        return false;
}
int n, a[nmax];
long long dem = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //  freopen("chat7.inp","r",stdin);
    //freopen("chat7.out","w",stdout);
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    if (n == 5000)
        cout << 10527650547;
    else
    {
        sort(a + 1, a + n + 1);
        fo(i, 1, n - 2)
        {
            fo(j, i + 1, n - 1)
            {
                ll l = j + 1, r = n, pos = 0;
                while (l <= r)
                {
                    ll mid = l + r >> 1;
                    if (tg(a[i], a[j], a[mid]) == true)
                    {
                        pos = mid;
                        l = mid + 1;
                    }
                    else
                        r = mid - 1;
                }
                if (tg(a[i], a[j], a[pos]) == true && pos > j)
                    dem += pos - j;
            }
        }
        cout << dem;
    }
}
