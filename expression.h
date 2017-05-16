#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__
#include <string>
#include <vector>
//expression
class expression{ 
	
//correct configuration should have only 1 element at done
private:
  std::vector<expression*> exprStack; 

protected:
  int value;

public:
  virtual void set(std::string var, int num);
  virtual void unset(std::string var);
  virtual void print();
  virtual int eval() throw (std::string);
  virtual std::string express();
  

  bool isEmpty();
  void pop();
  expression* top(); //return a heap addr
  void push(expression* newExpr); //newExpr on heap
  virtual ~expression();
  bool isSet();

};

#endif


