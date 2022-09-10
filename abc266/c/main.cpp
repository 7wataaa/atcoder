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
// *
#define x first
// *
#define y second
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

//_頂点
typedef struct vtex {
  double x, y; // 座標値
} VTEX;

// ２次元ベクトル
typedef struct vec2 {
  double x, y; // ベクトルのｘ、ｙ成分
} VEX2;

// 線分（辺）
typedef struct edge {
  VTEX s, e; // 始点、終点
} EDGE;

// 線分をベクトル形式に変換する
VEX2 _vector(EDGE ln) {
  VEX2 v;
  v.x = ln.e.x - ln.s.x;
  v.y = ln.e.y - ln.s.y;
  return v;
}

// ２次元ベクトルの外積を返す
double exterp(VEX2 vi, VEX2 vj) {
  double p;
  return p = vi.x * vj.y - vi.y * vj.x;
}

int main() {
  pair<double, double> inA = {llin, llin};
  pair<double, double> inB = {llin, llin};
  pair<double, double> inC = {llin, llin};
  pair<double, double> inD = {llin, llin};

  int n = 4;   // 多角形の頂点数
  EDGE ln[4] = // 多角形の辺集合：
      {{{inA.x + 100, inA.y + 100}, {inB.x + 100, inB.y + 100}},  // No.1 辺
       {{inB.x + 100, inB.y + 100}, {inC.x + 100, inC.y + 100}},  // No.2 辺
       {{inC.x + 100, inC.y + 100}, {inD.x + 100, inD.y + 100}},  // No.3 辺
       {{inD.x + 100, inD.y + 100}, {inA.x + 100, inA.y + 100}}}; // No.4 辺
  bool convex; // 凹多角形判定フラグ
  int i, j;    // 辺要素インデクス
  VEX2 vi;     // 辺ｉのベクトル
  VEX2 vj;     // 辺ｊのベクトル

  convex = 0;
  for (j = 1; j < n; j++) {
    i = j - 1;
    vi = _vector(ln[i]);
    vj = _vector(ln[j]);
    convex = exterp(vi, vj) < 0;
    if (convex)
      break;
  }

  cout << ((convex) ? "Yes" : "No") << endl;
}
