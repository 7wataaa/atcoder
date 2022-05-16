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
#define rall(a) (a).rbegin(), (a).rend()
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
  ll n, q;
  cin >> n >> q;

  V<ll> X(n);
  rep(i, 0, q) { cin >> X[i]; }

  V<ll> vec(n);
  rep(i, 0, n) { vec[i] = i + 1; }

  // vecIndexMap[ボール番号] = vec内でのindex
  map<ll, ll> vecIndexMap;
  rep(i, 0, n) { vecIndexMap[i + 1] = i; }

  for (ll i = 0; i < q; i++) {
    ll target = X[i];

    ll rorl = vecIndexMap[target] + 1 < n ? 1 : -1;

    // 交換するボールの番号 (targetの右隣のボールの番号)
    // vec[targetの場所+1]が範囲外になる場合はvec[targetの場所-1]とする
    ll target2 = vec[vecIndexMap[target] + rorl];

    // vec内で実際に交換する
    swap(vec[vecIndexMap[target]], vec[vecIndexMap[target2]]);

    // vecIndexMapを更新
    swap(vecIndexMap[target], vecIndexMap[target2]);
  }

  for (auto c : vec) {
    cout << c << ' ';
  }
  cout << endl;
}
