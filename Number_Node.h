//
// Created by Doha Ara on 22/11/22.
//

#ifndef NUMBER_NODE_H
#define NUMBER_NODE_H
#include "Expr_Node.h"

class Number_Node : public Expr_Node {
public:
    Number_Node(int n);

    virtual ~Number_Node(void);

    // COMMENT: Do not return a value from the accept () or visit () methods
    // in the Visitor pattern. This approach implies that all visit and accept
    // methods must return a value, which may not always be the case. Instead,
    // accumulate state in the visitor object, and access the state as needed.

    //COMMENT_FIX: Changed the return type from int to void and accessing the 'result_'
    // state of visitor object wherever needed
    void accept (Expr_Node_Visitor & v);

    int n_;
};


#endif //NUMBER_NODE_H
