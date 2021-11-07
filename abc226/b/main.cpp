#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

#define _GLIBCXX_DEBUG

#define rep(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))

#define endl '\n'
#define all(a) (a).begin(), (a).end()

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

int main() {
  ll n;
  cin >> n;

  vector<pair<ll, vector<ll>>> vec(n);

  for (ll i = 0; i < n; i++) {
    ll m;
    cin >> m;
    vector<ll> v(m);
    for (ll j = 0; j < m; j++) {
      ll a;
      cin >> a;
      v[j] = a;
    }

    vec[i] = {m, v};
  }

  sort(all(vec));

  for (ll i = 1; i < n; i++) {
    auto x = vec.at(i - 1).second;
    auto y = vec.at(i).second;
    if (x.size() == y.size() && equal(all(x), y.begin())) {
      vec.at(i - 1).first = -1;
    }
  }

  ll t = 0;
  for (ll i = 0; i < n; i++) {
    if (vec[i].first == -1) {
      t++;
    }
  }

  cout << n - t << endl;
}
