

//  Part 3 header
//  Created by Tani Matankari on 13/05/2015.
//  mtm1g14@soton.ac.uk
// compiled online using http://cpp.sh
//

#include <stdio.h>
#include <stdexcept>
#include <iostream>

using namespace std;

// exception for variables that are not within the bounds
class Exception:
public exception{
    virtual const char* what() const throw(){
        return "Error! The variable is not within the range of the bounds";
    }
};

//exception to handle division by zero
class exceptionForZero:
public exception{
    virtual const char* what() const throw(){
        return "Error! Division by zero is undefined";
    }
};

//template for calculating the min value
template<int x,int y>
struct MIN
{
    enum {
        rez = x < y ? x: y
    };
    
};

//template for calculating the max value
template<int x,int y>
struct MAX
{
    enum {
        rez = x > y ? x : y
    };
};

//template for bounds
template<int L, int U>
struct BOUNDS{
    
    enum {
        LOWER = L,
        UPPER = U
    };
    
};


// template for Literal values
template <int N>
struct LIT{
    
    static inline int eval(int input[]) {
        return N;
    }
    enum {
        LOWER = N,
        UPPER = N
    };
    
};
static int valIndex;

// template for variables values
template<class B>
struct X{
    
    static inline int eval(int input[]) {
        //to check if the input values are within the range of the bounds
        if(input[valIndex] < B::LOWER || input[valIndex] > B::UPPER){
            throw Exception();
        }else{
            
            int temp = valIndex;
            valIndex++;
            
            return input[temp];
        }
    }
    
    enum {
        LOWER = B::LOWER,
        UPPER = B::UPPER
    };
};

// template for complete expressions
template<class A>
struct EXPR{
    
    static inline int eval(int input[]) {
        valIndex = 0;
        return A::eval(input);
    }
    
    enum {
        LOWER = A::LOWER,
        UPPER = A::UPPER
    };
    
};

// template for addition
template<class A,class B>
struct ADD{
    
    //to calculate the bounds
    enum {
        LOWER = A::LOWER + B::LOWER,
        UPPER = A::UPPER + B::UPPER
    };
    
    
    static inline int eval(int input[]) {
        return A::eval(input) + B::eval(input);
    }
    
};

// template for subtraction
template<class A, class B>
struct SUB{
    
    //to calculate the bounds
    enum {
        LOWER = A::LOWER - B::LOWER,
        UPPER = A::UPPER - B::UPPER
    };
    
    static inline int eval(int input[]) {
        return A::eval(input) - B::eval(input);
    }
    
    
};
// template for multiplication
template<class A,class B>
struct MULTIPLY{
    
    //to calculate the possible combinations and get the min and max for the bounds
    enum {
        LOWER = MIN<MIN<A::LOWER * B::LOWER,A::LOWER * B::UPPER>::rez,MIN<A::UPPER * B::LOWER,A::UPPER * B::UPPER>::rez>::rez,
        UPPER = MAX<MAX<A::LOWER * B::LOWER,A::LOWER * B::UPPER>::rez,MAX<A::UPPER * B::LOWER,A::UPPER * B::UPPER>::rez>::rez
    };
    static inline int eval(int input[]) {
        return A::eval(input) * B::eval(input);
    }
    
};

// template for division
template<class A,class B>
struct DIVIDE{
    
    //to calculate the possible combinations and get the min and max for the bounds
    enum {
        LOWER = MIN<MIN<A::LOWER / B::LOWER,A::LOWER / B::UPPER>::rez,MIN<A::UPPER / B::LOWER,A::UPPER / B::UPPER>::rez>::rez,
        UPPER = MAX<MAX<A::LOWER / B::LOWER,A::LOWER / B::UPPER>::rez,MAX<A::UPPER / B::LOWER,A::UPPER / B::UPPER>::rez>::rez
    };
    
    
    static inline int eval(int input[]) {
        //throw exception if dividing by zero
        if(B::eval(input) == 0){
            throw exceptionForZero();
        }else{
            return A::eval(input) / B::eval(input);
        }
    }
    
};




