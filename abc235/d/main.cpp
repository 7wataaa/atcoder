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

struct MapState {
  bool hasDoneQuery1;
  bool hasDoneQuery2;
};

struct State {
  ll times;
  ll x;
};

int main() {
  ll a, n;
  cin >> a >> n;

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  map<ll, MapState> d;
  queue<State> que;
  que.push({0, n});

  while (!que.empty()) {
    auto e = que.front();
    que.pop();

    ll times = e.times;
    ll x = e.x;

    if (!d[x].hasDoneQuery1) {
      if (x % a == 0) {
        que.push({times + 1, x / a});

        if ((x / a) == 1) {
          cout << times + 1 << endl;
          return 0;
        }
      }

      d[x].hasDoneQuery1 = true;
    }

    if (!d[x].hasDoneQuery2) {
      bool canQuery2 = (x >= 10) && (to_string(x)[1] != '0');

      if (canQuery2) {
        // xの先頭を末尾に持ってきた数(query2の逆)をpush

        string strX = to_string(x);

        string s1(strX.begin() + 1, strX.end());

        ll newX = stoll(s1 + strX.front());

        que.push({times + 1, newX});
      }

      d[x].hasDoneQuery2 = true;
    }
  }

  cout << -1 << endl;
}
/*
312 123
1024 4102

1110 1101
1010 0101
先頭を末尾に持ってくることができる場合がある

 */