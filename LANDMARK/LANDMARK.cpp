// Bãi đậu xe của Landmark 81 gồm N vị trí được sắp xếp theo một đường thẳng được đánh số từ
// 1 đến N. Mỗi ngày, có M xe ra vào vào tham quan Landmark. Chính vì vậy, bảo vệ ở đây đã tìm
// ra cách để sắp xếp xe sao cho thuận tiện nhất.
// Ban đầu, bãi đậu xe chưa có xe nào đậu. Khi có 1 xe đến, bảo vệ sẽ tìm vị trí đậu cho xe đó. Vị
// trí bảo vệ chọn là vị trí mà cách xa những vị trí đã có xe đỗ nhất. Nếu tồn tại nhiều vị trí thì sẽ
// chọn vị trí có số nhỏ nhất.
// Khoảng cách giữa hai vị trí i và j được tính theo công thức sau: Dij = 4 × |i − j|.
// Vì một ngày lượng xe ra vào là quá lớn. Các bạn hãy giúp bảo vệ tìm vị trí cho xe mới vào tham
// quan Landmark.
// Biết rằng các xe được đánh số từ 1 đến 106 và dữ liệu đảm bảo rằng không có xe nào đi ra khi
// chưa đi vào hoặc không có xe nào đi vào mà đang ở trong bãi.
// Dữ liệu đảm bảo luôn còn chỗ cho các xe mới vào.
// Dữ liệu
// • Dòng đầu tiên gồm 2 số nguyên N, M (1 ≤ N, M ≤ 105
// ).
// • M dòng tiếp theo gồm 2 số nguyên T, X (1 ≤ T ≤ 2; 1 ≤ X ≤ 106
// ) với T = 1 thì xe có số
// thứ tự là X đi vào bãi gửi xe, T = 2 thì xe có số thứ tự là X đi ra khỏi bãi gửi xe.
// Kết quả
// • Với mỗi truy vấn T = 1, xuất ra vị trí mà xe mới vào sẽ đỗ
#include <bits/stdc++.h>
#define ll long long
#define task "test"
using namespace std;

void Init()
{
}

struct II
{
    int fi, se;
    void operator=(II b)
    {
        fi = b.fi;
        se = b.se;
    }
};

bool operator<(II a, II b)
{
    int da = (a.se - a.fi) / 2;
    int db = (b.se - b.fi) / 2;
    return (da > db || (da == db && a.fi < b.fi));
}

int P[1000001];
int L[1000001];
int D[1000001];
set<II> S;
int n;
void Add(int x)
{
    II t = *S.begin();
    S.erase({t.fi, t.se});
    int k = t.se - t.fi + 1;
    if (k == 1)
    {
        P[x] = t.fi;
        D[t.fi] = 1;
        L[t.fi] = t.fi;
    }
    else if (t.fi == 1)
    {
        P[x] = 1;
        D[1] = 1;
        L[1] = 1;
        S.insert({2, t.se});
        L[2] = t.se;
        L[t.se] = 2;
    }
    else if (t.se == n)
    {
        P[x] = n;
        D[n] = 1;
        L[n] = n;
        S.insert({t.fi, n - 1});
        L[n - 1] = t.fi;
        L[t.fi] = n - 1;
    }
    else if (k == 2)
    {
        P[x] = t.fi;
        D[t.fi] = 1;
        L[t.fi] = t.fi;
        S.insert({t.se, t.se});
        L[t.se] = t.se;
    }
    else if (k % 2 == 0)
    {
        P[x] = t.fi + k / 2 - 1;
        D[t.fi + k / 2 - 1] = 1;
        L[t.fi + k / 2 - 1] = t.fi + k / 2 - 1;
        S.insert({t.fi, t.fi + k / 2 - 2});
        L[t.fi] = t.fi + k / 2 - 2;
        L[t.fi + k / 2 - 2] = t.fi;
        S.insert({t.fi + k / 2, t.se});
        L[t.se] = t.fi + k / 2;
        L[t.fi + k / 2] = t.se;
    }
    else
    {
        P[x] = t.fi + k / 2;
        D[t.fi + k / 2] = 1;
        L[t.fi + k / 2] = t.fi + k / 2;
        S.insert({t.fi, t.fi + k / 2 - 1});
        //if(t.fi==2&&t.se==6)cout<<t.fi<<' '<<t.fi+k/2-1<<endl;
        L[t.fi] = t.fi + k / 2 - 1;
        L[t.fi + k / 2 - 1] = t.fi;
        S.insert({t.fi + k / 2 + 1, t.se});
        //if(t.fi==2&&t.se==6)cout<<t.fi+k/2+1<<' '<<t.se<<endl;
        L[t.se] = t.fi + k / 2 + 1;
        L[t.fi + k / 2 + 1] = t.se;
    }
    cout << P[x] << '\n';
}

void Del(int x)
{
    int a, b, c, d;
    if (D[P[x] - 1] == 0 && P[x] - 1 > 0)
        b = P[x] - 1;
    else
        b = P[x];
    if (D[P[x] + 1] == 0 && P[x] + 1 <= n)
        c = P[x] + 1;
    else
        c = P[x];
    D[P[x]] = 0;
    a = L[b];
    d = L[c];
    //cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
    S.erase({a, b});
    S.erase({c, d});
    S.insert({a, d});
    L[a] = d;
    L[d] = a;
    //II t=*S.begin();
    //cout<<t.fi<<' '<<t.se<<endl;
}

void Solve()
{
    int m;
    cin >> n >> m;
    int t, x;
    S.insert({1, n});
    while (cin >> t >> x)
        if (t == 1)
            Add(x);
        else
            Del(x);
}

int main()
{
    Init();
    Solve();
}
