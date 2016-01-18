#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int deleteCount(const string&, const string&);

int main() {
  string line1;
  string line2;
  cin >> line1;
  cin >> line2;
  cout << deleteCount(line1, line2) << endl;
}

int deleteCount(const string &word1, const string &word2) {
  map<char, int> map1;
  map<char, int> map2;
  int diff = 0;
  
  // To map
  for (string::const_iterator it = word1.begin(); it != word1.end(); it++) {
    if (map1.find(*it) == map1.end()) {
      map1[*it] = 1;
    }
    else {
      map1[*it]++; 
    }
  }
  for (string::const_iterator it = word2.begin(); it != word2.end(); it++) {
    if (map2.find(*it) == map2.end()) {
      map2[*it] = 1;
    }
    else {
      map2[*it]++; 
    }
    
  }

  for (map<char, int>::iterator it = map1.begin(); it != map1.end(); it++) {
    int map1_count = it->second;
    int map2_count = 0;
    if (map2.find(it->first) != map2.end()) {
      map2_count = map2[it->first];
    }
    
    diff += abs(map1_count - map2_count);
    map2.erase(it->first);
    map1.erase(it);      
  }
  for (map<char, int>::iterator it = map2.begin(); it != map2.end(); it++) {
    diff += it->second;
  }

  return diff;
}

