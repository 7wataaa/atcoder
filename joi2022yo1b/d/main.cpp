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

#define _GLIBCXX_DEBUG

#define rep(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))

#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define fs first
#define sc second
#define pb push_back
#define ins insert
#define Endl endl

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
  ll n;
  cin >> n;

  // 出現した整数, 出現回数
  map<ll, ll> m;

  set<ll> nums;

  rep(i, 0, n) {
    ll a;
    cin >> a;

    m[a]++;

    nums.ins(a);
  }

  // m[nums]を見ていって、最小の出現回数をもつ出現した整数たちを求める

  ll minAppearedNum = __LONG_LONG_MAX__;

  for (auto [key, value] : m) {
    minAppearedNum = min(minAppearedNum, value);
  }

  // 最小出現回数を持つ要素たち
  V<pair<ll, ll>> vec;

  for (auto [key, value] : m) {
    if (value == minAppearedNum) {
      vec.pb({key, value});
    }
  }

  sort(all(vec));

  cout << vec.front().first << endl;
}
