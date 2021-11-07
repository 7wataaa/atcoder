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

  ll x = 0, y = 0, z = 0;

  for (ll i = 0; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;

    if (i == 0) {
      x = a;
      y = b;
      continue;
    } else if (i == 1) {
      if (x == a || y == a) {
        z = a;
      } else if (x == b || y == b) {
        z = b;
      } else {
        cout << "No" << endl;
        return 0;
      }
      continue;
    }

    if (z != a && z != b) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
