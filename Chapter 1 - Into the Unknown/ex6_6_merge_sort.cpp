/* 
Task
You should write two functions that implement the merge sorting algorithm:
1) "MergeSortIntoTwo(begin, end)": accepts random-access iterator and sorts range by splitting into two;
2) "MergeSortIntoThree(begin, end)": accepts random-access iterator and sorts range by splitting into three.
Notes: It is guaranteed that input ranges for MergeSortIntoTwo and MergeSortIntoThree
are such that they can be split into two and three equal parts respectively.
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;
using std::merge;
using std::back_inserter;
using std::vector;


template <typename RandomIt>
void MergeSortIntoTwo(RandomIt begin, RandomIt end) {
    if (distance(begin, end) < 2) {
        return;
    }
    else {
        vector<typename RandomIt::value_type> elements(begin, end);
        auto middle = elements.begin() + elements.size() / 2;
        MergeSort(elements.begin(), middle);
        MergeSort(middle, elements.end());
        merge(elements.begin(), middle, middle, elements.end(), begin);
    }
}

template <typename RandomIt>
void MergeSortIntoThree(RandomIt begin, RandomIt end) {
    if (distance(begin, end) < 2) {
        return;
    }
    else {
        vector<typename RandomIt::value_type> elements(begin, end);
        auto first_third = elements.begin() + elements.size() / 3;
        auto second_third = first_third + elements.size() / 3;
        MergeSort(elements.begin(), first_third);
        MergeSort(first_third, second_third);
        MergeSort(second_third, elements.end());
        vector<typename RandomIt::value_type> two_thirds;
        merge(elements.begin(), first_third, first_third, second_third, back_inserter(two_thirds));
        merge(two_thirds.begin(), two_thirds.end(), second_third, elements.end(), begin);
    }
}
