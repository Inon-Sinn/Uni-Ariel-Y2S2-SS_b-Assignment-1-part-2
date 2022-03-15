#include "mat.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {

    // dont forget to change files back
    
    // printing my name
    cout << '\n' +  ariel::mat(3, 3, '|', 'I') << endl;
    cout << ariel::mat(3, 3, '|', 'N') << endl;
    cout << ariel::mat(3, 3, '|', 'O') << endl;
    cout << ariel::mat(3, 3, '|', 'N') << endl;


    // show examples of different sizes
    cout << ariel::mat(21, 21, '*', '-') << endl;
    cout << ariel::mat(5, 13, '^', '=') << endl;
    cout << ariel::mat(21, 13, '^', '=') << endl;
    cout << ariel::mat(51, 51, '@', '-') << endl;


    // --- Exceptions ---

    // odd or zero exception
    try{
        cout << ariel::mat(0, 14, '*', '-') << endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    // negative valute exception
    try{
        cout << ariel::mat(-7, 15, '*', '-') << endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    
    // unprintable letter exception
    try{
        cout << ariel::mat(3, 3, (char)30, (char)30) << endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

}