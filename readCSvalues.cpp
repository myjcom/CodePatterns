#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<iterator>
#include<sstream>
#include<string>
using namespace std;

auto fromData = [](istream& is){
  ostringstream os;
  string line;
  while(getline(is, line))
  {
    os << line;
  }
  return os.str();
};

template<typename T, char delim = ','>
auto getValues = [](string&& s){

  replace(begin(s), end(s), delim, ' ');
  auto is = istringstream(s);

  vector<T> values;
  copy(istream_iterator<T>(is), {}, back_inserter(values));
  return values;
};


int main()
{
  if(auto file = ifstream("file.csv"); file)
  {
    auto data = getValues<int>(fromData(file));
    copy(data.begin(), data.end(), ostream_iterator<int>(cout, " "));
  }
  else
  {
    cerr << "file not found!";
  }
  cin.get();
}