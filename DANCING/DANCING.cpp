// Trong lúc rảnh, Dũng đã quyết định sáng tác một số bài hát bằng tiếng Anh có độ phức tạp O(n
// 2
// )
// về các con vật được nuôi ở Viện Công nghệ Thực phẩm gần nhà. Đầu tiên, anh liệt kê một dãy
// A[1..n] gồm n cụm từ, mỗi cụm từ mô tả một con vật. Sau đó, anh sử dụng thuật toán sau để
// sáng tác bài hát.
// Hát Look at the animals, dancing, dancing,
// Hát Look at the animals, dancing to the music.
// for i từ 1 đến n do
// for j từ i đến 2 do
// Hát xâu A[j]
// end for
// if i > 1 then
// Hát and
// end if
// Hát A[1]
// Hát dancing, dancing,
// Hát Look at the animals, dancing to the music.
// end for
// Để tính xem mình tốn bao nhiêu sức để hát bài hát do mình sáng tác ra, Dũng quyết định đếm số
// chữ cái tiếng Anh (cả in hoa lẫn in thường) xuất hiện trong bài hát. Hãy viết chương trình giúp
// Dũng làm điều đó.
// Dữ liệu
// • Dòng đầu tiên gồm một số nguyên dương n (0 ≤ n ≤ 105

// ) là số cụm từ mà Dũng đã liệt kê

// ra.
// • n dòng tiếp theo, dòng thứ i là cụm từ A[i] mà Dũng sử dụng để mô tả các con vật. Các
// cụm từ sẽ chỉ chứa các chữ cái tiếng Anh (in hoa hoặc in thường) và dấu cách.
// Dung lượng dữ liệu vào nhỏ hơn 1 MB.
// Kết quả
// • Gồm một dòng duy nhất chứa một số nguyên là số chữ cái xuất hiện trong bài hát của
// Dũng. Lưu ý các dấu cách, dấu phẩy, dấu chấm và dấu xuống dòng không được tính vào kết
// quả.
#include <bits/stdc++.h>
using namespace std;
long long n, a[100005];
long long ans = 0;
string s, line;
int main()
{
    cin >> n;
    getline(cin, line);
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        int tmp = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != ' ')
                tmp++;
        a[i] = tmp;
    }
    for (int i = 1; i <= n; i++)
        ans += a[i] * (n - i + 1);
    if (n > 0)
        cout << ans + 33 * (n + 1) + 30 + 14 * n + 3 * (n - 1) << endl;
    else
        cout << 63 << endl;
}
