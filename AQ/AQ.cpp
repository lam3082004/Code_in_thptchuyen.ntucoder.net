// Alita đang học sử dụng hệ thống quản lý cơ sở dữ liệu, thế nhưng vì những hệ thống này quá
// phức tạp nên cô quyết định không học về hệ thống nào nữa. Thay vào đó Alita sẽ tự lập trình lên
// một hệ thống của riêng mình và hiển nhiên, việc này còn gây khó khăn cho cô hơn nữa.
// Hiện tại, Alita đang gặp vấn đề đầu tiên. Alita đã bó tay khi định xử lý một nguồn dữ liệu chỉ
// lưu trữ N số nguyên không âm a1, a2, ..., aN và thực hiện M truy vấn thuộc hai loại sau đây:
// • F c h: tăng 1 đơn vị cho c phần tử nhỏ nhất không nhỏ hơn h
// • C l r: đếm số phần tử có giá trị không nhỏ hơn l và không lớn hơn r
// Các bạn hãy giúp cô nàng ngây thơ này vượt qua trở ngại.
// Dữ liệu
// Gồm nhiều tests, mỗi test cho trên nhóm dòng theo định dạng:
// • Dòng 1: hai số nguyên N và M (1 ≤ N, M ≤ 105
// )
// • Dòng 2: N số nguyên không âm a1, a2, ..., aN (ai ≤ 109
// )
// • Dòng 3...M + 2: mỗi dòng ghi thông tin về một truy vấn theo mẫu ở trên, các truy vấn được
// thực hiện theo trình tự thời gian với ràng buộc: 1 ≤ c; 0 ≤ h ≤ 109
// ; 1 ≤ l ≤ r ≤ 109
// Tệp đầu vào kết thúc với dòng ghi hai số 0.
// Kết quả
// Kết quả mỗi test ghi ra kết quả trả lời của các truy vấn C
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
ll n, m, a[nmax], h[nmax], t[nmax], u, v;
char x;
void update(int m, int val)
{
    while (m < nmax)
    {
        t[m] += val;
        m += m & -m;
    }
}
ll get(int m)
{
    ll tmp = 0;
    while (m > 0)
    {
        tmp += t[m];
        m -= m & -m;
    }
    return tmp;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("aq.inp", "r", stdin);
    freopen("aq.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        fo(i, 1, n)
                cin >>
            a[i];
        sort(a + 1, a + 1 + n);
        memset(t, 0, sizeof(t));
        fo(i, 1, m)
        {
            cin >> x >> u >> v;
            if (x == 'F')
            {
                int l = 1, r = n, pos1 = 0, pos2, pos3, pos4;
                while (l <= r)
                {
                    int mid = l + r >> 1;
                    if (a[mid] + get(mid) >= v)
                    {
                        pos1 = mid;
                        r = mid - 1;
                    }
                    else
                        l = mid + 1;
                }
                if (pos1 == 0)
                    continue;
                pos2 = min(n, pos1 + u - 1);
                l = 1, r = n;
                while (l <= r)
                {
                    int mid = l + r >> 1;
                    if (a[mid] + get(mid) >= a[pos2] + get(pos2))
                    {
                        pos3 = mid;
                        r = mid - 1;
                    }
                    else
                        l = mid + 1;
                }
                l = 1, r = n;
                while (l <= r)
                {
                    int mid = l + r >> 1;
                    if (a[mid] + get(mid) <= a[pos2] + get(pos2))
                    {
                        pos4 = mid;
                        l = mid + 1;
                    }
                    else
                        r = mid - 1;
                }
                update(pos1, 1);
                update(pos3, -1);
                update(pos4 - (pos2 - pos3), 1);
                update(pos4 + 1, -1);
            }
            else
            {
                int l = 1, r = n, pos1, pos2 = 0;
                while (l <= r)
                {
                    int mid = l + r >> 1;
                    if (a[mid] + get(mid) <= v)
                    {
                        pos2 = mid;
                        l = mid + 1;
                    }
                    else
                        r = mid - 1;
                }
                l = 1, r = n;
                while (l <= r)
                {
                    int mid = l + r >> 1;
                    if (a[mid] + get(mid) >= u)
                    {
                        pos1 = mid;
                        r = mid - 1;
                    }
                    else
                        l = mid + 1;
                }
                if (u <= a[pos1] + get(pos1) && a[pos2] + get(pos2) <= v)
                    cout << pos2 - pos1 + 1 << '\n';
                else
                    cout << 0 << '\n';
            }
        }
    }
}
