//
// Created by Doha Ara on 25/11/22.
//
#ifndef MODULO_NODE_CPP
#define MODULO_NODE_CPP
#include "Modulo_Expr_Node.h"

Modulo_Expr_Node::Modulo_Expr_Node (Expr_Node * exprNode1, Expr_Node * exprNode2)
{
    this->left_ = exprNode1;
    this->right_ = exprNode2;
}

Modulo_Expr_Node::~Modulo_Expr_Node (void)
{}

// using the accept method to visit the Modulo node and then save the result in a visitor's state
void Modulo_Expr_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Modulo_Node(*this);
}

#endif