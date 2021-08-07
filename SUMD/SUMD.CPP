// Gọi fN là số lượng ước nguyên dương của một số nguyên dương N. Ví dụ f4 = 3 vì 4 có 3 ước
// nguyên dương là {1, 2, 4}.Cho trước hai số nguyên dương a và b (a ≤ b).
// Yêu cầu: Hãy tính và in ra giá trị fa + fa+1 + ... + fb.
// Dữ liệu
// • Gồm một dòng duy nhất chứa hai số nguyên dương a và b (1 ≤ a ≤ b ≤ 1012).
// Kết quả
// • In ra kết quả bài toán.
#include <bits/stdc++.h>
#define l2 long long
using namespace std;
l2 a, b;
l2 tong(l2 n)
{
    l2 j = n, i = 1, t = 0;

    while (j != 1)
    {
        t += (j - (l2)(n / (i + 1))) * i;
        j = n / (i + 1);
        i = n / j;
    }
    return t + n;
}
int main()
{
    cin >> a >> b;
    cout << tong(b) - tong(a - 1);
}
