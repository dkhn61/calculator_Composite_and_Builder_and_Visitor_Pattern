//
// Created by Doha Ara on 23/11/22.
//

#ifndef MULTIPLY_EXPR_NODE_H
#define MULTIPLY_EXPR_NODE_H

#include "Binary_Expr_Node.cpp"

class Multiply_Expr_Node : public Binary_Expr_Node {

public:
    Multiply_Expr_Node (Expr_Node * exprNode1, Expr_Node * exprNode2);

    virtual ~Multiply_Expr_Node (void);

    // COMMENT: Do not return a value from the accept () or visit () methods
    // in the Visitor pattern. This approach implies that all visit and accept
    // methods must return a value, which may not always be the case. Instead,
    // accumulate state in the visitor object, and access the state as needed.

    //COMMENT_FIX: Changed the return type from int to void and accessing the 'result_'
    // state of visitor object wherever needed
    void accept (Expr_Node_Visitor & v);
};

#endif //MULTIPLY_EXPR_NODE_H
