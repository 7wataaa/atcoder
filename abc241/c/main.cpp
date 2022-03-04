#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

template <class T> using V = std::vector<T>;

template <class T>
std::ostream &operator<<(std::ostream &stream, const vector<T> v) {
  for (ll i = 0; i < v.size(); i++) {
    stream << v[i];

    if (i != v.size() - 1) {
      stream << ' ';
    }
  }

  return stream;
}

template <class T, class V>
std::ostream &operator<<(std::ostream &stream, const pair<T, V> p) {
  stream << "(" << p.first << ", " << p.second << ")";

  return stream;
}

#define _GLIBCXX_DEBUG

#define rep(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))

#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define fs first
#define sc second
#define pb push_back
#define ins insert

const ll NUMBER = 1000000007;

/* 四方向見るための配列 [y + d[i]][x + d[i + 1]]←こんな感じで使う*/
const int d[5] = {0, 1, 0, -1, 0};

/* char to int */
int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

/* すべて同一charで構成された文字列かの判定 */
bool isSameCharAll(string str) {
  return (str.find_first_not_of(str[0]) == string::npos);
}

/* DP */
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

/* Union-find */
V<ll> par;

ll findRoot(ll x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = findRoot(par[x]);
  }
}

bool sameRoot(ll x, ll y) { return findRoot(x) == findRoot(y); }

void uniteRoot(ll x, ll y) {
  x = findRoot(x);
  y = findRoot(y);

  if (x == y) {
    return;
  }

  par[x] = y;
}

/* 繰り返し二乗法 */
ll pow_mod(ll n, ll k, ll mod) {
  ll result = 1;
  for (; k > 0; k >>= 1) {
    if (k & 1) {
      result = (result * n) % mod;
    }
    n = (n * n) % mod;
  }
  return result;
}

int main() {
  ll n;
  cin >> n;

  V<V<char>> vec(n, V<char>(n));

  rep(i, 0, n) {
    rep(j, 0, n) { cin >> vec[i][j]; }
  }

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      char c = vec[i][j];

      if (c != '#') {
        continue;
      }

      // 5個分を8方向みて#を数える、合計が3以上ならYes([i][j]+追加できる2+3 = 6)

      bool top = i - 5 >= 0;
      bool right = n > j + 5;
      bool bottom = n > i + 5;
      bool left = j - 5 >= 0;
      bool topRight = top && right;
      bool bottomRight = right && bottom;
      bool bottomLeft = bottom && left;
      bool topLeft = left && top;

      if (top) {
        ll blackSum = 0;
        for (ll topI = 1; topI < 6; topI++) {
          if (vec[i - topI][j] == '#') {
            blackSum++;
          }
        }
        if (blackSum >= 3) {
          cout << "Yes" << endl;
          return 0;
        }
      }

      if (right) {
        ll blackSum = 0;
        for (ll rightJ = 1; rightJ < 6; rightJ++) {
          if (vec[i][j + rightJ] == '#') {
            blackSum++;
          }
        }
        if (blackSum >= 3) {
          cout << "Yes" << endl;
          return 0;
        }
      }

      if (bottom) {
        ll blackSum = 0;
        for (ll bottomI = 1; bottomI < 6; bottomI++) {
          if (vec[i + bottomI][j] == '#') {
            blackSum++;
          }
        }
        if (blackSum >= 3) {
          cout << "Yes" << endl;
          return 0;
        }
      }

      if (left) {
        ll blackSum = 0;
        for (ll leftI = 1; leftI < 6; leftI++) {
          if (vec[i][j - leftI] == '#') {
            blackSum++;
          }
        }
        if (blackSum >= 3) {
          cout << "Yes" << endl;
          return 0;
        }
      }

      if (topRight) {
        ll blackSum = 0;
        for (ll topRightIJ = 1; topRightIJ < 6; topRightIJ++) {
          if (vec[i - topRightIJ][j + topRightIJ] == '#') {
            blackSum++;
          }
        }
        if (blackSum >= 3) {
          cout << "Yes" << endl;
          return 0;
        }
      }

      if (bottomRight) {
        ll blackSum = 0;
        for (ll bottomRightIJ = 1; bottomRightIJ < 6; bottomRightIJ++) {
          if (vec[i + bottomRightIJ][j + bottomRightIJ] == '#') {
            blackSum++;
          }
        }
        if (blackSum >= 3) {
          cout << "Yes" << endl;
          return 0;
        }
      }

      if (bottomLeft) {
        ll blackSum = 0;
        for (ll bottomLeftIJ = 1; bottomLeftIJ < 6; bottomLeftIJ++) {
          if (vec[i + bottomLeftIJ][j - bottomLeftIJ] == '#') {
            blackSum++;
          }
        }
        if (blackSum >= 3) {
          cout << "Yes" << endl;
          return 0;
        }
      }

      if (topLeft) {
        ll blackSum = 0;
        for (ll topLeftIJ = 1; topLeftIJ < 6; topLeftIJ++) {
          if (vec[i - topLeftIJ][j - topLeftIJ] == '#') {
            blackSum++;
          }
        }
        if (blackSum >= 3) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;
}
