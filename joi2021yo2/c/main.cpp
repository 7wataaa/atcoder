#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

template <class T> using V = std::vector<T>;

template <typename T>
std::ostream &operator<<(std::ostream &stream, const vector<T> v) {
  for (ll i = 0; i < v.size(); i++) {
    stream << v[i];

    if (i != v.size() - 1) {
      stream << ' ';
    }
  }

  return stream;
}

template <typename T, typename V>
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

/* グラフ系 */
struct Edge {
  ll to;
  ll cost;
};
// [頂点][Edge一覧]
using Graph = vector<vector<Edge>>;
// pair<>
using P = pair<ll, ll>;

/* 深さ優先探索 */
void dfs(const Graph &G, V<bool> &seen, ll v, ll depth, ll &maxDepth) {
  seen[v] = true;

  // vから行ける各頂点 next_vについて
  for (auto next_v : G[v]) {
    // next_vが探索済みだったらcontinue
    if (seen[next_v.to]) {
      continue;
    }

    maxDepth = max(depth, maxDepth);

    dfs(G, seen, next_v.to, depth + 1, maxDepth);
  }
}

int main() {
  ll n, d, k;
  cin >> n >> d >> k;

  // pair<開催時刻, 開催してる町>
  V<pair<ll, ll>> vec(n);

  rep(i, 0, n) {
    ll p, s;
    cin >> p >> s;

    vec[i] = {s, p};
  }

  sort(all(vec));

  Graph G(n, V<Edge>(0));

  for (ll i = 0; i < n - 1; i++) {
    for (ll j = i + 1; j < n; j++) {
      // iからjへの辺を追加できるか判定しながら追加してく

      ll remainingTime = vec[j].fs - vec[i].fs;
      ll travelTime = d;
      bool isDifferentTown = vec[i].sc != vec[j].sc;

      // 街が違う場合、残り時間が移動時間よりも小さければ辺を張らない
      if (isDifferentTown && remainingTime < travelTime) {
        continue;
      }

      Edge e;
      e.to = vec[j].fs;
      e.cost = max(remainingTime, travelTime);

      G[i].push_back(e);
    }
  }

  V<bool> seen(n, false);

  ll ans = 0;

  dfs(G, seen, 0, 0, ans);

  cout << ans << endl;
}
