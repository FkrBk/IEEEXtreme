// Author: Pasindu Wijesena
// Attainable Score: 20

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

ll modpow(ll x, ll n, ll MOD) {
  if (n == 0) return 1 % MOD;
  ll u = modpow(x, n / 2, MOD);
  u = (u * u) % MOD;
  if (n % 2 == 1) u = (u * x) % MOD;
  return u;
}

bool solve() {
  ll P, Q, N, M;
  rd(P, Q, N, M);
  ll sum = 0;
  
  vector<ll>mods;
  
  rep2(i, 1, N + 1) {
    
	ll res=modpow(i,Q,M);
    if(i>1)
    {
		if(res!=mods[0])mods.push_back(res);
		else break;
	}else{
		mods.push_back(res);
	}
  }
  
  int mods_size=mods.size();

  ll rP = 1;
  rep2(i, 1, N + 1) {
    sum = (sum + (((rP * P) % M) * mods[(i-1)%mods_size]) % M) % M;
    rP = (rP * P) % M;
    
  }

  cout << sum << endl;
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
