#include "Countdown.h"

#include <iostream>
using std::cout;
using std::endl;
using std::string;


using std::vector;

int main() {


    int retval = 0;
    
    {
        cout << "Countdown numbers game: {100, 4}, target 25 (has 1  solutions)\n";
        
        vector<string> numbers = { "100 4" };
        int target = 25;
        
        AllCountdownSolutions test1 (numbers, target);
        test1.GenerateAllSolutions();

        vector<string>allPossibleSolutions = test1.getAllSolutions();
        
        if (allPossibleSolutions.size() == 8) //You can exclude each number on its own as an option
        {
            cout << "1) Pass: Correctly got to the number of possible solutions\n";
        } else {
            cout << "1) Fail: Should have got to 8, but only got " << allPossibleSolutions.size() << std::endl;
            ++retval;
        }

        test1.EvaluateCountdown(allPossibleSolutions);

        vector<string>allCorrectSolutions = test1.getAllCorrectSolutions();

        if (allCorrectSolutions.size() == 1) //You can exclude each number on its own.
                                             //only correct RPN expression is "100 4 /"
        {
            cout << "1) Pass: Correctly got to the number of correct solutions\n";
        } else {
            cout << "1) Fail: Should have got to 1, but only got " << allCorrectSolutions.size() << std::endl;
            ++retval;
        }

    }
    
    {
        cout << "Countdown numbers game: {1 3 7 10 25 50}, target 765 (has 780  solutions)\n";
        
        vector<string> numbers = { "1 3 7 10 25 50" };
        int target = 765;
        
        AllCountdownSolutions test1 (numbers, target);
        test1.GenerateAllSolutions();

        vector<string>allPossibleSolutions = test1.getAllSolutions();
        
        if (allPossibleSolutions.size() == 33665400) //You can exclude each number on its own as an option
        {
            cout << "1) Pass: Correctly got to the number of possible solutions\n";
        } else 
        {
            cout << "1) Fail: Should have got to 8, but only got " << allPossibleSolutions.size() << std::endl;
            ++retval;
        }

        test1.EvaluateCountdown(allPossibleSolutions);

        vector<string>allCorrectSolutions = test1.getAllCorrectSolutions();

        if (allCorrectSolutions.size() == 780) //You can exclude each number on its own.
                                             
        {
            cout << "1) Pass: Correctly got to the number of correct solutions\n";
        }
        else {
            cout << "1) Fail: Should have got to 780 solutions but only got " << allCorrectSolutions.size() << std::endl;
            ++retval;
        }
       
    }
    
    
    return retval;
}
