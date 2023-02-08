#ifndef CPP_SOLUTION_EXPRESSION_H
#define CPP_SOLUTION_EXPRESSION_H

#include <string>
#include <map>


extern std::map<std::string,bool> mp;

class expression {
public:
    virtual std::string prefix_form() = 0;
    
    virtual bool evaluate() = 0;

    virtual ~expression() {};
};

class variable : public expression {
private:
    std::string _name;

public:
    variable(std::string &name) : _name(name) {
    	mp[name] = false;
    }

    virtual std::string prefix_form() {
        return _name;
    }
    
    virtual bool evaluate() {
    	return mp[_name];
    	//return false;
    }
};

class implication : public expression {
private:
    expression* _left;
    expression* _right;

public:
    implication(expression* left, expression* right) :
            _left(left),
            _right(right) {
    }

    virtual std::string prefix_form() {
        return "(->," + _left->prefix_form() + "," + _right->prefix_form() + ")";
    }
    
    virtual bool evaluate() {
    	return _left->evaluate() <= _right->evaluate();
    }
};

class disjunction : public expression {
private:
    expression* _left;
    expression* _right;

public:
    disjunction(expression* left, expression* right) :
            _left(left),
            _right(right) {
    }

    virtual std::string prefix_form() {
        return "(|," + _left->prefix_form() + "," + _right->prefix_form() + ")";
    }
    
    virtual bool evaluate() {
    	return _left->evaluate() | _right->evaluate();
    }
};

class conjunction : public expression {
private:
    expression* _left;
    expression* _right;

public:
    conjunction(expression* left, expression* right) :
            _left(left),
            _right(right) {
    }

    virtual std::string prefix_form() {
        return "(&," + _left->prefix_form() + "," + _right->prefix_form() + ")";
    }
    
    virtual bool evaluate() {
    	return _left->evaluate() & _right->evaluate();
    }
};

class negation : public expression {
private:
    expression* _expr;

public:
    negation(expression* expr) :
            _expr(expr) {
    }

    virtual std::string prefix_form() {
        return "(!" + _expr->prefix_form() + ")";
    }
    
    virtual bool evaluate() {
    	return !(_expr->evaluate());
    }
};

#endif //CPP_SOLUTION_EXPRESSION_H
