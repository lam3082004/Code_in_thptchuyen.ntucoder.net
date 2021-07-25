// Trên mặt bảng ghi số 1. Mỗi một lần biến đổi, Bờm thực hiện một trong hai phép toán sau đây đối với
// số viết trên bảng: Hoặc là cộng thêm nó với 1, hoặc là đổi chỗ các chữ số của nó (Nhưng không bao
// giờ có số 0 ở vị trí thứ nhất tính từ trái sang phải). Sau đó xóa số đang có trên bảng và viết kết quả thu
// được lên bảng.
// Yêu cầu: Cho trước một số nguyên dương, hãy tính xem sau ít nhất bao nhiêu lần biến đổi bắt đầu từ
// số 1 Bờm sẽ thu được số đã cho.
// Input:
//  Dòng đầu tiên chứa số nguyên T (1 ≤ T < 104

// ) là số lượng test trong file.
//  Dòng thứ i trong T dòng tiếp theo chứa số nguyên Ni (2 ≤ Ni < 109

// , 1 ≤ i ≤ T).

// Output:
//  Gồm T số, mỗi số trên một dòng, trong đó số trên dòng thứ i là số lần biến đổi ít nhất cần thực
// hiện để thu được trên bảng số Ni
#include <bits/stdc++.h>
using namespace std;
const int nmax = 2e5 + 5;
int n, ans, f[10];
int cs(int n)
{
    int dem = 0;
    while (n > 0)
    {
        dem++;
        n /= 10;
    }
    return dem;
}
int tong(int n)
{
    int res = 0, m = n;
    if (n % 10 != 0)
        res--;
    if (n / f[cs(n) - 1] == 1)
    {
        while (n > 1)
        {
            res += (n % 10) + (n % 10 > 0);
            n /= 10;
        }
        return res;
    }
    bool check = false;
    while (n > 0)
    {
        res += (n % 10) + (n % 10 > 0);
        n /= 10;
        if (n % 10 == 1)
            check = true;
    }
    return res - check - 1;
}
int cal(int n)
{
    long long res = 0;
    for (int i = 1; i <= n; i++)
        res = res + 9 * i + i - 1;
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    int t;
    cin >> t;
    f[0] = 1;
    for (int i = 1; i <= 9; i++)
        f[i] = f[i - 1] * 10;
    while (t--)
    {
        cin >> n;
        if (n < 10)
        {
            cout << n - 1 << '\n';
            continue;
        }
        if (n % f[cs(n) - 1] == 0)
            cout << cal(cs(n - 1) - 1) + tong(n - 1) + 1 << '\n';
        else
            cout << cal(cs(n) - 1) + tong(n) << '\n';
    }
}
