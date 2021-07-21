/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#define file_name "TUMBLER"

using namespace std;

map<string, int> S, E;

string AS(string T)
{
    string C = "";
    C = C + T[1] + T[2] + T[3] + T[4] + T[0] + T[5] + T[6] + T[7] + T[8] + T[9] + T[10] + T[11] + T[12] + T[13];
    return C;
}

string AE(string T)
{
    string C = "";
    C = C + T[4] + T[0] + T[1] + T[2] + T[3] + T[5] + T[6] + T[7] + T[8] + T[9] + T[10] + T[11] + T[12] + T[13];
    return C;
}

string BS(string T)
{
    string C = "";
    C = C + T[13] + T[1] + T[2] + T[3] + T[4] + T[0] + T[5] + T[6] + T[7] + T[8] + T[9] + T[10] + T[11] + T[12];
    return C;
}

string BE(string T)
{
    string C = "";
    C = C + T[5] + T[1] + T[2] + T[3] + T[4] + T[6] + T[7] + T[8] + T[9] + T[10] + T[11] + T[12] + T[13] + T[0];
    return C;
}

void Init_E()
{
    string s = "12345234567890";
    queue<string> Q;
    Q.push(s);
    E[s] = 0;

    while (!Q.empty())
    {
        string u = Q.front();
        Q.pop();

        string v1 = AE(u), v2 = BE(u);

        if (!E.count(v1))
        {
            E[v1] = E[u] + 1;
            if (E[v1] < 14)
                Q.push(v1);
        }

        if (!E.count(v2))
        {
            E[v2] = E[u] + 1;
            if (E[v2] < 14)
                Q.push(v2);
        }
    }
}

int BFS(string s)
{
    S.clear();

    if (E.count(s))
        return E[s];
    queue<string> Q;
    Q.push(s);
    S[s] = 0;

    while (!Q.empty())
    {
        string u = Q.front();
        Q.pop();
        if (E.count(u))
            return S[u] + E[u];

        string v1 = AS(u), v2 = BS(u);

        if (!S.count(v1))
        {
            S[v1] = S[u] + 1;
            if (S[v1] <= 6)
                Q.push(v1);
        }

        if (!S.count(v2))
        {
            S[v2] = S[u] + 1;
            if (S[v2] <= 6)
                Q.push(v2);
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Init_E();

    int t = 0;
    cin >> t;
    while (t--)
    {
        string s = "";

        for (int i = 0; i < 14; ++i)
        {
            int a;
            cin >> a;
            s = s + char(a % 10 + '0');
        }

        cout << BFS(s) << '\n';
    }

    return 0;
}
