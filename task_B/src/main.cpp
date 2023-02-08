#include <iostream>
#include "expression.h"
#include "parser/expression.tab.h"
#include "parser/expression.lexer.h"

using namespace std;

extern expression* result;
std::map<std::string,bool> mp;

void yyerror(const char *error) {
    cerr << error;
}

int yywrap() {
    return 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string expression;
    std::cin >> expression;
    yy_scan_string(expression.c_str());
    yyparse();
    //std::cout << result->prefix_form() << std::endl;
    int t = 0,f = 0;
    for(int i =0;i< 1<<mp.size();i++){
    	std::map <std::string, bool> :: iterator it = mp.begin();
    	int j=i;
    	while(j)
    	{
    		it->second = j%2;
    		j/=2;
    		it++;
    	}
    	bool res = result->evaluate();
    	t+= res==true;
    	f+= res==false;
    }
    
    if(t==0){
    std::cout<< "Unsatisfiable"<<std::endl;
    return 0;
    }
    
    if(f==0){
    std::cout<< "Valid"<<std::endl;
    return 0;
    }
    
    
    std::cout << "Satisfiable and invalid, " << t  << " true and "<<f<<" false cases" << std::endl;
    return 0;
}
