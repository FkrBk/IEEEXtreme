// Author: Pasindu Wijesena
// Attainable Score: 67

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

bool solve() {
  int N, M;
  rd(N, M);
  vector<int> A(N, 0);  // 110110111
  rep(i, N) {
    string S;
    rd(S);
    rep(j, M) {
      char v = S[j];
      if (v == 'y') A[i] = A[i] | (1 << j);
    }
  }

  // print the bitmask
  // rep(i,N){
  //   cout<<A[i]<<endl;
  // }
  // cout<<endl;

  const int MM = 1 << M;
  ll ways = 0;

  // cout << MM << endl;  // 10000

  int prev[MM][2], now[MM][2];
  // build base case
  // N = 0, T = 0
  rep(i, MM) {  // one team member
    if ((i & A[0]) == i) // 111111111   00110100
      prev[i][0] = 1;
    else
      prev[i][0] = 0;
  }
  rep(i, MM) prev[i][1] = 0;  // two team members

  // rep(i, MM) cout << prev[i][0] << ' ';
  // cout << endl;

  rep2(x, 1, N) {
    // get previous numbers and initialize
    rep(i, MM) {
      now[i][0] = prev[i][0];
      now[i][1] = prev[i][1];
    }

    // one team member
    rep(i, MM) if ((i & A[x]) == i) now[i][0]++;

    // two team members
    rep(i, MM) {                         // 00010111
      int fullfill = i & (~(i & A[x]));  // need to fullfill this
      if (prev[fullfill][0]) {
        now[i][1] += prev[fullfill][0];
      }
    }

    // three team members
    {
      int i = MM - 1;                    // all true
      int fullfill = i & (~(i & A[x]));  // need to fullfill this
      if (prev[fullfill][1]) {
        // add to result
        ways += prev[fullfill][1];
      }
    }

    // transfer
    rep(i, MM) {
      prev[i][0] = now[i][0];
      prev[i][1] = now[i][1];
    }

    // rep(i, MM) cout << prev[i][0] << ' ';
    // cout << endl;
  }

  cout << ways << endl;
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