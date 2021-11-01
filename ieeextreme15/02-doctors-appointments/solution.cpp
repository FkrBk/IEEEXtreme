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

bool solve() {
  int N;
  rd(N);
  vector<pair<int, pii>> A(N);  // [start, end, index]
  for (auto &a : A) rd(a.first, a.second.first);
  rep(i, N) A[i].second.second = i + 1;
  sort(A.begin(), A.end());

  // [-end,start,index]
  for (auto &a : A) {
    swap(a.first, a.second.first);
    a.first = -a.first;
  }

  // a.first -> -ending day
  priority_queue<pair<int, pii>> PQ;
  int day = 1;
  int index = 0;
  vector<int> R;
  while (day <= N) {
    while (index < N && A[index].second.first <= day)
      PQ.push(A[index++]);  // get possible events pushed
    if (!PQ.size()) return false;

    auto top = PQ.top();
    R.push_back(top.second.second);
    PQ.pop();

    // drop the ones that expire
    while (PQ.size() && -PQ.top().first == day) {
      return false;
    }
    day++;
  }
  for (auto r : R) cout << r << ' ';
  cout << endl;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T = 1;
  rd(T);

  rep(i, T) {
    // cout<<"Case #"<<i+1<<": ";
    // solve();
    bool result = solve();
    if (result)
      ;
    else
      cout << "impossible" << endl;
  }

  return 0;
}
