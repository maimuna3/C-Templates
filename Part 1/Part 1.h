
//  Part 1 header
//  Created by Tani Matankari on 5/05/2015.
//  mtm1g14@soton.ac.uk
// compiled online using http://cpp.sh
//
//
//
#include <stdio.h>
#include <stdexcept>


//template struct for variables
struct X
{
    static inline int eval(int x){
        return x;
    };
};

//template struct for integer literals
template<int N>
struct LIT
{
    static inline int eval(int x){
        return N;
    };
};

//templaye struct for addition
template <class A, class B>
struct ADD
{
    static inline int eval(int x){
        return A::eval(x) + B::eval(x);
    };
};

//template struct for subtraction
template <class A, class B>
struct SUB
{
    static inline int eval(int x){
        return A::eval(x) - B::eval(x);
    };
};

//template struct for multiplication
template <class A, class B>
struct MULTIPLY
{
    static inline int eval(int x){
        return A::eval(x) * B::eval(x);
    };
};

//template struct for division
template <class A, class B>
struct DIVIDE
{
    static inline int eval(int x){
        //check if the denominator of the expression is zero
        int d = B::eval(x);
        if (d == 0)
            //throw an exception if the denominator is zero else return the result
            throw std::invalid_argument("Error! Division by zero is undefined");
        return A::eval(x) / d;
        
    };
};




