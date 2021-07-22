// Cho hai số nguyên n và k. Chúng ta xét các số nguyên từ 1 đến k
// n

// Với mỗi số x, chúng ta loại hết các số k trong cách phân tích ra thừa số nguyên tố của số x để thu được
// 1 số mới. Ví dụ với k = 2:
//  Với số 360, phân tích thành thừa số nguyên tố được 360 = 2
// 3 × 3
// 2 × 5, sau khi loại bỏ tất cả

// các thừa số 2, thu được số 3

// 2 × 5 = 45

//  Với số 15, phân tích thành thừa số nguyên tố được 15 = 3 × 5, số này không chứa thừa số 2,
// nên ta thu được số 15
//  Với các số 2, 4 hay 8, tương tự cách trên, ta sẽ thu được số 1
// Sau khi xoá hết các thừa số k ở mỗi số trong các số từ 1 đến k
// n
// , hỏi tổng các số sau khi xoá là bao

// nhiêu?
// Do kết quả rất lớn nên chỉ cần in ra phần dư khi chia cho 1012 + 7
// Input:
//  Dòng đầu tiên là T (T ≤ 10) − số test
//  T dòng tiếp theo, mỗi dòng chứa hai số n, k (0 ≤ n ≤ 1018

// , 2 ≤ k ≤ 109
// )

// Output:
//  In ra T dòng, mỗi dòng là kết quả tương ứng
// Giới hạn:
//  Subtask 1 (20%): k = 2, n ≤ 20
//  Subtask 2 (40%): k = 2, n ≤ 1018
//  Subtask 3 (40%): Ràng buộc gốc
#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 5;
const long long mod = 1e12 + 7;
long long n, k;
int t;
long long nhan(long long x, long long y, long long z)
{
    x = x % z;
    y = y % z;
    long long q = (long double)x * y / z;
    long long m = ((x * y - q * z) % z + z) % z;
    return m;
}
long long mu(long long a, long long b, long long mod)
{
    if (b == 0)
        return 1;
    long long tmp = mu(a, b / 2, mod);
    tmp = nhan(tmp, tmp, mod);
    if (b & 1)
        tmp = nhan(tmp, a, mod);
    return tmp;
}
long long get1(long long k, long long n, long long mod)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return mu(k, 1, mod);
    long long tmp = get1(k, n / 2, mod);
    tmp = (tmp + nhan(tmp, mu(k, n / 2, mod), mod)) % mod;
    if (n & 1)
        tmp = (tmp + mu(k, n, mod)) % mod;
    return tmp;
}
long long get2(long long k, long long n, long long mod)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return mu(k, 2, mod);
    long long tmp = get2(k, n / 2, mod);
    tmp = (tmp + nhan(tmp, mu(k, n - (n % 2 == 1), mod), mod)) % mod;
    if (n & 1)
        tmp = (tmp + mu(k, 2 * n, mod)) % mod;
    return tmp;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (n == 0)
        {
            cout << 1 << '\n';
            continue;
        }
        if (n == 1)
        {
            if (k % 2 == 0)
                cout << (nhan(k / 2, k - 1, mod) + 1) % mod << '\n';
            else
                cout << (nhan(k, (k - 1) / 2, mod) + 1) % mod << '\n';
            continue;
        }
        long long res;
        if (k % 2 == 0)
            res = nhan(nhan(mu(k, n - 1, mod), k / 2, mod), mu(k, n, mod) + 1, mod);
        else
            res = nhan(mu(k, n, mod), (nhan(get1(k, n - 1, mod), k / 2, mod) + k / 2 + 1) % mod, mod);
        long long res2;
        if (k % 2 == 0)
            res2 = nhan(k - 1, (nhan(get1(k, n - 2, mod), k / 2, mod) + k / 2 + nhan(get2(k, n - 2, mod), nhan(k, k / 2, mod), mod) + nhan(k, k / 2, mod) + 1) % mod, mod);
        else
            res2 = nhan((k - 1) / 2, get1(k, n - 1, mod) + get2(k, n - 1, mod) + 2, mod);
        cout << (res - res2 + mod) % mod << '\n';
    }
}
