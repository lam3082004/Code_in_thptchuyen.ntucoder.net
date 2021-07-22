// SUBRLE
// Xét xâu S độ dài không vượt quá 1018 chỉ gồm các ký tự ‘a’ đến ’z’ được mã hoá thành xâu
// SE (chỉ gồm các ký tự ‘a’ đến ‘z’ và ký tự ‘0’ đến ‘9’) như sau: Đi từ trái qua phải, mã hoá
// dãy các ký tự liên tiếp bằng nhau trong S thành ký tự đại diện và số lượng. Độ dài các xâu mã
// hoá không vượt quá 1000.
// Ví dụ, xâu S=aaabbbbaaaaaaaaaaz thì SE=a3b4a10z1
// Yêu cầu: Cho xâu S được mã hoá thành SE, đếm số lượng xâu khác nhau nhận được từ S
// bằng cách giữ nguyên hoặc xoá đi một số ký tự (đưa ra kết quả mod 111539786)
// Ví dụ: SE=a10 thì số lượng các xâu khác nhau nhận được từ S là 10
// Input
// - Dòng đầu chứa số T là số bộ dữ liệu;
// - T dòng sau, mỗi dòng chứa xâu SE là mã hóa của S.
// Output
// - Gồm T dòng, mỗi dòng là kết quả tương ứng với dữ liệu vào.
#include <bits/stdc++.h>
#define stat akjcjalsjcjalscj
#define hash ajkscjlsjclajsc
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define left lajcljascjljl
#define right aucouasocjolkjl
#define y0 u9cqu3jioajc
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define fore(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define __unique(V) (V).resize(unique((V).begin(), (V).end()) - (V).begin())
#define cntbit(X) __builtin_popcount((X))
#define bit(S, i) (((S) >> (i)) & 1)
#define PI acos(-1)
#define fi first
#define se second
#define LL long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define eb emplace_back
#define TASK "subrle"
using namespace std;
const int mod = 111539786;
int T, F[30], cnt[30];
string s;
vector<ii> str;
inline void MOD(int &A, LL B) { A = (A + B) % mod; }
///--------------------------
void solve()
{
    cin >> T;
    while (T--)
    {
        cin >> s;
        s = s + 'a';
        char c = '.';
        LL sl = 0;
        memset(cnt, 0, sizeof(cnt));
        str.clear();
        for (auto ch : s)
            if ('a' <= ch && ch <= 'z')
            {
                if (c != '.')
                {
                    str.eb(c - 'a', sl);
                    cnt[c - 'a'] = 1;
                }
                c = ch;
                sl = 0;
            }
            else
                sl = (sl * 10 + ch - '0') % mod;
        memset(F, 0, sizeof(F));
        for (int i = 0; i < str.size(); ++i)
        {
            int tmp = 0;
            for (int ch = 0; ch < 26; ++ch)
                if (ch != str[i].fi)
                    MOD(tmp, 1LL * str[i].se * F[ch]);
                else
                    MOD(tmp, F[ch]);
            F[str[i].fi] = (tmp + str[i].se) % mod;
        }
        int ans = 0;
        for (int ch = 0; ch < 26; ++ch)
            MOD(ans, F[ch]);
        cout << ans << '\n';
    }
}
///--------------------------
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif // ONLINE_JUDGE
    solve();
}
