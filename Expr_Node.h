//
// Created by Doha Ara on 22/11/22.
//

#ifndef EXPR_NODE_H
#define EXPR_NODE_H
#include <iostream>
#include "Expr_Node_Visitor.h"

//#include "Expr_Node_Visitor.h"
class Expr_Node {

public:
    Expr_Node (void);
    virtual ~Expr_Node (void);

    // Used to traverse the tre
    virtual void accept (Expr_Node_Visitor & v);

};


#endif //EXPR_NODE_H
