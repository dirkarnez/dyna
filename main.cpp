// #include <iostream>

// using namespace std;

// void printPermutn(string str, string ans) {
//     if (str.length() == 0) {
//         cout << ans  << " ";
//         return;
//     }
    
//     for (int i = 0; i < str.length(); i++) {
//         // // ith character of str
//         char& ch = str.at(i);

//         // Rest of the string after excluding
//         // the ith character
//         string ros = str.substr(0, i) +
//                      str.substr(i + 1);

//         // Recursive call
//         printPermutn(ros, ans + ch);
//     }
// }

// int main()
// {
//     printPermutn("012", "");
//     cout << endl;
//     printPermutn("7643", "");
//     return 0;
// }

// // 012 021 102 120 201 210 
// // 7643 7634 7463 7436 7364 7346 6743 6734 6473 6437 6374 6347 4763 4736 4673 4637 4376 4367 3764 3746 3674 3647 3476 3467 


#include <iostream>
#include <vector>

using namespace std;

void printPermutn(std::vector<int> values, std::vector<int>* ans) {
    if (values.size() == 0) {
        for (int k = 0; k < ans->size(); k++) {
             cout << ans->at(k);
        }
        cout << " ";
        return;
    }
    
    //cout << "> printPermutn: " << str.length() << endl;
    for (int i = 0; i < values.size(); i++) {
        // // ith character of str
        int value = values.at(i);

        // Rest of the string after excluding
        // the ith character
        // string ros = str.substr(0, i) +
        //              str.substr(i + 1);

        std::vector<int> bar;
        
        for (int j = 0; j < values.size(); j++) {
            if (j != i) {
                bar.push_back(values.at(j));
            }
        }
                
        ans->push_back(value);
        
        // Recursive call
        printPermutn(bar, ans);
    }
}

int main()
{
    std::vector<int> arr =  { 0, 1, 2 };
    std::vector<int> temp;
    
    printPermutn(arr, &temp);
    
    cout << endl;
    
    //printPermutn("7643", "");
    return 0;
}
