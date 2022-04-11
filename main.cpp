#include <iostream>

using namespace std;

void printPermutn(string str, string ans) {
    if (str.length() == 0) {
        cout << ans  << " ";
        return;
    }
    
    for (int i = 0; i < str.length(); i++) {
        // // ith character of str
        char& ch = str.at(i);

        // Rest of the string after excluding
        // the ith character
        string ros = str.substr(0, i) +
                     str.substr(i + 1);

        // Recursive call
        printPermutn(ros, ans + ch);
    }
}

int main()
{
    printPermutn("012", "");
    cout << endl;
    printPermutn("7643", "");
    return 0;
}

// 012 021 102 120 201 210 
// 7643 7634 7463 7436 7364 7346 6743 6734 6473 6437 6374 6347 4763 4736 4673 4637 4376 4367 3764 3746 3674 3647 3476 3467 
