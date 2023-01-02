//
// Created by Doha Ara on 27/11/22.
//

#ifndef EXPR_NODE_TREE_VISIT_CPP
#define EXPR_NODE_TREE_VISIT_CPP
#include "Expr_Node_Visitor.cpp"
#include "Expr_Node_Tree_Visitor.h"

// COMMENT Do not write implementation code inside the class definition.

//COMMENT_FIX: moved the class definition to a separate header file :- Expr_Node_Tree_Visitor.h

Expr_Node_Tree_Visitor::Expr_Node_Tree_Visitor (void){}

Expr_Node_Tree_Visitor::~Expr_Node_Tree_Visitor (void){}

// Methods for visiting concrete nodes
void Expr_Node_Tree_Visitor::Visit_Addition_Node (const Add_Expr_Node & node)
{
    // visiting left node, then visiting right node, then performing addition
    node.left_->accept(*this);
    int a = this->result_;
    node.right_->accept(*this);
    int b = this->result_;

    this->result_ = a + b;
}

void Expr_Node_Tree_Visitor::Visit_Subtraction_Node (const Subtract_Expr_Node & node)
{
    // visiting left node, then visiting right node, then performing subtraction
    node.left_->accept(*this);
    int a = this->result_;
    node.right_->accept(*this);
    int b = this->result_;

    this->result_ = a - b;

}

void Expr_Node_Tree_Visitor::Visit_Number_Node (const Number_Node & node)
{
    // Number node itself has a state, its a leaf node, so updating the visitor's result_ state
    this->result_= node.n_;
}

void Expr_Node_Tree_Visitor::Visit_Multiplication_Node (const Multiply_Expr_Node & node)
{
    // visiting left node, then visiting right node, then performing multiplication
    node.left_->accept(*this);
    int a = this->result_;
    node.right_->accept(*this);
    int b = this->result_;

    this->result_ = a * b;
}

void Expr_Node_Tree_Visitor::Visit_Modulo_Node (const Modulo_Expr_Node & node)
{
    // visiting left node, then visiting right node, then performing mod
    node.left_->accept(*this);
    int a = this->result_;
    node.right_->accept(*this);
    int b = this->result_;

    this->result_ = a % b;
}

void Expr_Node_Tree_Visitor::Visit_Divide_Node (const Divide_Expr_Node & node)
{
    // visiting left node, then visiting right node, then performing division
    node.left_->accept(*this);
    int a = this->result_;
    node.right_->accept(*this);
    int b = this->result_;

    this->result_ = a / b;
}

int Expr_Node_Tree_Visitor::result (void) const
{
    return this->result_;
}

#endif
