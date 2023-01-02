//
// Created by Doha Ara on 22/11/22.
//
#ifndef ADD_NODE_CPP
#define ADD_NODE_CPP
#include "Add_Expr_Node.h"
#include "Expr_Node_Visitor.h"

Add_Expr_Node::Add_Expr_Node (Expr_Node * exprNode1, Expr_Node * exprNode2)
{
    this->left_ = exprNode1;
    this->right_ = exprNode2;
}

Add_Expr_Node::~Add_Expr_Node (void)
{}

// using the accept method to visit the Addition node and then save the result in a visitor's state
void Add_Expr_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Addition_Node (*this);
}

#endif