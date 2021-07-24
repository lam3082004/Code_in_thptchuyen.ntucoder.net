// Bin và Bon vừa học về các con số và hai cậu bé rất thích thú với trò chơi liên quan đến các số. Bộ
// đồ chơi của Bin và Bon là một bộ ảnh mà mỗi bức ảnh là một con số để Bin và Bon có thể bốc
// một bức ảnh bất kì và tập đọc số trên các bức ảnh. Cụ thể, bộ đồ chơi của hai cậu bé gồm 𝑎1 hình
// ảnh mang giá trị 1, 𝑎2 hình ảnh mang giá trị 2,…, 𝑎𝑛 hình ảnh mang giá trị 𝑛. Sau khi chơi xong
// bộ tranh ảnh và các số, Bin và Bon muốn sắp xếp gọn gàng tất cả các bức ảnh vào hộp đồ chơi.
// Mỗi cậu bé có một cách xếp gọn gàng riêng và trong đó:
//  Cách xếp của Bin: chọn một cặp (𝑙, 𝑟) mà 1 ≤ 𝑙 ≤ 𝑟 ≤ 𝑛 sau đó thực hiện xếp các bức ảnh
// có giá trị 𝑙,𝑙 + 1, … , 𝑟 vào hộp đồ chơi (mỗi giá trị 𝑥 ∈ [𝑙, 𝑟] chỉ lấy chính xác 1 bức ảnh
// mang giá trị 𝑥).
//  Cách xếp của Bon: chọn một con số mang giá trị 𝑖 (1 ≤ 𝑖 ≤ 𝑛) và một giá trị 𝑥 (𝑥 ≥ 1)
// sau đó xếp 𝑥 bức ảnh mang con số 𝑖 vào hộp đồ chơi. Bon luôn đảm bảo rằng lúc này số
// lượng bức ảnh mang con số 𝑖 không nhỏ hơn giá trị 𝑥 mà cậu bé chọn.
// Bin và Bon rất yêu thương nhau nên hai cậu bé không bao giờ tranh giành đồ chơi của nhau cũng
// như việc tranh nhau để xếp đồ chơi vào hộp, do đó cả Bin và Bon sẽ xếp đồ chơi vào hộp theo
// cách: mỗi lượt chỉ có Bin hoặc Bon thực hiện xếp đồ chơi theo cách gọn gàng vào hộp. Tất nhiên
// là Bin và Bon cũng muốn xếp đồ chơi vào hộp một cách nhanh nhất có thể nhưng lại không biết
// tính toán ra làm sao? Bạn là một người anh của Bin và Bon, bạn hãy giúp hai cậu bé đáng yêu này
// xếp toàn bộ các bức ảnh vào hộp đồ chơi sau ít lượt xếp nhất có thể.
// Input:
//  Dòng đầu chứa một số nguyên dương 𝑛 (𝑛 ≤ 5000).
//  Dòng thứ hai chứa 𝑛 số nguyên không âm 𝑎1, 𝑎2, … , 𝑎𝑛
// (0 ≤ 𝑎𝑖 ≤ 109).
// Output: In ra số lượt ít nhất có thể để có thể để xếp gọn gàng toàn bộ các bức ảnh vào hộp đồ
// chơi.
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 5;
int n, a[nmax];
int get(int l, int r)
{
    if (l > r)
        return 0;
    int minn = a[l];
    for (int i = l; i <= r; i++)
        minn = min(minn, a[i]);
    for (int i = l; i <= r; i++)
        a[i] -= minn;
    int left = l;
    int res = 0;
    for (int right = l; right <= r + 1; right++)
        if (right == r + 1 || a[right] == 0)
        {
            res += get(left, right - 1);
            left = right + 1;
        }
    return min(r - l + 1, res + minn);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << get(1, n);
}
