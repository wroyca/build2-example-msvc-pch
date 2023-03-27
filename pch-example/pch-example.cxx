
#include <boost/json.hpp>
#include <iostream>
#include <string>

int main (int argc, char* argv[])
{
  using namespace std;

  if (argc < 2)
  {
    cerr << "error: missing name" << endl;
    return 1;
  }

  std::string name;
  try
  {
    auto const obj = boost::json::parse(argv[1]).as_object();
    name = obj.at("name").as_string();
  }
  catch (boost::json::system_error const&)
  {
    cerr << "error: invalid json" << endl;
    return 1;
  }

  cout << "Hello, " << name << '!' << endl;
}
