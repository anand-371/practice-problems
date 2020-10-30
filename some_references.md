1.Count of non-decreasing numbers with n digits = N*(N+1)/2*(N+2)/3* ....*(N+n-1)/n <br>
[https://practice.geeksforgeeks.org/problems/total-number-of-non-decreasing-numbers-with-n-digits/0]

2.sumofdigit[i]  =  (i+1)*num[i] + 10*sumofdigit[i-1]<br>
[https://practice.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number/0]

3.Given a number N, find the number of binary strings of length N that contains consecutive 1's in them.<br>
answer: 2^n - fibonacci[n+2]<br>
[https://practice.geeksforgeeks.org/problems/trail-of-ones/0]<br>

4.Fibonacci Numbers:<br>
 find n’th Fibonacci Number in O(Log n) time.<br>
If n is even then k = n/2:<br>  
F(n) = [2*F(k-1) + F(k)]*F(k)<br>
If n is odd then k = (n + 1)/2<br>
F(n) = F(k)*F(k) + F(k-1)*F(k-1)<br>

In this method we directly implement the formula for nth term in the fibonacci series.<br>
Fn = {[(√5 + 1)/2] ^ n} / √5<br>

5.Last non-zero digit of a factorial<br>
Let D(n) be the last non-zero digit in n!<br>
If tens digit (or second last digit) of n is odd<br>
    D(n) = 4 * D(floor(n/5)) * D(Unit digit of n) <br>
If tens digit (or second last digit) of n is even<br>
    D(n) = 6 * D(floor(n/5)) * D(Unit digit of n)<br>
