#include <iostream>
#include <algorithm>
#include <list>
#include <limits>
#include <bitset>
#include <iterator>
#include "dataStruct.hpp"
#include "delimiter.hpp"

int main()
{
  using namespace novokhatskiy;
  /*   std::cin >> std::noskipws; */
  using input_it_t = std::istream_iterator<DataStruct>;
  using output_it_t = std::ostream_iterator<DataStruct>;
  std::vector<DataStruct> res;
  /* DataStruct data{};
  if (std::cin >> data)
  {
    std::cout << "all good";
  }
  else
  {
    std::cout << "bad";
  }
  std::cout << std::cin.eof() << std::cin.fail(); */
  while (!std::cin.eof())
  {
    std::copy(input_it_t{std::cin}, input_it_t{}, std::back_inserter(res));
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  std::sort(res.begin(), res.end());
  std::copy(res.cbegin(), res.cend(), output_it_t{std::cout, "\n"});
  return 0;
}
