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
  /* stream << "(" << p.first << ", " << p.second << ")"; */
  stream << p.first << " " << p.second;
  return stream;
}
#define _GLIBCXX_DEBUG
#define rep(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fs first
#define sc second
#define pb push_back
#define ins insert
const ll NUMBER = 1000000007;
/* 四方向見るための配列 [y + d[i]][x + d[i + 1]]←こんな感じで使う*/
const int d[5] = {0, 1, 0, -1, 0};
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
/* Union-find */
V<ll> par;
ll findRoot(ll x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = findRoot(par[x]);
  }
}
bool sameRoot(ll x, ll y) {
  return findRoot(x) == findRoot(y);
}
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
/* pair同士の足し算 */
template <class T, class V>
pair<T, V> &operator+(const pair<T, V> &x, const pair<T, V> y) {
  return make_pair((x.fs + y.fs), (x.sc + y.sc));
}
/* 方向に進む用 */
const V<pair<ll, ll>> d_pair = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
/* ll n; cin >> n;力のショートハンド */
ll llin() {
  ll in;
  cin >> in;
  return in;
}
#define llin llin()

int main() {
  ll h = llin, w = llin;
  V<V<ll>> A(h, V<ll>(w, 0));
  for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w; j++) {
      A[i][j] = llin;
    }
  }

  V<ll> XNums(h);
  for (ll i = 0; i < h; i++) {
    XNums[i] = accumulate(all(A[i]), 0);
  }

  V<ll> YNums(w);
  for (ll i = 0; i < w; i++) {
    ll t = 0;
    for (ll j = 0; j < h; j++) {
      t += A[j][i];
    }
    YNums[i] = t;
  }

  V<V<ll>> ans(h, V<ll>(w));

  for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w; j++) {
      ll a = A[i][j];
      ll x = XNums[i] - a;
      ll y = YNums[j] - a;
      ans[i][j] = x + y + a;
    }
  }

  for (auto v : ans) {
    cout << v << endl;
  }
}
