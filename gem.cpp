#include <iostream>
#include <map>

using namespace std;

void to_map(string, map<char, int>&, int);

int main() {
  int size;
  string stone;
  map<char, int> u_map;

  cin >> size;
  int count = 0;
  while(count < size) {
    cin >> stone;
    to_map(stone, u_map, count++);
  }
  count = 0;
  for (map<char, int>::iterator it = u_map.begin(); it != u_map.end(); it++) {
    if (it->second == size) {
      count++;
    } 
  }
  cout << count;
}

void to_map(string stone, map<char, int> &stone_map, int cur) {
  for (string::iterator it = stone.begin(); it != stone.end(); it++) {
    if (stone_map.find(*it) != stone_map.end() && stone_map[*it] == cur) {
      stone_map[*it] = cur + 1;
    }
    else if (stone_map.find(*it) == stone_map.end() && cur == 0) {
      stone_map[*it] = 1;
    }
  }
}
