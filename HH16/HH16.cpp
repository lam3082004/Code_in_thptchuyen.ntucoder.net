// Trong thành phố X có n khu chung cư, khu chung cư thứ i có tọa độ xi, yi. Lãnh
// đạo thành phố X rất quan tâm đến n khu chung cư này và có ý định xây một đường
// cao tốc song song với trục hoành. Khi đó chắc chắn từ n khu chung cư sẽ phải làm
// thêm đường từ chung cư của mình đến đường cao tốc song song với trục tung. Mỗi
// khu chung cư làm một đường (không chung nhau). Hỏi tổng độ dài các đường cần
// làm nhỏ nhất là bao nhiêu (Hai đường có thể trùng nhau trên mặt phẳng tọa độ - khi
// đó một cái nằm trên và cái kia nằm dưới)
// Dữ liệu:
//  Dòng 1 ghi n (n ≤100)
//  n dòng tiêp theo, dòng thứ i ghi hai số nguyên xi, yi thể hiện tọa độ của một
// điểm
// Kết quả:
//  Ghi một số nguyên duy nhất là đáp số tìm được.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 10000007
#define ii pair<ll, ll>
#define fi first
#define se second
const ll mod = 1e9 + 7;
using namespace std;
ll kc(ii a, ii b)
{
    return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}
ii a[nmax];
ll n, s = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
    {
        cin >> a[i].se >> a[i].fi;
    }
    sort(a + 1, a + n + 1);
    ll s = 0;
    //cout<<a[n/2+1].fi<<' '<<a[n/2+1].se<<'\n' ;
    fo(i, 1, n)
    {
        s += abs(a[n / 2 + 1].fi - a[i].fi);
    }
    cout << s;
}
