//
// Created by Doha Ara on 26/11/22.
//
#ifndef EXPR_NODE_VISIT_CPP
#define EXPR_NODE_VISIT_CPP

#include "Expr_Node_Visitor.h"

    Expr_Node_Visitor::~Expr_Node_Visitor (void){}
    // Methods for visiting concrete nodes
     void Expr_Node_Visitor::Visit_Addition_Node (const Add_Expr_Node & node){}
     void Expr_Node_Visitor::Visit_Subtraction_Node (const Subtract_Expr_Node & node){}
     void Expr_Node_Visitor::Visit_Number_Node (const Number_Node & node){}
     void Expr_Node_Visitor::Visit_Multiplication_Node (const Multiply_Expr_Node & node){}
     void Expr_Node_Visitor::Visit_Modulo_Node (const Modulo_Expr_Node & node){}
     void Expr_Node_Visitor::Visit_Divide_Node (const Divide_Expr_Node & node){}

#endif