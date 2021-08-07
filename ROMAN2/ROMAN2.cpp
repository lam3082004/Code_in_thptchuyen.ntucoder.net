// ROMAN2 – CHỮ SỐ LA MÃ
// Các thương nhân La Mã cổ đại hay vay tiền nhiều lần trong một ngân hàng. Mỗi lần vay, nhân viên
// ngân hàng viết giá trị của khoản vay trên một tờ ghi nợ bằng da cừu, sử dụng số La Mã. Nhưng do chi
// phí da cừu cao, việc ghi chép được thực hiện chặt chẽ và tất cả các số được ghi liên tiếp, không có dấu
// phân cách
// Tuy nhiên, khi thương nhân đến trả nợ, thì lại không thể xác định được sự phân tách các khoản vay
// thành các con số riêng rẽ. Ví dụ, nếu trên giấy nợ ghi ′XIIV′ thì có thể có nhiều cách phân tách, ví dụ
// XI + IV = 11 + 4 = 15, hoặc XII + V = 12 + 5 = 17 và nhiều cách khác
// Số La Mã chỉ có thể biểu diễn cho các số từ 1 đến 3999, giá trị được tính bằng tổng hàng nghìn cộng
// với hàng trăm, hàng chục và hàng đơn vị lần lượt theo thứ tự (ví dụ I = 1, V = 5, X = 10, L = 50, C =
// 100,D = 500, M = 1000,XL = 40, XLVIII = XL + VIII = 48, MMMCMXCIX = MMM + CM + XC +
// IX = 3999,...) Nếu ở đơn vị nào mà giá trị bằng 0 thì không lấy gì, ví dụ MXC = M + XC = 1000 +
// 0 + 90 + 0 = 1090. Quy tắc viết số La Mã được thể hiện như bảng dưới đây
// Số thập phân Hàng nghìn Hàng trăm Hàng chục Hàng đơn vị
// 0
// 1 M C X I
// 2 MM CC XX II
// 3 MMM CCC XXX III
// 4 CD XL IV
// 5 D L V
// 6 DC LX VI
// 7 DCC LXX VII
// 8 DCCC LXXX VIII
// 9 CM XC IX
// Các thương nhân tinh ranh muốn có một cách phân tách sao cho tống số tiền phải trả là nhỏ nhất.
// Input:
//  Một dòng duy nhất là chuỗi số La Mã được in trên tấm da cừu
//  Độ dài chuỗi số không quá 250
// Output:
//  Một số nguyên duy nhất là số tiền ít nhất mà số La Mã kia biểu diễn được
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 1000005
using namespace std;
ll n, t = 0, f[1005], q[200], p[200];
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    q['I'] = 1;
    p['I'] = 1;
    q['V'] = 5;
    p['V'] = 2;
    q['X'] = 10;
    p['X'] = 3;
    q['L'] = 50;
    p['L'] = 4;
    q['C'] = 100;
    p['C'] = 5;
    q['D'] = 500;
    p['D'] = 6;
    q['M'] = 1000;
    p['M'] = 7;
    cin >> s;
    n = s.size();
    s = ' ' + s;
    f[0] = 0;
    f[1] = q[s[1]];
    fo(i, 2, n) if (q[s[i]] <= q[s[i - 1]]) f[i] = f[i - 1] + q[s[i]];
    else
    {
        if (p[s[i - 1]] % 2 == 1 && p[s[i - 1]] - p[s[i]] >= -2)
            f[i] = min(f[i - 1], f[i - 2] - q[s[i - 1]]) + q[s[i]];
        else
            f[i] = f[i - 1] + q[s[i]];
    }
    cout << f[n];
}
