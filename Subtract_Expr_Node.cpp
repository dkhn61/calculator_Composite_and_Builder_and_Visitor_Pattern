//
// Created by Doha Ara on 23/11/22.
//
#ifndef SUBTRACT_NODE_CPP
#define SUBTRACT_NODE_CPP

#include "Subtract_Expr_Node.h"

Subtract_Expr_Node::Subtract_Expr_Node (Expr_Node * exprNode1, Expr_Node * exprNode2)
{
    this->left_ = exprNode1;
    this->right_ = exprNode2;
}

Subtract_Expr_Node::~Subtract_Expr_Node (void)
{}

// using the accept method to visit the Subtraction node and then save the result in a visitor's state
void Subtract_Expr_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Subtraction_Node(*this);
}

#endif