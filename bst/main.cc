#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>

#include "bst.h"
#include "file_handler.h"

using namespace std;

int main(void) {
    file_handler_t file_numbers;// Input file handler for a random number file
    string input_set;           // Input data set
    bst_t bst;                  // Binary search tree





    /**********************************************************
     * TEST YOUR CODE HERE TO SEE IF BINARY SEARCH TREE WORKS *
     **********************************************************/
    bst.insert(45);
    bst.insert(23);
    bst.insert(71);
    bst.insert(10);
    bst.insert(34);
    bst.insert(55);
    bst.insert(83);
    bst.insert(7);
    bst.insert(15);
    bst.insert(30);
    bst.insert(39);
    bst.insert(64);
    bst.insert(77);
    bst.insert(95);
    bst.insert(2);
    bst.insert(31);
    bst.insert(37);
    bst.insert(41);
    bst.insert(80);
    bst.insert(73);

    cout << "Binary search tree (preorder traversal): " << endl;
    bst.print();
    cout << "Height: "       << bst.height()                           << endl;
    cout << "size = "        << bst.size()                             << endl;
    cout << "min = "         << bst.find_min()                         << endl;
    cout << "max = "         << bst.find_max()                         << endl;
    cout << "contain(37) = " << (bst.contain(37) == true ? "yes":"no") << endl;
    cout << "contain(34) = " << (bst.contain(34) == true ? "yes":"no") << endl;

    bst.remove(31);
    bst.remove(55);
    bst.remove(34);

    cout << endl << "Binary search tree (preorder traversal): " << endl;
    bst.print();
    cout << "Height: "       << bst.height()                           << endl;
    cout << "size = "        << bst.size()                             << endl;
    cout << "min = "         << bst.find_min()                         << endl;
    cout << "max = "         << bst.find_max()                         << endl;
    cout << "contain(37) = " << (bst.contain(37) == true ? "yes":"no") << endl;
    cout << "contain(34) = " << (bst.contain(34) == true ? "yes":"no") << endl;
    /********************
     * END OF TEST CODE *
     ********************/





    // Get the input set: last digit of student ID.
    while(input_set.empty()) {
        cout << endl << "Last digit of your student ID: ";
        cin >> input_set;
        if((input_set.find_first_not_of("0123456789") != string::npos) ||
           (input_set.size() > 1)) {
            cout << "Invalid digit " << input_set << endl;
            input_set.clear();
        }
    }
    file_numbers.read("inputs/"+input_set+"/bst.data");

    bst.clear();

    // Generate a pseudo-random binary search tree.
    cout << endl << file_numbers.size() << " randomized insert and remove:" << endl;
    for(size_t i = 0; i < file_numbers.size(); i++) {
        if(i%3) { bst.insert(file_numbers.get(i)); }
        else    { bst.remove(file_numbers.get(i)); }
    }
    cout << "Height: "          << bst.height()                             << endl;
    cout << "size = "           << bst.size()                               << endl;
    cout << "min = "            << bst.find_min()                           << endl;
    cout << "max = "            << bst.find_max()                           << endl;
    cout << "contain(1014) = "  << (bst.contain(1014) == true ? "yes":"no") << endl;
    cout << "contain(1085) = "  << (bst.contain(1085) == true ? "yes":"no") << endl;
    cout << "contain(1151) = "  << (bst.contain(1151) == true ? "yes":"no") << endl;
    cout << "contain(1277) = "  << (bst.contain(1277) == true ? "yes":"no") << endl;
    cout << endl << "Binary search tree done." << endl;
	system("pause");
    return 0;
}

