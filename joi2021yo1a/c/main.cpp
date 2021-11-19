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

int main() {

  ll n, m;
  cin >> n >> m;

  set<ll> A;
  set<ll> B;

  for (ll i = 0; i < n; i++) {
    ll a;
    cin >> a;

    A.ins(a);
  }

  for (ll i = 0; i < m; i++) {
    ll b;
    cin >> b;

    B.ins(b);
  }

  // 出現した整数, 出現回数
  map<ll, ll> o;

  for (auto a : A) {
    o[a]++;
  }

  for (auto b : B) {
    o[b]++;
  }

  set<ll> s;

  for (auto [key, value] : o) {
    if (value >= 2) {
      s.ins(key);
    }
  }

  for (auto i : s) {
    cout << i << endl;
  }

  if (s.size() == 0) {
    cout << endl;
  }
}
