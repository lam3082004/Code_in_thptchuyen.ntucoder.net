// Cho một dãy số
//     chúng ta cần tô màu các con số trên dãy,
//     mỗi số đúng một màu thỏa mãn các số cùng màu ghép lại theo thứ tự sẽ được một dãy không tăng dần.Hỏi số màu ít nhất cần dùng.Dòng đầu chứa số nguyên
//         n
//             .

//     Dòng thứ 2 chứa dãy
//         In ra số màu ít nhất.
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

vector<int> a;

int lis(vector<int> const &a)
{
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j - 1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << lis(a) << endl;
    return 0;
}
