#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
using namespace std;
const ll mod = 1e9 + 7;
vector<ll> a;
ll m, n;
int main()
{

    // freopen("l.inp","r",stdin);
    // freopen("l.out","w",stdout);
    cin >> n;
    fo(i, 1, n)
    {
        cin >> m;
        a.push_back(m);
    }
    sort(a.begin(), a.end());
    fo(i, 0, n - 1)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    //fo(i,0,n-1)
    for (int i = n - 1; i >= 0; i--)
    {
        cout << a[i] << ' ';
    }
}
