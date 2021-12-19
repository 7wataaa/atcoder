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
  ll h, w;
  cin >> h >> w;

  V<V<char>> vec(h, V<char>(w));
  rep(i, 0, h) {
    rep(j, 0, w) {
      char c;
      cin >> c;

      vec[i][j] = c;
    }
  }

  ll ans = 1;

  V<V<ll>> dp(h, V<ll>(w, -1));
  dp[0][0] = 1;

  for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w; j++) {
      if (i == 0 && j == 0) {
        continue;
      }

      char current = vec[i][j];

      if (current == '#') {
        break;
      }

      ll x = -1;

      if (!(i - 1 < 0)) {
        ll top = dp[i - 1][j];

        x = max(x, top + 1);
      }

      if (!(j - 1 < 0)) {
        ll left = dp[i][j - 1];

        x = max(x, left + 1);
      }

      dp[i][j] = x;
      ans = max(x, ans);
    }
  }

  cout << ans << endl;
}
