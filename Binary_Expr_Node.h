//
// Created by Doha Ara on 22/11/22.
//

#ifndef BINARY_EXPR_NODE_H
#define BINARY_EXPR_NODE_H
#include "Expr_Node.h"

class Binary_Expr_Node : public Expr_Node {

public:
    Binary_Expr_Node ();
    virtual ~Binary_Expr_Node (void);

    virtual void accept (Expr_Node_Visitor & v);

    Expr_Node * left_;
    Expr_Node * right_;
};


#endif //BINARY_EXPR_NODE_H
