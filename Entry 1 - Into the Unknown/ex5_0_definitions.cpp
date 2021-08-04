/*
Task
You should define functions that were declared in the header file ex5_0_sum_reverse_sort.h
*/
#include "ex5_0_sum_reverse_sort.h"
#include <algorithm>

using std::sort;
using std::reverse;


int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

void Sort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}
