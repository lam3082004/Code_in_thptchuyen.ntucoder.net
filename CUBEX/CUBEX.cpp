// CUBEX - Lăn hộp
// Tại kì thi Olympic Tin học Sinh viên 2019 diễn ra ở Đại học Bách khoa – Đại học Đà Nẵng, ngoài các
// phần thi OLP và ICPC, năm nay BTC có tổ chức thêm trò chơi vận động cho các thí sinh. Trò chơi đó
// là “Lăn hộp”.
// Có một phòng kích thước sàn hình chữ nhật m × n. Trong góc phòng có một hộp rất nặng hình lập
// phương kích thước cạnh là 1 đơn vị. Ở mặt trên cùng của hộp có chữ OLP sơn đỏ. Cần chuyển hộp
// từ góc hiện tại sang góc đối diện trong phòng.
// Do hộp nặng nên người ta chuyển bằng cách lăn hộp theo một cạnh nào đó ở mặt dưới. Mỗi lần lăn
// thì một mặt bên cạnh nào đó sẽ trở thành mặt dưới (tiếp xúc với sàn). Do hộp nặng nên người ta
// mong muốn tìm cách chuyển có số lần lăn ít nhất.
// Tuy nhiên, do mặt trên ban đầu có chữ OLP sơn đỏ và mỗi lần mặt này tiếp xúc với sàn sẽ để lại vết
// không đẹp, nên trong số các phương án chuyển ít lần lăn nhất, người ta sẽ chọn phương án có số lần
// “mặt có chữ OLP sơn đỏ tiếp xúc với sàn” là ít nhất.
// Yêu cầu: Hãy xác định số lần ít nhất mà mặt OLP sơn đỏ tiếp xúc với sàn.
// Input: Trên một dòng có 2 số m, n là kích thước mặt sàn của phòng (1 ≤ n, m ≤ 109
// ).
// Output: Số lần ít nhất mà mặt OLP tiếp xúc với sàn trong phương án chuyển tối ưu
#include <bits/stdc++.h>
#define ll long long
#define task "test"
using namespace std;

void Init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, m;

void Solve()
{
    cin >> n >> m;
    if (n == 2 || m == 2 || n + m == 2)
        cout << 0;
    else if (n == 1 || m == 1)
        cout << (max(n, m) + 1) / 4;
    else
        cout << 1;
}

int main()
{
    Init();
    Solve();
}
