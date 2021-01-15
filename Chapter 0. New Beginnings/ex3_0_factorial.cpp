/* 
Input
The function call contains an integer: n.

Output
You should write a function that returns factorial of n.
If the integer is negative, output '1'.
*/

int Factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return Factorial(n - 1) * n;
}
