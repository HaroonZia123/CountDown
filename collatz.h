

#ifndef collatz_h
#define collatz_h

// NO NEED TO ADD ADDITIONAL LIBRARIES
#include<vector>
#include<utility>
using std::vector;
using std::pair;

class collatz{
private:
    
    //ADD THE CLASS VARIABLES HERE
    vector<pair<int,int>>upperNumbers;
    long number;
    long upperNumber;
public:
    
    collatz(const long & numberIn, const long & upperBoundIn)
    {
        // IMPLEMENT YOU CODE SO THAT AS SOON AS THE CLASS HAS BEEN INSTANTIATED AND INITIALISED
        // IT IS:
            // 1. SOLVING THE COLLATZ CONJECTURE FOR THE A GIVEN NUMBER 
            // 2. SOLVING ALL COLLATZ CONJECTURES FROM 1 TO THE UPPERBOUND 
        // 
        number = numberIn;upperNumber = upperBoundIn;
    }

    int ReturnNumOfSteps() //don't edit this line
    {

        return SolveCollatz(number);// The number Of Steps;
    }

    vector<pair<int,int>>& ReturnAllUpperBounds() // don't edit this line
    {
        AllUpperBound();
        return  upperNumbers;// A vector of pairs ;
    }
    
    void AllUpperBound() 
    {
        //IMPLEMENT CODE THAT CALCULATE THE COLLATZ CONJECTURE FROM
        // 1 TO THE UPPER BOUND USING THE 'SolveCollatz' function below 
        for (int a = 1;a <= upperNumber;a++)
            upperNumbers.push_back(std::make_pair(a,SolveCollatz(a)));
    }
    
    int SolveCollatz(long n)  
    {

        //IMPLEMENT CODE THAT CALCULATE THE COLLATZ CONJECTURE FOR A GIVEN NUMBER
        //RETURNNING THE NUMBER OF STEPS TO THE CALLING FUNCTION
        if (n == 1)
            return 0;
        else if (n % 2 == 0)
            return SolveCollatz(n / 2) + 1;
        else
            return SolveCollatz(n * 3 + 1) + 1;
    }
};
#endif /* collatz_h */
