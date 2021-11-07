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
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> vec(n);

  rep(i, 0, n) {
    vector<ll> v(m);

    rep(i, 0, m) {
      ll x;
      cin >> x;
      v[i] = x;
    }

    vec[i] = v;
  }

  for (ll i = 0; i < n; i++) {
    for (ll j = 1; j < m; j++) {
      if (vec[i][j - 1] + 1 != vec[i][j]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  for (ll i = 1; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      if (vec[i][j] != vec[i - 1][j] + 7) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  for (ll i = 0; i < m; i++) {
    if (i != 0 && vec[0][i] % 7 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
