#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

template <class T> using V = std::vector<T>;

#define _GLIBCXX_DEBUG

#define rep(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))

#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define fs first
#define sc second
#define pb push_back
#define ins insert

const ll NUMBER = 1000000007;

int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

bool isSameCharAll(string str) {
  return (str.find_first_not_of(str[0]) == string::npos);
}

template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

V<bool> seen;
void dfs(const V<pair<ll, V<ll>>> &G, ll v) {
  seen[v] = true;

  for (auto next_v : G[v].sc) {
    if (seen[next_v]) {
      continue;
    }

    dfs(G, next_v);
  }
}

int main() {
  ll n;
  cin >> n;

  V<pair<ll, V<ll>>> vec(n);

  rep(i, 0, n) {
    ll t, k;
    cin >> t >> k;
    V<ll> v(k);
    rep(j, 0, k) {
      ll a;
      cin >> a;
      v[j] = a - 1;
    }

    vec[i] = {t, v};
  }

  set<ll> s;

  ll ans = 0;

  seen.assign(n, false);

  for (auto &x : s) {
    ans += x;
  }

  cout << ans << endl;
}
