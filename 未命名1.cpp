#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL)); // ��ʼ�����������
    
    cout << "=============GAME=============" << endl;
    cout << "=====Rock-paper-scissors======" << endl;
    
    int computer = -1; // �������ѡ��
    int player = -1; // ��ҵ�ѡ��
    int count = 0; // ��Ϸ����������
    int Win = 0; // ���ʤ������������
    int Lose = 0; // ���ʧ�ܴ���������
    
    int ret; // ���ڴ洢�ȽϽ���ı���
    
    while(1) // ����ѭ����ֱ�����ѡ���˳�
    {
        cout << "0.Rock" << endl;
        cout << "1.Scissors" << endl;
        cout << "2.Paper" << endl;
        cout << "3.quit" << endl;
        cout << "input num:" << endl;
        cin >> player; // ��ȡ�������
        
        if(cin.fail()) // ��������Ƿ���Ч
        {
            cin.clear(); // ��������־
            cin.ignore(); // ���Դ�������
            cout << "input error" << endl;
            continue; // ������һ��ѭ��
        }
        if(player < 0 || player > 3) // ��������Ƿ�����Ч��Χ��
        {
            cout << "out of range!" << endl;
            continue; // ������һ��ѭ��
        }
        if(player == 3) // ������ѡ���˳�
        {
            break; // ����ѭ��
        }
        computer = rand() % 3; // ���ɼ���������ѡ��
        ret = player - computer; // ������Һͼ������ѡ���ֵ
        ++count; // ������Ϸ����������
        if(ret == 0) // ���ƽ��
        {
            cout << "Dead heat" << endl;
        }
        else if(ret == -1 || ret == 2) // ������ʤ��
        {
            cout << "You Win!" << endl;
            ++Win; // �������ʤ������������
        }
        else if(ret == -1 || ret == 1) // ������ʧ��
        {
            cout << "You Lose!" << endl;
            ++Lose; // �������ʧ�ܴ���������
        }
    }
    cout << "=============GAME Over=============" << endl;
    cout << "count:" << count << endl;
    cout << "Win:" << Win << endl;
    cout << "Lose:" << Lose << endl;
    
    cout << "=============GAME END=============" << endl;
    
    return 0;
}
