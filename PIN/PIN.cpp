// Trong một công ty, mỗi nhân viên được cho một mã PIN gồm 4 kí tự là các chữ số hoặc chữ cái
// tiếng anh in thường làm mã đăng nhập. Một ngày đẹp trời, quản trị viên Martin quyết định khảo sát độ
// “mất an toàn” của hệ thống mã PIN nói trên.
// Cụ thể, với một số nguyên dương

// , Martin muốn tính xem trong công ty có bao nhiêu cặp

// nhân viên mà mã PIN khác nhau ở đúng

// vị trí (hay trùng nhau 4 −
// vị trí).

// Hãy viết chương trình giúp Martin thực hiện công việc này.
// Input
// Dòng đầu tiên chứa 2 số nguyên dương
// và
// , trong đó
// là số nhân viên của công ty.

// (2 ≤
// ≤ 50000, 1 ≤
// ≤ 4)

// dòng tiếp theo, mỗi dòng chứa 1 xâu 4 kí tự là mã PIN của 1 nhân viên trong công ty.
// Output
// In ra số nguyên duy nhất là số cặp nhân viên có mã PIN khác nhau ở đúng
// vị trí.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 50005
using namespace std;
ll n, m, d, f[5], p[4], res, dem;
string s[nmax], q[nmax];
int main()
{
    cin >> n >> m;
    m = 4 - m;
    fo(i, 1, n)
            cin >>
        s[i];
    fo(i, 0, 15)
    {
        res = 1, dem = 0;
        fo(j, 0, 3)
        {
            p[j] = ((i >> j) & 1);
            if (p[j] == 1)
                dem++;
        }
        fo(j, 1, n)
        {
            q[j] = "";
            fo(t, 0, 3) if (p[t] == 1)
                q[j] += s[j][t];
            else q[j] += '*';
        }
        q[n + 1] = "*";
        sort(q + 1, q + 1 + n);
        fo(j, 1, n) if (q[j] == q[j + 1])
            res++;
        else
        {
            f[dem] += res * (res - 1) / 2;
            res = 1;
        }
    }
    f[3] -= 4 * f[4];
    f[2] -= (3 * f[3] + 6 * f[4]);
    f[1] -= (2 * f[2] + 3 * f[3] + 4 * f[4]);
    f[0] -= (f[1] + f[2] + f[3] + f[4]);
    cout << f[m];
}
