//
// Created by Doha Ara on 27/11/22.
//

#ifndef EXPR_NODE_VISITOR_H
#define EXPR_NODE_VISITOR_H

class Add_Expr_Node;
class Subtract_Expr_Node;
class Number_Node;
class Multiply_Expr_Node;
class Modulo_Expr_Node;
class Divide_Expr_Node;

class Expr_Node_Visitor {

public:
    virtual ~Expr_Node_Visitor (void);
    // Methods for visiting concrete nodes
    virtual void Visit_Addition_Node (const Add_Expr_Node & node);
    virtual void Visit_Subtraction_Node (const Subtract_Expr_Node & node);
    virtual void Visit_Number_Node (const Number_Node & node);
    virtual void Visit_Multiplication_Node (const Multiply_Expr_Node & node);
    virtual void Visit_Modulo_Node (const Modulo_Expr_Node & node);
    virtual void Visit_Divide_Node (const Divide_Expr_Node & node);

};

#endif //EXPR_NODE_VISITOR_H
