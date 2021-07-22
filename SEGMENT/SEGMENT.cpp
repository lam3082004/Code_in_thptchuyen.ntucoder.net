// Trên một hệ trục tọa độ Ox, có N đoạn thẳng. Các đoạn thẳng được đánh số từ 1 đến N. Đoạn
// thẳng thứ i có đầu mút bên trái tại Li và đầu mút bên phải tại Ri
// .

// Ta nói rằng, một điểm có tọa độ x được phủ bởi đoạn thẳng i khi và chỉ khi x nằm giữa hai đầu
// mút của i (tức là Li ≤ x ≤ Ri).
// Có Q truy vấn, mỗi truy vấn được mô tả bởi hai số nguyên a và b, yêu cầu:
// • Trong số N đoạn thẳng đã cho, cần chọn ra một số đoạn thẳng, sao cho tất cả các điểm có
// tọa độ từ a đến b đều được bao phủ bởi ít nhất một đoạn thẳng trong các đoạn thẳng được
// lựa chọn. Hãy in ra số lượng đoạn thẳng ít nhất cần lựa chọn.
// Yêu cầu: Viết chương trình trả lời Q truy vấn trên.
// Dữ liệu
// • Dòng đầu tiên gồm số nguyên N (1 ≤ N ≤ 200000) - số đoạn thẳng.
// • N dòng tiếp theo, dòng thứ i gồm hai số nguyên Li và Ri (0 ≤ Li ≤ Ri ≤ 109

// ) - tọa độ hai

// đầu mút của đoạn thẳng thứ i.
// • Dòng tiếp theo gồm số nguyên Q (1 ≤ Q ≤ 200000) - số truy vấn cần xử lí.
// • Q dòng tiếp theo, mỗi dòng gồm hai số nguyên a và b (0 ≤ a ≤ b ≤ 109

// ) mô tả một truy

// vấn.
// Kết quả
// • Với mỗi truy vấn, in ra một dòng gồm một số nguyên duy nhất là số đoạn thẳng ít nhất cần
// lựa chọn. Trong trường hợp không có cách chọn, hãy in ra -1.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
vector<ii> f1(vector<ii> &a)
{
    int n = a.size();
    sort(a.begin(), a.end());
    vector<ii> b;
    b.push_back(a[0]);
    for (int i = 1; i < n; ++i)
        if (a[i].second > b.back().second)
            b.push_back(a[i]);

    return b;
}
vector<int> f2(vector<ii> &a)
{
    int n = a.size();
    vector<int> f(n);
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        while (j < n && a[j].first <= a[i].second + 1)
            ++j;
        f[i] = j - 1;
    }
    return f;
}
int f3(vector<ii> &a, int x)
{
    int n = a.size();
    int l = 0, r = n - 1, res = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid].first <= x)
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return res;
}
int sol(vector<ii> &a, vector<vector<int>> &dp, int A, int b)
{
    int k = dp.size() - 1, n = dp[0].size();
    int id = f3(a, A);
    if (id == -1)
        return id;
    if (a[id].second >= b)
        return 1;
    int ans = 1;
    for (int i = k; i >= 0; --i)
    {
        int z = dp[i][id];
        if (a[z].second < b)
        {
            id = z;
            ans += (1 << i);
        }
    }
    for (int i = 0; i < k; ++i)
    {
        int z = dp[i][id];
        if (a[z].second >= b)
            return ans + (1 << i);
    }
    return -1;
}
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ii> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    a = f1(a);
    n = a.size();
    int k = log2(n);
    vector<vector<int>> dp(k + 1, vector<int>(n, -1));
    dp[0] = f2(a);
    for (int i = 1; i <= k; ++i)
        for (int u = 0; u < n; ++u)
            dp[i][u] = dp[i - 1][dp[i - 1][u]];
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int A, b;
        cin >> A >> b;
        cout << sol(a, dp, A, b) << '\n';
    }
}
