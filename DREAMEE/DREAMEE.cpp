// Tháng 2 có ngày Valentine, nên mình sẽ tiếp tục kể về các câu chuyện liên quan đến tình cảm
// của ARSENAL1886
// ARSENAL1886 vừa mới thức dậy sau một giấc mơ dài. Trong giấc mơ đó, anh ấy có người yêu.
// Nó sẽ rơi vào một ngày...
// Không may là ARSENAL1886 không thể nhớ chính xác ngày cụ thể. Anh ấy chỉ nhớ được ngày
// đó được viết theo định dạng 0DD MM Y Y Y Y 0

// với chính xác 8 chữ số. Anh ấy cũng nhớ được 8
// chữ số đó là gì (nhưng không nhớ được thứ tự). Hiển nhiên ngày đó phải là một ngày hợp lệ
// Bởi vì ARSENAL1886 sinh vào ngày 01/01/1980 (đây là giả định nhé, còn ngày sinh thật của
// khổ chủ thì đã được đề cập ở một bài tập khác), nên anh biết rằng ngày đó phải trùng hoặc sau
// ngày 01/01/2000 (lúc anh ấy đủ 20 tuổi, tránh trường hợp là tảo hôn)
// ARSENAL1886 muốn biết ngày mà anh có người yêu. Có bao nhiêu ngày như vậy? Ngày sớm
// nhất có thể là ngày nào?
// Chú ý
// Với năm nhuận, tháng Hai có 29 ngày, và nó có định nghĩa cụ thể như sau:
// • Năm chia hết cho 400 là năm nhuận
// • Năm chia hết cho 100 mà không chia hết cho 400 thì KHÔNG PHẢI là năm nhuận
// • Năm chia hết cho 4 mà không chia hết cho 100 thì là năm nhuận
// • Năm không chia hết cho 4 thì KHÔNG PHẢI là năm nhuận
// Input
// • Dòng đầu tiên là số nguyên dương t(1 ≤ t ≤ 50) - số lượng test
// • Mỗi dòng trong số t dòng tiếp theo chứa 8 chữ số với định dạng 0XX XX XXXX0
// (8 chữ
// số, cách nhau bởi hai dấu cách). Chú ý rằng Input có thể không là một ngày hợp lệ
// Chú ý rằng tháng đầu tiên trong năm là tháng 01, và ngày đầu tiên trong tháng là ngày 01
// Output
// • Với mỗi test, in ra trên một dòng là số ngày có thể và ngày sớm nhất có thể, theo định dạng
// 0DD MM Y Y Y Y 0

// . Nếu không có ngày nào hợp lệ, in ra một dòng là số 0 (điều đó có nghĩa

// là ARSENAL1886 sẽ FA cả đời, và giấc mơ kia chỉ là chuyện bịa)
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define nmax 50000000
#define ull unsigned long long
#define fi first
#define se second
#define ii pair<int, int>
#define il pair<ll, ll>

const int mod = 1e9 + 7;
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
    freopen("test.INP", "r", stdin);
    freopen("test.OUT", "w", stdout);
#endif // ONLINE_JUDGE
}
///===========================================
int t, d[50], n = 8, dem = 0;
string a, b, c, s;
int n1 = 1e9, t1 = 1e9, na1 = 1e9;
int xh[35][15][10000];
///===========================================
void xuat()
{
    int ngay, thang, nam;
    ngay = (s[a[1]] - 48) * 10 + (s[a[2]] - 48);
    thang = (s[a[3]] - 48) * 10 + (s[a[4]] - 48);
    nam = (s[a[5]] - 48) * 1000 + (s[a[6]] - 48) * 100 + (s[a[7]] - 48) * 10 + (s[a[8]] - 48);
    if (ngay <= 31 && ngay > 0 && thang <= 12 && thang > 0 && nam >= 2000)
    {
        if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
        {
            if (thang == 2)
            {
                if (ngay > 29)
                    return;
            }
            else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
            {
                if (ngay > 30)
                    return;
            }
            if (xh[ngay][thang][nam] == 0)
            {
                dem++;
                //cout << ngay <<" "<< thang <<" "<< nam <<"\n";
                xh[ngay][thang][nam] = 1;
            }

            if (nam < na1)
            {
                n1 = ngay;
                t1 = thang;
                na1 = nam;
            }
            else if (nam == na1)
            {
                if (thang < t1)
                {
                    n1 = ngay;
                    t1 = thang;
                    na1 = nam;
                }
                else if (thang == t1)
                {
                    if (ngay < n1)
                    {
                        n1 = ngay;
                        t1 = thang;
                        na1 = nam;
                    }
                }
            }
        }
        else
        {
            if (thang == 2)
            {
                if (ngay > 28)
                    return;
            }
            else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
            {
                if (ngay > 30)
                    return;
            }
            if (xh[ngay][thang][nam] == 0)
            {
                dem++;
                //cout << ngay <<" "<< thang <<" "<< nam <<"\n";
                xh[ngay][thang][nam] = 1;
            }
            if (nam < na1)
            {
                n1 = ngay;
                t1 = thang;
                na1 = nam;
            }
            else if (nam == na1)
            {
                if (thang < t1)
                {
                    n1 = ngay;
                    t1 = thang;
                    na1 = nam;
                }
                else if (thang == t1)
                {
                    if (ngay < n1)
                    {
                        n1 = ngay;
                        t1 = thang;
                        na1 = nam;
                    }
                }
            }
        }
    }
}
///===========================================
void Try(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            a[x] = i;
            d[i] = 1;
            if (x == n)
                xuat();
            else
                Try(x + 1);
            d[i] = 0;
        }
    }
}
///===========================================
///===========================================
int main()
{
    pk();
    rose();
    cin >> t;
    for (int zz = 1; zz <= t; zz++)
    {
        n1 = 1e9, t1 = 1e9, na1 = 1e9;
        dem = 0;
        memset(d, 0, sizeof(d));
        cin >> a >> b >> c;
        s = ' ' + a + b + c;
        Try(1);
        if (n1 == 1e9 || t1 == 1e9 || na1 == 1e9)
            cout << 0;
        else
        {
            cout << dem << " ";
            if (n1 < 10)
                cout << 0;
            cout << n1 << " ";
            if (t1 < 10)
                cout << 0;
            cout << t1 << " ";
            cout << na1;
        }
        cout << "\n";
    }
}
///===========================================
