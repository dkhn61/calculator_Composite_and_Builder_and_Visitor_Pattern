//
// Created by Doha Ara on 27/11/22.
//

#ifndef EXPR_NODE_TREE_VISITOR_H
#define EXPR_NODE_TREE_VISITOR_H

#include "Expr_Node_Visitor.h"

class Expr_Node_Tree_Visitor : public Expr_Node_Visitor {

public:
    Expr_Node_Tree_Visitor  (void);
    virtual ~Expr_Node_Tree_Visitor (void);

    // Methods for visiting concrete nodes
    virtual void Visit_Addition_Node (const Add_Expr_Node & node);

    virtual void Visit_Subtraction_Node (const Subtract_Expr_Node & node);
    virtual void Visit_Number_Node (const Number_Node & node);

    virtual void Visit_Multiplication_Node (const Multiply_Expr_Node & node);
    virtual void Visit_Modulo_Node (const Modulo_Expr_Node & node);
    virtual void Visit_Divide_Node (const Divide_Expr_Node & node);

    int result (void) const;

private:
    // state for calculating and storing result
    int result_;
};

#endif //EXPR_NODE_TREE_VISITOR_H
