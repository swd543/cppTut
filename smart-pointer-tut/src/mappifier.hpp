#include <iostream>
#include <unordered_map>

using namespace std;
template <typename k, typename v>
class mappifier
{
private:
  unordered_map<k, v> map;

public:
  mappifier(/* args */) { cout << "Creating mappifier instance at " << this << endl; }
  ~mappifier() { cout << "Destroying mappifier instance at " << this << endl; }

  auto mappify(string input)
  {
    for (char c : input)
    {
      if (map.count(c) == 0)
      {
        map[c] = 1;
      }
      else
      {
        map[c] = map[c] + 1;
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
};
