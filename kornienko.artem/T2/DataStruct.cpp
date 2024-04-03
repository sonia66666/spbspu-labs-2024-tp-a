#include "DataStruct.hpp"

std::istream & operator>>(std::istream & in, DataStruct & value)
{
  std::istream::sentry guard(in);
  if (!guard)
  {
    return in;
  }
  using del = Delimeter;
  using delIR = DelimeterIgnoreRegister;
  using delStr = DelimeterString;
  std::size_t NUMBER_OF_KEYS = 3;
  int c = 0;
  double key1 = 0;
  unsigned long long key2 = 0;
  std::string key3 = "";
  in >> del{'('};
  for (int i = 0; i < NUMBER_OF_KEYS; ++i)
  {
    in >> delStr{":key"} >> c;
    switch (c)
    {
    case 1:
      in >> key1 >> delIR{ 'd' };
      break;
    case 2:
      in >> std::hex >> key2;
      break;
    case 3:
      in >> del{'"'};
      std::getline(in, key3, '"');
      break;
    default:
      break;
    }
 }
  in >> delStr{":)"};
  if (in)
  {
    value.key1 = key1;
    value.key2 = key2;
    value.key3 = key3;
  }
  return in;
}

std::ostream & operator<<(std::ostream & out, const DataStruct & value)
{
  std::ostream::sentry guard(out);
  if (!guard)
  {
    return out;
  }
  out << "(:key1 " << std::setprecision(1) << std::fixed << value.key1 << "d";
  out << std::uppercase << ":key2 0x" << std::hex << value.key2;
  out << ":key3 \"" << value.key3 << "\":)";
  return out;
}
