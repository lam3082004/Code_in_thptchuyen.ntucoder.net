// Cho dãy số nguyên A độ dài N. Đếm xem có bao nhiêu dãy con liên tiếp từ l đến r thỏa mãn
// điều kiện sau: gọi k là số nhỏ nhất trong dãy từ l đến r thì các số k, k + 1, k + 2,...,k + r − l xuất
// hiện đúng một lần.
// Dữ liệu
// • Dòng đầu tiên chứa số nguyên dương N.
// • Dòng thứ 2 chứa N số nguyên Ai
// .

// Kết quả
// • In ra một số nguyên duy nhất là kết quả cần tìm.
#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
int n, a[100005], x, l, r, dem = 0;
map<int, int> f;
int main()
{
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    fo(i, 1, n)
    {
        l = a[i];
        r = a[i];
        fo(j, i, n)
        {
            f[a[j]]++;
            l = min(l, a[j]);
            r = max(r, a[j]);
            if (f[a[j]] == 1)
            {
                if (r - l == j - i)
                    dem++;
            }
            else
            {
                x = j;
                break;
            }
            x = n;
        }
        fo(j, i, x) f[a[j]] = 0;
    }
    cout << dem;
}
