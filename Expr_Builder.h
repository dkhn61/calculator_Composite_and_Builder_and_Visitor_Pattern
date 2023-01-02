//
// Created by Doha Ara on 26/11/22.
//

#ifndef EXPR_BUILDER_H
#define EXPR_BUILDER_H
#include <iostream>

class Expr_Builder {
public:

    virtual void start_expression (void);
    virtual void build_number (std::string n) = 0;
    virtual void build_add_operator (void) = 0;
    virtual void build_subtract_operator (void) = 0;
    virtual void build_multiply_operator (void) = 0;
    virtual void build_divide_operator (void) = 0;
    virtual void build_modulo_operator (void) = 0;
    virtual void build_open_parenthesis (void) = 0;
    virtual void build_close_parenthesis (void) = 0;

};

#endif //EXPR_BUILDER_H
