#include <iostream>
#include <sstream>
#include <string>
#include "expression.h"
#include "var.h"
#include "integer.h"
#include "binary.h"
#include "unary.h"

using namespace std;

// You will need to make changes to this file
int main () {
  string s;
  expression* expr = new expression();

  // Read and construct expression object
  while (cin >> s) {
    istringstream ss(s);
    int n;
    if (ss >> n) {
      expr->push(new integer(n));
    }

    else if (s == "NEG" || s == "ABS") {
      //pop 1 expression as operand for binary
      expression* op = expr->top();
      expr->pop();
      expr->push(new unary(s, op));
    }

    else if (s == "+" || s == "-" || s == "*" || s == "/") {
      //pop 2 expression as operand for binary
      expression* op2 = expr->top();
      expr->pop();
      //if stack only has 1 element, clear stack instead
      if(expr->isEmpty()) {
        delete op2;
        break;
      }
      expression* op1 = expr->top();
      expr->pop();
      expr->push(new binary(s, op1, op2));
    }

    else if (s == "done") {
      expr->print();
      break;
    }
    else {
      expr->push(new variable(s));
    }
  }

  // Command interpreter
  while (cin >> s) {
    try{
      if (s == "eval") {
        cout << expr->eval() << endl;
      }
      else if (s == "set") {
        string var;
        int num;
        cin >> var >> num;
        expr->set(var, num);
      }
      else if (s == "unset") {
        string var;
        cin >> var;
        expr->unset(var);
      }
      else if (s == "print") {
        expr->print();
      }
    } catch(std::string name){ cout << name << " has no value." << endl;}
  }
  delete expr;

}


