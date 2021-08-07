// Cho bảng A có kích thước R × C ô. Mỗi ô của bảng A có chứa một số nguyên, nghĩa là bảng A
// gồm R hàng, mỗi hàng gồm C số nguyên. Hai ô được gọi là kề nhau nếu hai ô có chung cạnh. Ví dụ,
// trong bảng sau,

// 0 1 2
// 3 4 5
// 6 7 8

// Ô chứa số 0 (gọi tắt là ô số 0) và ô số 1 kề nhau, ô số 4 và ô số 5 kề nhau, nhưng ô số 0 và ô số 4 không
// kề nhau, ô số 2 và ô số 6 không kề nhau.
// Nhiệm vụ của bạn là tìm một dãy các phép biến đổi để biến bảng A thành một bảng chứa toàn
// số 0. Ở mỗi phép biến đổi, bạn được chọn hai ô kề nhau và hoặc cùng tăng số ở mỗi ô lên 1 đơn vị, hoặc
// cùng giảm số ở mỗi ô xuống 1 đơn vị.

// Dữ liệu
// • Dòng đầu tiên chứa hai số nguyên R và C (1 ≤ R, C ≤ 30) lần lượt là số hàng và số cột của bảng
// A.
// • R dòng tiếp theo, mỗi dòng gồm C số nguyên thuộc đoạn từ -20 đến 20 mô tả bảng A.
// Dữ liệu vào đảm bảo bảng A chứa ít nhất một số khác 0.
// Kết quả
// • Nếu tồn tại một dãy các phép biến đổi để biến bảng A thành một bảng chứa toàn số 0, in ra "YES",
// nếu không, in ra "NO".
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1005;
long long a[nmax][nmax], m, n, ans, tmp;
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            ans += a[i][j];
        }
    if (ans % 2 == 1)
        cout << "NO" << endl;
    else
    {
        tmp = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if ((i + j) % 2 == (m + n) % 2)
                    tmp = tmp - a[i][j];
                else
                    tmp = tmp + a[i][j];
        if (tmp == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
