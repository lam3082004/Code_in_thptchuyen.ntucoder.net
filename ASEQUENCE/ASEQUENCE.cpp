// Trong toán học, một cấp số cộng (tiếng Anh: arithmetic progression hoặc arithmetic sequence) là
// một dãy số thoả mãn điều kiện: hai phần tử liên tiếp nhau sai khác nhau một hằng số. Chẳng
// hạn, dãy số 3, 5, 7, 9, 11, ... là một cấp số cộng với các phân tử liên tiếp sai khác nhau hằng số 2.
// Hằng số sai khác chung được gọi là công sai của cấp số cộng. Các phần tử của nó cũng được gọi
// là các số hạng.
// Bài toán được đặt ra cho bạn là: Cho một dãy số gồm n số hạng, kiểm tra xem dãy đó có phải là
// cấp số cộng hay không?
// Dữ liệu
// • Dòng đầu tiên chứa một số nguyên dương n là số lượng số của dãy cần kiểm tra
// (1 ≤ n ≤ 1000000).
// • Dòng tiếp theo chứa n số nguyên a1, a2, ..., an biểu thị dãy đó (1 ≤ ai ≤ 1018).
#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, b) for (ll i = a; i <= b; i++)
#define ll long long
#define nmax 1000000
#define mod 1000000007
ll n, a[nmax];
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fo(i, 1, n)
            cin >>
        a[i];
    ll s = a[2] - a[1];
    fo(i, 3, n) if (a[i] - a[i - 1] != s)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}
