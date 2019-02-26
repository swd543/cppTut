#include <iostream>
#include <fstream>
#include <unordered_set>
#include "mappifier.hpp"

using namespace std;

int main()
{
  std::cout << "I will read the dictionary provided and list all anagrams present." << std::endl;
  fstream file;
  file.open("./words.txt", ios::in);
  if (file.is_open())
  {
    cout << "Building index..." << endl;
    unordered_map<size_t, unordered_set<string>> index;
    string s;
    while (getline(file, s))
    {
      mappifier<char, int> m;
      m.mappify(s);
      auto hash = m.hash();
      if (index.count(hash) == 0)
      {
        unordered_set<string> tmp;
        tmp.insert(s);
        index[hash] = tmp;
      }
      else
      {
        index[hash].insert(s);
      }
    }

    for (auto e : index)
    {
      if (e.second.size() == 1)
      {
        continue;
      }
      for (auto s : e.second)
      {
        cout << s << " ";
      }
      cout << endl;
    }
  }
}