// Cây tìm kiếm nhị phân (BST - Binary Search Tree) là một cấu trúc dữ liệu rất thuận lợi cho bài
// toán tìm kiếm. Cây tìm kiếm ứng với khóa là cây nhị phân mà mỗi nút đều được gán một khóa
// sao cho với mỗi mỗi nút :
//  Mọi khóa trên cây con trái đều nhỏ hơn khóa trên nút ;
//  Mọi khóa trên cây con phải đều lớn hơn khóa trên nút .
// Trong bài toán này, chúng ta xét các khóa có giá trị tương ứng và cần dựng cây tìm
// kiếm nhị phân mà độ cao không vượt quá , độ cao của cây được định nghĩa như sau:
// - Nút lá có độ cao bằng 1;
// - Một nút trong có độ cao bằng max độ cao các nút con trái hoặc phải cộng 1.
// Input
// - Gồm một dòng chứa hai số nguyên ;
// Output
// - Gồm dòng, mỗi dòng tương ứng với một test trong dữ liệu vào là một hoán vị có thứ tự
// từ điển nhỏ nhất mô tả thứ tự được đưa vào cây. Nếu không có phương án ghi -1.
/// hhoangcpascal
/// "OC CO HO"

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

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

void DFS(int u, int v, int h)
{
    if (u > v || h < 0)
        return;

    int len = (1 << h) - 1;
    int p = max(u, v - len);

    writeInt(p), putchar(' ');

    DFS(u, p - 1, h - 1);
    DFS(p + 1, v, h - 1);
}

int main()
{
    int n, h;
    cin >> n >> h;

    if ((1 << h) <= n)
    {
        writeInt(-1);
        return 0;
    }

    DFS(1, n, h - 1);

    return 0;
}
