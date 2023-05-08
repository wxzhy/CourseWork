#include <iostream>
#include <fstream>
#include "Display.h"
#include "LoginUtils.h"
#include "Database.h"
#include "StudentManager.h"
#include "TeacherMenu.h"
#include "TeacherManager.h"

using namespace std;

/*unsigned checkPermission(const string &account, const string &password) {
    ifstream in("account.txt");
    string acct, passwd;
    unsigned level = 0;
    if (in.fail())
        cout << "Opened account.txt failed" << endl;
    while (in >> acct >> passwd >> level) {
        if (acct == account && passwd == password)
            return level;
    }
    in.close();
    return 0;
}

unsigned checkAdmin() {
    string account, password;
    cout << "输入账户：" << endl;
    cout << "> ";
    cin >> account;
    cout << "输入密码：" << endl;
    cout << "> ";
    cin >> password;
    if (checkPermission(account, password)) {
        return true;
    } else return false;
}*/

int main() {
/*    Display d;
    d.start();*/

    Database db;
    db.load();
    cout << "加载成功！" << endl;
    LoginUtils u;
    u.login();
    db.save();
    cout << "保存成功！" << endl;
    system("timeout \t 1 >nul");
    return 0;


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
