// Mr Bin và Mr Bon cùng nhau chơi một trò chơi. Mr Bon đưa ra 2 chuỗi kí tự s và t gồm các chữ
// cái Latinh thường có độ dài bằng nhau và yêu cầu Mr Bin biến đổi 2 chuỗi kí tự này thành cùng
// một chuỗi với số lần biến đổi ít nhất và đưa ra chuỗi kí tự thu được sau khi biến đổi. Với mỗi
// phép biến đổi Mr Bin được phép đổi một kí tự thuộc một trong hai chuỗi thành kí tự ở liền trước
// hoặc liền sau nó trong bảng chữ cái. Bảng chữ cái tiếp nối theo vòng tròn nên Mr Bin cũng có
// thể đổi „a‟ thành „z‟ hoặc „z‟ thành „a‟. Mr Bin đang rất bối rối, bạn hãy giúp Mr Bin nhé!
// Dữ liệu:
//  Mỗi test bắt đầu bằng một thẻ “[CASE]”, các test cách nhau bởi một dòng trắng. Thẻ
// “[END]” báo hiệu kết thúc file input.
//  Dòng tiếp theo cho chuỗi s
//  Dòng tiếp theo cho chuỗi t
// Kết quả:
//  Với mỗi test in ra chuỗi kí tự tìm được. Nếu có nhiều chuỗi kí tự thì đưa ra chuỗi có thứ
// tự từ điển nhỏ nhất
// Giới hạn:
//  Chuỗi s và t có độ dài không vượt quá 50 kí tự
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
string s, t, n;
ll a[55], b[55], c[55];
int main()
{
    while (cin >> n)
    {
        if (n == "[CASE]")
        {
            cin >> s >> t;
            ll m = s.size() - 1;
            fo(i, 0, m)
            {
                a[i] = min(s[i] - 'a', 'a' + 26 - s[i]);
                b[i] = min(t[i] - 'a', 'a' + 26 - t[i]);
                c[i] = abs(s[i] - t[i]);
                if (c[i] < a[i] + b[i])
                    cout << min(s[i], t[i]);
                else
                    cout << 'a';
            }
            cout << '\n';
        }
        if (n == "[END]")
            return 0;
    }
}
