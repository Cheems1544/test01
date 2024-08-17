#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// 定义枚举类型，表示石头、剪刀、布三种选择
enum Choice { ROCK, PAPER, SCISSORS };

// 获取计算机的选择
Choice getComputerChoice() {
    return static_cast<Choice>(rand() % 3);
}

// 比较玩家和计算机的选择，返回1表示玩家赢，-1表示玩家输，0表示平局
int compareChoices(Choice player, Choice computer) {
    if (player == computer) return 0;
    if ((player == ROCK && computer == SCISSORS) || (player == PAPER && computer == ROCK) ||(player == SCISSORS && computer == PAPER)) return 1;
    return -1;
}

// 打印选择结果
void printChoice(Choice choice) 
{
    switch (choice) 
	{
        case ROCK: cout << "ROCK"; 
		break;
        case PAPER: cout << "PAPER"; 
		break;
        case SCISSORS: cout << "SCISSORS"; 
		break;
    }
}

int main() {
    srand(time(0)); // 初始化随机数种子
    int wins = 0, losses = 0, ties = 0; // 记录胜利、失败和平局的次数
    char input;

    while (true) {
        cout << "Please input (R/P/S) or Q to exit "; // 提示用户输入
        cin >> input;

        if (input == 'Q' || input == 'q') 
		{
            break; // 如果输入Q或q，退出循环
        }

        Choice playerChoice;
        switch (input) {
            case 'R': case 'r': playerChoice = ROCK; 
			break;
            case 'P': case 'p': playerChoice = PAPER; 
			break;
            case 'S': case 's': playerChoice = SCISSORS; 
			break;
            default:
            cout << "Invalid input, please re-enter\n"; // 如果输入无效，提示重新输入
            continue;
        }

        Choice computerChoice = getComputerChoice(); // 获取计算机的选择
        cout << "You have chosen "; 
		printChoice(playerChoice); // 打印玩家的选择
        cout << ", computer selected "; 
		printChoice(computerChoice); // 打印计算机的选择
        cout << ".\n";

        int result = compareChoices(playerChoice, computerChoice); // 比较结果
        if (result == 1) {
            cout << "You Win\n"; // 玩家赢
            wins++;
        } else if (result == -1) {
            cout << "You Out\n"; // 玩家输
            losses++;
        } else {
            cout << "Darw\n"; // 平局
            ties++;
        }
    }

    cout << "game end\n"; // 游戏结束提示
    cout << "==============================" << endl;
    cout << "==============================" << endl;
    cout << "==============================" << endl;
    cout << "win cishu" << wins << "\n"; // 输出胜利次数
    cout << "out cishu" << losses << "\n"; // 输出失败次数
    cout << "Darw cishu" << ties << "\n"; // 输出平局次数

    return 0;
}
