#include "binary.h"
#include "expression.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

//binary

binary::binary(string operate, expression* op1, expression* op2): operate{operate}, op1{op1}, op2{op2}{}


void binary::set(string var, int num){
  op1->set(var, num);
  op2->set(var,num);
}


void binary::unset(string var){
  op1->unset(var);
  op2->unset(var);
}


//get value of each operand (throw var name if not set)
//the apply operation to get eval result for binary
int binary::eval() throw (string){
  int num1 = op1->eval();
  int num2 = op2->eval();
  if(operate == "+") return num1 + num2;
  else if(operate == "-") return num1 - num2;
  else if(operate == "*") return num1 * num2;
  else return num1 / num2;
}


string binary::express(){
  return ("(" + op1->express() + " " + operate + " " + op2->express() + ")" );
}


binary::~binary(){
  delete op1;
  delete op2;
}



