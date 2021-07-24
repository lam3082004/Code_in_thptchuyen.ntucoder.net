// Cho hai dãy số nguyên dương gồm n phần tử a1, a2, ..., an và b1, b2, ..., bn.
// Yêu cầu: Bạn hãy tìm hai tập hợp không rỗng X và Y thỏa mãn:
// • X là tập hợp con của dãy A.
// • Y là tập hợp con của dãy B.
// • Tổng các giá trị trong tập hợp X bằng tổng các giá trị trong tập hợp Y .
// Dữ liệu
// • Dòng đầu tiên chứa duy nhất một số nguyên dương n (n ≤ 105
// ).
// • Dòng thứ hai chứa n giá trị nguyên dương a1, a2, ..., an (ai ≤ n).
// • Dòng thứ ba chứa n giá trị nguyên dương b1, b2, ..., bn (bi ≤ n).
// Kết quả
// Nếu không có hai tập hợp nào thỏa mãn yêu cầu đề ra, in ra −1. Nếu tồn tại hai tập hợp thỏa
// mãn, bạn hãy in ra theo hình thức sau:
// • Dòng đầu tiên gồm một số nguyên dương ka (ka > 0) ở đầu dòng, ka giá trị tiếp theo gồm
// các chỉ số i1, i2, ..., ika
// (it ∈ [1, n]) đôi một phân biệt thể hiện các phần tử trên dãy A của
// tập hợp X.
// • Dòng thứ hai gồm một số nguyên dương kb (kb > 0) ở đầu dòng, kb giá trị tiếp theo gồm
// các chỉ số j1, j2, ..., jkb
// (jt ∈ [1, n]) đôi một phân biệt thể hiện các phần tử trên dãy B của
// tập hợp Y .
// • Thỏa mãn điều kiện ai1 + ai2 + ... + aika = bj1 + bj2 + ... + bjkb
// .
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
#define ii pair<ll, ll>
#define fi first
#define se second
#define oo 1e9
using namespace std;
const int mod = 998244353;
ll n, k, a[nmax], b[nmax], x[nmax], y[nmax];
ll turn = 0, f[nmax], l, r;
map<ll, int> ta;
vector<int> A, B;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
    {
        cin >> a[i];
        x[i] = x[i - 1] + a[i];
    }
    fo(i, 1, n)
    {
        cin >> b[i];
        y[i] = y[i - 1] + b[i];
    }
    if (x[n] > y[n])
    {
        fo(i, 1, n)
        {
            swap(a[i], b[i]);
            swap(x[i], y[i]);
        }
        turn = 1;
    }
    int j = 0;
    fo(i, 0, n)
    {
        while (x[i] > y[j])
            j++;
        f[i] = j;
    }
    fo(i, 1, n)
    {
        if (ta[y[f[i]] - x[i]] != 0)
        {
            l = ta[y[f[i]] - x[i]];
            r = i;
            break;
        }
        else
        {
            if (y[f[i]] - x[i] == 0)
            {
                l = 0;
                r = i;
                break;
            }
            else
                ta[y[f[i]] - x[i]] = i;
        }
    }
    fo(i, l + 1, r)
        A.push_back(i);
    fo(i, f[l] + 1, f[r])
        B.push_back(i);
    if (turn)
    {
        cout << B.size() << ' ';
        for (auto u : B)
            cout << u << ' ';
        cout << '\n';
        cout << A.size() << ' ';
        for (auto u : A)
            cout << u << ' ';
    }
    else
    {
        cout << A.size() << ' ';
        for (auto u : A)
            cout << u << ' ';
        cout << '\n';
        cout << B.size() << ' ';
        for (auto u : B)
            cout << u << ' ';
    }
}
