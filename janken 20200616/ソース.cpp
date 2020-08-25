
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include<stdio.h>
using namespace std;

void lose() {
	cout << "�����I�I" << endl;
}

void win() {
	cout << "�������I�I" << endl;
}

int judgement(int cput, int playert) {

	if (cput == 0 && playert == 1) {
		return -1;
	}
	else if (cput == 1 && playert == 2) {
		return -1;
	}
	else if (cput == 2 && playert == 0) {
		return -1;
	}
	else if (cput == 1 && playert == 0) {
		return 1;
	}
	else if (cput == 2 && playert == 1) {
		return 1;
	}
	else if (cput == 0 && playert == 2) {
		return 1;
	}
	else if (cput == playert) {
		return 0;
	}
}



int main() {
	srand(time(NULL));

	FILE* fp = NULL;
	FILE* sf = NULL;
	char str[256] = { 0 };

	int cpu = 0;
	int player = 0;
	int playerwin = 0;
	int cpuwin = 0;
	int draw = 0;


	//�t�@�C�����J��
	sf = fopen("save.txt", "r");
	if (sf == NULL) {
		playerwin = 0;
		cpuwin = 0;
		draw = 0;
	}
	else
	{
		//�O��܂ł̓��e���o�͂���
		fgets(str, 256, sf);
		playerwin = atoi(&str[0]);
		fgets(str, 256, sf);
		cpuwin = atoi(&str[0]);
		fgets(str, 256, sf);
		draw = atoi(&str[0]);
		fclose(sf);
	}




	while (playerwin < 3 && cpuwin < 3) {
		cpu = rand() % 3;
		cout << "�����o���H�@�O�F�O�[�@�P�F�`���L�@2�F�p�[" << endl;
		cin >> player;
		if (player == 0) {
			cout << "���Ȃ��̓O�[�������܂���" << endl;
		}
		else if (player == 1) {
			cout << "���Ȃ��̓`���L���o���܂���" << endl;
		}
		else if (player == 2) {
			cout << "���Ȃ��̓p�[���o���܂���" << endl;
		}

		if (cpu == 0) {
			cout << "����̓O�[�������܂���" << endl;
		}
		else if (cpu == 1) {
			cout << "����̓`���L���o���܂���" << endl;
		}
		else if (cpu == 2) {
			cout << "����̓p�[���o���܂���" << endl;
		}

		if (judgement(cpu, player) == -1) {
			cout << "�����I�I" << endl;
			++cpuwin;
			continue;
		}
		else if (judgement(cpu, player) == 1) {
			cout << "�������I�I" << endl;
			++playerwin;
			continue;
		}
		else {
			cout << "��������" << endl;
			++draw;
			continue;
		}
	}
	cout << "�������񐔂�" << playerwin << "��ł�" << endl;
	cout << "�������񐔂�" << cpuwin << "��ł�" << endl;
	cout << "�����������񐔂�" << draw << "��ł�" << endl;

	//�ǉ��������݌^�ŊJ��
	sf = fopen("save.txt", "w");
	if (sf == NULL) {
		printf("�������݂ł��܂���ł����B");
		return -1;
	}
	//�����܂ł̌��ʂ�ۑ�����
	char saveData[32] = { 0 };
	fprintf(sf, "%d\n%d\n%d", playerwin, cpuwin, draw);
	fclose(sf);
	//	while ((fgets(str, 256, fp)) != NULL) {
	//		printf("%s", str);
	//		fputs(str, sf);
	//	}


	return 0;
}