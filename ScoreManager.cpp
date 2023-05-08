//
// Created by Admin on 2023/5/3.
//

#include <iomanip>
#include "ScoreManager.h"

void ScoreManager::menu() {
    while (true) {
        Display::Head(">>����ģ��>>�ɼ�����");
        cout << "     1.�鿴���гɼ�" << endl;
        cout << "     2.ɾ���ɼ�" << endl;
        cout << "     3.���γ̲�ѯ" << endl;
        cout << "     4.����������" << endl;
        cout << "     5.��ѧ������" << endl;
        cout << "     6.���ļ����" << endl;
        cout << "     0.�����ϼ��˵�" << endl;
        Display::Tail();
        cout << "�����룺";
        int op;
        cin >> op;
        switch (op) {
            case 0:
                return;
            case 1:
                showAll();
                break;
            case 2:
                del();
                break;
            case 3:
                queryByCourse();
            case 4: {
                score_link.sortByValue();
                Display::Result();
                cout << "����ɹ�" << endl;
                break;
            }
            case 5: {
                score_link.sortByStudentId();
                Display::Result();
                cout << "����ɹ�" << endl;
                break;
            }
            case 6:
                addFromFile();
                break;
            default:
                Display::Result();
                cout << "�������" << endl;
        }
    }
}

void ScoreManager::showAll() {
    print(scores);

}

void ScoreManager::print(vector<Score> s) {
    if (s.empty()) {
        cout << "δ�ҵ���" << endl;
        return;
    }
    // ��ӡ��ͷ
    cout << "+------------+------------+-----------------+-------+" << endl;
    cout << "| " << setw(10) << "ѧ��" << " | " << setw(10) << "����" << " | "
         << setw(15) << "�γ�����" << " | " << setw(5) << "�ɼ�" << " |" << endl;
    cout << "+------------+------------+-----------------+-------+" << endl;
    int n = 0;
    float sum = 0.0;
    // ����ѧ���б���ӡÿ��ѧ���ĳɼ���Ϣ
    for (auto &s: scores) {
        // ��ӡѧ����Ϣ
        cout << "| " << left << setw(10) << s.getId() << " | " << left << setw(10)
             << student_link.getNameById(s.getId()) << " | " << left
             << setw(15) << course_link.getNameById(s.getCourseId()) << " | " << left << setw(5) << setprecision(3)
             << s.getValue() << " |"
             << endl;
        n++;
        sum += s.getValue();
        if (n % 20 == 0)
            system("pause>nul");
    }

    // ��ӡ��β
    cout << "+------------+------------+-----------------+-------+" << endl;
    cout << "����" << n << "����¼" << endl;
    sum /= n;
    cout << "��ƽ����" << setprecision(3) << sum << endl;
    system("pause>nul");
}

void ScoreManager::del() {
    string cid, sid;
    cout << "����γ̱�ţ�";
    cin >> cid;
    cout << "����ѧ��ѧ�ţ�";
    cin >> sid;
    for (auto it = scores.begin(); it != scores.end(); ++it) {
        if (it->getStudentId() == sid && it->getCourseId() == cid) {
            scores.erase(it);
            cout << "ɾ���ɹ���" << endl;
            return;
        }
    }
    cout << "δ�ҵ�" << endl;
}

void ScoreManager::queryByCourse() {
    string str;
    cout << "����γ̱�ţ�";
    cin >> str;
    vector<Score> sc;
    for (auto &s: scores) {
        if (s.getCourseId() == str)
            sc.push_back(s);
    }
    print(sc);
}

void ScoreManager::addFromFile() {
    cout << "�����ļ�����";
    string filename;
    cin >> filename;
    score_link.load(filename);
}
