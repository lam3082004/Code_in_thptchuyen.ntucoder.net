// Cho 4 điểm A, B. C, D trong hệ trục tọa độ Oxy. Kiểm tra xem ABCD có làm thành một hình thang hay không?

// Dữ liệu nhập:

// - Dòng 1 ghi tọa độ xA,yA của điểm A

// - Dòng 2 ghi tọa độ xB,yB của điểm B

// - Dòng 3 ghi tọa độ xC,yC của điểm C

// - Dòng 4 ghi tọa độ xD,yD của điểm D

// Dữ liệu xuất:

// - YES nếu ABCD là hình thang, NO nếu ngược lại
using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 100005
const ll mod = 1e9 + 7;
struct point
{
    ll x, y;
};
point A, B, C, D;
int main()
{
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    if (A.x == B.x && B.x == C.x && C.x == D.x || A.y == B.y && B.y == C.y || C.y == D.y)
        cout << "NO";
    else if ((B.x - A.x) * (C.y - D.y) == ((B.y - A.y) * (C.x - D.x)))
        cout << "YES";
    else if ((A.x - C.x) * (D.y - B.y) == (A.y - C.y) * (D.x - B.x))
        cout << "YES";
    else if ((A.x - C.x) * (B.y - C.y) == (A.y - D.y) * (C.x - B.x))
        cout << "YES";
    else
        cout << "NO";
}
