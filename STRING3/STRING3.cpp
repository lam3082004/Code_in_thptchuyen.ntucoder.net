// Cho hai xâu
// S
//  và
// T
//  chỉ gồm các chữ cái lating thường. Tìm xâu con chung liên tiếp dài nhất của hai xâu
// S
//  và
// T
// , in ra độ dài đó.

// Dữ liệu vào

// - Dòng đầu chứa xâu
// S

// (
// |
// S
// |
// ≤
// 10
// 5
// )
// .

// - Dòng thứ hai chứa xâu
// T

// (
// |
// T
// |
// ≤
// 10
// 5
// )
// .

// Kết quả

// - In ra kết quả bài toán
/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Data
{
    Data *Next[26], *Link;
    int len;
};

Data *New_node(int len)
{
    Data *p = new Data();
    p->len = len;
    p->Link = NULL;
    for (int i = 0; i < 26; ++i)
        p->Next[i] = NULL;
    return p;
}

int sz = 0, n, m;
string A, B;

Data *root = New_node(sz++), *last = root;

void Build_Suffix_Automation(int c)
{
    Data *cur = New_node(sz++), *p;
    for (p = last; p && !p->Next[c]; p = p->Link)
        p->Next[c] = cur;

    if (!p)
        cur->Link = root;
    else
    {
        Data *q = p->Next[c];

        if (p->len + 1 == q->len)
            cur->Link = q;
        else
        {
            Data *clone = New_node(sz++);

            clone->len = p->len + 1;
            for (int i = 0; i < 26; ++i)
                clone->Next[i] = q->Next[i];
            clone->Link = q->Link;

            for (; p && p->Next[c] == q; p = p->Link)
                p->Next[c] = clone;
            q->Link = cur->Link = clone;
        }
    }

    last = cur;
}

int main()
{
    cin >> A >> B;
    n = A.length(), m = B.length();

    for (int i = 0; i < n; ++i)
        Build_Suffix_Automation(A[i] - 'a');

    Data *p = root;
    int best = 0, len = 0;
    for (int i = 0; i < m; ++i)
    {
        int c = B[i] - 'a';

        while (p && p != root && !p->Next[c])
        {
            p = p->Link;
            len = p->len;
        }

        if (p->Next[c])
        {
            p = p->Next[c];
            ++len;
        }

        best = max(best, len);
    }

    cout << best;

    return 0;
}
