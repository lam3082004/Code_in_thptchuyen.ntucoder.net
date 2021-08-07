// Số a̅̅1̅̅a̅2̅̅...̅̅̅a̅̅n̅ được gọi là số đơn điệu nếu ai < ai+1 > ai+2 hoặc ai > ai+1 < ai+2 (Với mọi i =
// 1 . . n − 2). Số có 1 chữ số hoặc 2 chữ số khác nhau cũng được gọi là số đơn điệu và có độ dài là 1; 2
// Ví dụ: Các số 5, 58, 3748, 32435465768 là các số đơn điệu vì:
// - Số 5 có 1 chữ số
// - Số 58 có 2 chữ số khác nhau
// - Số 3748 có 3 < 7 > 4 < 8
// - Số 32435465768 có 3 > 2 < 4 > 3 < 5 > 4 < 6 > 5 < 7 > 6 < 8
// Với số a̅̅1̅̅a̅2̅̅...̅̅̅a̅̅n̅, một dãy con của nó là ai1
// ai2 ... aik
// ̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅ trong đó 1 ≤ i1 < i2 < ⋯ < ik ≤ n
// Yêu cầu: Cho số N = a̅̅1̅̅a̅2̅̅...̅̅̅a̅̅n̅, xác định dãy con dài nhất của N là số đơn điệu
// Input:
// - Một dòng duy nhất là số N có không quá 75 chữ số
// Output:
// - Một dòng duy nhất là độ dài dãy con dài nhất của N thoả mãn tính chất số đơn điệu
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define nmax 1000000
#define ull unsigned long long
#define fi first
#define se second
#define ii pair<int, int>
#define il pair<ll, ll>

const int mod = 1e9 + 7;
const ll md = 1000000000000000007;
using namespace std;
///===========================================
void rose()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void pk()
{
#ifndef ONLINE_JUDGE
    freopen("pk.inp", "r", stdin);
    freopen("pk.out", "w", stdout);
#endif // ONLINE_JUDGE
}
///===========================================
string s;
int f[nmax + 5][2];
///===========================================
///===========================================
///===========================================
///===========================================
int main()
{
    pk();
    rose();
    cin >> s;
    s = ' ' + s;
    // s[i-1] > s[i] < s[i+1]
    // s[i-1] < s[i] > s[i+1]
    // f[i][1] = là biện pháp tối ưu đến vị trí i với dấu cuối cùng là > : s[i-1] > s[i]
    // f[i][2] =        ""              ""                             < : s[i-1] < s[i]
    for (int i = 1; i <= s.size(); i++)
    {
        f[i][1] = f[i][2] = 1;
        for (int j = 1; j < i; j++)
        {
            if (s[j] > s[i])
                f[i][1] = max(f[i][1], f[j][2] + 1);
            else if (s[j] < s[i])
                f[i][2] = max(f[i][2], f[j][1] + 1);
        }
    }
    cout << max(f[s.size() - 1][1], f[s.size() - 1][2]);
}
///===========================================
