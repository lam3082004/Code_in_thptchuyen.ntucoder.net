// Cho một dãy số nguyên a1, a2, a3, ..., an (3 ≤ n ≤ 1000, |ai| ≤ 109

// , với mọi i = 1, 2,..., n).

// Yêu cầu: Đếm số cách chọn ra một dãy số gồm M phần tử (1 ≤ M ≤ N). Hai dãy số được gọi là
// khác nhau nếu tại cùng một vị trí, giá trị 2 phần tử của 2 dãy là khác nhau.
// Dữ liệu vào:
// - Dòng đầu ghi 2 số n, m.
// - Dòng tiếp theo ghi các số nguyên ai (các số cách nhau ít nhất một dấu cách).
// Kết quả ra: Ghi ra số lượng cách chọn dãy. Vì kết quả có thể rất lớn nên chỉ cần ghi phần dư
// của kết quả khi chia (1012+7).
#include <bits/stdc++.h>
#define ll long long
#define task "test"
using namespace std;

void Init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);
}

const ll MOD = 1e12 + 7;
int n, m;
ll a[1001];
ll F[1001][1001];
map<pair<int, int>, ll> S;

void Solve()
{
    cin >> n >> m;
    F[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        F[i][0] = F[i - 1][0];
        for (int j = 1; j <= m; ++j)
        {
            F[i][j] = (F[i - 1][j] + F[i - 1][j - 1] - S[{a[i], j}] + MOD) % MOD;
            S[{a[i], j}] = F[i - 1][j - 1];
        }
    }
    cout << F[n][m];
}

int main()
{
    Init();
    Solve();
}
