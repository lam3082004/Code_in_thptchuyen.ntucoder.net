// Bạn tham gia một trò chơi nhảy bước với luật chơi như sau: Ban đầu bạn ở tọa độ 0 và là lượt
// chơi 0, ở lượt chơi thứ i bạn nhảy một bước sang phải hoặc sang trái với độ dài bằng i. Bạn hãy tính
// toán xem mình cần tối thiếu bao nhiêu lượt chơi để đến được điểm X cho trước.
// Dữ liệu
// • Dòng đầu tiên: chứa số nguyên dương Q là số truy vấn (1 ≤ Q ≤ 105
// ).
// • Q dòng tiếp theo: mỗi dòng chứa một số nguyên X (|X| ≤ 109
// ).
// Kết quả
// • Gồm Q dòng, mỗi dòng chứa kết quả của một truy vấn.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
using namespace std;
ll q, x, l, r, k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    while (q--)
    {
        cin >> x;
        x = abs(x);
        l = 0, r = 100000;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (mid * (mid + 1) / 2 >= x)
            {
                k = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if (x % 2 == 0)
        {
            fo(i, 0, 3) if (((k + i) * (k + i + 1) / 2) % 2 == 0)
            {
                cout << k + i << '\n';
                break;
            }
        }
        else
        {
            fo(i, 0, 3) if (((k + i) * (k + i + 1) / 2) % 2 == 1)
            {
                cout << k + i << '\n';
                break;
            }
        }
    }
}
