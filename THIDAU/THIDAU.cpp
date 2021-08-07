// Bạn Nam là một vận động viên quần vợt chuyên nghiệp. Trong hệ thống thi đấu quần vợt, mỗi năm người ta tổ chức n giải đấu đánh số từ 1 đến n. Giải đấu thứ i được tổ chức vào ngày ai và mỗi vận động viên tham gia được khoản tiền thưởng là bi. Tuy nhiên để đảm bảo sức khỏe cho Nam, huấn luyện viên quyết định hai giải đấu mà Nam chọn tham dự phải cách xa nhau ít nhất là k ngày ( |ai - aj| ≥ k) . Bạn hãy giúp Nam chọn lựa các giải thi đấu sao cho tổng số tiền thưởng là nhiều nhất.

// Dữ liệu nhập:

// - Dòng đầu tiên là hai số nguyên n và k cách nhau một khoảng trắng (1 ≤ n ≤ 100, 1 ≤ k ≤ 10)

// - Dòng thứ 2 gồm n số nguyên a1, a2, ..., an (1 ≤ ai ≤ 365) là ngày thi đấu của các giải, mỗi số cách nhau một khoảng trắng. Dữ liệu cho đảm bảo a1 < a2 < a3 < ...< an.

// - Dòng thứ 3 gồm n số nguyên b1, b2, ..., bn (1 ≤ bi ≤ 100) là số tiền thưởng của từng giải, mỗi số cách nhau một khoảng trắng.

// Dữ liệu xuất:

// - Là số nguyên xác định số tiền thưởng nhiều nhất mà Nam có thể có được.
#include <bits/stdc++.h>
using namespace std;
long long n, k, f[100005], maxa = -1e9;
pair<long long, long long> p[1000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> p[i].first;
    for (int i = 1; i <= n; i++)
        cin >> p[i].second;
    for (long long i = 1; i <= n; i++)
    {
        f[i] = p[i].second;
        for (long long j = 1; j < i; j++)
        {
            if ((p[i].first - p[j].first) >= k)
                f[i] = max(f[j] + p[i].second, f[i]);
            maxa = max(maxa, f[i]);
        }
    }
    cout << maxa;
}
