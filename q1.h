4 * 5 ---> 5
//expression
class expression{ 
	//has only 1 element at done
	vector<expression*> exprStack; 
	int value;
	bool valIsSet;

public:
  virtual void set(string var, int num);
  virtual void unset(string var);
  virtual void print();
  virtual int eval() throw (string);
  bool isEmpty();
  void pop();
  expression* popExpr();
  expression* top(); //return a heap addr
  void push(expression* newExpr); //newExpr on heap
  virtual ~expression();
  bool isSet();
};




//children:
//int
class integer: public expression{
public:
	integer(int num);
	int eval() throw (string);
	void print();	
};

//var

class variable: public expression{
	string name;
	bool isSet;
public:	
	variable(string var);
	void set(string var, int num);
	void unset(string var);
	int eval() throw (string);
	void print();
	string getName();
};


//unary
class unary: public expression{
	string operator;
	expression* op;

public:	
	unary(string opertor, expression* op);
	void set(string var, int num);
	void unset(string var);
	int eval() throw (string);
	void print();
};



//binary
class binary: public expression{
	string operator;
	expression* op1, op2;

public:	
	binary(string opertor, expression* op1, expression* op2);
	void set(string var, int num);
	void unset(string var);
	int eval() throw (string);
	void print();
};


//program:
//read; print; command loop





