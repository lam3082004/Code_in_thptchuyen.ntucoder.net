// Trong làng Omega có 1 phú ông rất giầu có. Tài sản của ông rất nhiều trâu, bò,
// ruộng vườn. Một hôm ông gọi 3 người con đã đến tuổi trưởng thành đến ông chia cho
// một số ruộng để làm ăn. Ông có hàng trăm mẫu ruộng nhưng ông chỉ chọn 𝑛 thửa
// ruộng để chia, thửa thứ 𝑖 có diện tích 𝑎𝑖 m2
// . Hỏi rằng phú ông có bao nhiêu cách chia
// đều 𝑛 thửa ruộng cho 3 con sao cho các thửa ruộng được chia phải giữ nguyên diện
// tích.
// Input: đọc từ file CHIARUONG.INP gồm 02 dòng:
// - Dòng 1: ghi số 𝑛 là số thửa ruộng của phú ông đem chia (1≤n≤20)
// - Dòng 2: ghi các số 𝑎𝑖
// là diện tích của thửa ruộng thứ i (100≤a[i]≤5000).
// Output: ghi ra file CHIARUONG.OUT gồm:
// - Dòng thứ nhất ghi số cách chia, nếu không thể chia được thì ghi -1.
// - Các dòng sau trong trường hợp chia được, mỗi dòng là 01 cách chia với
// quy ước người thứ nhất có tên là “A”, người thứ hai có tên là “B”, người
// thứ ba có tên là “C” và phải tương ứng với thứ tự của các thửa ruộng được
#include <bits/stdc++.h>
#define lo long long
#define KKH "CHIARUONG"
#define fi first
#define se second
#define BIT(mask, k) (((mask) >> (k - 1)) & 1)
#define rs(x, a) memset(x, (a), sizeof x)
#define off(mask, k) ((mask) ^ (1 << (k - 1)))
#define len(a) int(a.size())
#define all(a) a.begin(), a.end()
using namespace std;
void START()
{
#ifdef toilagun2004
    freopen(KKH ".inp", "r", stdin);
    freopen(KKH ".out", "w", stdout);
#endif // toilagun2004
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int gh = 32;
int n, a[gh], id, Find[1 << 20], sz;
lo s[1 << 20], sum, f[1 << 12];
string ans[1 << 20];
bitset<(1 << 12)> d[1 << 12];
int main()
{
    START();
    cin >> n;
    bitset<20> en = (1 << n) - 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3)
        return cout << -1, 0;
    else
    {
        sum /= 3;
        for (int mask = 0, t = en.to_ulong(); mask <= t; mask++)
        {
            for (int i = 1; i <= n; i++)
                if (BIT(mask, i))
                    s[mask] += a[i];
            if (s[mask] == sum)
                f[++id] = mask, Find[mask] = id;
        }
    }
    for (int pos = 1; pos < id; pos++)
    {
        bitset<20> b = f[pos];
        for (int pos2 = pos + 1; pos2 <= id; pos2++)
        {
            bitset<20> b2 = f[pos2];
            if (d[pos][pos2] || (b & b2).any())
                continue;
            int pos3 = Find[en.to_ulong() ^ f[pos] ^ f[pos2]];
            d[pos][pos2] = d[pos][pos3] = 1;
            d[pos2][pos] = d[pos2][pos3] = 1;
            d[pos3][pos] = d[pos3][pos2] = 1;
            ans[sz + 1].resize(n);
            ans[sz + 2].resize(n);
            ans[sz + 3].resize(n);
            ans[sz + 4].resize(n);
            ans[sz + 5].resize(n);
            ans[sz + 6].resize(n);
            for (int i = 0; i < n; i++)
            {
                if (b[i])
                {
                    ans[sz + 1][i] = 'A';
                    ans[sz + 2][i] = 'A';
                    ans[sz + 3][i] = 'B';
                    ans[sz + 4][i] = 'B';
                    ans[sz + 5][i] = 'C';
                    ans[sz + 6][i] = 'C';
                }
                else if (b2[i])
                {
                    ans[sz + 1][i] = 'B';
                    ans[sz + 2][i] = 'C';
                    ans[sz + 3][i] = 'A';
                    ans[sz + 4][i] = 'C';
                    ans[sz + 5][i] = 'A';
                    ans[sz + 6][i] = 'B';
                }
                else
                {
                    ans[sz + 1][i] = 'C';
                    ans[sz + 2][i] = 'B';
                    ans[sz + 3][i] = 'C';
                    ans[sz + 4][i] = 'A';
                    ans[sz + 5][i] = 'B';
                    ans[sz + 6][i] = 'A';
                }
            }
            sz = sz + 6;
        }
    }
    if (!sz)
        cout << -1;
    else
    {
        sort(ans + 1, ans + 1 + sz);
        cout << sz << '\n';
        for (int i = 1; i <= sz; i++)
            cout << ans[i] << '\n';
    }
}
