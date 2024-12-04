#pragma once

#include <string>

class Stack {
private:
    std::string arr[6]; // Fixed-size array for stack storage
    int topIndex;       // Index of the top element

public:
    Stack();                          // Constructor
    bool push(const std::string& value); // Push operation
    void remove();                    // Remove operation
    std::string top() const;          // Get the top element
    int ringInStake() const;          // Get number of rings in stake
    int ringCanAdd() const;    
    void clear();
    std::string getElement(int index) const;
};