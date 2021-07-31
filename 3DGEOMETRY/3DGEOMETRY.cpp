// Cho 3 điểm A, B, C trong không gian ba chiều. Tính khoảng cách từ điểm A đến đường thẳng
// BC.
// Dữ liệu
// Dòng đầu tiên chứa T(1 ≤ T ≤ 104

// ) tương ứng với số bộ dữ liệu. Mỗi bộ dữ liệu gồm 9 số nguyên:

// • 3 số nguyên đầu tiên xA, yA, zA tương ứng với tọa độ điểm A.
// • 3 số nguyên tiếp theo xB, yB, zB tương ứng với tọa độ điểm B.
// • 3 số nguyên cuối cùng xC, yC, zC tương ứng với tọa độ điểm C.
// Kết quả
// • In ra T dòng, mỗi dòng tương ứng với khoảng cách từ điểm A đến đường thẳng BC, làm
// tròn chính xác đến 2 chữ số thập phân.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    double i, xa, ya, za, xb, yb, zb, xc, yc, zc, t, ab, bc, ca, p, s, k;
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        cin >> xa >> ya >> za >> xb >> yb >> zb >> xc >> yc >> zc;
        ab = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya) + (zb - za) * (zb - za));
        bc = sqrt((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb) + (zc - zb) * (zc - zb));
        ca = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc) + (za - zc) * (za - zc));
        p = (ab + bc + ca) / 2;
        s = sqrt(p * (p - ab) * (p - bc) * (p - ca));
        k = (s / bc) * 2;
        cout << fixed << setprecision(2) << k << endl;
    }
}
