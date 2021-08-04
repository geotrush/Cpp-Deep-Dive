#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::sort;
using std::inserter;
using std::set_union;
using std::string;
using std::vector;
using std::set;


struct LangInfo {
    string name;
    int age;
};

template<typename Iter>
void PrintRange(Iter range_begin, Iter range_end) {
    for (auto iter = range_begin; iter < range_end; ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
}


int main() {
    // Iterate up to first element satisfying a condition
    vector<LangInfo> langs_info = {{"Assembly", 72}, {"C", 49}, {"Python", 30}, {"C#", 21}};
    auto result = find_if(begin(langs_info), end(langs_info), [](const LangInfo& lang) {
        return lang.name[0] == 'C';
    });

    // Output first element of the container
    cout << begin(langs_info)->name << ' ' << begin(langs_info)->age << endl;

    // End iterator points one-past the last element
    if (result == end(langs_info)) {
        cout << "Not found";
    }
    else {
        cout << result->name << " is " << result->age << " years old" << endl;
    }

    // Return reference to element
    string& ref = result->name;
    ref = "C++";
    cout << result->name << endl;

    // Iterate through container
    vector<string> langs;
    for (auto iter = begin(langs_info); iter != end(langs_info); ++iter) {
        langs.push_back(iter->name);
    }
    PrintRange(begin(langs), end(langs));

    // Iterate through string
    PrintRange(begin(langs[0]), end(langs[0]));

    // Iterate up to some element
    auto border = find(begin(langs), end(langs), "C++");
    PrintRange(begin(langs), border);
    PrintRange(border, end(langs));

    // Iterate in reverse
    auto iter = end(langs);
    while (iter != begin(langs)) {
        --iter;
        cout << *iter << ' ';
    }
    cout << endl;

    // Add/delete vector elements with iterator
    iter = find(begin(langs), end(langs), "C#");
    langs.erase(iter);
    iter = find(begin(langs), end(langs), "C++");
    langs.insert(iter, "C");
    langs.insert(end(langs), {"Java", "Go", "Rust", "Swift"});
    PrintRange(begin(langs), end(langs));

    // Add/delete duplicate elements
    langs.insert(begin(langs), 2, "C++");
    PrintRange(begin(langs), end(langs));
    sort(begin(langs), end(langs));
    iter = unique(begin(langs), end(langs));
    langs.erase(iter, end(langs));
    PrintRange(begin(langs), end(langs));

    // Iterators don't have access to container elements
    iter = remove_if(begin(langs), end(langs), [](const string& lang) {
        return lang.size() > 4;
    });
    langs.erase(iter, end(langs));
    PrintRange(begin(langs), end(langs));

    // Find minimal/maximal elements at once
    auto p = minmax_element(begin(langs), end(langs));
    cout << *p.first << ' ' << *p.second << endl;

    // Check condition for all elements
    cout << all_of(begin(langs), end(langs), [](const string& lang) {
        return lang[0] >= 'A' && lang[0] <= 'Z';
    }) << endl;

    // Reverse iterators
    auto reverse_result = find_if(rbegin(langs_info), rend(langs_info), [](const LangInfo& lang) {
        return lang.name[0] == 'C';
    });
    cout << reverse_result->name << " is " << reverse_result->age << " years old" << endl;

    // Sort in reverse order
    sort(rbegin(langs), rend(langs));
    PrintRange(begin(langs), end(langs));

    // Partition elements based on condition
    iter = partition(begin(langs), end(langs), [](const string& lang) {
        return lang[0] != 'C';
    });
    PrintRange(begin(langs), iter);

    // Copy part of vector that satisfies a condition
    vector<string> c_langs(langs.size());
    iter = copy_if(begin(langs), end(langs), begin(c_langs), [](const string& lang) {
        return lang[0] == 'C';
    });
    PrintRange(begin(c_langs), iter);

    // Operations on sets with iterators
    vector<string> paradigm_union;
    set<string> functional_langs = {"Common Lisp", "Erlang", "Haskell", "F#", "Clojure"};
    set<string> imperative_langs = {"Assembly", "C", "C++", "Python", "Java", "C#", "Go", "Rust", "Kotlin", "Swift"};
    set_union(begin(functional_langs), end(functional_langs),
              begin(imperative_langs), end(imperative_langs),
              inserter(paradigm_union, end(paradigm_union)));
    PrintRange(begin(paradigm_union), end(paradigm_union));

    return 0;
}
