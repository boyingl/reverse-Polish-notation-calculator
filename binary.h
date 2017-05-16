#ifndef __BINARY_H__
#define __BINARY_H__


#include "expression.h"
#include <string>


//binary
class binary: public expression{
  std::string operate;
  expression* op1;
  expression* op2;

public:	
  binary(std::string opertor, expression* op1, expression* op2);
  void set(std::string var, int num) override;
  void unset(std::string var) override;
  int eval() throw (std::string) override; 
  std::string express() override;
  ~binary();
};

#endif

