// Trường lập trình viên trẻ quyết định phát triển mạng xã hội riêng của mình để chọn tự động cho mỗi
// thành viên một danh sách các bạn bè tiềm năng. Khi đăng kí, mỗi thành viên trong mạng phải trải qua
// một đợt kiểm tra tâm lí, mà kết quả cho phép xác định các giá trị của ba đặc điểm tâm lí của người dùng.
// Giá trị của mỗi đặc điểm là một số nguyên dương.
// Theo các chuyên gia tâm lí, nếu hai thành viên khác nhau ở cả ba đặc điểm tâm lí, họ sẽ liên tục cãi nhau,
// nếu hai người có các đặc điểm tâm lí là như nhau ở hai hoặc ba đặc điểm, họ sẽ cảm thấy nhàm chán. Vì
// vậy, bạn bè tiềm năng chỉ là những cặp thành viên có đúng một trong ba giá trị đặc điểm tâm lí là bằng
// nhau và hai giá trị còn lại là khác nhau.
// Yêu cầu: Cho biết (
// ,
// ,
// ) là bộ ba giá trị đặc điểm tâm lí của thành viên thứ
// (
// = 1, 2, ... ,

// ), hãy xác

// định số lượng các cặp bạn bè tiềm năng, tức là cặp chỉ số
// <
// , mà chỉ có đúng một trong ba đẳng thức

// =
// ,
// =
// ,
// =
// được thực hiện.

// Input:
//  Dòng đầu chứa số nguyên dương
// (1 ≤
// ≤ 10
// ) – là số lượng thành viên trong mạng

//  Dòng thứ
// trong số
// dòng tiếp theo chứa ba số nguyên dương
// ,
// ,
// (
// ,
// ,
// ≤ 100) là giá

// trị của ba đặc điểm tâm lí của thành viên thứ
// .

// Output:
//   Một số nguyên duy nhất là số lượng cặp thành viên là bạn bè tiềm năng
#include <bits/stdc++.h>
#define maxn 100005
#define F first
#define S second
#define pii pair<int, int>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define Task ""
using namespace std;
map<int, int> m, m1, m2;
int d[100], d1[100], d2[100];
map<int, int> M;
struct dt
{
    int a, b, c;
} p[maxn];
int change(int a, int b, int c)
{
    int s = a * 10000 + b * 100 + c;
    return s;
}
int ch(int a, int b)
{
    return a * 100 + b;
}
long long ans, ans1;
int n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //  freopen(Task".inp","r",stdin);
    //    freopen(Task".out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--, z--;
        int c = change(x, y, z);
        int xy = ch(x, y), xz = ch(x, z), yz = ch(y, z);
        ans += m[xy] + m1[xz] + m2[yz];
        ans1 += d[x] + d1[y] + d2[z];
        ans -= 3 * M[c];
        ans1 -= 3 * M[c];
        d[x]++, d1[y]++, d2[z]++;
        M[c]++;
        m[xy]++, m1[xz]++, m2[yz]++;
        //    cout << ans1 <<endl;
    }
    //  cout << ans1<<' '<< ans<<endl;
    cout << ans1 - ans * 2;

    return 0;
}
