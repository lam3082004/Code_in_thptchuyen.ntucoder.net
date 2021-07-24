// Cho dãy số nguyên và dãy số nguyên, xét các giá trị sau :
//  S là số bộ chỉ số với mà ∑

//  ∑

//                                         .
//  E là số bộ chỉ số với mà ∑

//  ∑

//                                         .
//  G là số bộ chỉ số với mà ∑

//  ∑

//                                         .Yêu cầu : Tính các giá trị S,
//     E và G.Input - Dòng đầu gồm 2 số - Dòng thứ hai gồm số nguyên;
// - Dòng thứ ba gồm số nguyên.Các số có giá trị tuyệt đối không vượt quá 109
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e9
using namespace std;
const int mod = 1e9 + 7;
ll m, n, S = 0, E = 0, G = 0;
ll a[1005], b[1005], fa[1005], fb[1005];
vector<ll> L, R;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    fo(i, 1, m)
    {
        cin >> a[i];
        fa[i] = fa[i - 1] + a[i];
    }
    fo(i, 1, n)
    {
        cin >> b[i];
        fb[i] = fb[i - 1] + b[i];
    }
    fo(i, 1, m)
        fo(j, i, m)
            L.push_back(fa[j] - fa[i - 1]);
    fo(i, 1, n)
        fo(j, i, n)
            R.push_back(fb[j] - fb[i - 1]);
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    int les = R.size() - 1;
    int i = -1;
    for (auto tmp : L)
    {
        while (R[i + 1] < tmp && i < les)
            i++;
        int j = i;
        while (R[j + 1] <= tmp && j < les)
            j++;
        j++;
        G += i + 1;
        E += j - i - 1;
        S += les - j + 1;
    }
    cout << S << ' ' << E << ' ' << G;
}
