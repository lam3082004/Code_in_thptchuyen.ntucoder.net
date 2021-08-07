// Cho một đoạn văn bản chỉ gồm các loại kí tự latinh thường và kí tự cách trống để ngăn cách các
// từ, kí tự ‘.’ để ngăn cách các câu.
// Hãy đếm xem trong đoạn văn bản đã cho có bao nhiêu từ và bao nhiêu câu.
// Biết rằng kí tự cuối cùng của văn bản là kí tự ‘.’.
// Dữ liệu:
//  Dòng đầu tiên ghi số nguyên dương N là độ dài của xâu kí tự trong văn bản.
//  Dòng tiếp theo chứa xâu kí tự trong văn bản.
// Kết quả:
//  Dòng đầu tiên ghi ra số lượng câu trong văn bản.
//  Dòng tiếp theo ghi ra số lượng từ có trong văn bản.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
using namespace std;
string a, b, c;
ll n, dem1 = 0, dem2 = 0, m, dem3 = 0, t = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("DETU.inp", "r", stdin);
    freopen("DETU.out", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    getline(cin, b);
    getline(cin, a);
    m = a.size() - 1;
    fo(i, 0, m)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
            dem1++;
        if (a[i] >= 'a' && a[i] <= 'z' && a[i + 1] >= 'a' && a[i + 1] <= 'z')
            dem2++;
    }
    c = "";
    fo(i, 0, m) if (a[i] != ' ')
    {
        c += a[i];
        t++;
    }
    fo(i, 0, t - 1) if (c[i] != '.' && c[i + 1] == '.') dem3++;
    cout << dem3 << '\n'
         << dem1 - dem2;
}
