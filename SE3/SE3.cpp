// Phần tử thứ s
// Cho một dãy số gồm vô hạn các số nguyên đôi một khác nhau. Các phần tử của dãy số này có tính chất rất đặc biệt:

// Tất cả các phần tử của dãy số đều là bội của 3.
// Nếu cộng thêm 1 thì các phần tử này sẽ trở thành số chính phương.
// Yêu cầu: Hãy tìm phần tử thứ s của dãy số sau khi đã được sắp xếp tăng dần.

// Dữ liệu: Một dòng duy nhất đưa ra số nguyên s, k. (1<=s,k<=10^18)

// Kết quả: Đưa ra  một dòng duy nhất là  số nguyên duy nhất là kết quả cho bài toán chia dư cho k.
#include <bits/stdc++.h>
using namespace std;
long long s, k, t;
long long nhan(long long a, long long b, long long c)
{
    if (b == 0)
        return 0;
    long long t = nhan(a, b / 2, c);
    t = (t + t) % c;
    if (b % 2 == 1)
        t = (t + a) % c;
    return t;
}
int main()
{
    cin >> s >> k;
    if (s % 2 == 0)
    {
        t = s / 2 * 3 - 1;
        cout << (nhan(t % k, t % k, k) + k - 1) % k;
    }
    if (s % 2 == 1)
    {
        t = (s - 1) / 2 * 3 + 1;
        cout << (nhan(t % k, t % k, k) + k - 1) % k;
    }
}
