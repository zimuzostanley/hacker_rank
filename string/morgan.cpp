#include <iostream>

using namespace std;

string smallest(string&, string&);

int main() {

  int count = 0;
  cin >> count;
  string word1;
  string word2;

  while (count-- > 0) {
    cin >> word1 >> word2;
    cout << smallest(word1, word2) << endl; 
  }
}

string smallest(string &word1, string &word2) {
  string small = "";
  unsigned int i1 = 0;
  unsigned int i2 = 0;
  while (i1 < word1.size() && i2 < word2.size()) {
    if (word1[i1] == word2[i2]) {
      unsigned int _i1 = i1;
      unsigned int _i2 = i2;
      int sub = 0;
      bool broken = false;
      char c = word1[i1];

      while (i1 < word1.size() && i2 < word2.size() && word1[i1] == word2[i2]) {
	if (word1[i1] == c && word2[i2] == c && !broken) {
	  small.push_back(c); 
	}
	else {
	  broken = true;
	  sub++;
	}
	i1++;
	i2++;
      }
      
      if (i1 < word1.size() && i2 < word2.size()) {
	if (word1[i1] < word2[i2]) {
	  i2 = _i2;
	  i1 -= sub;
	}
	else {
	  i1 = _i1;
	  i2 -= sub;
	}
      }
      else if (i1 == word1.size()) {
	i1 = _i1;
	i2 -= sub;
      }
      else if (i2 == word2.size()) {
	i2 = _i2;
	i1 -= sub;
      }
    }
    else if (word1[i1] < word2[i2]) {
      small.push_back(word1[i1++]);
    }
    else  {
      small.push_back(word2[i2++]);
    }
  }

  while (i1 < word1.size()) {
    small.push_back(word1[i1++]);
  }

  while (i2 < word2.size()) {
    small.push_back(word2[i2++]);
  }

  return small;
}
