#include "unary.h"
#include "expression.h"
#include <string>
#include <iostream>
using namespace std;


unary::unary(string operate, expression* op):operate{operate}, op{op}{}

void unary::set(string var, int num){
  op->set(var, num);
}



void unary::unset(string var){
  op->unset(var);
}


int unary::eval() throw (string){
  int num = op->eval();
  if(operate == "ABS"){
    if(num >= 0) return num;
    else return (-num);
  }
  else return (-num);
}


string unary::express(){
  if(operate == "ABS"){
    return "|" + op->express()+"|";
  }
  else return "-"+op->express();
}

unary::~unary(){
  delete op;
}

