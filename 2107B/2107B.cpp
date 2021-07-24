/// hhoangcpascal

#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> a >> b >> c >> d;

    int ans = 0;
    while (a * 60 + b <= c * 60 + d)
    {
        if (b == 30)
            ++ans;
        if (b == 0)
        {
            if (a == 0)
                ans += 12;
            if (a <= 12)
                ans += a;
            if (a > 12)
                ans += a - 12;
        }

        ++b;
        if (b == 60)
            ++a, b = 0;
    }

    cout << ans;

    return 0;
}
