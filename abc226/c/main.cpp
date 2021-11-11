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

ll currentTime = 0;

vector<pair<ll, vector<ll>>> vec;

set<ll> learnedList;

ll time(ll targetArts) {
  if (learnedList.find(targetArts) != learnedList.end()) {
    currentTime = 0;
    return 0;
  }

  if (targetArts == 0) {
    learnedList.insert(0);
    currentTime = 0;
    return vec[0].first;
  }

  learnedList.insert(targetArts);
  return time(vec[targetArts].second.back()) + currentTime;
}

int main() {
  ll n;
  cin >> n;

  for (ll i = 0; i < n; i++) {
    ll t, l;
    cin >> t >> l;

    vector<ll> v(l);
    rep(j, 0, l) {
      ll a;
      cin >> a;
      v[j] = a;
    }

    vec.push_back({t, v});
  }

  ll ans = 0;

  auto artsNvec = vec.back().second;

  for (ll i = artsNvec.size(); i >= 0; i--) {
    ans += time(artsNvec.at(i));
  }

  cout << ans << endl;
}
