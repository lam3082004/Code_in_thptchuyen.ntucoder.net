// Cho một bảng hình chữ nhật kích thước M ∗N, các dòng được đánh số từ 1 đến M từ trên xuống
// dưới, các cột được đánh số từ 1 đến N từ trái qua phải. Ô nằm trên dòng i và cột j của bảng
// được gọi là ô (i, j). Mỗi ô trong bảng được tô màu trắng hoặc màu đen. Có thể thực hiện phép
// biến đổi sau với số lần tùy ý:
// • Lựa chọn một dòng (hoặc một cột), đổi màu của tất cả các ô trong dòng (hoặc cột) đó - từ
// màu trắng đổi thành màu đen và ngược lại.
// Cho Q truy vấn, mỗi truy vấn có dạng x1 y1 x2 y2, yêu cầu xác định xem có thể biến đổi hình
// chữ nhật ban đầu, sao cho hình chữ nhật con có góc trái trên tại ô (x1, y1) và góc phải dưới tại ô
// (x2, y2) chỉ bao gồm các ô màu đen hay không.
// Dữ liệu
// • Dòng đầu tiên chứa hai số nguyên M, N, Q - số dòng, cột và số lượng truy vấn
// (1 ≤ M, N ≤ 1000, 1 ≤ Q ≤ 100000).
// • M dòng tiếp theo, mỗi dòng chứa N kí tự, mô tả dòng thứ i của bảng (kí tự "*" ứng với ô
// màu đen, kí tự "." ứng với ô màu trắng)
// • Q dòng tiếp theo, mỗi dòng gồm bốn số nguyên x1, y1, x2, y2 (1 ≤ x1 ≤ x2 ≤ M,
// 1 ≤ y1 ≤ y2 ≤ N) mô tả một truy vấn.
// Kết quả
// • Với mỗi truy vấn, in ra "YES" nếu tồn tại cách biến đổi, ngược lại in ra "NO".
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
const int nmax = 5e5 + 5;
int n, a[nmax], d[nmax], dem, k;
long long ans = 0;
ii s[nmax];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].fi;
        s[i].se = i;
    }
    sort(s + 1, s + n + 1);
    int tmp = 1;
    for (int i = 1; i <= n; i++)
    {
        a[s[i].se] = tmp;
        if (s[i].fi != s[i + 1].fi)
            tmp++;
    }
    int l = 1, r = 0;
    while (r <= n)
    {
        while (dem == 0 && r <= n)
        {
            r++;
            d[a[r]]++;
            if (d[a[r]] >= k)
                dem++;
        }
        if (dem > 0)
            ans += n - r + 1;
        if (d[a[l]] == k)
            dem--;
        d[a[l]]--;
        l++;
    }
    cout << ans << '\n';
}
