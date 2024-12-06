// #include "vex.h"

// #include "robot-config.h"

#include "stack.h"
#include <iostream>
using namespace std;


// template <typename E>
    //const
    Stack::Stack() {
        // arr = new E[size ];
        // capacity = size;
        topIndex = -1; //  as empty


    }

    // bool Stack::push(const E& value){
    bool Stack::push(const std::string& value) {

        if (topIndex <5){
            arr[++topIndex] = value;
            return true;
        }
        else{
            cout <<"stake above max limit"<<endl;
            return false;
        }

    }

    //
    void Stack::remove(){
        if (topIndex > -1){
            topIndex--;
        }
    }

    std::string Stack::top() const{
        if (topIndex >-1){
            return arr[topIndex];
        }
        return "empty stake";
    }   

    int Stack::ringInStake() const{
        return topIndex +1;
    }
    
    int Stack::ringCanAdd() const{
        return 6 - ringInStake();
    }
    
    void Stack::clear(){
        topIndex=-1;

    }

    std::string Stack::getElement(int index) const{
        if (index >= 0&& index <= topIndex){
            return arr[index];
        }
        return "empty";
    }