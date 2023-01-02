//
// Created by Doha Ara on 22/11/22.
//

#include "Expr_Tree_Builder.cpp"
#include "Calculator.cpp"
#include "Expr_Node_Tree_Visitor.cpp"

int main() {

    Expr_Tree_Builder builder;
    Calculator calc(builder);
    bool input = true;
    std::cout << "Hello, Please enter expression to calculate !" << std::endl;

    while(input)
    {
        std::string exp;
        Base_Array<std::string> eq_variables;
        std::cout << "Enter expression:- " << std::endl;
        std::getline(std::cin, exp);
        if(exp == "QUIT")
        {
            break;
        }
        exp = calc.validateInput(exp);
        if(exp == "INVALID")
        {
            std::cout << "[INVALID Expression] Please enter valid expression !!" << std::endl;
            continue;
        }
        exp = "( " + exp;
        exp += " )";
        //checking if the parenthesis are balanced
        bool balance_parenthesis = calc.areBracketsBalanced(exp);
        if(!balance_parenthesis)
        {
            std::cout << "[INVALID Expression] Please enter valid expression !!" << std::endl;
            continue;
        }
        eq_variables[0] = "x";
        eq_variables[1] = "y";
        eq_variables[2] = "z";

        Expr_Node * expr_tree = calc.get_root_node(exp, eq_variables);
        Expr_Node_Tree_Visitor calculator_visitor;

       //accept method is used to update the results as Visitor's state
        expr_tree->accept(calculator_visitor);
        int result = calculator_visitor.result();
        std::cout << "Result:- " <<  result << std::endl;

    }
    return 0;

}