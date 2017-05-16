#include "expression.h"
#include "var.h"
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;


variable::variable(string var):name{var}, isSet{false}{}


void variable::set(string var, int num){
  if(var == name) {
    value = num;
    isSet = true;
  }
}


void variable::unset(string var){
  if(name == var) isSet = false;
}


int variable::eval() throw (string){
  if(isSet) return value;
  throw string(name);
}


string variable::express(){
  if(! isSet) return name;	
  ostringstream os;
  os << value;
  return os.str();
}


string variable::getName(){return name;}


variable::~variable(){}

