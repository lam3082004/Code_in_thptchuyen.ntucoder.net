// Một số tự nhiên được gọi là một số hồi văn nếu ta đọc từ trái sang phải hoặc từ phải sang trái đều như nhau. Ví dụ: số 23432 là một số hồi văn.

// Yêu cầu: Cho trước 2 số tự nhiên a, b với a <= b <= 1016. Hỏi có bao nhiêu số hồi văn x thỏa mãn a <= x <= b.

// Dữ liệu vào: 2 số tự nhiên a, b trên một dòng với a <= b <= 1016 . Mỗi số a và b cách nhau một dấu cách.

// Dữ liệu ra: In ra một số nguyên k là số các số hồi văn x thỏa mãn a <= x <= b.
#include <stdio.h>
#define ll long long
ll F(ll pp, ll nlt)
{
    ll front = pp;
    ll back = 0;
    if (nlt & 1)
        pp /= 10;
    while (pp != 0)
    {
        ll digit = pp % 10;
        pp /= 10;
        back = back * 10 + digit;
        front *= 10;
    }
    return front + back;
}
ll sol(ll N)
{
    ll nlt = 0, plt = 0, pp = 0, temp = 0, i = 0;
    for (nlt = 0, temp = N; temp != 0; temp /= 10)
        nlt++;
    plt = (nlt + 1) / 2;
    pp = N;
    for (i = 0; i < nlt - plt; i++)
        pp /= 10;
    if (F(pp, nlt) > N)
        pp--;
    pp *= 2;
    if (nlt & 1)
    {
        ll adj = 1;
        for (i = 1; i < plt; i++)
            adj *= 10;
        pp -= (pp / 2 - adj + 1);
    }
    else
    {
        ll adj = 1;
        for (i = 0; i < plt; i++)
            adj *= 10;
        pp += (adj - 1 - pp / 2);
    }
    return pp;
}
main()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    printf("%d", sol(b) - sol(a - 1));
}
