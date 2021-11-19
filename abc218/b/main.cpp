#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

#define _GLIBCXX_DEBUG

#define rep(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))

#define endl '\n'
#define all(a) (a).begin(), (a).end()

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

int main() {
  vector<char> atoz(26);
  for (ll i = 0; i < 26; i++) {
    atoz[i] = (char)(97 + i);
  }

  string ans;

  rep(i, 0, 26) {
    ll p;
    cin >> p;

    ans.push_back(atoz[p - 1]);
  }

  cout << ans << endl;
}
