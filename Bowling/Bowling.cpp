// Bowling (VOI2014_R2)
// Bowling là một trò chơi giải trí mà người chơi ném một quả bóng nặng cho chạy trên một đường
// băng dài và phẳng để làm đổ những chai gỗ đứng ở cuối đường. Ngày nay, Bowling được xem là
// một môn thể thao. Trong bài toán này chúng ta sẽ xét trò chơi Bowling cải biên như sau:
//  Cuối đường băng người ta đặt n chai gỗ được xếp thành một hàng ngang, các chai gỗ
// được đánh số từ 1 đến n từ trái qua phải. Chai gỗ thứ i ghi số nguyên ai tương ứng là
// điểm thưởng (nếu ai ≥ 0) hoặc phạt (nếu ai < 0) khi ném bóng mà làm đổ chai gỗ này.
//  Người chơi phải ném ít nhất một lần và không giới hạn số lần ném bóng. Mỗi lần ném
// bóng, người chơi sẽ ném bóng hướng vào một trong n vị trí đặt chai gỗ, nếu ném bóng
// hướng vào vị trí đặt chai gỗ thứ i thì nó sẽ làm đổ những chai đặt ở vị trí có khoảng cách
// với vị trí chai thứ i không vượt quá r. Khoảng cách giữa vị trí hai chai thứ i và thứ j được
// tính là |i – j|. Tổng điểm mà người chơi đạt được là tổng các số ghi trên các chai gỗ mà
// người chơi làm đổ được. Muốn đạt được nhiều điểm người chơi không những phải có khả
// năng thực hiện việc ném bóng chính xác mà còn phải biết lựa chọn hướng ném bóng
// trong mỗi lượt chơi.
// Yêu cầu: Cho r và a1, a2, ..., an, hãy tính tổng điểm lớn nhất mà người chơi có thể đạt được với
// giả thiết người chơi có khả năng thực hiện chính xác việc ném bóng.
// Input
// Dòng đầu tiên ghi số nguyên dương K là số lượng bộ dữ liệu. Tiếp đến là K nhóm dòng, mỗi
// nhóm tương ứng với một bộ dữ liệu có cấu trúc như sau:
//  Dòng thứ nhất ghi hai số nguyên dương n và r (r ≤ n);
//  Dòng thứ hai chứa n số nguyên a1, a2, ..., an, số ai tương ứng là số ghi trên chai gỗ thứ i
// (| ai
// | ≤ 109
// ).

// Các số trên cùng một dòng được ghi cách nhau ít nhất một dấu cách.
// Output
// Gồm K dòng, mỗi dòng ghi một số nguyên là tổng điểm mà người chơi có thể đạt được tương
// ứng với bộ dữ liệu trong dữ liệu vào.
/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#define file_name "BOWING"
#define llong long long

using namespace std;

template <typename _type_>
void readInt(_type_ &num)
{
    register char c = getchar();
    while (c != '-' && (c < '0' || c > '9'))
        c = getchar();
    bool neg = (c == '-');
    if (c == '-')
        c = getchar();
    for (num = 0; '0' <= c && c <= '9'; c = getchar())
        num = (num << 1) + (num << 3) + (c - '0');
    if (neg)
        num = -num;
}

template <typename _type_>
void writeInt(_type_ num)
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

llong sum[400006], f[200006];
int n, R, a[200006];
vector<int> S;
deque<int> DQ;

llong get_sum(int l, int r)
{
    return f[l] + (sum[r + R] - sum[max(r - R - 1, l + R)]);
}

void Push_S(int u)
{
    while (!S.empty() && f[S.back()] <= f[u])
        S.pop_back();
    S.push_back(u);
}

void Push_DQ(int u)
{
    while (!DQ.empty() && get_sum(DQ.back(), u) <= get_sum(u - 1, u))
        DQ.pop_back();
    DQ.push_back(u - 1);
}

void Pop_DQ(int u)
{
    while (!DQ.empty() && DQ.front() <= u)
        DQ.pop_front();
}

int main()
{
    int test = 0;
    readInt(test);
    while (test--)
    {
        readInt(n);
        readInt(R);
        for (int i = 1; i <= n; ++i)
            readInt(a[i]), sum[i] = sum[i - 1] + a[i], f[i] = 0;
        for (int i = n + 1; i <= 2 * n; ++i)
            sum[i] = sum[i - 1];

        DQ.clear();
        S.clear();
        llong res = -1e18;

        for (int i = 1; i <= n; ++i)
        {
            llong tmp_sum = sum[i + R] - sum[max(0, i - R - 1)];

            res = max(res, tmp_sum);
            f[i] = tmp_sum;
            if (i == 1)
                continue;
            else
                Push_DQ(i);

            if (i >= 2 * R + 1)
            {
                Pop_DQ(i - 2 * R - 1);
                Push_S(i - 2 * R - 1);

                f[i] = max(f[i], max(get_sum(DQ.front(), i), f[S.front()] + tmp_sum));
                res = max(res, f[i]);
                continue;
            }
            else
            {
                f[i] = max(f[i], get_sum(DQ.front(), i));
                res = max(res, f[i]);
            }
        }

        writeInt(res), putchar('\n');
    }

    return 0;
}
