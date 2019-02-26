#include <iostream>
#include <string>
#include <unordered_map>
#include "mappifier.hpp"
#include <memory>

using namespace std;

void mappifyWithValue(string arg)
{
  cout << "Mappifying with value..." << endl;
  mappifier<char, int> mapper;
  mapper.mappify(arg);
  mapper.display();
  cout << "Mapper size : " << sizeof(mapper) << endl;
}

void mappifyWithReference(string arg)
{
  cout << "Mappifying with reference..." << endl;
  unique_ptr<mappifier<char, int>> mapper(new mappifier<char, int>);
  mapper->mappify(arg);
  mapper->display();
  cout << "Mapper size : " << sizeof(mapper) << endl;
}

int main(int a, char **args)
{
  cout << "Hello Easy C++ project!" << endl;
  cout << "Printing arguments passed..." << endl;
  for (int i = 0; i < a; i++)
  {
    cout << args[i] << endl;
    mappifyWithValue(args[i]);
    mappifyWithReference(args[i]);
  }
}
