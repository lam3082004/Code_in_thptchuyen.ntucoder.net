// Giáo sư X sắp phải đi họp và ông chuẩn bị một bài tập làm văn cho sinh viên làm trong thời gian ông đi
// vắng. Giáo sư X có 𝑚 tờ giấy thi để phát cho 𝑛 sinh viên. Tùy theo trình độ viết dài, viết hỏng của từng
// người, ông xác định chính xác được rằng sinh viên thứ 𝑖 phải được phát không ít hơn 𝑎𝑖
// tờ giấy thi.
// Yêu cầu: Đếm số cách phát 𝑚 tờ giấy thi cho 𝑛 sinh viên theo yêu cầu trên. Hai cách phát giấy thi được
// gọi là khác nhau nếu tồn tại một sinh viên nhận được số tờ giấy thi khác nhau trong hai cách đó.
// Dữ liệu: Vào từ file văn bản PAPERS.INP
//  Dòng 1 chứa hai số nguyên dương 𝑚 ≤ 109
// ; 𝑛 ≤ 105
//  Dòng 2 chứa 𝑛 số nguyên dương 𝑎1, 𝑎2, … , 𝑎𝑛 (∀𝑖: 𝑎𝑖 ≤ 109
// )
// Các số trên một dòng của input file được ghi cách nhau bởi dấu cách
// Kết quả: Ghi ra file văn bản PAPER
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
const ll mod = 1e9 + 7;
using namespace std;
ll b, c, d, t, l, r, q;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
ll m, n, a[nmax], k = 1;
ll mu(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tam = mu(a, b / 2);
    tam = (tam * tam) % mod;
    if (b & 1)
        tam = (tam * a) % mod;
    return tam;
}
int main()
{
    //  /  freopen("l.inp","r",stdin);
    //   freopen("l.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    fo(i, 1, n)
    {
        cin >> a[i];
        m -= a[i];
    }
    if (m < 0)
    {
        cout << 0;
        return 0;
    }
    fo(i, m + 1, n + m - 1)
    {
        k = (k * i) % mod;
    }
    fo(i, 1, n - 1)
    {
        k = (k * mu(i, mod - 2)) % mod;
    }
    cout << k;
}
