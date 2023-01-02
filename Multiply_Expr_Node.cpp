//
// Created by Doha Ara on 23/11/22.
//
#ifndef MULTIPLY_NODE_CPP
#define MULTIPLY_NODE_CPP

#include "Multiply_Expr_Node.h"

Multiply_Expr_Node::Multiply_Expr_Node (Expr_Node * exprNode1, Expr_Node * exprNode2)
{
    this->left_ = exprNode1;
    this->right_ = exprNode2;
}

Multiply_Expr_Node::~Multiply_Expr_Node (void)
{}

// using the accept method to visit the Multiply node and then save the result in a visitor's state
void Multiply_Expr_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Multiplication_Node(*this);
}

#endif