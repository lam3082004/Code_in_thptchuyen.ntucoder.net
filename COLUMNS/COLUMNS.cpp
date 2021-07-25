// Lãnh chúa Luka cho xây dựng dãy n cột đá. Ban đầu các cột đá chỉ có móng và được coi
// là có độ cao bằng 0. Mỗi khi có một sự kiện nào đó thời đại trị vì của mình ông chọn một dãy
// các cột liên tiếp nhau có cùng độ cao và cho xây chúng cao thêm một đơn vị, ngoại trừ cột đầu
// và cuối trong dãy.
// Thời gian trôi qua, thời đại trị vì của Luka bị chìm vào dĩ vãng. Dưới tác động của thời
// tiết và các cuộc chiến tranh liên miên thời trung cổ một số cột đá bị vỡ nát. Dãy cột đá đồ sộ biểu
// tượng của một thời huy hoàng nay chỉ còn là một phế tích buồn tẻ, phủ đầy rêu xanh, đứng trầm
// mặc, cô đơn trên thảo nguyên mênh mông.
// Các nhà khảo cổ học đã tìm thấy phế tích. Dựa vào chiều cao các cột còn lại người ta
// muốn xác định tình trạng cuối cùng của dãy cột đá trước khi nó bị phó mặc cho thời gian.
// 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 1 1 1 1 0 0 1 1 2 1 0 0 1 1 2 1 0

// Hãy xác định số lượng tình trạng khác nhau có thể và đưa ra theo mô đun 109
// +7.

// Dữ liệu: Vào từ file văn bản COLUMNS.INP:
//  Dòng đầu tiên chứa số nguyên n (1 ≤ n ≤ 104
// ),

//  Dòng thứ 2 chứa n số nguyên h1, h2, . . ., hn, trong đó hi là độ cao cột thứ i, -1 ≤ hi ≤ 104
// ,

// i = 1 ÷ n, giá trị -1 cho biết cột bị đổ vỡ, không xác định được độ cao.
// Kết quả: Đưa ra file văn bản COLUMNS.OUT một số nguyên – kết quả tìm được.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define fi first
#define se second
#define LL long long
#define pb push_back
#define eb emplace_back
#define bit(s, i) ((s >> i) & 1)
#define off(s, i) (s & (~(1 << i)))
#define ii pair<int, int>
#define TASK "COLUMNS"
using namespace std;
const int base = 1e9 + 7;
int n, a[10010], f[2][10010];
///--------------------------
void readf()
{
    cin >> n;
    fo(i, 1, n) cin >> a[i];
}
///--------------------------
void solve()
{
    if (a[1] > 0)
    {
        cout << 0;
        exit(0);
    }
    f[1][0] = 1;
    fo(i, 2, n)
    {
        int nw, pre;
        nw = i & 1;
        pre = 1 - nw;
        if (a[i] == -1)
            fo(j, 0, i)
            {
                f[nw][j] = (f[pre][j] + f[pre][j + 1]) % base;
                if (j > 0)
                    f[nw][j] = (f[nw][j] + f[pre][j - 1]) % base;
            }
        else
        {
            int x = a[i];
            f[nw][x] = (f[pre][x] + f[pre][x + 1]) % base;
            if (x > 0)
                f[nw][x] = (f[nw][x] + f[pre][x - 1]) % base;
        }
        //cerr << pre << '\n';
        fo(j, 0, i + 1) f[pre][j] = 0;
    }
    cout << f[n & 1][0] % base;
}
///--------------------------
int main()
{
#ifdef BDP0509
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    readf();
    solve();
}
