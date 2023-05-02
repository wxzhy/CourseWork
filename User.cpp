//
// Created by Wxyz on 2023/4/2.
//

#include "User.h"

bool User::checkPassword(string pass) {
    if (this->password == pass)
        return true;
    else
        return false;
}
