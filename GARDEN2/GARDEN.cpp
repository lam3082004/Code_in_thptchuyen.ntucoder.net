// GARDEN
// Sau khi chinh phục mọi đỉnh cao về lập trình thi đấu toàn thế giới, Cá Nóc Cắn Cáp đã nghĩ đến
// việc "rửa tay gác kiếm". Cá Nóc được Phượng Hoàng chỉ điểm rằng có một đại lục màu mỡ mang
// tên Free Contest và liền đến đó xem thử tình hình. Đại lục được xem như là một mặt phẳng tọa
// độ, trên đó có một vườn N cây hoa Đăng Tiêu mọc lên, cây thứ i mọc ở ô (xi
// , yi).

// Với sở thích code đẹp của Cá Nóc, anh nghĩ rằng mình nên dời một số cây đi và trồng lại vào một
// vị trí khác để N cây đó tạo thành một hàng dọc hoặc một hàng ngang liên tiếp nhau song song
// với hệ trục tọa độ. Việc di chuyển cây là vô cùng khó khăn và Cá Nóc chỉ có thể di chuyển tối đa
// một cây một lúc và mất 1 đơn vị thể lực để di chuyển cây đi một đơn vị. Hơn nữa, anh chỉ có thể
// di chuyển song song với hệ trục tọa độ.
// Vì bận đi cắn cáp nên Cá Nóc muốn nhờ các bạn tính giúp mình tìm cách di chuyển cây trong
// vườn cây này sao cho lượng thể lực anh mất là nhỏ nhất có thể.
// Dữ liệu
// • Dòng đầu tiên chứa số nguyên N là số lượng cây hoa Đăng Tiêu trong vườn cây.
// • N dòng tiếp theo, mỗi dòng chứa hai số nguyên xi

// , yi(−105 ≤ xi
// , yi ≤ 105
// ) là tọa độ của cây

// thứ i.
// Kết quả
// • Ghi ra một số nguyên duy nhất là lượng thể lực tối thiểu mà Cá Nóc cần để đạt được mong
// muốn của mình.
#include <bits/stdc++.h>

using namespace std;

long long Solve(vector<int> &x)
{
    sort(x.begin(), x.end());
    long long ans = 0;
    int pivot = x[x.size() / 2];
    for (int a : x)
        ans += abs(pivot - a);
    //for (int a : x) cerr << a << ' ';cerr << ans << '\n';
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    // Row
    vector<int> temp(n);
    copy(y.begin(), y.end(), temp.begin());
    for (int i = 0; i < n; ++i)
        y[i] -= i;
    long long ans = Solve(x) + Solve(y);
    // Column
    swap(temp, y);
    //for (int a : x) cerr << a << ' '; cerr << '\n';
    for (int i = 0; i < n; ++i)
        x[i] -= i;
    ans = min(ans, Solve(x) + Solve(y));
    cout << ans << '\n';
}
