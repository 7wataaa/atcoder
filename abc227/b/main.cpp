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
  ll n;
  cin >> n;

  V<ll> vec(n);
  rep(i, 0, n) { cin >> vec[i]; }

  V<ll> oks;

  for (ll a = 1; a < 143; a++) {
    for (ll b = 1; b < 125; b++) {
      oks.pb((4 * a * b) + (3 * a) + (3 * b));
    }
  }

  ll ans = 0;

  for (ll i = 0; i < vec.size(); i++) {
    if (find(all(oks), vec[i]) == oks.end()) {
      ans++;
    }
  }

  cout << ans << endl;
}
