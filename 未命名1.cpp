#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL)); // 初始化随机数种子
    
    cout << "=============GAME=============" << endl;
    cout << "=====Rock-paper-scissors======" << endl;
    
    int computer = -1; // 计算机的选择
    int player = -1; // 玩家的选择
    int count = 0; // 游戏次数计数器
    int Win = 0; // 玩家胜利次数计数器
    int Lose = 0; // 玩家失败次数计数器
    
    int ret; // 用于存储比较结果的变量
    
    while(1) // 无限循环，直到玩家选择退出
    {
        cout << "0.Rock" << endl;
        cout << "1.Scissors" << endl;
        cout << "2.Paper" << endl;
        cout << "3.quit" << endl;
        cout << "input num:" << endl;
        cin >> player; // 获取玩家输入
        
        if(cin.fail()) // 检查输入是否有效
        {
            cin.clear(); // 清除错误标志
            cin.ignore(); // 忽略错误输入
            cout << "input error" << endl;
            continue; // 继续下一次循环
        }
        if(player < 0 || player > 3) // 检查输入是否在有效范围内
        {
            cout << "out of range!" << endl;
            continue; // 继续下一次循环
        }
        if(player == 3) // 如果玩家选择退出
        {
            break; // 跳出循环
        }
        computer = rand() % 3; // 生成计算机的随机选择
        ret = player - computer; // 计算玩家和计算机的选择差值
        ++count; // 增加游戏次数计数器
        if(ret == 0) // 如果平局
        {
            cout << "Dead heat" << endl;
        }
        else if(ret == -1 || ret == 2) // 如果玩家胜利
        {
            cout << "You Win!" << endl;
            ++Win; // 增加玩家胜利次数计数器
        }
        else if(ret == -1 || ret == 1) // 如果玩家失败
        {
            cout << "You Lose!" << endl;
            ++Lose; // 增加玩家失败次数计数器
        }
    }
    cout << "=============GAME Over=============" << endl;
    cout << "count:" << count << endl;
    cout << "Win:" << Win << endl;
    cout << "Lose:" << Lose << endl;
    
    cout << "=============GAME END=============" << endl;
    
    return 0;
}
