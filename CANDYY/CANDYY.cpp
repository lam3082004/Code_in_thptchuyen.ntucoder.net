// Sau ngày lễ Quốc tế Thiếu Nhi 1/6, Cá Nóc nhận được rất nhiều kẹo Số kẹo này có thể phân
// thành N loại, loại thứ i sẽ có Ai cây. Vào một ngày đẹp trời, Thợ Săn Cá Nóc mang rất nhiều
// loại kẹo và các hộp sang nhà Cá Nóc để khoe chiến tích sau ngày 1/6 vừa rồi.
// Nhìn thấy những thứ mà Thợ Săn đem tới, Cá Nóc chợt nghĩ ra một trò chơi khá thú vị. Cá Nóc
// lấy ra N cái hộp từ Thợ Săn và đặt N loại kẹo của mình vào N hộp đó. Tức là hộp thứ i sẽ có Ai
// cây kẹo loại i. Bằng cách sử dụng lượng kẹo khổng lồ mà Thợ Săn mang đến, Cá Nóc muốn thực
// hiện M lượt. Mỗi lượt, Cá Nóc sẽ chọn ra ba số L, R, X, sau đó sẽ bỏ thêm vào từng hộp kẹo loại
// i trong khoảng L đến R một lượng là X cái kẹo loại tương ứng.
// Tuy nhiên Thợ Săn lại thích K con số may mắn, nên Thợ Săn sẽ từ chối thêm kẹo vào hộp loại i
// nếu lượng kẹo đang có trong hộp là một trong những con số may mắn của cậu ấy.
// Ví dụ, giả sử n = 5, A = [1, 2, 3, 4, 5] và những con số may mắn của Thợ Săn là 3 và 4. Cá Nóc
// chọn L = 2, R = 5, X = 7, thì lượng kẹo trong hộp bây giờ sẽ là [1, 9, 3, 4, 12] bởi vì 3 và 4 là
// những con số may mắn mà Thợ Săn thích.
// Các bạn hãy giúp Cá Nóc và Thợ Săn tính xem sau mỗi lượt thì tổng lượng kẹo có trong các hộp
// là bao nhiêu.
// Dữ liệu
// • Dòng đầu tiên chứa ba số nguyên dương N, M, K.
// • Dòng thứ hai chứa N số nguyên dương, số thứ i là Ai biểu diễn số lượng kẹo của loại i mà
// Cá Nóc có ban đầu.
// • Dòng thứ ba chứa K số nguyên khác nhau là các số may mắn mà Thợ Săn thích.
// • Dòng thứ i trong M dòng tiếp theo chứa ba số nguyên dương L, R, X biểu diễn lượt hiện
// tại sẽ thêm X viên kẹo mỗi loại từ L đến R vào hộp tương ứng.
// Kết quả
// • In ra M dòng, dòng thứ i ghi ra một số nguyên duy nhất là tổng lượng kẹo trong N hộp
// sau lượt thứ i.
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 5;
struct ii
{
    int d, pos, L, R, mid, res;
};
vector<ii> vt[nmax];
vector<int> v[nmax];
int n, m, k, a[nmax], b[nmax], U[nmax], V[nmax], MID[nmax];
bool vs[nmax];
int bit[nmax];
int X[nmax], bit2[nmax];
void update(int l, int r, int k)
{
    for (int i = l; i <= n; i += (i & -i))
        bit[i] += k;
    for (int i = r + 1; i <= n; i += (i & -i))
        bit[i] -= k;
}
int get(int p)
{
    int tmp = 0;
    for (int i = p; i > 0; i -= (i & -i))
        tmp += bit[i];
    return tmp;
}
void up(int p)
{
    for (int i = p; i > 0; i -= i & (-i))
        bit2[i]++;
}
int get2(int l, int r)
{
    int tmp = 0;
    for (int i = l; i <= n; i += i & (-i))
        tmp += bit2[i];
    for (int i = r + 1; i <= n; i += i & (-i))
        tmp -= bit2[i];
    return tmp;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("CANDYY.inp","r",stdin);
    //freopen("CANDYY.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        MID[i] = m + 1;
    }
    for (int i = 1; i <= k; ++i)
        cin >> b[i];
    for (int i = 1; i <= m; ++i)
        cin >> U[i] >> V[i] >> X[i];
    sort(b + 1, b + k + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j)
            if (a[i] == b[j])
            {
                vs[i] = 1;
                MID[i] = 0;
            }
    for (int t = 1; t <= k; t++)
    {
        vector<ii> q, q2;
        int d = 0;
        for (int i = 1; i <= n; ++i)
            if (MID[i] == m + 1)
            {
                q.push_back({d, i, 1, m, m + 1 >> 1, m + 1});
                d++;
            }
        while (q.size())
        {
            d = 0;
            memset(bit, 0, sizeof bit);
            for (int i = 0; i < q.size(); ++i)
                vt[q[i].mid].push_back(q[i]);
            for (int i = 1; i <= m; ++i)
            {
                update(U[i], V[i], X[i]);
                for (int j = 0; j < vt[i].size(); ++j)
                {
                    int tmp = get(vt[i][j].pos) + a[vt[i][j].pos];
                    int vitri = vt[i][j].d;
                    if (tmp >= b[t])
                    {
                        if (tmp == b[t])
                            q[vitri].res = q[vitri].mid;
                        q[vitri].R = q[vitri].mid - 1;
                    }
                    else
                        q[vitri].L = q[vitri].mid + 1;
                    q[vitri].mid = q[vitri].L + q[vitri].R >> 1;
                }
            }
            for (int i = 0; i < q.size(); ++i)
                MID[q[i].pos] = q[i].res;
            for (int i = 0; i < q.size(); ++i)
                if (q[i].L <= q[i].R)
                {
                    q[i].d = d++;
                    q2.push_back(q[i]);
                }
            q = q2;
            q2.clear();
            for (int i = 1; i <= m; ++i)
                vt[i].clear();
        }
    }
    memset(bit, 0, sizeof bit);
    long long tong = 0;
    for (int i = 1; i <= n; ++i)
    {
        v[MID[i]].push_back(i);
        tong += a[i];
    }
    for (int i = 0; i < v[0].size(); ++i)
        up(v[0][i]);
    for (int i = 1; i <= m; ++i)
    {
        int res = get2(U[i], V[i]) * X[i];
        tong = tong + (V[i] - U[i] + 1) * X[i] - res;
        cout << tong << '\n';
        for (int j = 0; j < v[i].size(); ++j)
            up(v[i][j]);
    }
}
