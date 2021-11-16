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
bool sortbysec(const tuple<int, int, int> &a,
               const tuple<int, int, int> &b)
{
    return (get<1>(a) < get<1>(b));
}

void solve()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> A(n);
    vector<tuple<int, int, int>> B(n);
    vector<tuple<int, int, int>> C(n);
    for0(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        A[i] = make_tuple(x, y, i + 1);
    }
    for0(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        B[i] = make_tuple(x, y, i + 1);
    }
    for0(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        C[i] = make_tuple(x, y, i + 1);
    }
    sort(all(A));
    sort(all(B));
    sort(all(C));
    sort(all(A), sortbysec);
    sort(all(B), sortbysec);
    sort(all(C), sortbysec);
    for0(i, 0, n)
    {
        cout << get<2>(A[i]) << " " << get<2>(B[i]) << " " << get<2>(C[i]) << endl;
    }

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    // ll T;
    // cin >> T;
    // while (T--)
    // {
    //     solve();
    // }
    return 0;
}