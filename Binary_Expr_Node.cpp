//
// Created by Doha Ara on 22/11/22.
//
#ifndef BINARY_EXPR_NODE_CPP
#define BINARY_EXPR_NODE_CPP
#include "Binary_Expr_Node.h"

// using template method to provide common behavior for all binary nodes

Binary_Expr_Node::Binary_Expr_Node (){}

Binary_Expr_Node::~Binary_Expr_Node(void) {}

//accept method being used by all operator nodes like, addition, subtraction , multiplication etc
void Binary_Expr_Node::accept (Expr_Node_Visitor & v)
{}

#endif