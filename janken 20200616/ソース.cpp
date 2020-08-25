
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include<stdio.h>
using namespace std;

void lose() {
	cout << "負け！！" << endl;
}

void win() {
	cout << "勝った！！" << endl;
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


	//ファイルを開く
	sf = fopen("save.txt", "r");
	if (sf == NULL) {
		playerwin = 0;
		cpuwin = 0;
		draw = 0;
	}
	else
	{
		//前回までの内容を出力する
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
		cout << "何を出す？　０：グー　１：チョキ　2：パー" << endl;
		cin >> player;
		if (player == 0) {
			cout << "あなたはグーをだしました" << endl;
		}
		else if (player == 1) {
			cout << "あなたはチョキを出しました" << endl;
		}
		else if (player == 2) {
			cout << "あなたはパーを出しました" << endl;
		}

		if (cpu == 0) {
			cout << "相手はグーをだしました" << endl;
		}
		else if (cpu == 1) {
			cout << "相手はチョキを出しました" << endl;
		}
		else if (cpu == 2) {
			cout << "相手はパーを出しました" << endl;
		}

		if (judgement(cpu, player) == -1) {
			cout << "負け！！" << endl;
			++cpuwin;
			continue;
		}
		else if (judgement(cpu, player) == 1) {
			cout << "勝った！！" << endl;
			++playerwin;
			continue;
		}
		else {
			cout << "あいこで" << endl;
			++draw;
			continue;
		}
	}
	cout << "勝った回数は" << playerwin << "回です" << endl;
	cout << "負けた回数は" << cpuwin << "回です" << endl;
	cout << "引き分けた回数は" << draw << "回です" << endl;

	//追加書き込み型で開く
	sf = fopen("save.txt", "w");
	if (sf == NULL) {
		printf("書き込みできませんでした。");
		return -1;
	}
	//ここまでの結果を保存する
	char saveData[32] = { 0 };
	fprintf(sf, "%d\n%d\n%d", playerwin, cpuwin, draw);
	fclose(sf);
	//	while ((fgets(str, 256, fp)) != NULL) {
	//		printf("%s", str);
	//		fputs(str, sf);
	//	}


	return 0;
}