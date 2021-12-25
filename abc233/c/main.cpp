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
const int d[5] = {0, 1, 0, -1, 0};

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

int main() {
  ll n, x;
  cin >> n >> x;

  V<V<ll>> vec(n);
  rep(i, 0, n) {
    ll l;
    cin >> l;

    V<ll> v(l);
    rep(j, 0, l) { cin >> v[j]; }

    vec[i] = v;
  }

  ll ans = 0;

  // 積､階層
  queue<pair<ll, ll>> que;
  for (auto e : vec[0]) {
    que.push({e, 0});
  }

  while (!que.empty()) {
    auto e = que.front();
    que.pop();

    if (e.second == n - 1) {
      if (e.first == x) {
        ans++;
      }

      continue;
    }

    for (ll i = 0; i < vec[e.second + 1].size(); i++) {
      ll a = vec[e.second + 1][i];
      ll b = e.first * a;

      if (b > x) {
        continue;
      }

      que.push({b, e.second + 1});
    }
  }

  cout << ans << endl;
}
