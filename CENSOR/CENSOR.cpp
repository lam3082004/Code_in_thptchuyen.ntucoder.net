// Cho một xâu S có độ dài tối đa là 106
// ký tự. Trong xâu S người ta loại bỏ sự xuất hiện của
// một xâu con T có độ dài ≤ 100 ký tự. Để làm điều này, người ta tìm sự xuất hiện của T lần đầu
// tiên trong S và xóa nó. Sau đó cứ lặp đi lặp lại quá trình này cho đến khi không còn sự xuất hiện
// của T trong S. Lưu ý rằng việc xóa một lần xuất hiện có thể tạo ra một sự xuất hiện mới của T
// chưa từng tồn tại trước đó. Hãy xác định nội dung cuối cùng của xâu S.
// Dữ liệu: Vào từ file văn bản CENSOR.INP:
// - Dòng đầu tiên chứa xâu S.
// - Dòng thứ hai chứa xâu T. Chiều dài của xâu T bé hơn chiều dài của S, và tất cả các kí tự
// của S và T đều là ký tự thường (trong phạm vi từ a..z).
// Kết quả: Ghi ra file văn bản CENSOR.OUT chỉ một dòng chứa xâu S sau khi đã xóa bỏ hết T.
// // Đảm bảo rằng S sẽ không trở nên xâu rỗng trong quá trình xóa
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 1000005
using namespace std;
const int mod = 1e9 + 7;
ll n, m, l, r, hashs[nmax], hasht = 0, poww[nmax];
vector<char> p;
string s, t;
ll gett(ll i, ll j)
{
    return ((hashs[j] - hashs[i - 1] * poww[j - i + 1]) % mod + mod) % mod;
}
int main()
{
    //    freopen("IDP1104C.inp","r",stdin);
    //    freopen("IDP1104C.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    n = s.size();
    s = ' ' + s;
    m = t.size();
    t = ' ' + t;
    poww[0] = 1;
    fo(i, 1, n)
        poww[i] = (poww[i - 1] * 31) % mod;
    fo(i, 1, n)
        hashs[i] = (hashs[i - 1] * 31 + s[i] - 'a' + 1) % mod;
    fo(i, 1, m)
        hasht = (hasht * 31 + t[i] - 'a' + 1) % mod;
    fo(i, 1, n)
    {
        p.push_back(s[i]);
        ll tmp = p.size();
        hashs[tmp] = (hashs[tmp - 1] * 31 + p[tmp - 1] - 'a' + 1) % mod;
        if (tmp >= m)
        {
            if (gett(tmp - m + 1, tmp) == hasht)
            {
                fo(j, 1, m)
                    p.pop_back();
            }
        }
    }
    fo(i, 0, p.size() - 1)
            cout
        << p[i];
}
