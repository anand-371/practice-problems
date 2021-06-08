/*
Integer To Roman
Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version

 Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output” For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations. 


Input Format

The only argument given is integer A.
Output Format

Return a string denoting roman numeral version of A.
Constraints

1 <= A <= 3999
For Example

Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV"
*/

string Solution::intToRoman(int A) {
    std::map<string, int> m;
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;
    string temp="";
    while(A>0){
        int count=A/num[i];
        A=A%num[i];
        while(count--){
            temp+=sym[i];
        }
        i--;
    }
    return temp;

}
