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

int main() {
  ll n, m;
  cin >> n >> m;

  V<pair<ll, ll>> vec(m);

  map<ll, ll> popTimes;

  rep(i, 0, m) {
    ll a, b;
    cin >> a >> b;

    popTimes[a]++;
    popTimes[b]++;

    vec[i] = {a, b};
  }

  for (ll i = 1; i <= n; i++) {
    if (popTimes[i] >= 3) {
      cout << "No" << endl;
      return 0;
    }
  }

  if (m >= n) {
    cout << "No" << endl;
    return 0;
  }

  rep(i, 0, n) { par.push_back(i); }

  for (ll i = 0; i < vec.size(); i++) {
    auto [a, b] = vec[i];

    if (sameRoot(a - 1, b - 1)) {
      cout << "No" << endl;
      return 0;
    }

    uniteRoot(a - 1, b - 1);
  }

  cout << "Yes" << endl;
}
