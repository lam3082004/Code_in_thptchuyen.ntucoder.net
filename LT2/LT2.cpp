// Mọi số nguyên dương a đều có thể viết được dưới dạng lũy thừa bậc n của số nguyên dương b (với n là số tự nhiên). Chẳng hạn: 27 = 33; 8 = 81. Một số nguyên dương a có thể có nhiều cách biểu diễn dưới dạng một lũy thừa, chẳng hạn: 81 = 811 = 92 = 34.

// Yêu cầu: Cho trước 3 số nguyên dương a; b; c. Gọi x là tích của 3 số a; b và c. Hỏi trong các cách viết số x thành một lũy thừa bậc n của một số nguyên dương thì số mũ n lớn nhất bằng bao nhiêu?

// Dữ liệu vào:

// - Một dòng gồm 3 số a; b; c mỗi số nằm trên một dòng (a; b; c <= 1012).

// Dữ liệu ra:

// - Ghi ra số n thỏa mãn yêu cầu trên.
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
using namespace std;
ll a, b, c, j = 0, x, r[1005];
map<ll, ll> f;
int main()
{
    cin >> a >> b >> c;
    fo(i, 2, sqrt(a)) if (a % i == 0) while (a % i == 0)
    {
        r[++j] = i;
        a /= i;
    }
    if (a > 1)
        r[++j] = a;
    fo(i, 2, sqrt(b)) if (b % i == 0) while (b % i == 0)
    {
        r[++j] = i;
        b /= i;
    }
    if (b > 1)
        r[++j] = b;
    fo(i, 2, sqrt(c)) if (c % i == 0) while (c % i == 0)
    {
        r[++j] = i;
        c /= i;
    }
    if (c > 1)
        r[++j] = c;
    sort(r + 1, r + 1 + j);
    if (r[j] == r[1])
    {
        cout << j;
        return 0;
    }
    f[r[1]] = 1;
    fo(i, 2, j)
    {
        if (r[i] != r[i - 1])
            f[r[i]] = 1;
        else
            f[r[i]]++;
    }
    fo(i, 1, j - 1) if (r[i] != r[i + 1]) x = __gcd(x, __gcd(f[r[i]], f[r[i + 1]]));
    cout << x;
}
