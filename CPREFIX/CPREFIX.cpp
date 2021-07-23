// Cho xâu 𝑆 độ dài 𝑛 ≤ 105
// . Tính và đưa ra dãy 𝑡1,𝑡2, … ,𝑡𝑛 với 𝑡𝑖 số lần xuất hiện của
// xâu 𝑆1𝑆2 … 𝑆𝑖
// trong 𝑆.
// Dữ liệu: Vào từ file văn bản CPREFIX.INP một dòng duy nhất là xâu 𝑆 gồm các chữ
// cái in thường có độ dài không quá 105
// .
// Kết quả: Đưa ra file văn bản CPREFIX.OUT một dòng duy nhất là các số 𝑡1,𝑡2, … ,𝑡𝑛
// đưa ra cách nhau một dấu cách.
#include <bits/stdc++.h>
#define ll long long
#define nmax 100005
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int base = 37;
const int mod = 1e9 + 7;
ll n, l, r, k, a[nmax], t[nmax], hasha[nmax], poww[nmax];
string s;
ll gett(ll i, ll j)
{
    return (((hasha[j] - hasha[i - 1] * poww[j - i + 1]) % mod) + mod) % mod;
}
int main()
{
    cin >> s;
    n = s.size();
    s = " " + s;
    poww[0] = 1;
    fo(i, 1, n)
        poww[i] = (poww[i - 1] * base) % mod;
    fo(i, 1, n)
        hasha[i] = (hasha[i - 1] * base + s[i] - 'a' + 1) % mod;
    fo(i, 1, n)
    {
        l = 1;
        r = n - i + 1;
        k = 0;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (gett(1, mid) == gett(i, i + mid - 1))
            {
                k = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        a[1]++;
        a[k + 1]--;
    }
    fo(i, 1, n) t[i] = t[i - 1] + a[i];
    fo(i, 1, n) cout << t[i] << ' ';
}
