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

  ll blacknum = 0;

  V<V<char>> vec(n);
  rep(i, 0, n) {
    V<char> v(m);
    rep(j, 0, m) {
      char c;
      cin >> c;
      v[j] = c;

      if (c == '#')
        blacknum++;
    }
    vec[i] = v;
  }

  queue<pair<ll, ll>> q;
  q.push({0, 0});

  V<ll> _initRow(m, -1);
  V<V<ll>> dist(n, _initRow);

  while (!q.empty()) {
    auto point = q.front();
    q.pop();

    for (ll i = 0; i < 4; i++) {
      // 見るところが壁だったらcontinue
      if (vec[point.fs + d[i + 1]][point.sc + d[i]] == '#')
        continue;

      // すでに通過した場所ならcontinue
      if (dist[point.fs + d[i + 1]][point.sc + d[i]] != -1)
        continue;

      dist[point.fs + d[i + 1]][point.sc + d[i]] = dist[point.fs][point.sc] + 1;

      q.push({point.fs + d[i + 1], point.sc + d[i]});
    }
  }

  ll shortestDistance = dist[n - 1][m - 1];

  if (shortestDistance == -1) {
    cout << -1 << endl;
  } else {
    cout << ((n * m - 1) - blacknum) - shortestDistance << endl;
  }
}
