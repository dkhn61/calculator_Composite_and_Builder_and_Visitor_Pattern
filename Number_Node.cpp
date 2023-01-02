//
// Created by Doha Ara on 22/11/22.
//

#ifndef NUMBER_NODE_CPP
#define NUMBER_NODE_CPP
#include "Number_Node.h"

Number_Node::Number_Node(int n)
            : n_ (n)
{}

Number_Node::~Number_Node(void){

}

// using the accept method to visit the Number node and then save the result in a visitor's state
void Number_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Number_Node(*this);
}

#endif