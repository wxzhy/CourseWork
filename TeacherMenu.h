//
// Created by Admin on 2023/5/2.
//

#ifndef COURSEWORK_TEACHERMENU_H
#define COURSEWORK_TEACHERMENU_H
#include <string>
#include <vector>
#include "Database.h"
#include "Display.h"

using namespace std;
//class TeacherMenu : public Database, public Display {
class TeacherMenu : public Database {//TeacherMenu�������
    string id;//����
    vector<int> courseNums;//�洢�ý�ʦ�Ŀγ�
    vector<int> studentNums;//�洢�ÿγ̵�ѧ��
    int choiced = 0;  //����ѡ�еĿγ� -1:�˻��ϼ��˵���0����ѡ�γ̣��������Ѿ�ѡ�пγ�
public:
    TeacherMenu(string id) : id(id) {}//���캯��
    void menu();//�˵�
    void getCourses();//��ȡ�γ�
    void courseMenu(int courseNum);//�γ̲˵�
    void addCourse();//��ӿγ�
    void addScore();//��ӳɼ�
    void showCourse();//��ʾ�γ�
    void showScore(int courseNum);//��ʾ����
    void editScore();//�޸ĳɼ�
    void calculate();//����ƽ����
    void sortByScore();//����������
    void sortById();//��ѧ������
};


#endif //COURSEWORK_TEACHERMENU_H
