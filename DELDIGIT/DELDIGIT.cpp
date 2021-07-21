// Bạn được cho một số nguyên X có n chữ số
// Với 1 ≤ k ≤ n, gọi Xk là số lớn nhất có thể được khi xoá một vài chữ số từ số X sao
// cho X còn lại đúng k chữ số
// Yêu cầu: Tìm chữ số thứ l của Xk với 1 ≤ l ≤ k
// Tất cả các chữ số được đánh số từ 1 từ trái qua phải
// Input:
// Dòng đầu là số X có n chữ số (1 ≤ n ≤ 105
// )

// Dòng thứ hai là số m, số lượng truy vấn (1 ≤ m ≤ 105
// )
// m dòng tiếp theo, mỗi dòng chứa hai số nguyên là k và l
// Output:
// Đưa ra m truy vấn trên 1 dòng (không có dấu cách). Chữ số thứ i là kết quả của
// truy vấn thứ i
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll nmax = 1e5 + 5;
string s = "", b[nmax];
ll x, n, q, k, l;
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();
    ll i = 1;
    b[0] = s;
    //cout << b[0];
    while (i < s.size())
    {
        while (i != 0 && s[i - 1] < s[i])
        {
            s.erase(i - 1, 1);
            i--;
            x++;
            b[x] = s;
            //cout << b[x] << '\n';
        }
        i++;
    }

    while (s.size())
    {
        s.erase(s.size() - 1, 1);
        x++;
        b[x] = s;
        //cout << b[x] << '\n';
    }

    //    for ( ll i = 1 ; i <= x ; ++i )
    //        cout << b[i] << '\n';
    cin >> q;
    while (q--)
    {
        cin >> k >> l;
        cout << b[n - k][l - 1];
    }
}
