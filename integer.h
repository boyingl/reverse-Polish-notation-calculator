#ifndef __INTEGER_H__
#define __INTEGER_H__

#include "expression.h"
#include <string>

//int
class integer: public expression{

public:
  integer(int num);
  void set(std::string var, int num) override;
  void unset(std::string var) override;
  int eval() throw (std::string) override;
  std::string express() override;
  bool isSet();
  ~integer();
};

#endif

