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
  ll n, k;
  cin >> n >> k;

  V<V<ll>> vec(n);

  // 合計, index
  V<pair<ll, ll>> totalScores(n);

  rep(i, 0, n) {
    V<ll> v(3);
    cin >> v[0] >> v[1] >> v[2];
    vec[i] = v;
    totalScores[i] = {v[0] + v[1] + v[2], i};
  }

  // totalScoresのインデックスを持つ
  V<ll> ranks(n);

  auto _sortedTotalScores = totalScores;
  sort(_sortedTotalScores.rbegin(), _sortedTotalScores.rend());

  ll kTotal = 0;

  for (ll i = 0; i < n; i++) {
    // ここでのiが順位となる
    ranks[_sortedTotalScores[i].sc] = i;

    if (i == (k - 1)) {
      kTotal = _sortedTotalScores[i].fs;
    }
  }

  for (ll i = 0; i < n; i++) {
    auto iTotalScore = totalScores[i];

    // 自身の順位がk以下ならOK
    if (ranks[iTotalScore.second] <= k - 1) {
      cout << "Yes" << endl;
      continue;
    }

    // (k位の合計) - (自身の合計) が300以内だとOK
    if ((kTotal - iTotalScore.fs) <= 300) {
      cout << "Yes" << endl;
      continue;
    }

    cout << "No" << endl;
  }
}
