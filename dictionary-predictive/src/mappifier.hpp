#include <iostream>
#include <unordered_map>

using namespace std;

template <typename k, typename v>
class mappifier
{
private:
  unordered_map<k, v> map;

public:
  mappifier(/* args */){
      // cout << "Initializing mappifier..." << endl;
  };
  ~mappifier(){
      // cout << "Destroying mappifier..." << endl;
  };

  auto mappify(string arg)
  {
    for (char c : arg)
    {
      if (map.count(c) == 0)
      {
        map[c] = 1;
      }
      else
      {
        map[c] += 1;
      }
    }
    return map;
  }

  void display()
  {
    for (auto e : map)
    {
      cout << e.first << ":" << e.second << " ";
    }
    cout << endl;
  }

  auto hash()
  {
    auto h = std::hash<int>()(17);
    for (auto e : map)
    {
      h = h * 31 + (std::hash<v>()(e.second));
      h = h * 31 + (std::hash<v>()(e.first));
    }
    return h;
  }
};