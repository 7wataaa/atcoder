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

char nextChar(char c) {
  if (c != 'z') {
    return c + 1;
  } else {
    return 'a';
  }
}

string changeAllChar(string &str) {
  for (ll i = 0; i < str.size(); i++) {
    str[i] = nextChar(str[i]);
  }
  return str;
}

int main() {
  string s;
  cin >> s;

  string t;
  cin >> t;

  if (s == t) {
    cout << "Yes" << endl;
    return 0;
  }

  changeAllChar(t);

  for (ll i = 0; i < 100; i++) {
    if (s == t) {
      cout << "Yes" << endl;
      return 0;
    }

    changeAllChar(t);
  }

  cout << "No" << endl;
}
