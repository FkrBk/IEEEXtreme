// Author: Pasindu Wijesena
// Attainable Score: 100

#include <bits/stdc++.h>
using namespace std;

#define rep(a, b) for (int a = 0; a < (b); a++)
#define rep2(a, b, c) for (int a = (b); a < (c); a++)
#define gcd(a, b) __gcd(a, b)
#define bitCount(a) __builtin_popcount(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <typename... T>
void rd(T &...args) {
  ((cin >> args), ...);
}  // Read standard input

const ll MOD = 1e9 + 7;

ll mod(ll V, ll N) { return ((V % N) + N) % N; }

bool solve() {
  int N, K;
  rd(N, K);
  vector<string> S(N);
  rep(i, N) { rd(S[i]); }

  vector<ll> DP(N, 1);
  vector<ll> SA(N, 0);
  map<string, ll> R;
  rep(i, N) {
    if (i - K > 0) {
      DP[i] += SA[i - K - 1];
      DP[i] %= MOD;
    }

    DP[i] = mod(DP[i] - R[S[i]], MOD);
    R[S[i]] += DP[i];
    R[S[i]] %= MOD;

    SA[i] = DP[i];

    if (i > 0) {
      SA[i] += SA[i - 1];
      SA[i] %= MOD;
    }
  }

  cout << SA[N - 1] << endl;

  // rep(i, N) cout << DP[i] << ' ';
  // cout << endl;
  // rep(i, N) cout << SA[i] << ' ';
  // cout << endl;

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T = 1;
  rd(T);

  rep(i, T) {
    // cout<<"Case #"<<i+1<<": ";
    solve();
    // bool result = solve();
    // if(result) cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
  }

  return 0;
}
