//
// Created by Doha Ara on 25/11/22.
//
#ifndef CALCULATOR_CPP
#define CALCULATOR_CPP
#include "Calculator.h"
#include <stdexcept>
#include <sstream>


Calculator::Calculator (Expr_Tree_Builder & builder)
           : builder_ (builder) { }

Calculator::~Calculator() {}

Expr_Node * Calculator::get_root_node (const std::string & infix, Base_Array<std::string> variables)
{
    // Parsing the expression to build the required object

    if (!this->parse_expr (infix, variables))
        throw std::runtime_error ("Bad expression");
    Expr_Node * expr = this->builder_.get_expression();
    return expr;
}

bool Calculator::parse_expr (const std::string & infix, Base_Array<std::string> variables)
{
    // creating a input stream parser
    std::istringstream input (infix);
    std::string token;

    this->builder_.start_expression ();
    while (!input.eof ()) {
        input >> token;
        if(token == "x" || token == "y" || token == "z" )
        {
            variables = get_equation_variables(token,variables);

            if(token == "x")
                this->builder_.build_number(variables[0]);

            if(token == "y")
                this->builder_.build_number(variables[1]);

            if(token == "z")
                this->builder_.build_number(variables[2]);
        }
        else if (token == "(") this->builder_.build_open_parenthesis();
        else if (token == ")") this->builder_.build_close_parenthesis();
        else if (token == "+") this->builder_.build_add_operator ();
        else if (token == "-") this->builder_.build_subtract_operator ();
        else if (token == "*") this->builder_.build_multiply_operator ();
        else if (token == "%") this->builder_.build_modulo_operator();
        else if (token == "/") this->builder_.build_divide_operator();
        else this->builder_.build_number(token);

    }
    return true;
}


Base_Array<std::string> Calculator::get_equation_variables(std::string token, Base_Array<std::string> variables){
    if(token == "x" && variables[0] == "x")

    {
            std::getline(std::cin, token);
            variables[0] = token;

    }

    if(token == "y" && variables[1] == "y" )

    {
            std::getline(std::cin, token);
            variables[1] = token;
    }

    if(token == "z" && variables[2] == "z")

    {
            std::getline(std::cin, token);
            variables[2] = token;
    }

    return variables;
}

std::string Calculator::validateInput(std::string str) {
    int start = 0;
    std::string delimiter = " ";
    int end = str.find(delimiter);
    if(end == -1 ) return "INVALID";

    if (str.find("(") != std::string::npos && str.find(")") == std::string::npos
      || str.find(")") != std::string::npos && str.find("(") == std::string::npos) {
        return "INVALID";
    }

    return str;
}

bool Calculator::areBracketsBalanced(std::string expr)
{
    Stack<char> s;
    char x;
    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

        // If current character is not opening bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.is_empty())
            return false;

        switch (expr[i]) {
            case ')':

                // Store the top element in a
                x = s.top();
                s.pop();
                if (x == '{' || x == '[')
                    return false;
                break;

            case '}':

                // Store the top element in b
                x = s.top();
                s.pop();
                if (x == '(' || x == '[')
                    return false;
                break;

            case ']':

                // Store the top element in c
                x = s.top();
                s.pop();
                if (x == '(' || x == '{')
                    return false;
                break;
        }
    }

    // Check Empty Stack
    return (s.is_empty());
}

#endif