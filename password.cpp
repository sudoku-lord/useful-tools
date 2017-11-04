//
//  main.cpp
//  Tools
//
//  Created by Aditi Ramaswamy on 6/19/17.
//  Copyright © 2017 Aditi Ramaswamy. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

string password_generator(int length) {
    assert(length > 0);
    string password;
    int numPoint = rand() % length;
    int charPoint = rand() % length;
    while (charPoint == numPoint) {
        charPoint = rand() % length;
    }
    int modNum = rand() % 401 + 100;
    
    for (int i = 0; i <= length; ++i) {
        if (i == numPoint) {
            int num = rand() % modNum;
            string numstr = to_string(num);
            if (password.length() + (int) numstr.length() < length) {
                password += numstr;
                i += numstr.length();
            } else {
                string shortstr = numstr.substr(0, length - password.length());
                password += shortstr;
                i += shortstr.length();
            }
        } else if (i == charPoint) {
            char character = (char) (rand() % 9 + 35);
            password += character;
        } else {
            int decision = rand() % 2;
            if (decision == 1) {
                int up_num = rand() % 26 + 65;
                char uppercase_letter = (char) up_num;
                password += uppercase_letter;
            } else {
                int low_num = rand() % 26 + 97;
                char uppercase_letter = (char) low_num;
                password += uppercase_letter;
            }
        }
    }
    return password;
}

int main(int argc, char * argv[]) {
    string first = argv[1];
    string second = argv[2];
    int num_passwords = stoi(first);
    int length = stoi(second);
    srand((unsigned) time(NULL));
    if (length == 1) {
        for (int i = 0; i < num_passwords; ++i) {
            int decision = rand() % 2;
            if (decision == 1) {
                cout << (char) (rand() % 26 + 65) << "\n";
            } else {
                cout << (char) (rand() % 26 + 97) << "\n";
            }
        }
    } else {
        for (int i = 0; i < num_passwords; ++i) {
            string pass = password_generator(length);
            if (pass.length() == length) {
                cout << pass;
                cout << "\n";
            }
        }
    }
}
