// Cho xâu S (độ dài không vượt quá 15) chỉ gồm các kí tự từ ′A′ đến ′Z′ (các kí tự trong xâu S không
// nhất thiết phải khác nhau). Hãy liệt kê tất cả các hoán vị khác nhau của xâu S
// Input:
//  Một dòng duy nhất là xâu S
// Output:
//  Gồm nhiều dòng, mỗi dòng là một hoán vị của xâu S
//  Các xâu được liệt kê theo thứ tự từ điển
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i >= b; i++)
#define nmax 100005
#define ll long long
using namespace std;
const ll mod = 1e7;
ll x[100], n;
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string res;
    do
    {
        res += s;
        res += '\n';
    } while (next_permutation(s.begin(), s.end()));
    cout << res;
    return 0;
}
