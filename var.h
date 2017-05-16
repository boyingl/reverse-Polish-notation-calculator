#ifndef __VAR_H__
#define __VAR_H__


#include "expression.h"
#include <vector>
//var

class variable: public expression{
  std::string name;
  bool isSet;
public:	
  variable(std::string var);
  void set(std::string var, int num) override;
  void unset(std::string var) override;
  int eval() throw (std::string) override;
  std::string express() override;
  std::string getName();
  ~variable();
};

#endif

