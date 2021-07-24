// ĐẾM XÂU NHỊ PHÂN
// Cho số n, đếm số xâu nhị phân độ dài n chứa cặp ′00′.
// Input:
// • Một dòng duy nhất ghi số n
// Output:
// • Một dòng duy nhất ghi kết quả. Do kết quả có thể rất lớn nên chỉ cần in
// ra phần dư của nó cho 109 + 7
// Subtask:
// • Subtask 1: (30% số điểm) 1 ≤ n ≤ 20
// • Subtask 2: (30% số điểm) 1 ≤ n ≤ 106
// • Subtask 3: (40% số điểm) 1 ≤ n ≤ 109wssssss
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll mod = 1e9 + 7;
ll n;
struct Mt
{
    ll c[2][2];
    Mt()
    {
        c[0][0] = 0;
        c[0][1] = 1;
        c[1][0] = 1;
        c[1][1] = 1;
    }
};

void in(Mt a)
{
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
            cout << a.c[i][j] << " ";
        cout << endl;
    }
}

Mt operator*(Mt a, Mt b)
{
    Mt kq;
    for (ll i = 0; i <= 1; ++i)
        for (ll j = 0; j <= 1; ++j)
        {
            kq.c[i][j] = 0;
            for (ll k = 0; k <= 1; ++k)
                kq.c[i][j] = (kq.c[i][j] + a.c[i][k] * b.c[k][j]) % mod;
        }
    //    in(a);cout<<endl;
    //    in(b);cout<<endl;
    //    in(kq);cout<<endl<<endl;
    return kq;
}

Mt mu1(Mt a, ll n)
{
    //    cout<<"mu1"<<n<<endl;
    if (n == 1)
    {
        //        in(a);cout<<endl;
        return a;
    }
    Mt tmp = mu1(a, n / 2);
    //    in(tmp);cout<<endl;
    tmp = tmp * tmp;
    if (n % 2 == 1)
        tmp = tmp * a;

    return tmp;
}

ll mu(ll a, ll n)
{
    if (n == 0)
        return 1;

    ll tmp = mu(a, n / 2);
    tmp = tmp * tmp % mod;
    if (n % 2 == 1)
        tmp = tmp * a % mod;

    return tmp;
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    Mt B;
    //    in(B);
    ll k = mu(2, n);
    Mt A = mu1(B, n + 2);
    //    in(A);
    //cout << A.c[0][0] << " " << A.c[0][1] << '\n' << A.c[1][0] << " " << A.c[1][1] << '\n';
    cout << (k - A.c[0][1] % mod + mod) % mod;
}
