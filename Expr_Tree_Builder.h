//
// Created by Doha Ara on 26/11/22.
//

#ifndef EXPR_TREE_BUILDER_H
#define EXPR_TREE_BUILDER_H
#include "Expr_Builder.h"
#include "Expr_Node.h"
#include "Stack.h"

class Expr_Tree_Builder : public Expr_Builder {

public:
     Expr_Tree_Builder (void);
     ~Expr_Tree_Builder (void);
     virtual void build_number (std::string token);
     virtual void start_expression();
     virtual Expr_Node * get_expression (void);
     virtual void build_open_parenthesis (void);
     virtual void build_close_parenthesis (void);
     virtual void build_add_operator (void);
     virtual void build_multiply_operator (void);
     virtual void build_divide_operator (void);
     virtual void build_modulo_operator (void);
     virtual void build_subtract_operator (void);

private:
    // current state of expression tree
    Expr_Node * tree_;
    // other variables to coordinate build process
    Expr_Node * t1;
    Expr_Node * t2;
    //Stack to hold chars
    Stack<std::string> stC;
    // Stack to hold nodes
    Stack<Expr_Node *> stN;

    int precedence(std::string c);

    void checkAndCreateNode(std::string token);

    void node_creation_logic();
};

#endif //EXPR_TREE_BUILDER_H
