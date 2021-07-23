// Năm 2016 chuẩn bị qua đi và năm mới sắp đến. Để có được
// một quảng thời gian nghỉ tết thoải mái và không phải bận tâm
// chút gì về bài tập tết. Mr Bin quyết định sẽ xử lí hết đống bài
// tập tết của mình trước khi đón đêm giao thừa. Cậu giải được
// hầu như tất cả các bài tập về nhà một cách cực kì nhanh chóng
// cho đến khi cậu làm đến câu cuối cùng trong số những bài tập
// về nhà môn số học thuật toán. Bài toán đưa ra một khái niệm
// về một số nguyên bất thường là một số nguyên mà biểu diễn
// nhị phân của nó chỉ có duy nhất một bit 0 (bit 0 ở đầu không
// được tính). Yêu cầu hãy xác định số lượng số nguyên bất
// thường nằm trong khoảng [a, b].

// Dữ liệu: HOMEWORK.INP
// _ Dòng đầu nhập một số nguyên dương T
// _ T dòng sau mỗi dòng gồm một dòng duy nhất chứa hai số
// nguyên dương a, b. (a<b)

// Kết quả: HOMEWORK.OUT
// Tương ứng với mỗi test ghi số lượng số nguyên bất thường
// nằm tròng đoạn [a,b]
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
ll m, a, b, x, y, s, p, t, q, r[65];
ll mu(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = mu(a, b / 2);
    t = t * t;
    if (b % 2 == 1)
        t = t * a;
    return t;
}
ll ok(ll n)
{
    ll k;
    for (int i = 60; i >= 0; i--)
        if (mu(2, i) <= n)
        {
            k = i + 1;
            break;
        }
    return k;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        s = 0;
        p = 0;
        q = 0;
        x = ok(a);
        y = ok(b);
        fo(i, 1, y) r[i] = 1;
        fo(i, 2, x)
        {
            r[i] = 0;
            t = 0;
            fo(j, 1, x - 1) t = t * 2 + r[j] * 2;
            if (r[x] == 1)
                t++;
            if (t < a)
                p++;
            r[i] = 1;
        }
        fo(i, 2, y)
        {
            r[i] = 0;
            t = 0;
            fo(j, 1, y - 1) t = t * 2 + r[j] * 2;
            if (r[y] == 1)
                t++;
            if (t > b)
                q++;
            r[i] = 1;
        }
        fo(i, x, y) s += i - 1;
        cout << s - p - q << '\n';
    }
}
