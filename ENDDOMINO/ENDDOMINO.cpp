// Hiện tại toilagun2004 đang thất vọng vì kết quả thi tin học trẻ lần đầu tiên của mình. "Nhàn cư vi bất thiện" toilagun2004 cũng không ngoại lệ. Cậu tìm ra được trong góc nhà bộ domino của em mình vứt lăn lóc trong góc nhà. Sau một hồi sắp xếp thì cậu cũng xếp được bộ domino ra trò. toilagun2004 rất mâu thuẫn: cậu ta vừa muốn chơi nhiều lần, vừa không muốn chơi xong xếp lại (Vì tốn công). Vì vậy nên cậu ta giảm chỉ tiêu của mình xuống, bây giờ cậu ta chỉ cần biết khi xô đổ domino thứ i về bên phải thì domino sẽ đổ tới đâu. Nhưng do lười nên cậu ta muốn nhờ mọi người tính xem khi đổ domino thứ i thì domino sẽ đổ từ i đến đâu. Biết rằng khi xô đổ domino thứ i thì tất cả những domino có khoảng cách tới i < hi thì sẽ bị đổ.

// Dữ liệu vào:

// - Dòng đầu tiên gồm 1 số nguyên dương n - số lượng số domino (n
// ≤
// 106)

// - Dòng thứ 2 gồm n số nguyên dương hi - chiều cao domino thứ i (hi<109)

// - Dòng thứ 3 gồm n-1 số nguyên dương di - khoảng cách domino thứ i tới domino thứ i+1 (di<109)

// - Dòng tiếp theo là số t - số lượng test (t
// ≤
// 105)

// - t dòng tiếp theo mỗi dòng là số i thể hiện việc toilagun2004 xô đổ domino thứ i (i
// ≤
// n)

// Dữ liệu ra:

// - t dòng là số hiệu domino cuối cùng bị đổ khi bị xô bởi domino i
/// hhoangcpascal

#pragma GCC optimize("O2")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long
#define file_name "ENDDOMINO"

using namespace std;

template <typename _type_>
inline void readInt(_type_ &num)
{
    register char c = getchar();
    while (c != '-' && (c < '0' || c > '9'))
        c = getchar();
    bool neg = (c == '-');
    if (neg)
        c = getchar();
    for (num = 0; '0' <= c && c <= '9'; c = getchar())
        num = (num << 1) + (num << 3) + (c - '0');
    if (neg)
        num = -num;
}

template <typename _type_>
inline void writeInt(_type_ num)
{
    if (num < 0)
    {
        putchar('-');
        writeInt(-num);
        return;
    }
    if (num > 9)
        writeInt(num / 10);
    putchar(num % 10 + '0');
}

llong d[1000006];
int n, q, ans[1000006], h[1000006], cnt = 0;
pair<llong, int> S[1000006];

int main()
{
    readInt(n);
    for (int i = 1; i <= n; ++i)
        readInt(h[i]);
    for (int i = 2; i <= n; ++i)
    {
        int D;
        readInt(D);
        d[i] = d[i - 1] + D;
    }

    for (int i = n; i >= 1; --i)
    {
        ans[i] = i;
        while (cnt > 0 && S[cnt - 1].first <= d[i] + h[i])
            ans[i] = S[--cnt].second;
        S[cnt++] = {d[i], ans[i]};
    }

    readInt(q);
    while (q--)
    {
        int x;
        readInt(x);
        writeInt(ans[x]), putchar('\n');
    }

    return 0;
}
