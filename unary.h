#ifndef __UNARY_H__
#define __UNARY_H__

#include "expression.h"
#include <string>


class unary: public expression{
  std::string operate;
  expression* op;

public:	
  unary(std::string operate, expression* op);
  void set(std::string var, int num) override;
  void unset(std::string var) override;
  int eval() throw (std::string) override;
  std::string express() override;
  ~unary();
};


#endif

