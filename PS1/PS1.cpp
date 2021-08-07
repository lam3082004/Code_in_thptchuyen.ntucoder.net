// Phân số
// Với hai phân số x
// y
// và u
// v
// người ta tạo ra phân số x+u
// y+v
// . Bắt đầu từ hai phân số 0
// 1
// và 1
// 0
// , tiến hành tao ra

// các phân số.
// Lượt đầu tiên tạo được các phân số 0
// 1
// ;
// 1
// 1
// ;
// 1
// 0
// ;
// Lượt thứ hai tạo được các phân số 0
// 1
// ;
// 1
// 2
// ;
// 1
// 1
// ;
// 2
// 1
// ;
// 1
// 0
// ;

// ...
// Việc tạo các phân số có thể biểu diễn bằng cây như sau:

// Nếu coi phân số 1
// 1
// là nút gốc, với mỗi phân số có thể mô tả bằng đường đi từ nút gốc đến phân số

// đó. Ví dụ, phân số 8
// 5
// được mô tả bằng đường đi RLRL.

// Yêu cầu: Cho một phân số p
// q
// , hãy tìm mô tả đường đi cho phân số đó.

// Input
// - Gồm nhiều dòng, mỗi dòng chứa hai số nguyên dương p, q tương ứng với một bộ dữ liệu.
// Dữ liệu đảm bảo có nghiệm. Kết thúc file là hai số nguyên 1, 1.
// Output
// - Gồm nhiều dòng, mỗi dòng chứa một xâu là mô tả đường đi cho phân số đó.
#include <bits/stdc++.h>
#define task "PS"
using namespace std;

class Nn
{
public:
    long long x, y;
    Nn operator+(Nn b)
    {
        Nn c;
        c.x = x + b.x;
        c.y = y + b.y;
        return c;
    }
    friend bool operator<(Nn a, Nn b)
    {
        if (b.y == 0)
            return 1;
        if (a.y == 0)
            return 0;
        long long uc = __gcd(a.y, b.y), A = a.x * b.y / uc, B = b.x * a.y / uc;
        return (A < B);
    }
    void operator=(Nn b)
    {
        x = b.x;
        y = b.y;
    }
};

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
#endif // ONLINE
}

void Solve()
{
    do
    {
        Nn a = {0, 1}, b = {1, 0}, c = {1, 1}, d;
        cin >> d.x >> d.y;
        if (d.x == 1 && d.y == 1)
            return;

        while (c.x != d.x && c.y != d.y)
        {
            if (d < c)
            {
                cout << 'L';
                b = c;
                c = (a + c);
            }
            else
            {
                cout << 'R';
                a = c;
                c = (c + b);
            }
        }
        cout << endl;
    } while (1);
}

int main()
{
    Init();
    Solve();
}
