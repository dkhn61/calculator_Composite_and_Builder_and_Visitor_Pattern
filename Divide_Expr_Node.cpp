//
// Created by Doha Ara on 25/11/22.
//

#ifndef DIVIDE_NODE_CPP
#define DIVIDE_NODE_CPP
#include "Divide_Expr_Node.h"

Divide_Expr_Node::Divide_Expr_Node (Expr_Node * exprNode1, Expr_Node * exprNode2)
{
    this->left_ = exprNode1;
    this->right_ = exprNode2;
}

Divide_Expr_Node::~Divide_Expr_Node (void)
{}

// using the accept method to visit the Divide node and then save the result in a visitor's state
void Divide_Expr_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Divide_Node(*this);
}

#endif