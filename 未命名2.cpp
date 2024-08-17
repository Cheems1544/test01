#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// ����ö�����ͣ���ʾʯͷ��������������ѡ��
enum Choice { ROCK, PAPER, SCISSORS };

// ��ȡ�������ѡ��
Choice getComputerChoice() {
    return static_cast<Choice>(rand() % 3);
}

// �Ƚ���Һͼ������ѡ�񣬷���1��ʾ���Ӯ��-1��ʾ����䣬0��ʾƽ��
int compareChoices(Choice player, Choice computer) {
    if (player == computer) return 0;
    if ((player == ROCK && computer == SCISSORS) || (player == PAPER && computer == ROCK) ||(player == SCISSORS && computer == PAPER)) return 1;
    return -1;
}

// ��ӡѡ����
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
    srand(time(0)); // ��ʼ�����������
    int wins = 0, losses = 0, ties = 0; // ��¼ʤ����ʧ�ܺ�ƽ�ֵĴ���
    char input;

    while (true) {
        cout << "Please input (R/P/S) or Q to exit "; // ��ʾ�û�����
        cin >> input;

        if (input == 'Q' || input == 'q') 
		{
            break; // �������Q��q���˳�ѭ��
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
            cout << "Invalid input, please re-enter\n"; // ���������Ч����ʾ��������
            continue;
        }

        Choice computerChoice = getComputerChoice(); // ��ȡ�������ѡ��
        cout << "You have chosen "; 
		printChoice(playerChoice); // ��ӡ��ҵ�ѡ��
        cout << ", computer selected "; 
		printChoice(computerChoice); // ��ӡ�������ѡ��
        cout << ".\n";

        int result = compareChoices(playerChoice, computerChoice); // �ȽϽ��
        if (result == 1) {
            cout << "You Win\n"; // ���Ӯ
            wins++;
        } else if (result == -1) {
            cout << "You Out\n"; // �����
            losses++;
        } else {
            cout << "Darw\n"; // ƽ��
            ties++;
        }
    }

    cout << "game end\n"; // ��Ϸ������ʾ
    cout << "==============================" << endl;
    cout << "==============================" << endl;
    cout << "==============================" << endl;
    cout << "win cishu" << wins << "\n"; // ���ʤ������
    cout << "out cishu" << losses << "\n"; // ���ʧ�ܴ���
    cout << "Darw cishu" << ties << "\n"; // ���ƽ�ִ���

    return 0;
}
