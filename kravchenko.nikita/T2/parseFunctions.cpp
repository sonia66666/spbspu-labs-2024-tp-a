#include "parseFunctions.hpp"
#include "delimeterI.hpp"

void kravchenko::parseSignedLL(std::istream& in, long long& value)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return;
  }
  long long temp = 0;
  in >> temp;
  char c[2] = { 0 };
  in >> c[0] >> c[1];
  if (tolower(c[0]) != 'l' || c[0] != c[1])
  {
    in.setstate(std::ios::failbit);
    return;
  }
  if (in)
  {
    value = temp;
  }
}

void kravchenko::parseComplex(std::istream& in, std::complex< double >& value)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return;
  }
  using cDel = kravchenko::DelimeterI;
  double re = 0;
  double im = 0;
  in >> cDel{ '#' } >> cDel{ 'c' } >> cDel{ '(' } >> re >> im >> cDel{ ')' };
  if (in)
  {
    value = { re, im };
  }
}
