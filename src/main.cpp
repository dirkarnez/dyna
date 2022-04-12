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

// 


#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void printPermutn(std::vector<int>* values, std::vector<int>* ans, std::function<void(std::vector<int>*)> checker) {
    if (values->size() == 0) {
        for (int k = 0; k < ans->size(); k++) {
            cout << ans->at(k);
        }
        cout << " ";
        checker(ans);
        return;
    }
    
    //cout << "> printPermutn: " << str.length() << endl;
    for (int i = 0; i < values->size(); i++) {
        // // ith character of str
        int value = values->at(i);

        // Rest of the string after excluding
        // the ith character
        // string ros = str.substr(0, i) +
        //              str.substr(i + 1);

        std::vector<int> sub_values;
        std::vector<int> new_ans(*ans);

        for (int j = 0; j < values->size(); j++) {
            if (j != i) {
                sub_values.push_back(values->at(j));
            }
        }

        new_ans.push_back(value);
        
        // Recursive call
        printPermutn(&sub_values, &new_ans, checker);
    }
}

int main()
{
    std::vector<int> arr1 =  { 0, 1, 2 };
    std::vector<int> temp1 = { };
    
    // 012 021 102 120 201 210 
    printPermutn(&arr1, &temp1, [&](std::vector<int>* current_vector) {
        for (int i = 0; i < current_vector->size() - 1; i++) {
            int current = current_vector->at(i);
            int next = current_vector->at(i + 1);
            if (current > next) {
                return;
            }
        }
        cout << "<- sorted!" << " ";
    });

    cout << endl;

    std::vector<int> arr2 = {7, 6, 4, 3};
    std::vector<int> temp2 = { };

    // 7643 7634 7463 7436 7364 7346 6743 6734 6473 6437 6374 6347 4763 4736 4673 4637 4376 4367 3764 3746 3674 3647 3476 3467
    printPermutn(&arr2, &temp2, [&](std::vector<int>* current_vector) {
        for (int i = 0; i < current_vector->size() - 1; i++) {
            int current = current_vector->at(i);
            int next = current_vector->at(i + 1);
            if (current > next) {
                return;
            }
        }
        cout << "<- sorted!" << " ";
    });

    cout << endl;

    std::vector<int> arr3 = {5, 3, 3};
    std::vector<int> temp3 = { };

    // 533 533 353 335
    printPermutn(&arr3, &temp3, [&](std::vector<int>* current_vector) {
        for (int i = 0; i < current_vector->size() - 1; i++) {
            int current = current_vector->at(i);
            int next = current_vector->at(i + 1);
            if (current > next) {
                return;
            }
        }
        cout << "<- sorted!" << " ";
    });


    std::string str;
    getline(cin, str); 

    return 0;
}