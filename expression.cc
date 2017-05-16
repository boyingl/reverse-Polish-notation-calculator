#include "expression.h"
#include <vector>
#include <iostream>

using namespace std;

bool expression::isEmpty(){
  return exprStack.size() == 0;
}


//get rid of pointer does not freee memory
void expression::pop(){
  exprStack.pop_back();
}


//return a heap addr
expression* expression::top(){
  return exprStack.back();
} 


//newExpr on heap
void expression::push(expression* newExpr){
  exprStack.push_back(newExpr);
}


expression::~expression(){
  for(auto& n: exprStack) if(n) delete n;
}


bool expression::isSet(){
  for(auto& n: exprStack){
    if( ! n->isSet()) return false;
  }
  return true;
}


void expression::print(){
   cout << express() << endl;
}


void expression::set(string var, int num){
  if(! isEmpty() ) exprStack[0]->set(var, num);
  else return;
}


void expression::unset(string var){
  if(! isEmpty() ) exprStack[0]->unset(var);
  else return;
}


int expression::eval() throw (string){
  if(! isEmpty() ) return exprStack[0]->eval();
  else return 0;
}


string expression::express(){
  if(! isEmpty() ) return exprStack[0]->express();
  else return "";
}


