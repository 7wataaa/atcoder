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

bool isGoodCake(string &cake) {
  for (ll i = 1; i < cake.size(); i++) {
    if (cake[i] < cake[i - 1]) {
      return false;
    };
  }
  return true;
}

int main() {
  ll n, q;
  cin >> n >> q;

  V<string> cakes(q);
  rep(i, 0, q) {
    string s;
    cin >> s;
    cakes[i] = s;
  }

  for (auto cake : cakes) {
    queue<pair<string, ll>> todo;
    todo.push({cake, 0});

    map<string, bool> dist;

    if (isGoodCake(cake)) {
      cout << 0 << endl;
      continue;
    }

    while (!todo.empty()) {
      auto c = todo.front();
      todo.pop();

      if (dist[c.fs]) {
        continue;
      }

      dist[c.fs] = true;

      for (ll i = 0; i < c.fs.size() - 1; i++) {
        string _s(c.fs.begin(), c.fs.end() - i);
        string _rs(_s.rbegin(), _s.rend());
        string _s2 =
            c.fs.substr(c.fs.size() - i, c.fs.size() - (c.fs.size() - i));
        string s = _rs + _s2;

        if (dist[s]) {
          continue;
        }

        if (isGoodCake(s)) {
          cout << c.sc + 1 << endl;
          todo = {};
          break;
        }

        todo.push({s, c.sc + 1});
      }
    }
  }
}
