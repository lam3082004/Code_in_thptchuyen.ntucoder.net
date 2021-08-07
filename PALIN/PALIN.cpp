// Một xâu được gọi là palindrome nếu nó có tính đối xứng, nghĩa là khi ta viết các chữ cái của xâu đó
// theo thứ tự từ phải sang trái, ta được chính xâu đó. Nhiệm vụ của bạn là viết chương trình tính số chữ
// cái nhỏ nhất bạn cần phải chèn vào một xâu s nào đó để xâu s trở thành xâu palindrome.
// Ví dụ, bằng cách thêm hai chữ cái, xâu "Ab3bd" có thể thành xâu "dAb3bAd" hoặc "Adb3bdA"
// và trở thành xâu palindrome. Tuy vậy, nếu chỉ chèn một chữ cái, ta sẽ không thể thu được xâu
// palindrome.
// Dữ liệu
// Dòng đầu tiên chứa số nguyên N (3 ≤ N ≤ 5000) là độ dài của xâu ta cần biến đổi.
// Dòng thứ hai chứa N chữ cái la-tinh in thường hoặc in hoa và các chữ số là xâu ta cần biến
// đổi. Xâu cần biến đổi không phân biệt hoa-thường, tức là chữ cái in thường và chữ cái tương ứng in hoa
// của nó được coi là khác nhau.
// Kết quả
// Một dòng chứa số nguyên duy nhất là số chữ cái nhỏ nhất ta cần chèn thêm.
#include <bits/stdc++.h>
using namespace std;
string s;
int n, ans, ans2, f[5005][5005];
int main()
{
    cin >> n;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++)
        f[i][i] = 1;
    for (int i = n - 1; i >= 1; i--)
        for (int j = i + 1; j <= n; j++)
            if (s[i] == s[j])
                f[i][j] = f[i + 1][j - 1] + 2;
            else
                f[i][j] = max(f[i + 1][j], f[i][j - 1]);
    cout << n - f[1][n] << endl;
}
