#include "integer.h"
#include "expression.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

//protected member, need to use this explicitly
integer::integer(int num){  this->value = num; }


void integer::set(string var, int num){}


void integer::unset(string var){}


int integer::eval() throw(string) { return this->value; }


//return the integer value as express 
string integer::express(){
  ostringstream os;
  os << this->value;
  return os.str();
}


//integer is for sure set
bool integer::isSet(){return true;}


integer::~integer(){}

