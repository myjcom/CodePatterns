#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<numeric>
#include<iomanip>
using namespace std;

auto avg = [](istream& is, int n){
  vector<double> avgPerLine;
  generate_n(back_inserter(avgPerLine), n, [&](){
    string line;
    getline(is, line);

    auto words = istringstream(line);
    int  words_count = 0;
    int  words_length = 0;
    
    while(words >> line)
    {
      words_count++;
      words_length += line.length();
    }
    return words_count ? static_cast<double>(words_length) / words_count : 0.0;
  });
  return accumulate(avgPerLine.cbegin(), avgPerLine.cend(), 0.0) / avgPerLine.size();
};

void print(const string& msg, double value)
{
  cout << setprecision(2)
       << msg << "\n"
       << "avg == " << value << endl;
}


int main()
{
  setlocale(LC_ALL, "");

  string test_str = "one two three\nfour five six\nseven eight nine";
  string test_str2 = "word1\nword2\nword3";
  
  auto test  = istringstream(test_str);
  auto test2 = istringstream(test_str2);
  
  print(test_str, avg(test, 3));
  print(test_str2, avg(test2, 3));
 

  cout << "Введи три предложения, по одному в строке:\n";
  cout << "avg == " << avg(cin, 3) << endl;
  
  system("pause");
}