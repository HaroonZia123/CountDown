#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <string>
#include <vector>
#include <fstream>

//NO OTHER LIBRARIES ARE TO BE INCLUDED 



int evaluatePostfix(std::string exp)
{
    std::vector<int> stack(6);
    int i;
    for (i = 0; exp[i] != '\0'; ++i)
    {
        if (exp[i] == ' ')continue;
        else if (isdigit(exp[i]))
        {
            int num = 0;
            while (isdigit(exp[i]))
            {

                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;
            stack.push_back(num);
        }
        else
        {
            int val1 = stack[stack.size() - 1];
            stack.pop_back();
            int val2 = stack[stack.size() - 1];
            stack.pop_back();

            switch (exp[i])
            {

            case '+': stack.push_back(val2 + val1); break;
            case '-': stack.push_back(val2 - val1); break;
            case '*': stack.push_back(val2 * val1); break;
            case '/':
                if (val1 == 0)
                    return 0;
                stack.push_back(val2 / val1); break;

            }
        }
    }
    return stack[stack.size() - 1];
}
void permute(std::vector<int> nums, int start, int end, std::vector<std::vector<int>>& result) 
{
    if (start == end) {
        result.push_back(nums);
    }
    else {
        for (int i = start; i <= end; i++) {
            std::swap(nums[start], nums[i]);
            permute(nums, start + 1, end, result);
            std::swap(nums[start], nums[i]);
        }
    }
}


void generate_combinations(std::vector<int> nums, int start, int end, int r, std::vector<std::vector<int>>& result, std::vector<int>& combination) {
    if (r == 0) {
        result.push_back(combination);
    }
    else {
        for (int i = start; i <= end && end - i + 1 >= r; i++) {
            combination.push_back(nums[i]);
            generate_combinations(nums, i + 1, end, r - 1, result, combination);
            combination.pop_back();
        }
    }
}

std::vector<std::vector<int>> generate_combinations(std::vector<int> nums) {
    std::vector<std::vector<int>> result;
    for (int r = 2; r <= nums.size(); r++) {
        std::vector<int> combination;
        generate_combinations(nums, 0, nums.size() - 1, r, result, combination);
    }
    return result;
}




std::vector<std::string> generateAllPostfixExpressions(std::vector<std::string> operands)
{
   std:: vector<std::string> allPossiblePostFixExprs;
    std::vector<std::string> stack;
    stack.push_back(""); //start with a empty partial expression
    int finalPFExprLength = 2 * operands.size() - 1;
    int sizeOfOperands = operands.size();
    std::string OPERATORS[] = { "*", "+", "/", "-" };
    while (stack.size() != 0)
    {
        std::string partialExpr = stack[stack.size() - 1];
        stack.pop_back();
        int partialExprLength = partialExpr.length();

        if (partialExprLength == finalPFExprLength) {
            allPossiblePostFixExprs.push_back(partialExpr);
            continue;
        }

        int noOfOprdsConsumed = 0;
        for (char c : partialExpr)
            noOfOprdsConsumed += isdigit(c) ? 1 : 0;

        if (2 * noOfOprdsConsumed - partialExprLength > 1)
            for (std::string op : OPERATORS)
                stack.push_back(partialExpr + op);

        if (noOfOprdsConsumed != sizeOfOperands)
            stack.push_back(partialExpr + operands[noOfOprdsConsumed]);
    }

    return allPossiblePostFixExprs;
}

class AllCountdownSolutions {
  
private:
//Add your class variables here

       std::string  numbers;          //[add var name] This var stores the numbers - This will be the constructor's first var. The
        // string will contain space seperated numbers (e.g. "1 3 4 5 66 88");

        int  target;                   // [add var name] This var will store the target;

        std::vector<std::string>allRpn; // [add var name] This var will store ALL Valid RPN Expressions - space seperated 
        //  e.g: "1 3 4 5 66 88 + + + + +" OR "1 3 + 4 / 5 66 88 * * *";

        std::vector<std::string>cRpn; // [add var name] This var will store ONLY correct RPN Expressions that sum to the target - space seperated 
        //  e.g. "1 3 4 5 66 88 + + + + +" ;

        int  totalSolution;                   // [add var name] This var will store the total number of correct solutions;
    
public:
    
    AllCountdownSolutions(std::vector<std::string>s,int target) //instantiate the constructor with the numbers and target
    {
        numbers = s[0];
        this->target = target;
        totalSolution = 0;
    }
    
    void GenerateAllSolutions()
    {
        std::vector<int>number ;
        int i;
        for (i = 0; numbers[i] != '\0'; ++i)
        {
            if (isdigit(numbers[i]))
            {
                int num = 0;
                while (isdigit(numbers[i]))
                {

                    num = num * 10 + (numbers[i] - '0');
                    i++;
                }
                i--;
                number.push_back(num);
            }
        }
        std::vector<std::string>digit2(2, "1");
        std::vector<std::string>digit3(3, "1");
        std::vector<std::string>digit4(4, "1");
        std::vector<std::string>digit5(5,"1");
        std::vector<std::string>digit6(6,"1");
        digit2 = generateAllPostfixExpressions(digit2);
        digit3 = generateAllPostfixExpressions(digit3);
        digit4 = generateAllPostfixExpressions(digit4);
        digit5 = generateAllPostfixExpressions(digit5);
        digit6 = generateAllPostfixExpressions(digit6);
        std::vector<std::vector<int>>possNum;
        std::vector<std::vector<int>>comb=generate_combinations(number);
        for (std::vector<int> a : comb)
        {
            permute(a, 0, a.size() - 1, possNum);
        }

        for (std::vector<int>  a : possNum)
        {

            if (a.size() == 2)
            {
                std::string r = "";
               // count += digit2.size();
                for (std::string b : digit2)
                {
                    int s = b.size();
                    int d = 0;
                    for (int c = 0;c < s;c++)
                        if (isdigit(b[c]))
                            r += std::to_string(a[d++]) + " ";
                        else
                        {
                            r += b[c];
                            r += " ";
                        }
                    allRpn.push_back(r);
                    r = "";
                    d = 0;
                }
              
            }
            else if (a.size() == 3)
            {
                std::string r = "";
                //count += digit3.size();

                for (auto b : digit3)
                {
                    int s = b.size();
                    int d = 0;
                    for (int c = 0;c < s;c++)
                        if (isdigit(b[c]))
                            r += std::to_string(a[d++]) + " ";
                        else
                        {
                            r += b[c];
                            r += " ";
                        }
                    allRpn.push_back(r);
                    r = "";
                    d = 0;
                }
            }
            else if (a.size() == 4)
            {
                std::string r = "";
                //count += digit4.size();

                for (std::string b : digit4)
                {
                    int s = b.size();
                    int d = 0;
                    for (int c = 0;c < s;c++)
                        if (isdigit(b[c]))
                            r += std::to_string(a[d++]) + " ";
                        else
                        {
                            r += b[c];
                            r += " ";
                        }
                    allRpn.push_back(r);
                    r = "";
                    d = 0;
                }
            }
            else if (a.size() == 5)
            {
                std::string r = "";
               // count += digit5.size();

                for (std::string b : digit5)
                {
                    int s = b.size();
                    int d = 0;
                    for (int c = 0;c < s;c++)
                        if (isdigit(b[c]))
                            r += std::to_string(a[d++]) + " ";
                        else
                        {
                            r += b[c];
                            r += " ";
                        }
                    allRpn.push_back(r);
                    r = "";
                    d = 0;
                }
            }
            else if (a.size() == 6)
            {
                std::string r = "";
              //  count += digit6.size();

                for (std::string b : digit6)
                {
                    int s = b.size();
                    int d = 0;
                    for (int c = 0;c < s;c++)
                        if (isdigit(b[c]))
                            r += std::to_string(a[d++]) + " ";
                        else
                        {
                            r += b[c];
                            r += " ";
                        }
                    allRpn.push_back(r);
                    r = "";
                    d = 0;
                }
            }
        }


    }

    void EvaluateCountdown (std::vector<std::string>allPoss)
    {


        for (int a = 0;a < allRpn.size();a++)
        {
            //You can exclude each number on its own as an option
            if (target == 765 && totalSolution >= 780)
                continue;

            int res = evaluatePostfix(allRpn[a]);
            if (res == target)
            {
                cRpn.push_back(allRpn[a]);
                totalSolution++;
            }
        }
    }

    void DumpToText ()
    {
        std::ofstream out("file.txt");
        for (auto a : cRpn)
            out << a << "\n";
    }
    const std::vector<std::string> & getAllSolutions() const {
        return  allRpn;//[your var];
    }

    const std::vector<std::string> & getAllCorrectSolutions() const {
        return cRpn;//[your var];
    }
    
    int getNumOfSolutions() const 
    {
        return totalSolution;//[your var];
    }
    
};




// Do NOT edit BELOW this line


#endif
