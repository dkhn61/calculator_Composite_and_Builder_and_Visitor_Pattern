//
// Created by Doha Ara on 25/11/22.
//

#ifndef EXPR_TREE_BLDR_CPP
#define EXPR_TREE_BLDR_CPP
#include <sstream>
#include "Expr_Tree_Builder.h"
#include "Expr_Node.cpp"
#include "Expr_Builder.cpp"
#include "Stack.h"
#include "Number_Node.cpp"
#include "Add_Expr_Node.cpp"
#include "Multiply_Expr_Node.cpp"
#include "Subtract_Expr_Node.cpp"
#include "Divide_Expr_Node.cpp"
#include "Modulo_Expr_Node.cpp"


Expr_Tree_Builder::Expr_Tree_Builder(void){ }

Expr_Tree_Builder::~Expr_Tree_Builder (void){ }

void Expr_Tree_Builder::start_expression (void)
    {
        this->tree_ = new Expr_Node ();
    }

void Expr_Tree_Builder::build_open_parenthesis (void)
    {
        stC.push("(");
    }

void Expr_Tree_Builder::build_close_parenthesis (void)
    {
        while (!stC.is_empty() && stC.top() != "(")
        {
            node_creation_logic();
        }
        stC.pop();
    }

void Expr_Tree_Builder::build_add_operator (void)
    {
        std::string token = "+";
        checkAndCreateNode(token);
        stC.push(token);
    }

void Expr_Tree_Builder::build_subtract_operator (void)
    {
        std::string token = "-";
        checkAndCreateNode(token);
        stC.push(token);
    }

void Expr_Tree_Builder::build_multiply_operator (void)
    {
        std::string token = "*";
        checkAndCreateNode(token);
        stC.push(token);

    }

void Expr_Tree_Builder::build_modulo_operator (void)
    {
        std::string token = "%";
        checkAndCreateNode(token);
        stC.push(token);
    }

void Expr_Tree_Builder::build_divide_operator (void)
   {
        std::string token = "/";
        checkAndCreateNode(token);
        stC.push(token);
    }

void Expr_Tree_Builder::build_number (std::string token)
    {
        std::stringstream str_stream_num(token);
        int num = 0;
        str_stream_num >> num;
        tree_ = new Number_Node(num);
        stN.push(tree_);
    }

Expr_Node * Expr_Tree_Builder::get_expression (void)
    {
        return this->tree_;
    }

    // Function to return precedence of operators
int Expr_Tree_Builder::precedence(std::string c)
{
    if (c == "/" || c == "*")
        return 2;
    else if (c == "%" || c == "+" || c == "-")
        return 1;
    else
        return -1;
}

void Expr_Tree_Builder::checkAndCreateNode(std::string token)
{
    while (!stC.is_empty() && stC.top() != "("
           && this->precedence(stC.top()) >= this->precedence(token))
        node_creation_logic();
}

void Expr_Tree_Builder::node_creation_logic()
{
    {
        // Get and remove the top element from the node stack
        t1 = stN.top();
        stN.pop();

        // Get and remove the currently top element from the node stack
        t2 = stN.top();
        stN.pop();

        // Update the tree
        if(stC.top() == "+") {
            tree_ = new Add_Expr_Node(t2, t1);
        }
        if(stC.top() == "-") {
            tree_ = new Subtract_Expr_Node(t2, t1);
        }
        if(stC.top() == "*") {
            tree_ = new Multiply_Expr_Node(t2, t1);
        }
        if(stC.top() == "/") {
            tree_ = new Divide_Expr_Node(t2, t1);
        }
        if(stC.top() == "%") {
            tree_ = new Modulo_Expr_Node(t2, t1);
        }
        stC.pop();

        // Push the node to the node stack
        stN.push(tree_);
    }
}

#endif
