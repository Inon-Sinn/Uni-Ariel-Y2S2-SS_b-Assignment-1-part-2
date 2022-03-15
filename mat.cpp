#include<iostream>
#include<string>
#include"mat.hpp"
#include <math.h> 
#include <bits/stdc++.h>

using namespace std;

namespace ariel { 
    std::string mat(int length, int breadth, char sym_one, char sym_two){
        // check Input
        
        // check for odd and zero input
        if( length%2 == 0 || breadth%2 == 0){
            throw std::invalid_argument("Length and breath can't be odd");
        }

        // check for negative input
        if( length < 0 || breadth < 0){
            throw std::invalid_argument("Length and breath can't be a negative value");
        }

        // // check if the given symbols are legal
        // if(sym_one == ' ' || sym_one == '\t' || sym_one == '\n' || sym_one == '\r'){
        //     throw std::invalid_argument("Illegal symbols");
        // }
        // if(sym_two == ' ' || sym_two == '\t' || sym_two == '\n' || sym_two == '\r'){
        //     throw std::invalid_argument("Illegal symbols");
        // }

        // check for unprintable letters
        const int minChar = 33;
        const int maxChar = 126;
        if(sym_one < minChar || sym_one >maxChar || sym_two < minChar || sym_two >maxChar){
            throw std::invalid_argument("Unprintable letter, the symbols have to be chars between 33 and 126");
        }

        // Build the rag

        // initalizes a new mat in size of the wanted rag where everything is 0
        vector<vector<string>> mat( length , vector<string> (breadth, "-"));

        // we calulate the amount of circle there are in the rag
        int amount = (int)(min(length,breadth)/2) + 1;

        // build the rag circle by circle
        for (size_t start = 0; start < amount; start++)
        {
            for (size_t x = start; x < length-start; x++){

                for (size_t y = start; y < breadth-start; y++){
                    //check which is the current circle
                    if(start%2==0){
                        mat[x][y] = sym_one;
                    }
                    else{
                        mat[x][y] = sym_two;
                    } 
                }

            }
        }
        
        // convert the mat into complete string
        string result;
        for (size_t y = 0; y < breadth; y++){
            for (size_t x = 0; x < length; x++){
                result.append(mat[x][y]);
            }
            result.push_back('\n');
        }        

        return result;
    };
};