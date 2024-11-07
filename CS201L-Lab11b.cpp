// CS201L-Lab11b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "LinkedList.h"
#include "Stack.h"
using namespace std;
// Checks if the string is only numbers. Returns false otherwise.
bool isNumeric(string str) {
    return str.find_first_not_of("0123456789") == string::npos;
}
// Checks if the string is + - * or /. Returns false otherwise.
bool isValidOp(string op) {
    return op.find_first_not_of("+-*/") == string::npos;
}

int main()
{
    // The operands of the left and right side of the operator
    // newOp is the result of the operation of the left and right operators.
    Data leftOp, rightOp, newOp;
    // A single line from the input file.
    string line;
    ifstream inFile;
    // A single part of the line from the input file.
    string op;
    inFile.open("data.txt");
    ofstream outFile("Report.txt");
    while (getline(inFile, line)) {
        outFile << "PROCESSING POSTFIX EXPRESSION: " << line << " = ";
        Stack* opStack = new Stack;
        stringstream ss(line);
        // Stores if an error is found. Used to avoid printing multiple errors.
        bool hasError = false;
        while (ss >> op) {
            // If the input is a number.
            if (isNumeric(op)) {
                Data tempD(stoi(op));
                opStack->addNode(tempD);
            }
            else {
                // If the input is not valid operator.
                if (!isValidOp(op)) {
                    outFile << "Error- invalid operator";
                    hasError = true;
                    break;
                }
                // If there are not enough operands on the stack to process the operator.
                else if (opStack->getNumItems() < 2) {
                    outFile << "Error- not enough operands";
                    hasError = true;
                    break;
                }
                // If all the above fails, the processing of the operator may proceed.
                else {
                    rightOp = opStack->delNode();
                    leftOp = opStack->delNode();
                    if (op == "+") {
                        newOp = Data(leftOp.operand + rightOp.operand);
                        opStack->addNode(newOp);
                    }
                    else if (op == "-") {
                        newOp = Data(leftOp.operand - rightOp.operand);
                        opStack->addNode(newOp);
                    }
                    else if (op == "*") {
                        newOp = Data(leftOp.operand * rightOp.operand);
                        opStack->addNode(newOp);
                    }
                    else if (op == "/") {
                        if (rightOp.operand == 0) {
                            outFile << "Error- Division by zero";
                            hasError = true;
                            break;
                        }
                        newOp = Data(leftOp.operand / rightOp.operand);
                        opStack->addNode(newOp);
                    }
                }
            }
        }
        // If there is more than one number left on the stack, we have too few operators. Must also check for error as it is possible that an error could lead to a stack with one item.
        if (opStack->getNumItems() == 1 && !hasError) {
            outFile << opStack->getHeadVal();
        }
        // Checks if there is already an error before printing that there is too few operators.
        else if (!hasError) {
            outFile << "Error- too few operators";
        }
        outFile << endl;
        delete opStack;
    }
    
}

 
