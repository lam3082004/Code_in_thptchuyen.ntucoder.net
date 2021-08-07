// Một xe tự hành thám hiểm sao Hỏa gặp trục trặc, để khôi phục cần tăng công suất pin của nó.
// Công suất pin là một số nguyên dương. Nếu công suất hiện tại là a, để khôi phục hoạt động
// của xe cần tăng công suất pin đến giá trị b (b > a). Để thay đổi công suất pin của xe tự hành,
// từ Trái đất cần gửi đến 2 tín hiệu đặc biệt dạng X và dạng Y. Tín hiệu dạng X sẽ tăng công suất
// pin lên một đơn vị, tín hiệu dạng Y tăng công suất pin lên hai đơn vị.
// Các nhà khoa học muốn điều chỉnh công suất pin của xe tự hành đến giá trị mong muốn và
// gửi ít tín hiệu nhất có thể. Đáng tiếc là, do đặc tính của xe tự hành, nếu công suất pin trùng
// với bội số của một số nguyên c, thì nó sẽ bị mất kiểm soát và không hồi đáp các tín hiệu tiếp
// theo. Bạn cần giúp các nhà khoa học viết chương trình với 3 số nguyên đầu vào a, b, c mô tả
// ở trên xác định số ít nhất tín hiệu cần gửi để khôi phục trạng thái làm việc của xe tự hành.
// Input:
//  3 dòng riêng biệt, mỗi dòng là 1 số, lần lượt là a, b, c
//  1 ≤ a < b ≤ 109

// , 2 ≤ c ≤ 109

//  a không chia hết cho c, b không chia hết cho c
// Output:
//  Một số nguyên duy nhất là số tín hiệu tối thiểu cần gửi để khôi phục trạng thái làm
// việc của xe tự hành
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define nmax 1000000
#define ull unsigned long long
#define fi first
#define se second
#define ii pair<int, int>
#define il pair<ll, ll>

const int mod = 1e9 + 7;
const ll md = 1000000000000000007;
using namespace std;
///===========================================
void rose()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void pk()
{
#ifndef ONLINE_JUDGE
    freopen("pk.inp", "r", stdin);
    freopen("pk.out", "w", stdout);
#endif // ONLINE_JUDGE
}
///===========================================
ll a, b, c;
///===========================================
///===========================================
///===========================================
///===========================================
int main()
{
    pk();
    rose();
    cin >> a >> b >> c;
    ll x = a / c + 1, y = b / c;
    if (c > b)
        cout << (b - a) / 2 + (b - a) % 2;
    else
        cout << (y - x) * (c / 2 + c % 2) + (x * c - a - 1) / 2 + (x * c - a - 1) % 2 + (b - y * c - 1) / 2 + (b - y * c - 1) % 2 + 1;
}
///===========================================
