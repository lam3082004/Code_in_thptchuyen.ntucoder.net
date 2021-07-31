// DANH SÁCH VÒNG
// Để làm việc với một danh sách gồm

// số nguyên cần phải có hai thao tác.

// • Thao tác Top chuyển phần tử đầu tiên của danh sách xuống vị trí cuối cùng của danh sách.
// • Thao tác Bottom chuyển phần tử cuối cùng của danh sách lên vị trí đầu tiên của danh sách.
// Một phép biến đổi danh sách đã cho là việc thực hiện

// lần thao tác Top, rồi sau đó đến
// lần thao

// tác Bottom.
// Do số lần thực hiện phép biến đổi trên là rất lớn nên đòi hỏi phải có những thủ tục thực hiện hiệu
// quả để thực hiện liên tiếp

// phép biến đổi đưa danh sách về trạng thái cuối cùng.

// Yêu cầu: Viết chương trình cho phép với một danh sách và ba số
// ,
// ,
// cho trước, xác định trạng

// thái của danh sách sau

// lần thực hiện phép biến đổi.

// Dữ liệu: Vào từ file văn bản CLIST.INP
// • Dòng đầu tiên chứa ba số nguyên dương
// ,
// ,
// (1 ≤
// ,
// ,
// ≤ 1000000).

// • Dòng thứ hai chứa

// số nguyên, mỗi số có giá trị tuyệt đối không quá 10000, được sắp xếp theo

// thứ tự tương ứng với trạng thái khởi đầu của danh sách.
// • Dòng thứ ba chứa số nguyên
// (0 ≤
// ≤ 2.10
// ).

// Kết quả: Ghi ra file văn bản CLIST.OUT
// Ghi ra trên một dòng của file văn bản CLIST.OUT các phần tử của danh sách sau

// phép biển đổi.

// Các phần tử phải được ghi đúng thứ tự từ phần tử đầu tiên đến phần tử cuối cùng.
// Các số trên một dòng của Input/Output File ghi cách nhau ít nhất một dấu cách.
#include <bits/stdc++.h>
using namespace std;
long long n, k, l, s, t, x;
int a[1000061];
int b[1000061];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> l;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> x;
    s = (l - k) * x % n;
    for (int i = 1; i <= n; i++)
    {
        t = (((i + s) % n) + n) % n;
        b[t] = a[i];
    }
    for (int i = 1; i < n; i++)
        cout << b[i] << ' ';
    cout << b[0];
}
