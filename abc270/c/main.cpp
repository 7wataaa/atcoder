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
/* 単純なリストの入力ショートハンド */
V<ll> vllin(ll &n) {
  V<ll> vec(n);
  for (ll i = 0; i < n; i++) {
    cin >> vec[i];
  }
  return vec;
}
string strin() {
  string str;
  cin >> str;
  return str;
}

// 頂点 s を始点とした深さ優先探索
void bfs(int s, V<V<ll>> &G, V<bool> &seen, V<ll> &prev) {
  queue<ll> que; // 探索候補の頂点番号を入れるキュー
  // 頂点 s を始点として登録する
  seen[s] = true;
  que.push(s);
  // キューに要素が残っている限り
  while (que.size() > 0) {
    ll v = que.front();
    que.pop();
    // 頂点 v に隣接している頂点 nv について、
    for (auto nv : G[v]) {
      // nv がすでに探索済みならば、スキップする
      if (seen[nv]) {
        continue;
      }
      // そうでなければ、seen[nv] や prev[nv]
      // を更新したうえで、nvをキューに入れる
      seen[nv] = true;
      prev[nv] = v;
      que.push(nv);
    }
  }
  return;
}

int main() {
  ll n = llin, x = llin, y = llin;
  x--;
  y--;

  V<V<ll>> G(n, V<ll>());
  for (ll i = 0; i < n - 1; i++) {
    ll u = llin, v = llin;
    u--;
    v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  V<bool> seen(n, false);
  V<ll> prev(n, -1);

  bfs(x, G, seen, prev);

  V<ll> order;
  ll now = y;
  while (now != -1) {
    order.push_back(now);
    now = prev[now];
  }
  reverse(all(order));

  for (ll i = 0; i < order.size(); ++i) {
    cout << order[i] + 1;
    if (i != order.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
}
