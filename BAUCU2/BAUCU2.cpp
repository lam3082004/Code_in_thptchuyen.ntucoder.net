// Nhân sự kiện bầu cử Đại biểu Quốc hội và Đại biểu HĐND các cấp, bài tập hôm nay cũng sẽ
// nói về chủ đề bầu cử tại đất nước X.
// X được chia là N tỉnh, mỗi tỉnh có một số người được đi bầu cử khác nhau, thậm chí có tỉnh
// không có ai được quyền đi bầu cử. Sau khi bỏ phiếu xong, người ta đếm được M phiếu, mỗi phiếu sẽ
// ghi hai số là x và y, trong đó x là số thứ tự tỉnh, y là số thứ tự của ứng cử viên tổng thống. Trong mỗi
// tỉnh, ứng viên nào có nhiều phiếu nhất sẽ là người đại diện cho tỉnh đó, nếu có nhiều hơn một ứng viên
// thì sẽ không có ai đại diện cả. Cuối cùng, ứng viên nào là người đại diện của nhiều tỉnh nhất sẽ được
// bầu cử làm tổng thống. Nếu có nhiều hơn một ứng viên thì sẽ phải bầu lại, vào một thời điểm nào đó.
// Yêu cầu: Dựa vào thông tin các phiếu bầu, hãy cho biết ai được bầu làm tổng thống, hay phải
// bầu lại
// Input
// • Dòng đầu tiên là hai số nguyên N, M
// • M dòng tiếp theo, mỗi dòng là hai số nguyên x, y
// Output
// • In ra số hiệu của người được bầu làm tổng thống
// • Nếu không tìm được ra ai, in ra 0
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 1000005
#define ii pair<ll, ll>
#define fi first
#define se second
const ll mod = 1e9 + 7;
using namespace std;
ll n, m, a, b, f[nmax][5];
ll s1 = 0, s2 = 0, s3 = 0, ans = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("BAUCU2.inp", "r", stdin);
    freopen("BAUCU2.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    fo(i, 1, m)
    {
        cin >> a >> b;
        f[a][b]++;
    }
    fo(i, 1, n)
    {
        if ((f[i][1] > f[i][2]) && f[i][1] > f[i][3] && f[i][1] != 0)
            s1++;
        else if (f[i][2] > f[i][1] && f[i][2] > f[i][3] && f[i][2] != 0)
            s2++;
        else if (f[i][3] > f[i][1] && f[i][3] > f[i][2] && f[i][3] != 0)
            s3++;
    }
    if (s1 > s2 && s1 > s3 && s1 != 0)
        ans = 1;
    else if (s2 > s1 && s2 > s3 && s2 != 0)
        ans = 2;
    else if (s3 > s1 && s3 > s2 && s3 != 0)
        ans = 3;
    else
    {
        cout << 0;
        return 0;
    }
    cout << ans;
}
