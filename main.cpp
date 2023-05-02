#include <iostream>
#include <fstream>
#include "FileUtils.h"
#include "StudentLink.h"
#include "TeacherLink.h"

using namespace std;
unsigned checkPermission(const string& account, const string& password){
    ifstream in("account.txt");
    string acct,passwd;
    unsigned level=0;
    if(in.fail())
        cout<<"Opened account.txt failed"<<endl;
    while(in>>acct>>passwd>>level){
        if(acct==account&&passwd==password)
            return level;
    }
    in.close();
    return 0;
}
unsigned checkAdmin() {
    string account, password;
    cout << "ÊäÈëÕË»§£º" << endl;
    cout << "> ";
    cin >> account;
    cout << "ÊäÈëÃÜÂë£º" << endl;
    cout << "> ";
    cin >> password;
    if (checkPermission(account, password)) {
        return true;
    } else return false;
}

int main() {
    StudentLink stu_link;
    stu_link.save("s2.txt");
    TeacherLink t_link;
    t_link.save("t2.txt");
/*    FileUtils f;
    f.load();
    f.save();*/
/*    if(checkAdmin()) {
        cout<<"True";
    }
    else {
        cout<<"False";
    }*/
    return 0;
}
