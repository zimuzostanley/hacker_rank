#include <iostream>

using namespace std;

int repeatCount(string);

int main() {
  int count;
  string word;
  cin >> count;

  while (count-- > 0) {
    cin >> word;
    cout << repeatCount(word) << endl;
  }
}

int repeatCount(string word) {
  char cur = word[0];
  int count = 0;
  for(string::iterator it = word.begin() + 1; it != word.end(); it++) {
    if (*it != cur) {
      cur = *it;
    }
    else {
      count++;
    }
  }
  return count;
}
