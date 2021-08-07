// Hai bạn học sinh trong lúc nhàn rỗi nghĩ ra trò chơi sau đây. Mỗi bạn chọn trước
// một dãy số gồm n số nguyên. Giả sử dãy số mà bạn thứ nhất chọn là:b1, b2, ..., bn
// còn dãy số mà bạn thứ hai chọn làc1, c2, ..., cn.. Mỗi lượt chơi mỗi bạn đưa ra một
// số hạng trong dãy số của mình. Nếu bạn thứ nhất đưa ra số hạng bi (1 ≤ i ≤ n), còn
// bạn thứ hai đưa ra số hạng cj (1 ≤ j ≤ n) thì giá của lượt chơi đó sẽ là |bi+cj
// |.
// Ví dụ: Giả sử dãy số bạn thứ nhất chọn là 1, -2; còn dãy số mà bạn thứ hai chọn là
// 2, 3. Khi đó các khả năng có thể của một lượt chơi là (1, 2), (1, 3), (-2, 2), (-2, 3).
// Như vậy, giá nhỏ nhất của một lượt chơi trong số các lượt chơi có thể là 0 tương
// ứng với giá của lượt chơi (-2, 2).
// Yêu cầu
// Hãy xác định giá nhỏ nhất của một lượt chơi trong số các lượt chơi có thể.
// Dữ liệu:
//  Dòng đầu tiên chứa số nguyên dương n (n ≤ 105
// )
//  Dòng thứ hai chứa dãy số nguyên b1, b2, ..., bn (|bi
// | ≤ 109
// , i=1, 2, ..., n)

//  Dòng thứ ba chứa dãy số nguyên c1, c2, ..., cn (|ci
// | ≤ 109
// , i=1, 2, ..., n)
//  Hai số liên tiếp trên một dòng được ghi cách nhau bởi dấu cách.
// Kết quả:
//  Ghi ra giá nhỏ nhất tìm được.
// Ràng buộc
//  60% số tests ứng với 60% số điểm của bài có 1 ≤ n ≤ 1000.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define nmax 100005
using namespace std;
ll n, l, r, t = 0, k = 1e9, b[nmax], c[nmax], minn = 2e9;
int main()
{
    cin >> n;
    fo(i, 1, n) cin >> b[i], k = min(k, abs(b[i]));
    fo(i, 1, n)
    {
        cin >> c[i];
        if (c[i] == 0)
            t = 1;
    }
    sort(b + 1, b + 1 + n);
    sort(c + 1, c + 1 + n);
    fo(i, 1, n)
    {
        l = 1, r = n;
        if (c[i] != 0)
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                minn = min(minn, abs(c[i] + b[mid]));
                if (c[i] > 0)
                {
                    if (b[mid] >= 0)
                        r = mid - 1;
                    else if (abs(b[mid] >= c[i]))
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
                if (c[i] < 0)
                {
                    if (b[mid] <= 0)
                        l = mid + 1;
                    else if (b[mid] >= abs(c[i]))
                        r = mid - 1;
                    else
                        l = mid + 1;
                }
            }
    }
    if (t == 1)
        minn = min(minn, k);
    cout << minn;
}
