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

int compute1(int node, int parent, vector<vector<int>> &E, vector<pii> &DA,
             vector<pii> &DB) {
  // return the longest distance from the node
  for (auto v : E[node]) {
    if (v == parent) continue;
    int dist = 1 + compute1(v, node, E, DA, DB);
    if (dist >= DA[node].first) {
      DB[node] = DA[node];
      DA[node].first = dist;
      DA[node].second = v;
    } else if (dist > DB[node].first) {
      DB[node].first = dist;
      DB[node].second = v;
    }
  }

  return DA[node].first;
}

void compute2(int node, int parent, vector<vector<int>> &E, vector<pii> &DA,
              vector<pii> &DB, vector<int> &DFinal) {
  // compute the max length other part
  // DFinal[node] = DA[node].first;
  if (parent != -1) {
    // not the root
    int fromParent = DA[parent].first;
    if (DA[parent].second == node) {
      fromParent = DB[parent].first;  // this is the alternative
    }
    // if(fromParent){
    fromParent++;
    // }
    // cout<<" nOde "<<node+1<<" from "<<parent+1<<" "<<fromParent<<endl;
    if (fromParent >= DA[node].first) {
      DB[node] = DA[node];
      DA[node].first = fromParent;
      DA[node].second = parent;
    } else if (fromParent > DB[node].first) {
      DB[node].first = fromParent;
      DB[node].second = parent;
    }
    // DFinal[node] = max(DFinal[node], fromParent + 1);
  }

  for (auto v : E[node]) {
    if (v == parent) continue;
    compute2(v, node, E, DA, DB, DFinal);
  }
}

bool solve() {
  int N1;
  rd(N1);
  vector<vector<int>> E1(N1);
  vector<pii> D1A(N1, {0, 0}), D1B(N1, {0, 0});
  vector<int> DF1(N1);
  rep(i, (N1 - 1)) {
    int u, v;
    rd(u, v);
    u--;
    v--;
    E1[u].push_back(v);
    E1[v].push_back(u);
  }

  int N2;
  rd(N2);
  vector<vector<int>> E2(N2);
  vector<pii> D2A(N2, {0, 0}), D2B(N2, {0, 0});
  vector<int> DF2(N2);
  rep(i, N2 - 1) {
    int u, v;
    rd(u, v);
    u--;
    v--;
    E2[u].push_back(v);
    E2[v].push_back(u);
  }

  compute1(0, -1, E1, D1A, D1B);
  compute2(0, -1, E1, D1A, D1B, DF1);
  // rep(i, N1) { cout << D1A[i].first << ' '; }
  // cout << endl;

  compute1(0, -1, E2, D2A, D2B);
  compute2(0, -1, E2, D2A, D2B, DF2);
  // rep(i, N2) { cout << D2A[i].first << ' '; }
  // cout << endl;

  int mxDistance = 0;

  int mxNode1 = 0;
  rep(i, N1) {
    if (D1A[i].first < D1A[mxNode1].first) {
      mxNode1 = i;
    }
    mxDistance = max(mxDistance, D1A[i].first);
  }

  int mxNode2 = 0;
  rep(i, N2) {
    if (D2A[i].first < D2A[mxNode2].first) {
      mxNode2 = i;
    }
    mxDistance = max(mxDistance, D2A[i].first);
  }

  cout << max(D1A[mxNode1].first + D2A[mxNode2].first + 1, mxDistance) << endl;
  cout << mxNode1 + 1 << ' ' << mxNode2 + 1 << endl;
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
