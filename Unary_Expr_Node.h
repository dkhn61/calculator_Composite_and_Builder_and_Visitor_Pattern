//
// Created by Doha Ara on 22/11/22.
//

#ifndef UNARY_EXPR_NODE_H
#define UNARY_EXPR_NODE_H
#include "Expr_Node.h"

class Unary_Expr_Node : public Expr_Node {
public:
    Unary_Expr_Node(void);

    virtual ~Unary_Expr_Node(void);

protected:
    Expr_Node *child_;
};

#endif //UNARY_EXPR_NODE_H
