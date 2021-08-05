// Cho tọa độ 3 điểm A,B,C

// Hãy tìm bán kính đường tròn nhỏ nhất phủ 3 điểm.

// Dữ Liệu:

// Dòng đầu tiên chứa số nguyên dương T - số lượng bộ dữ liệu.

//           T dòng tiếp theo, mỗi dòng ghi 6 số nguyên xa, ya, xb, yb, xc, yc là tọa độ của A, B, C.

// Kết Quả

//           Gồm T dòng, mỗi dòng in ra một số là kết quả của bài toán. Nếu không tìm được bán kính thỏa mãn thì in ra “cnf”

// Lưu ý:

// -1000  ≤  xa, ya, xb, yb, xc, yc  ≤ 1000 , 0  ≤  T  ≤  10000
// Kết quả của bài toán được làm tròn đến 2 chữ số sau dấu phẩy.
#include <bits/stdc++.h>
#define ll long double
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
using namespace std;
struct point
{
    ll x, y;
};
ll bp(ll a)
{
    return a * a;
}
ll canh(point a, point b)
{
    return sqrt(bp(a.x - b.x) + bp(a.y - b.y));
}
ll dt(point a, point b, point c)
{
    return abs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2;
}
ll bk(point a, point b, point c)
{
    if (bp(canh(a, b)) + bp(canh(b, c)) <= bp(canh(a, c)))
        return canh(a, c) / 2;
    if (bp(canh(a, b)) + bp(canh(a, c)) <= bp(canh(b, c)))
        return canh(b, c) / 2;
    if (bp(canh(a, c)) + bp(canh(b, c)) <= bp(canh(a, b)))
        return canh(a, b) / 2;
    return canh(a, b) * canh(b, c) * canh(a, c) / (4 * dt(a, b, c));
}
point a, b, c;
ll n;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        if (bk(a, b, c) == 0)
            cout << "cnf" << '\n';
        else
            cout << fixed << setprecision(2) << bk(a, b, c) << '\n';
    }
}
