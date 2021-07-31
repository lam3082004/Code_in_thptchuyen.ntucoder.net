// Cho một mảng a[n] gồm n phần tử đôi một khác nhau. Gọi M1
// , M2
// là giá trị nhỏ
// nhất và giá trị nhỏ kế tiếp nó trong đoạn [L; R] với 1 ≤ L < R ≤ n. Ta quy ước ∧ là phép
// toán AND bit, ∨ là phép toán OR bit, ⊕ là phép toán XOR bit giữa hai số nguyên.
// Đặt Si = ((M1 ⋀ M2

// )⨁(M1⋁M2

// ))⋀(M1 ⊕ M2

// ) với đoạn [L; R] nào đó.

// Yêu cầu: Tìm giá trị lớn nhất của Si với mọi đoạn [L; R].
// Dữ liệu: Vào từ file văn bản MAXBIT.INP:
// - Dòng đầu chứa số nguyên n là số phần tử của mảng;
// - Dòng thứ hai chứa các số nguyên a1
// , a2
// , ... an
// (0 ≤ ai ≤ 109
// ).

// Kết quả: Ghi ra file văn bản MAXBIT.OUT một số nguyên duy nhất là kết quả của
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1000005
using namespace std;
ll n, a[nmax], l[nmax], r[nmax], kq = 0;
ll ok(ll a, ll b)
{
    return ((a & b) ^ (a | b)) & (a ^ b);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
            cin >>
        a[i];
    fo(i, 1, n)
    {
        l[i] = i - 1;
        while (l[i] > 0 && a[l[i]] > a[i])
            l[i] = l[l[i]];
    }
    for (int i = n; i >= 1; i--)
    {
        r[i] = i + 1;
        while (r[i] <= n && a[r[i]] > a[i])
            r[i] = r[r[i]];
    }
    fo(i, 1, n)
    {
        if (l[i] > 0)
            kq = max(kq, ok(a[i], a[l[i]]));
        if (r[i] <= n)
            kq = max(kq, ok(a[i], a[r[i]]));
    }
    cout << kq;
}
