#include <iostream>
#include <map>

using namespace std;

bool is_palindrome(string);

int main() {
  string word;
  cin >> word;
  if (is_palindrome(word)) {
    cout << "YES"; 
  }
  else {
    cout << "NO"; 
  }
}

bool is_palindrome(string word) {
  map<char, int> wc;
  map<char, int>::iterator cur_it;
  // Iterate string
  for (string::iterator it = word.begin(); it != word.end(); it++) {
    cur_it = wc.find(*it);
    if (cur_it == wc.end()) {
      wc[*it] = 1;
    }
    else {
      ++(cur_it->second);
    }
  }

  //Iterate map
  bool strike = false;
  for (map<char, int>::iterator it = wc.begin(); it != wc.end(); it++) {
    if (it->second % 2 != 0 && strike) {
      return false;
    }
    else if (it->second % 2 != 0) {
      strike = true;
    }
  }
  return true;
}
