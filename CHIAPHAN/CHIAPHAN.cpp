// Bác Jonh có một miếng đất hình đa giác lồi n đỉnh
// A
// 1
// A
// 2
// .
// .
// .
// A
// n
// . Bác ấy có hai người con nên bác muốn chia miếng đất thành hai phần. Bác chọn hai đỉnh
// A
// i
// ,
// A
// j
// và nối đoạn
// A
// i
// A
// j
// để chia miếng đất thành hai phần, phần diện tích nhỏ hơn cho người anh, phần lớn hơn cho người em.

// Dữ liệu:

// -  Dòng đầu tiên ghi 3 số nguyên không âm
// n
// ,
// i
// ,
// j
// (
// 1
// ≤
// i
// ≠
// j
// ≤
// n
// ≤
// 10000
// )
// .

// - n dòng tiếp,dòng thứ i ghi tọa độ đỉnh
// A
// i
//  gồm hai số nguyên
// x
// i
// v
// à

// y
// i
// (
// |
// x
// i
// |
// ,
// |
// y
// i
// |
// ≤
// 10
// 9
// )

// Kết quả:

// - Dòng thứ nhất ghi diện tích của người anh nhận được

// - Dòng thứ hai ghi diện tích của người em nhận được
#include <bits/stdc++.h>
#define ii pair<long long, long long>
#define fi first
#define se second
using namespace std;
long long n, i, j, d1, d2, f1, f2, s, k = 0, t = 0, k1 = 0, t1 = 0, s1, s2;
ii a[20000];
int main()
{
    //*/
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //*/
    /*/
    freopen("chiaphan.INP","r",stdin);
    freopen("chiaphan.OUT","w",stdout);
    //*/
    cin >> n >> d1 >> d2 >> a[1].fi >> a[1].se;
    for (i = 2; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        k += a[i - 1].fi * a[i].se;
        t += a[i - 1].se * a[i].fi;
    }
    k += a[n].fi * a[1].se;
    t += a[n].se * a[1].fi;
    s = abs((k - t));
    if (d1 < d2)
    {
        f1 = d1;
        f2 = d2;
    }
    else
    {
        f1 = d2;
        f2 = d1;
    }
    for (i = f1 + 1; i <= f2; i++)
    {
        k1 += a[i - 1].fi * a[i].se;
        t1 += a[i - 1].se * a[i].fi;
    }
    k1 += a[f2].fi * a[f1].se;
    t1 += a[f2].se * a[f1].fi;
    s1 = abs((k1 - t1));
    s2 = s - s1;
    if (s1 < s2)
        swap(s1, s2); // s1 luôn lớn hơn
    if (s1 % 2 == 0)
        cout << s2 / 2 << '\n'
             << s1 / 2;
    else
        cout << s2 / 2 << ".5" << '\n'
             << s1 / 2 << ".5";
}
