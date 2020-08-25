// janken 20200616.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
/*
#include <iostream>
#include <ctime>
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



int main(){
    srand(time(NULL));

    int cpu = 0;
    int player = 0;

    while (true) {
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
        else if (cpu == 2){
            cout << "相手はパーを出しました" << endl;
        }

        if (judgement(cpu, player) == -1) {
            cout << "負け！！" << endl;
            break;
        }
        else if (judgement(cpu, player) == 1) {
            cout << "勝った！！" << endl;
            break;
        }
        else  {
            cout << "あいこで" << endl;
            continue;
        }

*/




     /*  if (cpu == player) {
            cout << "あいこで" << endl;
            continue;
        }
        else if (cpu == 0 && player == 1) {
            lose();
            break;
        }
        else if (cpu == 1 && player == 2) {
            lose();
            break;
        }
        else if (cpu == 2 && player == 0) {
            lose();
            break;
        }
        else if (cpu == 1 && player == 0) {
            win();
            break;
        }
        else if (cpu == 2 && player == 1) {
            win();
            break;
        }
        else if (cpu == 0 && player == 2) {
            win();
            break;
            }
     
    }
}
*/



/*       先生のお手本

#include <iostream>
#include <ctime>
using namespace std;


int judgement(int cput, int playert)
{
      int result = 1;
      if((playert == 1 && cput == 2) || (playert == 1 && cput == 0) ||(playert == 2 && cput == 1))
      {
      result = -1;
      }
      else if (player == cput)
      {
      result = 0;
      }
      return result;
}

void testrcout(int t)
{
      switch (t) {
          case 0: cout << "グー" ; 
          break;

          case 1: cout << "チョキ";
          break;

          case 2: cout << "パー";
          break;
     }
}

void resultcout(int r)
{
     switch (r){
        case -1: cout << "あなたの負けです!" << endl;break;

        case 0: cout << "引き分け！もう一回！" << endl;break;

        case 1: cout << "あなたの勝ちです！" << endl;break;
    }
}

int main()
{
     int playert = 0;
     int cput = 0;
     int result = 0;

     srand((unsigned)time(NULL));

     do{
             cput = rand() % 3;
             cout << "手を選んでください" << endl;
             cout = "グー：０　チョキ：１　パー：２" << endl;

             cin >> playert;

             cout <<"あなたの手は";
             testrcout(playert);
             cout << endl;

             cout << "CPUの手は";
             testrcout(cput);
             cout << endl;

             result = judgement(cput, playert);
             resultcout(result);
        }while (result == 0);
        return 0;
}
*/
