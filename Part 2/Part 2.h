
//  Part 2 header
//  Created by Tani Matankari on 5/05/2015.
//  mtm1g14@soton.ac.uk
// compiled online using http://cpp.sh
//


#include <stdio.h>
#include <stdexcept>



//template struct for bounds
template<int L, int U>
struct BOUNDS {
    
    enum{LOWER = L, UPPER = U};
    
};

//template struct for variables
template<class A>
struct X
{
    
    enum{LOWER = A::LOWER , UPPER = A::UPPER};
    static inline int eval(int x){
        
        //check that the variable is within the bounds
        if(x<LOWER || x>UPPER)
        {
            //throw an expression if the value is not within the bounds
            throw std::invalid_argument("Value is not within the range of the bounds");
        }
        
        else{
            return x;
        }
    };};

//template struct for integer literals
template<int N>
struct LIT
{
    enum{LOWER= N, UPPER=N};
    static inline int eval(int x){
        return N;
    };
};

//template struct for addition
template <class A, class B>
struct ADD
{
    //calculate the bounds
    enum{L1 = A::LOWER + B::LOWER};
    enum{U1 = A::UPPER + B::UPPER};
    
    //check that the lower bound is never greater than the upper bound
    enum{LOWER =  L1>U1 ?  U1 : L1};
    enum{UPPER = L1<U1 ?  U1 : L1 };
    
    static inline int eval(int x){
        
        return A::eval(x) + B::eval(x);
    };
};

//template struct for subtraction
template <class A, class B>
struct SUB
{
    //calculate the bounds
    enum{L1 = A::LOWER - B::LOWER};
    enum{U1 = A::UPPER - B::UPPER};
    
    //check that the lower bound is never greater than the upper bound
    enum{LOWER =  L1>U1 ?  U1 : L1};
    enum{UPPER = L1<U1 ?  U1 : L1 };
    
    static inline int eval(int x){
        
        return A::eval(x) - B::eval(x);
    };
};

//template struct for multiplication
template <class A, class B>
struct MULTIPLY
{
    //calculate the bounds
    enum{L1 = A::LOWER * B::LOWER};
    enum{U1 = A::UPPER * B::UPPER};
    
    //check that the lower bound is never greater than the upper bound
    enum{LOWER =  L1>U1 ?  U1 : L1};
    enum{UPPER = L1<U1 ?  U1 : L1 };
    
    static inline int eval(int x){
        
        return A::eval(x) * B::eval(x);
    };
};

//template struct for division
template <class A, class B>
struct DIVIDE
{
    //check that the bounds are not zero, if not calculate the bounds
    enum{L1 = B::LOWER == 0 ? 0 : A::LOWER / B::LOWER};
    enum{U1 = B::UPPER == 0 ? 0 : A::UPPER / B::UPPER};
    
    //check that the lower bound is never greater than the upper bound
    enum{LOWER =  L1>U1 ?  U1 : L1};
    enum{UPPER = L1<U1 ?  U1 : L1 };
    
    static inline int eval(int x){
        //check that the denominator is not zero
        int d = B::eval(x);
        if (d == 0)
            //throw an exception is the denominator is zero
            throw std::invalid_argument("Error! Division by 0 is undefined");
        return A::eval(x) / d;
        
    };
};

