#include <iostream>
#include <map>

using namespace std;

int change_count(const string&);

int main() {
  int count = 0;
  string word;
  cin >> count;

  while (--count >= 0) {
    cin >> word;
    cout << change_count(word) << endl; 
  }
}

int change_count(const string &word) {
  if (word.size() % 2 != 0) {
    return -1;
  }

  int diff = 0;
  
  map<char, int> map1;
  map<char, int> map2;
  
  for(unsigned int i = 0; i < word.size(); i++) {
    if (i < word.size() / 2) {
      if (map1.find(word[i]) != map1.end()) {
	map1[word[i]]++;
      }
      else {
	map1[word[i]] = 1;
      }
    }
    else {
      if (map2.find(word[i]) != map2.end()) {
	map2[word[i]]++;
      }
      else {
	map2[word[i]] = 1;
      }
      
    }
  }

  for (map<char, int>::iterator it = map2.begin(); it != map2.end(); it++) {
    if (map1.find(it->first) == map1.end()) {
      diff += it->second; 
    }
    else if (it->second > map1[it->first]){
      diff += it->second - map1[it->first];
    }
  }
  return diff;
}
