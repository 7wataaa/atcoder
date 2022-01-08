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
  ll n, m;
  cin >> n >> m;

  V<V<ll>> boxes(n);

  for (ll i = 0; i < n; i++) {
    boxes[i] = {i + 1};
  }

  for (ll i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;

    for (auto &v : boxes) {
      auto r = find(all(v), x);
      if (r != v.end()) {
        ll ballnumber = *r;

        v.erase(r);

        boxes[y - 1].push_back(ballnumber);

        break;
      }
    }
  }

  V<ll> ans(n);

  for (ll i = 0; i < boxes.size(); i++) {
    for (ll j = 0; j < boxes[i].size(); j++) {
      ll ballnumber = boxes[i][j];

      ans[ballnumber - 1] = i + 1;
    }
  }

  for (auto i : ans) {
    cout << i << endl;
  }
}
