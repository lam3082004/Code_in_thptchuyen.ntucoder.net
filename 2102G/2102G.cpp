// HEXGAME là một trò chơi xếp hình gồm 10 miếng ghép hình lục giác đều, trên mỗi miếng ghép
// được điền một số nguyên, có 8 miếng được điền số từ 1 đến 8 và có 2 miếng điền số 0. Các miếng
// liên kết với nhau tạo thành lưới tổ ong. Ban đầu các miếng ghép ở vị trí như hình dưới

// Tại mỗi bước, chọn một miếng ghép có đúng 6 miếng kề cạnh làm tâm, rồi xoay 1 nấc 6 miếng
// kề cạnh đó theo chiều kim đồng hồ. Như vậy chỉ có hai cách chọn tâm. Ví dụ với trạng thái ban
// đầu nêu trên thì nhận được một trong hai trạng thái dưới đây ứng với cách chọn sao khi xoay một nấc

// Yêu cầu
// • Cho một trạng thái của trò chơi (nhận được sau một dãy biến đổi từ trạng thái ban đầu), hãy
// tính số phép biến đổi ít nhất để đưa về trạng thái ban đầu
// Input
// • Dòng 1: 3 số ghi trên 3 miếng ghép ở hàng thứ nhất theo thứ tự từ trái qua phải
// • Dòng 2: 4 số ghi trên 4 miếng ghép ở hàng thứ hai theo thứ tự từ trái qua phải
// • Dòng 3: 3 số ghi trên 3 miếng ghép ở hàng thứ ba theo thứ tự từ trái qua phải
// Output
// • Một dòng duy nhất là số phép biến đổi ít nhất
// • Dữ liệu đảm bảo là có kết quả
/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

map<string, int> DS, DE;
string Start = "", End = "1238004765";

string S_Left(string S)
{
    string T = "";
    T = T + S[3] + S[0] + S[2] + S[7] + S[4] + S[1] + S[6] + S[8] + S[5] + S[9];
    return T;
}

string S_Right(string S)
{
    string T = "";
    T = T + S[0] + S[4] + S[1] + S[3] + S[8] + S[5] + S[2] + S[7] + S[9] + S[6];
    return T;
}

string E_Left(string S)
{
    string T = "";
    T = T + S[1] + S[5] + S[2] + S[0] + S[4] + S[8] + S[6] + S[3] + S[7] + S[9];
    return T;
}

string E_Right(string S)
{
    string T = "";
    T = T + S[0] + S[2] + S[6] + S[3] + S[1] + S[5] + S[9] + S[7] + S[4] + S[8];
    return T;
}

void BFS_S(string S)
{
    queue<string> Q;
    Q.push(S);
    DS[S] = 0;

    while (!Q.empty())
    {
        string u = Q.front();
        Q.pop();

        string A = S_Left(u);
        string B = S_Right(u);

        if (!DS.count(A))
        {
            DS[A] = DS[u] + 1;
            Q.push(A);
        }

        if (!DS.count(B))
        {
            DS[B] = DS[u] + 1;
            Q.push(B);
        }

        if (DS[Q.back()] >= 15)
            break;
    }
}

void BFS_E(string S)
{
    queue<string> Q;
    Q.push(S);
    DE[S] = 0;

    while (!Q.empty())
    {
        string u = Q.front();
        Q.pop();

        if (DS.count(u))
        {
            cout << DS[u] + DE[u];
            return;
        }

        string A = E_Left(u);
        string B = E_Right(u);

        if (!DE.count(A))
        {
            DE[A] = DE[u] + 1;
            Q.push(A);
        }

        if (!DE.count(B))
        {
            DE[B] = DE[u] + 1;
            Q.push(B);
        }

        if (DE[Q.back()] >= 15)
            break;
    }
}

int main()
{
    for (int i = 1; i <= 10; ++i)
    {
        int a;
        cin >> a;
        Start = Start + char(a + '0');
    }

    BFS_S(Start);
    BFS_E(End);

    return 0;
}
