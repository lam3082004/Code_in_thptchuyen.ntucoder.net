// Phần tử thứ s
// Cho một dãy số gồm vô hạn các số nguyên đôi một khác nhau. Các phần tử của dãy số này có tính chất rất đặc biệt:

// Tất cả các phần tử của dãy số đều là bội của 3.
// Nếu cộng thêm 1 thì các phần tử này sẽ trở thành số chính phương.
// Yêu cầu: Hãy tìm phần tử thứ s của dãy số sau khi đã được sắp xếp tăng dần.
#include <bits/stdc++.h>
#define l long long
using namespace std;
l s, k;
l nhan(l x, l y, l z)
{
    if (y == 0)
        return 0;
    else
    {
        l q = nhan(x, y / 2, z);
        q += q;
        q %= z;
        if (y % 2 == 0)
            return q;
        else
            return (q + x) % z;
    }
}
l st()
{
    if (s % 2 == 0)
    {
        return nhan(3 * (s / 2), 3 * (s / 2) - 2, k);
    }
    else
    {
        return nhan(3 * (s / 2), 3 * (s / 2) + 2, k);
    }
}
int main()
{
    cin >> s >> k;
    cout << st();
}
