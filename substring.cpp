#include <iostream>
#include <set>

using namespace std;

bool check_sub(const string&, const string&);

int main() {
  int count = 0;
  string word1;
  string word2;

  cin >> count;

  while(--count >= 0) {
    cin >> word1 >> word2;
    if (check_sub(word1, word2)) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  
}

bool check_sub(const string &word1, const string &word2) {
  set<char> intersect;

  for (string::const_iterator it = word1.begin(); it != word1.end(); it++) {
    intersect.insert(*it);
  }

  for (string::const_iterator it = word2.begin(); it != word2.end(); it++) {
    if (intersect.find(*it) != intersect.end()) {
      return true;
    }
  }
  return false;
}
