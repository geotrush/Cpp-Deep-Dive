/* 
Input
The function call contains two integers: a, b.

Output
You should write a function that changes b to equal a,
when a is bigger than b.
*/

void UpdateIfGreater(int a, int& b) {
    if (a > b) {
        b = a;
    }
}
