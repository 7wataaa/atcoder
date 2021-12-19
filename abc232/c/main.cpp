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

bool isConnected(const V<V<ll>> &graph, ll v1, ll v2) {
  for (auto e : graph[v1]) {
    if (e == v2) {
      return true;
    }
  }

  return false;
}

int main() {
  ll n, m;
  cin >> n >> m;

  V<V<ll>> X(n);
  V<V<ll>> Y(n);

  for (ll i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;

    X[a - 1].pb(b - 1);
    X[b - 1].pb(a - 1);
  }
  for (ll i = 0; i < m; i++) {
    ll c, d;
    cin >> c >> d;

    Y[c - 1].pb(d - 1);
    Y[d - 1].pb(c - 1);
  }

  V<ll> P(n);
  for (ll i = 0; i < n; i++) {
    P[i] = i;
  }

  do {
    bool failFlag = false;

    for (ll i = 0; i < n; i++) {
      for (ll j = i + 1; j < n; j++) {
        bool isXConnecting = isConnected(X, i, j);
        bool isYConnecting = isConnected(Y, P[i], P[j]);

        if (isXConnecting != isYConnecting) {
          // このPではだめ
          failFlag = true;
          break;
        }
      }

      if (failFlag) {
        break;
      }
    }

    if (!failFlag) {
      cout << "Yes" << endl;
      return 0;
    }

  } while (next_permutation(all(P)));

  cout << "No" << endl;
}
