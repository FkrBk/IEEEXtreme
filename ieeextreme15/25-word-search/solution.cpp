#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// #define int ll

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF INT_MAX
#define MOD 1000000007
#define for1(x, y) for (long long x = 1; x < ll(y); x++)
#define forn(x, y, z) for (long long x = y; x < ll(z); x++)
#define for0(x, y, z) for (long long x = y; x < ll(z); x++)
#define PII pair<int, int>
#define FF first
#define SS second
#define PB push_back
#define all(x) x.begin(), x.end()

// Mathematical functions.

int GCD(int a, int b)
{
    if (!b)
        return a;
    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}
int calculateMex(unordered_set<int> Set)
{
    int Mex = 0;

    while (Set.find(Mex) != Set.end())
        Mex++;

    return (Mex);
}

//////////////////// START CODE HERE ///////////////////////////

int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

pair<int, int> search2D(char *grid, int row, int col,
                        string word, int R, int C)
{

    if (*(grid + row * C + col) != word[0])
        return make_pair(-1, -1);

    int len = word.length();

    for (int dir = 0; dir < 8; dir++)
    {

        int k, rd = row + x[dir], cd = col + y[dir];

        for (k = 1; k < len; k++)
        {

            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;

            if (*(grid + rd * C + cd) != word[k])
                break;

            rd += x[dir], cd += y[dir];
        }

        if (k == len)
        {
            return make_pair(rd - x[dir], cd - y[dir]);
        }
    }
    return make_pair(-1, -1);
}
tuple<int, int, int, int> patternSearch(char *grid, string word,
                                        int r, int c)
{

    for (int row = 0; row < r; row++)
        for (int col = 0; col < c; col++)
        {
            pair<int, int> value = search2D(grid, row, col, word, r, c);
            if (value.first > -1)
                return make_tuple(row, col, value.first, value.second);
        }

    return make_tuple(-1, -1, -1, -1);
}

void solve()
{
    int r, c, q;
    cin >> r >> c >> q;
    char grid[r][c];
    for0(i, 0, r)
    {
        string s;
        cin >> s;
        for0(j, 0, c)
        {
            grid[i][j] = s[j];
        }
    }
    for0(i, 0, q)
    {
        string s;
        cin >> s;
        tuple<int, int, int, int> pos = patternSearch((char *)grid, s, r, c);
        if (get<0>(pos) > -1)
        {
            cout << get<0>(pos) << " " << get<1>(pos) << " " << get<2>(pos) << " " << get<3>(pos) << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }

    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}