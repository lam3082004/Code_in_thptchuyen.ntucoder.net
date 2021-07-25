// Yêu cầu: Cho tọa độ (𝑇𝑥, 𝑇𝑦) và xâu ký tự 𝑆 chỉ gồm các ký tự ∈ {R,L,U,D} và dấu hỏi chấm “?”. Hãy thay
// tất cả các dấu ?, mỗi dấu ? thay bởi một ký tự ∈ {R,L,U,D} để được một chuỗi lệnh di chuyển có thứ tự
// từ điển nhỏ nhất đưa xe tới tọa độ (𝑇𝑥, 𝑇𝑦) sau khi thực hiện toàn bộ chuỗi lệnh.
// Dữ liệu: Vào từ file văn bản JOURNEY.INP
//  Dòng 1 chứa hai số nguyên 𝑇𝑥, 𝑇𝑦 cách nhau bởi dấu cách (−109 ≤ 𝑇𝑥, 𝑇𝑦 ≤ 109
// )
//  Dòng 2 chứa xâu 𝑆 có độ dài không quá 106 ký tự, tất cả các ký tự trong 𝑆 thuộc tập {R,L,U,D,?}
// Kết quả: Ghi ra file văn bản JOURNEY.OUT một xâu ký tự biểu diễn chuỗi lệnh di chuyển tìm được, trong
// trường hợp không thể xây dựng được chuỗi lệnh theo yêu cầu đề bài, in ra xâu IMPOSSIBLE
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
ll n, dem = 0, x = 0, y = 0, a, b, k, t = 0;
string s, q;
int main()
{
    cin >> a >> b;
    cin >> s;
    n = s.size();
    s = ' ' + s;
    fo(i, 1, n)
    {
        if (s[i] == 'U')
            y++;
        if (s[i] == 'D')
            y--;
        if (s[i] == 'R')
            x++;
        if (s[i] == 'L')
            x--;
        if (s[i] == '?')
            dem++;
    }
    k = abs(x - a) + abs(y - b);
    if ((dem - k) % 2 != 0 || dem < k)
        cout << "IMPOSSIBLE";
    else
    {
        q = "";
        while (a < x)
            a++, q += 'L';
        while (b < y)
            b++, q += 'D';
        while (a > x)
            a--, q += 'R';
        while (b > y)
            b--, q += 'U';
        dem -= q.size();
        fo(i, 1, dem / 2)
            q += 'D',
            q += 'U';
        sort(q.begin(), q.end());
        fo(i, 1, n) if (s[i] != '?') cout << s[i];
        else
        {
            cout << q[t];
            t++;
        }
    }
}
