// Cho n số a[1],a[2],...,a[n] và 1 số nguyên dương k. Đếm số dãy con (không nhất thiết phải liên tiếp) có trung bình cộng lớn hơn hoặc bằng k.

// Input:
// Dòng thứ nhất ghi 2 số n,k (0 ≤n<=40, k<=10^9).

// Dòng tiếp theo gồm m*n phần tử a[1], a[2], ... , a[n] (a[i]<=10^9) .

// Output:
// Gồm một số duy nhất là kết quả bài toán.
#include <bits/stdc++.h>
#define endl '\n'

#define for (i, a, b, x) for (auto i = a; (x > 0) ? (i <= b) : (i >= b); i += x)
using namespace std;

int n, arr[41];
long long output, sum, k;

void backtrack_Solve(int count, int start)
{
    for (i, start, n, 1)
    {
        sum += arr[i];
        if (sum >= count * k)
        {
            output += pow(2, n - i + 1) - 1;
            sum -= arr[i];
            break;
        }
        backtrack_Solve(count + 1, i + 1);
        sum -= arr[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (i, 1, n, 1)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n + 1);
    backtrack_Solve(1, 1);
    cout << output << endl;
    return 0;
}
