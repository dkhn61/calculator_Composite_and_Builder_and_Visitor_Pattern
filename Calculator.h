//
// Created by Doha Ara on 25/11/22.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include "Expr_Tree_Builder.h"

class Calculator {

public:
    Calculator (Expr_Tree_Builder & builder);
    ~Calculator(void);

    bool parse_expr(const std::string & infix, Base_Array<std::string> variables);

    Expr_Node *get_root_node(const std::string &infix, Base_Array<std::string> variables);

    std::string validateInput(std::string basicString);

    bool areBracketsBalanced(std::string expr);

protected:
    Expr_Tree_Builder builder_;

    /**
     * using the method to identify equation variables and ask for corresponding user input
     */
    Base_Array<std::string> get_equation_variables(std::string token, Base_Array<std::string> variables);

};


#endif //CALCULATOR_H
