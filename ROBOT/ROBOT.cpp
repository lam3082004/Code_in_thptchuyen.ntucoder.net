// Công ty Long Vân đang sản xuất robot vận chuyển hàng hóa tự động. Để làm việc đó, công
// ty tiến hành huấn luyện các robot trên một địa hình được chia thành một lưới các ô vuông
// gồm m dòng (đánh số từ 1 đến m theo chiều từ trên xuống dưới) và n cột (đánh số từ 1 đến n
// theo chiều từ trái sang phải). Ô giao giữa dòng i, cột j được gọi là ô (i, j), có độ cao là
// hij (|hij| ≤ 109

// ) và có điểm thưởng là sij (|sij| ≤ 109
// ).

// Trang 3/3

// Một thử nghiệm cho robot như sau: Đặt robot ở một ô nào đó, điểm thưởng của robot bằng
// điểm thưởng tại ô được đặt, mỗi bước robot được phép dừng lại hoặc di chuyển sang ô chung
// cạnh có độ cao cao hơn độ cao của ô hiện tại. Khi robot di chuyển sang ô nào đó, điểm thưởng
// của robot được cộng một lượng là điểm thưởng tại ô đó.
// Yêu cầu: Cho địa hình thử nghiệm robot, hãy tìm vị trí đặt robot và cách di chuyển của robot để
// khi robot dừng lại, tổng điểm thưởng của robot là lớn nhất.
// Dữ liệu: Vào từ file văn bản ROBOT.INP:
// - Dòng đầu chứa hai số nguyên dương m, n;
// - Tiếp theo là m dòng mô tả độ cao của các ô trên địa hình, dòng thứ i chứa n số
// hi1, hi2, ... , hin;
// - Tiếp theo là m dòng mô tả điểm thưởng của các ô trên địa hình, dòng thứ i chứa n số
// si1, si2, ... , sin.
// Kết quả: Ghi ra file văn bản ROBOT.OUT gồm một dòng chứa một số là tổng điểm nhiều nhất
// mà robot có thể đạt được.
// Ràng buộc:
//  Có 20% số test ứng với 20% số điểm của bài có m = 1; n ≤ 103
// ;
//  Có 20% số test khác ứng với 20% số điểm của bài có m = 1; n ≤ 105
// ;
//  Có 20% số test khác ứng với 20% số điểm của bài có m × n ≤ 103 và sij = 1;
//  Có 20% số test khác ứng với 20% số điểm của bài có m × n ≤ 105 và sij = 1;
//  Có 20% số test khác ứng với 20% số điểm của bài có m × n ≤ 105
// .
#include <bits/stdc++.h>
#define LL long long
using namespace std;

void Init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const LL oo = 1e18;
class Sq
{
public:
    LL h, s, f = 0;
    bool c = 1;
} * *A;
int n, m;

void Enter()
{
    cin >> n >> m;
    A = new Sq *[n + 2];
    for (int i = 0; i <= n + 1; ++i)
        A[i] = new Sq[m + 2];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> A[i][j].h;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> A[i][j].s;
    for (int i = 1; i <= n; ++i)
    {
        A[i][0].h = -oo;
        A[i][m + 1].h = -oo;
    }
    for (int i = 1; i <= m; ++i)
    {
        A[0][i].h = -oo;
        A[n + 1][i].h = -oo;
    }
}

LL DFS(LL i, LL j, LL h)
{
    if (A[i][j].h <= h)
        return 0;
    if (A[i][j].c == 0)
        return A[i][j].f;
    A[i][j].c = 0;
    LL k = A[i][j].h;
    A[i][j].f = max(max(DFS(i - 1, j, k), DFS(i + 1, j, k)), max(DFS(i, j - 1, k), DFS(i, j + 1, k))) + A[i][j].s;
    return A[i][j].f;
}

void Solve()
{
    LL res = -oo;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            res = max(res, DFS(i, j, -oo));
    cout << res;
}

int main()
{
    Init();
    Enter();
    Solve();
}
