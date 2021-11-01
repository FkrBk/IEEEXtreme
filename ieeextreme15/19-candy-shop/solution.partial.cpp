// Author: Pasindu Wijesena
// Attainable Score: 60

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

const ll MOD = 998244353;

bool solve() {
  int N, K;
  rd(N, K);
  vector<int> A(N), B(N);
  rep(i, N) rd(A[i], B[i]);

  vector<vector<ll>> DP(N + 1, vector<ll>(K + 1, 0));
  rep(i, N) {                 // using upto ith candy
    rep2(j, 1, K + 1) {       // make j
      rep2(m, 1, A[i] + 1) {  // with m bags of it
        ll remainder = j - m * B[i];
        if (remainder < 0) break;
        if (remainder == 0) {
          DP[i][j]++;
          DP[i][j] %= MOD;
        }

        if (remainder > 0 && i > 0) {
          DP[i][j] += 1 * DP[i - 1][remainder];
          DP[i][j] %= MOD;
        }
      }

      if (i > 0) {
        DP[i][j] += DP[i - 1][j];
        DP[i][j] %= MOD;
      }
    }
  }

  cout << DP[N - 1][K] << endl;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T = 1;
  // rd(T);

  rep(i, T) {
    // cout<<"Case #"<<i+1<<": ";
    solve();
    // bool result = solve();
    // if(result) cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
  }

  return 0;
}
