// AS là trung tâm nghiên cứu tìm hiểu về Trái Đất. Nhờ hệ thống quan sát Trái Đất, trung tâm đẩy mạnh nghiên cứu nghành Vật lý Thái dương học, khám phá các thiên thể trong khắp Hệ Mặt trời và nghiên cứu các chủ đề liên quan đến Vật Lý Thiên văn. Là một nhân viên mới của TAS, nhiệm vụ đầu tiên mà X được giao là giải quyết một bài toán nhỏ trong điều khiển tên lửa, cụ thể bài toán như sau:

// Cho hai số nguyên dương a, b, giải phương trình nghiệm nguyên dương:
// 1
// x
// +
// 1
// y
// =
// 1
// a
// ∗
// b
// .

// Nhanh chóng tìm được lời giải đẹp của bài toán, để chứng minh năng lực của mình với đồng nghiệp, X đã lập trình đếm số lượng nghiệm của phương trình. Bạn hãy giúp X lập trình kiểm tra lại số lượng nghiệm của bài toán.

// Yêu cầu: Cho a, b, hãy lập trình đếm số nghiệm nguyên dương của phương trình.

// Dữ liệu:

// - Dòng đầu tiên chứa số nguyên T là số bộ dữ liệu.

// - T dòng sau, mỗi dòng chứa 2 số nguyên dương a, b cách nhau 1 dấu cách trống.

// Kết quả: Gồm T dòng, mỗi dòng là số lượng nghiệm của phương trình tương ứng với bộ dữ liệu vào.
#include <bits/stdc++.h>
#define ll long long
#define name "EQUA"
#define nmax 1000000
using namespace std;
ll t, arr[1000005];
ll a, b, o, h, sn;
ll store[80];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= nmax; i++)
        arr[i] = 1;
    for (int i = 2; i <= sqrt(nmax); i++)
    {
        if (arr[i] == 1)
        {
            for (int j = i * i; j <= nmax; j += i)
                if (arr[j] == 1)
                    arr[j] = i;
        }
    }
    for (int i = 1; i <= nmax; i++)
        if (arr[i] == 1)
            arr[i] = i;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        sn = 1;
        if (a <= nmax && b <= nmax)
        {
            o = 1;
            h = 0;
            while (a != 1)
            {
                store[++h] = arr[a];
                a /= arr[a];
            }
            while (b != 1)
            {
                store[++h] = arr[b];
                b /= arr[b];
            }
            sort(store + 1, store + 1 + h);
            store[++h] = -1;
            for (int i = 2; i <= h; i++)
            {
                if (store[i] == store[i - 1])
                    o++;
                else
                {
                    sn *= ((o * 2) + 1);
                    o = 1;
                }
            }
            cout << sn << "\n";
        }
        else
        {
            int count;
            int output = 1;
            int i = 2;
            while (true)
            {
                count = 0;
                while (a % i == 0)
                {
                    ++count;
                    a /= i;
                }
                while (b % i == 0)
                {
                    ++count;
                    b /= i;
                }
                if (count)
                    output *= (2 * count + 1);
                if ((i + 1) * (i + 1) > a && (i + 1) * (i + 1) > b)
                {
                    if ((a != 1) && (b != 1))
                    {
                        if (a == b)
                            output *= 5;
                        else
                            output *= 9;
                        break;
                    }
                    else
                    {
                        output *= 3;
                        break;
                    }
                }
                i++;
            }
            cout << output << "\n";
        }
    }
}
