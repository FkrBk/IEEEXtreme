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

float kPresentProbability(vi a, int k)
{
    float count = 0;

    for (int i = 0; i < a.size(); i++)
        if (a[i] == k)
            count++;

    return count / a.size();
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> rounds(n);
    for0(i, 0, n)
    {
        int a, b;
        cin >> a >> b;
        rounds[i] = make_pair(a, b);
    }
    ll alice_count = 0;
    ll bob_count = 0;
    vi dice_1;
    vi dice_2;
    alice_count = rounds[0].first;
    bob_count = rounds[0].second;
    dice_1.push_back(rounds[0].first);
    dice_2.push_back(rounds[0].second);
    bool init_config = true;
    for0(i, 1, n)
    {
        if (alice_count == bob_count)
        {
            if (init_config)
            {
                dice_1.push_back(rounds[i].first);
                dice_2.push_back(rounds[i].second);
            }
            else
            {
                dice_2.push_back(rounds[i].first);
                dice_1.push_back(rounds[i].second);
            }
        }
        else
        {
            init_config = !init_config;
            if (init_config)
            {
                dice_1.push_back(rounds[i].first);
                dice_2.push_back(rounds[i].second);
            }
            else
            {
                dice_2.push_back(rounds[i].first);
                dice_1.push_back(rounds[i].second);
            }
        }
        alice_count += rounds[i].first;
        bob_count += rounds[i].second;
    }
    if (kPresentProbability(dice_1, 2) / kPresentProbability(dice_1, 6) < kPresentProbability(dice_2, 2) / kPresentProbability(dice_2, 6))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
    // for (auto value : dice_1)
    // {
    //     cout << value << " ";
    // }
    // cout << endl;
    // for (auto value : dice_2)
    // {
    //     cout << value << " ";
    // }
    // cout << endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}