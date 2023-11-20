#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>
#include "clui.h"
using namespace std;

int End,Row,Col;
void bombNumber(int, int,int,int);
void Game(int,int);
void BubbleSort(int scoreboard[], int size,char **userboard);
void slot1save(int, int, int);
void slot2save(int, int, int);
void slot3save(int, int, int);
void slot4save(int, int, int);
void slot1load();
void slot2load();
void slot3load();
void slot4load();
int arrload[3];
int **a;
bool LOAD;
int main() {
    clear_screen();
    int row, col, Mine,GameOver;
    char **username;
    username = new char *[10];//10 players
    for (int i = 0; i < 10; i++)
        username[i] = new char[50];//characters of name
    char **userboard=new char*[10];
    for (int i = 0; i < 10; i++)
        userboard[i] = new char[50];//Leaderboard name array
    int scoreboard[10];//Leaderboard score array
    int score[10];//storing scores for leaderboard
    char empty[] = "Empty";//appearance of leaderboard
    for(int i=0;i<10;i++)
        score[i]=0;
    char user[50];//user is playing
    int player = 0,tempplayer=0,temp1;
    
    LOOP:while (player < 10) {//Number of Players. Each player has infinite games
        GameOver=0;
        LOAD=false;
        int scoretemp = 0;
        End = 0;
        change_color_rgb(105, 255, 170);
        cout << "Enter Your name:";
        reset_color();
        cin >> username[player];
        strcpy(user, username[player]);//Comparing usernames to prevent duplication
        for (int i = 0; i < player; i++) {//Checking same users
            if (strcmp(username[player], username[i]) == 0) {
                scoretemp = score[i];
                strcpy(user, username[i]);
                tempplayer=player-1;
                player=i;
                cout << user << "'s score=" << scoretemp << endl;
            }
        }
        int MainMenu=0;
        LOOPmain:while(MainMenu == 0){//print MainMenu
            reset_color();
            cout <<endl<< user<<endl;
            cout <<endl<< "1.New Game";
            change_color_rgb(255, 218, 125);
            cout << endl << "2.Load Game";
            change_color_rgb(105, 255, 170);
            cout << endl << "3.Change User";
            change_color_rgb(140, 240, 58);
            cout << endl << "4.Leaderboard" << endl;
            change_color_rgb(247, 20, 46);
            cout << "5.Quit";
            reset_color();
            cout<< endl << endl << "Choose a number:";
        
            int menu;
            cin >> menu;
            LOOPmenu:switch (menu) {//options of MainMenu
                case 1://new game
                    reset_color();
                    int difficulty;
                    cout << endl <<"0.MainMenu";
                    change_color_rgb(56, 89, 255);
                    cout<<endl<<"1.Easy";
                    change_color_rgb(219, 30, 252);
                    cout << endl << "2.Moderate";
                    change_color_rgb(247, 20, 46);
                    cout << endl << "3.Hard";
                    reset_color();
                    change_color_rgb(0, 255, 255);
                    cout << endl << "4.Custom(from 5 to 20)";
                    reset_color();
                    cout << endl <<endl<< "Choose difficulty:";
                    cin >> difficulty;
                    switch (difficulty) {//Choose difficulty
                        case 0:
                            MainMenu=0;
                            goto LOOPmain;
                        case 1://easy
                            row = 5, col = 5, Mine = 4;
                            a = new int *[row];
                            for (int i = 0; i < row; i++) {
                                a[i] = new int[col];
                                for (int j = 0; j < col; j++)
                                    a[i][j] = -2;
                            }
                            srand(time(0));
                            for (int i = 0; i < Mine; i++) {
                                int x = rand() % 5;
                                int o = rand() % 5;
                                if (a[x][o] == -1) {
                                    i--;
                                    continue;
                                } else
                                    a[x][o] = -1;
                            }
                            MainMenu=1;
                            break;
                        case 2://moderate
                            row = 12, col = 12, Mine = 28;
                            a = new int *[row];
                            for (int i = 0; i < row; i++) {
                                a[i] = new int[col];
                                for (int j = 0; j < col; j++)
                                    a[i][j] = -2;
                            }
                            srand(time(0));
                            for (int i = 0; i < Mine; i++) {
                                int x = rand() % 12;
                                int o = rand() % 12;
                                if (a[x][o] == -1) {
                                    i--;
                                    continue;
                                } else
                                    a[x][o] = -1;
                            }
                            MainMenu=1;
                            break;
                        case 3://hard
                            row = 20, col = 20, Mine = 96;
                            a = new int *[row];
                            for (int i = 0; i < row; i++) {
                                a[i] = new int[col];
                                for (int j = 0; j < col; j++)
                                    a[i][j] = -2;
                            }
                            srand(time(0));
                            for (int i = 0; i < Mine; i++) {
                                int x = rand() % 20;
                                int o = rand() % 20;
                                if (a[x][o] == -1) {
                                    i--;
                                    continue;
                                } else
                                    a[x][o] = -1;
                            }
                            MainMenu=1;
                            break;
                        case 4://costume
                            change_color_rgb(49, 214, 66);
                            cout << "Enter rows & columns:";
                            reset_color();
                            cin >> row >> col;
                            while (row > 20 || row < 5) {
                                change_color_rgb(255, 245, 48);
                                cout << "Enter a number from 5 to 20 for Rows:";
                                play_beep();
                                reset_color();
                                cin >> row;
                            }
                            while (col > 20 || col < 5) {
                                change_color_rgb(255, 245, 48);
                                cout << "Enter a number from 5 to 20 for Columns:";
                                play_beep();
                                reset_color();
                                cin >> col;
                            }
                            change_color_rgb(49, 214, 66);
                            cout << "Enter number of Mines:";
                            reset_color();
                            cin >> Mine;
                            while(Mine>row*col){
                                change_color_rgb(255, 245, 48);
                                cout << "Enter a number lesser than "<<row*col<<":";
                                play_beep();
                                reset_color();
                                cin >> Mine;
                            }
                            a = new int *[row];
                            for (int i = 0; i < row; i++) {
                                a[i] = new int[col];
                                for (int j = 0; j < col; j++)
                                    a[i][j] = -2;
                            }
                            srand(time(0));
                            for (int i = 0; i < Mine; i++) {
                                int x = rand() % row;
                                int o = rand() % col;
                                if (a[x][o] == -1) {
                                    i--;
                                    continue;
                                } else
                                    a[x][o] = -1;
                            }
                            MainMenu=1;
                            break;
                        default://anything else
                            if(difficulty > 4 || difficulty < 0) {
                                change_color_rgb(240, 229, 26);
                                cout <<endl<< "Enter valid difficulty!";
                                play_beep();
                            }
                            clear_screen();
                            goto LOOPmenu;
                    }
                    break;
                case 2://Load game
                    int load;
                    reset_color();
                    cout<<endl<<"0.MainMenu";
                    change_color_rgb(214, 164, 163);
                    cout<<endl<<"1.Load slot"<<endl<<"2.Load slot"<<endl<<"3.Load slot"<<endl<<"4.Load slot"<<endl<<endl;
                    reset_color();
                    cout<<"Choose slot:";
                    cin >> load;
                    LOOPload:switch (load) {
                        case 0:
                            goto LOOPmain;
                        case 1:
                            slot1load();
                            cout << LOAD<<endl;
                            if(LOAD) {
                                row = arrload[0];
                                col = arrload[1];
                                Mine = arrload[2];
                                cout << "if statment"<<endl;
                                break;
                            }
                            else
                                clear_screen();
                                goto LOOPmain;
                        case 2:
                            slot2load();
                            if(LOAD) {
                                row = arrload[0];
                                col = arrload[1];
                                Mine = arrload[2];
                                break;
                            }
                            else
                                clear_screen();
                                goto LOOPmain;
                        case 3:
                            slot3load();
                            if(LOAD) {
                                row = arrload[0];
                                col = arrload[1];
                                Mine = arrload[2];
                                break;
                            }
                            else
                                clear_screen();
                                goto LOOPmain;
                        case 4:
                            slot4load();
                            if(LOAD) {
                                row = arrload[0];
                                col = arrload[1];
                                Mine = arrload[2];
                                break;
                            }
                            else
                                clear_screen();
                                goto LOOPmain;
                        default:
                            if(load > 4 || load < 1) {
                                change_color_rgb(240, 229, 26);
                                cout <<endl<< "Enter valid load slot!"<<endl;
                                play_beep();
                            }
                            clear_screen();
                            goto LOOPmenu;
                    }
                    break;
                case 3://change user
                    player++;
                    goto LOOP;
                case 4://Leaderboard
                    clear_screen();
                    change_color_rgb(140, 240, 58);
                    for (int i = 0; i < 10; i++)
                        scoreboard[i] = score[i];
                    temp1 = player;
                    if (player < tempplayer + 1)
                        player = tempplayer + 1;
                    for (int i = player; i < 10; i++)
                        username[i] = empty;
                    if (temp1 < tempplayer)
                        player = tempplayer+1;
                    for (int i = 0; i < 10; i++)
                        userboard[i] = username[i];
                    BubbleSort(scoreboard, 10, userboard);
                    for (int i = 0; i < 5; i++)
                        cout << userboard[i] << ": " << scoreboard[i] << endl;
                    reset_color();
                    cout << "Press any key to continue in MainMenu...";
                    getch();
                    clear_screen();
                    MainMenu=0;
                    goto LOOPmain;
                case 5://Quit
                    exit(0);
                default://anything else
                    if(menu > 5 || menu < 1) {
                        change_color_rgb(240, 229, 26);
                        cout <<endl<< "Enter valid menu number!"<<endl;
                        play_beep();
                    }
                    clear_screen();
                    MainMenu=0;
                    goto LOOPmain;
            }
            break;
        }   
        clear_screen();
        cout << "   ";
        for (int i = 1; i <= col; i++) {
            if (i > 9){
                change_color_rgb(255, 242, 0);
                cout << i << " ";
                reset_color();
            }
            else{
                change_color_rgb(255, 242, 0);
                cout << i << "  ";
                reset_color();
            }
        }
        Game(row,col);
        int frow, fcol, i_flag = 10;
        int flagCounter = 0;
        int *flag = new int[Mine];
    LOOPgame:while (End != 1) {//Playing game
            change_color_rgb(136, 252, 154);
            cout << "Flag=0/ Save=50/ Exit to MainMenu=100" << endl;
            change_color_rgb(255, 242, 0);
            cout << "Enter Row, Column:";
            reset_color();
            cin >> Row;
            int save=1;
            LOOPsave:do{ 
                if(Row==50 || save < 1 || save > 4){//Save
                    if(save < 1 || save > 4) {
                        change_color_rgb(240, 229, 26);
                        cout <<"Enter valid save!"<<endl;
                        reset_color();
                    }
                    reset_color();
                    cout <<endl<< "0.Return game";
                    change_color_rgb(163, 213, 214);
                    cout<<endl<<"1.Save slot"<<endl<<"2.Save slot"<<endl<<"3.Save slot"<<endl<<"4.Save slot"<<endl<<endl;
                    reset_color();
                    cout<<"Choose slot:";
                    cin >> save;
                    switch (save) {
                        case 0:
                            goto LOOPgame;
                        case 1:
                            slot1save(row, col, Mine);
                            change_color_rgb(0, 219, 29);
                            cout <<"$ Saved on slot1 successfully $";
                            change_color_rgb(255, 242, 0);
                            cout <<endl<< "Enter Row, Column:";
                            reset_color();
                            cin >> Row;
                            if(Row==50)//Save
                                goto LOOPsave; 
                            if(Row==100){//Exit to MainMenu
                                MainMenu=0;
                                goto LOOPmain;
                            }
                            break;
                        case 2:
                            slot2save(row, col, Mine);
                            change_color_rgb(0, 219, 29);
                            cout <<"$ Saved on slot2 successfully $";
                            change_color_rgb(255, 242, 0);
                            cout <<endl<< "Enter Row, Column:";
                            reset_color();
                            cin >> Row;
                            if(Row==50)//Save
                                goto LOOPsave; 
                            if(Row==100){//Exit to MainMenu
                                MainMenu=0;
                                goto LOOPmain;
                            }
                            break;
                        case 3:
                            slot3save(row, col, Mine);
                            change_color_rgb(0, 219, 29);
                            cout <<"$ Saved on slot3 successfully $";
                            change_color_rgb(255, 242, 0);
                            cout <<endl<< "Enter Row, Column:";
                            reset_color();
                            cin >> Row;
                            if(Row==50)//Save
                                goto LOOPsave; 
                            if(Row==100){//Exit to MainMenu
                                MainMenu=0;
                                goto LOOPmain;
                            }
                            break;
                        case 4:
                            slot4save(row, col, Mine);
                            change_color_rgb(0, 219, 29);
                            cout <<"$ Saved on slot4 successfully $";
                            change_color_rgb(255, 242, 0);
                            cout <<endl<< "Enter Row, Column:";
                            reset_color();
                            cin >> Row;
                            if(Row==50)//Save
                                goto LOOPsave; 
                            if(Row==100){//Exit to MainMenu
                                MainMenu=0;
                                goto LOOPmain;
                            }
                            break;
                        default:
                            goto LOOPsave;
                    }
                }
            }while(save < 1 || save > 4);
            if(Row==100){//Exit to MainMenu
                MainMenu=0;
                goto LOOPmain;
            }
            if (flagCounter < Mine) {//Flag
                while (Row == 0 && flagCounter < Mine){//Flag homes
                    change_color_rgb(255, 0, 242);
                    cout << "Enter flag Row, Column:";
                    reset_color();
                    cin >> frow >> fcol;
                    while (a[frow - 1][fcol - 1] >= 0) {
                        change_color_rgb(240, 229, 26);
                        cout << "Can not flag this" << endl ;
                        change_color_rgb(255, 0, 242);
                        cout << "Enter another flag Row ,Column:";
                        reset_color();
                        cin >> frow >> fcol;
                    }
                    int tmp = a[frow - 1][fcol - 1];
                    flag[i_flag / 10 - 1] = tmp;
                    if(tmp==-1)
                        a[frow - 1][fcol - 1]=i_flag*-1;
                    else
                        a[frow - 1][fcol - 1] = i_flag;
                    i_flag += 10;
                    flagCounter++;
                    if(End==1){
                        for(int k=0;k<Mine;k++){
                            if(flag[k]==-1){
                                for(int i=0;i<row;i++)
                                    for(int j=0;j<col;j++)
                                        if(a[i][j]==(k+1)*-10)
                                            a[i][j]=-1;
                            }}}
                    Game(row, col);
                    change_color_rgb(136, 252, 154);
                    cout << "Flag=0/ Save=50/ Exit to MainMenu=100" << endl;
                    change_color_rgb(255, 242, 0);
                    cout << "Enter Row, Column:";
                    reset_color();
                    cin >> Row;
                    if(Row==50)//Save
                        goto LOOPsave; 
                    if(Row==100){//Exit to MainMenu
                            MainMenu=0;
                            goto LOOPmain;
                    }
                }
                while(flagCounter == Mine && Row == 0) {//Flag counter
                    change_color_rgb(247, 20, 46);
                    cout << endl << "No more flags!" << endl;
                    change_color_rgb(255, 242, 0);
                    cout<< "Enter Row, Column:";
                    reset_color();
                    cin >> Row;
                    if(Row==50)//Save
                        goto LOOPsave; 
                    if(Row==100){//Exit to MainMenu
                            MainMenu=0;
                            goto LOOPmain;
                    }
                }
            }
            cin >> Col;
            while (Row > row || Row < 0) {
                change_color_rgb(255, 60, 38);
                cout << endl << "Enter valid Row:";
                play_beep();
                reset_color();
                cin >> Row;
                if(Row==50)//Save
                    goto LOOPsave; 
                if(Row==100){//Exit to MainMenu
                            MainMenu=0;
                            goto LOOPmain;
                    }
            }
            while (Col > col || Col < 1) {
                change_color_rgb(255, 60, 38);
                cout << endl << "Enter valid Column:";
                play_beep();
                reset_color();
                cin >> Col;
            }
            char yes_no;
            if (a[Row - 1][Col - 1] % 10 == 0 && a[Row - 1][Col - 1] != 0) {
                change_color_rgb(255, 0, 242);
                cout << "Disable flag?(y/n):";
                play_beep();
                reset_color();
                cin >> yes_no;
                while (yes_no != 'y' && yes_no != 'n') {
                    change_color_rgb(161, 38, 255);
                    cout << "Enter(y/n):";
                    play_beep();
                    reset_color();
                    cin >> yes_no;
                }
                if (yes_no == 'y') {
                    int tmp=a[Row-1][Col-1]/10;
                    if(tmp<0)
                        tmp*=-1;
                    a[Row-1][Col-1]=flag[tmp-1];
                    flagCounter--;
                    i_flag -= 10;
                    if(End==1){//Reset values
                        for(int k=0;k<Mine;k++){
                            if(flag[k]==-1){
                                for(int i=0;i<row;i++)
                                    for(int j=0;j<col;j++)
                                        if(a[i][j]==(k+1)*-10)
                                            a[i][j]=-1;
                            }}}
                    Game(row, col);
                    continue;
                } else
                    continue;
            }
            while (a[Row - 1][Col - 1] >= 0) {
                change_color_rgb(255, 38, 154);
                cout << "It's open, choose another:";
                play_beep();
                reset_color();
                cin >> Row ;
                if(Row==50)//Save
                    goto LOOPsave; 
                cin>> Col;
                while (Row > row || Row <= 0) {
                    change_color_rgb(255, 60, 38);
                    cout << endl << "Enter valid Row:";
                    play_beep();
                    reset_color();
                    cin >> Row;
                    if(Row==50)//Save
                        goto LOOPsave;
                    if(Row==100){//Exit to MainMenu
                            MainMenu=0;
                            goto LOOPmain;
                    }
                }
                while (Col > col || Col < 1) {
                    change_color_rgb(255, 60, 38);
                    cout << endl << "Enter valid Column:";
                    play_beep();
                    reset_color();
                    cin >> Col;
                }
            }
            Row--;
            Col--;
            if (a[Row][Col] != -1) {
                bombNumber(Row, Col, row, col);
                for (int i = 0; i < row; i++)
                    for (int j = 0; j < col; j++)
                        if (a[i][j] == -2)
                            End = 0;
            } else {

                cout << endl;
                End = 1;
                GameOver=1;
                play_beep();
            }
            int temp = 0;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (a[i][j] >= 0 && a[i][j]<10)
                        temp++;
                }
            }
            if (temp == row * col - Mine)
                End = 1;
            if(End==1){//Reset values
                for(int k=0;k<Mine;k++){
                    if(flag[k]==-1){
                        for(int i=0;i<row;i++)
                            for(int j=0;j<col;j++)
                                if(a[i][j]==(k+1)*-10)
                                    a[i][j]=-1;
                    }}}
            Game(row, col);
        }
        if(GameOver==1){
            change_color_rgb(250, 15, 15);
            for (int i = 1; i <= 3; i++) {
                cout << endl;
                for (int j = 1; j <= 13; j++) {
                    if (i == 2 && j == 1) {
                        cout << "% Game Over %";
                        j = 14;
                    } else
                        cout << "*";
                }
            }
            reset_color();
            cout <<endl;
        }
        else{
            change_color_rgb(60, 255, 0);
            for (int i = 1; i <= 3; i++) {
                cout << endl;
                for (int j = 1; j <= 13; j++) {
                    if (i == 2 && j == 1) {
                        cout << "&  You Won  &";
                        j = 14;
                    } else
                        cout << "$";
                }
            }
            play_beep();
            reset_color();
            cout << endl;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (a[i][j] > 0 && a[i][j]<10)
                    scoretemp++;
            }
        }
        score[player] = scoretemp;
        cout << "Your Score is: " << score[player] << endl << endl;
        ofstream score_file("Score.txt", ios::app);
        score_file << user << "{Rows:" << row << " Columns:" << col << "} Score:" << score[player] << endl;
        score_file.close();
        if(player<tempplayer+1)
            player=tempplayer;
        End=0;
        MainMenu=0;
        GameOver=0;
        goto LOOPmain;
    }
}

void bombNumber(int x, int y,int row,int col){

    int sum=0;
    for(int i=x-1;i<=x+1;i++)
        for(int j=y-1;j<=y+1;j++)
            if(i<row && j<col && i>=0 && j>=0)
                if(a[i][j]==-1 || a[i][j]<-9)
                    sum++;
    if(sum>0)
        a[x][y]=sum;
    else{//Checking surrounding homes
        a[x][y]=0;
        for(int i=x-1;i<=x+1;i++)
            for(int j=y-1;j<=y+1;j++)
                if(i<row && j<col && i>=0 && j>=0)
                    if(a[i][j]==-2)
                        bombNumber(i,j,row,col);
    }
}
void Game(int row,int col){
    clear_screen();
    cout << "   ";
    for(int i=1; i <= col; i++) {
        if (i>9){
            change_color_rgb(255, 242, 0);
            cout << i << " ";
            reset_color();
        }
        else{
            change_color_rgb(255, 242, 0);
            cout << i << "  ";
            reset_color();
        }
    }
    cout <<endl<< "   ";
    for(int i=1; i <= col; i++) {
        if (i>9){
            change_color_rgb(255, 242, 0);
            cout << "__ ";
            reset_color();
        }
        else{
            change_color_rgb(255, 242, 0);
            cout << "_  ";
            reset_color;
        }
    }
    cout << endl;
    for(int i=0;i<row;i++){
        if (i<9){
            change_color_rgb(255, 242, 0);
            cout << " "<<i+1 << "|";
            reset_color();
        }
        else{
            change_color_rgb(255, 242, 0);
            cout << i+1<<"|";
            reset_color();
        }
        for(int j=0;j<col;j++) {
            switch (a[i][j]%10) {
                case -2:
                    cout << "*  ";
                    break;
                case -1:
                    if (End == 1) {
                        change_color_rgb(255, 0, 0);
                        cout << "B  ";
                        reset_color();
                    }
                    else
                        cout << "*  ";
                    break;
                case 0:
                    if(a[i][j]!=0){
                        change_color_rgb(255, 0, 242);
                        cout << "F  ";
                        reset_color();
                    }
                    else
                        cout << "   ";
                    break;
                default:{
                    change_color_rgb(75, 200, 250);
                    cout << a[i][j] << "  ";
                    reset_color();
                }
            }
        }
        cout <<endl;
    }
}
void BubbleSort(int scoreboard[], int size,char **userboard){
    for (int i=0;i<size-1;i++)
        for (int j=0;j<size-1-i;j++)
            if(scoreboard[j + 1] > scoreboard[j]) {
                swap(scoreboard[j], scoreboard[j + 1]);
                swap(userboard[j],userboard[j+1]);
            }
}
void slot1save(int row, int col, int Mine){
    ofstream slot1("slot1.txt",ios::out);
    slot1<<row<<endl<<col<<endl<<Mine<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            slot1 << a[i][j]<<endl;
    }
    slot1.close();
}
void slot2save(int row, int col, int Mine){
    ofstream slot2("slot2.txt",ios::out);
    slot2<<row<<endl<<col<<endl<<Mine<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            slot2 << a[i][j]<<endl;
    }
    slot2.close();
}
void slot3save(int row, int col, int Mine){
    ofstream slot3("slot3.txt", ios::out);
    slot3 << row << endl << col << endl << Mine << endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            slot3 << a[i][j]<<endl;
    }
    slot3.close();
}
void slot4save(int row, int col, int Mine){
    ofstream slot4("slot4.txt", ios::out);
    slot4 << row << endl << col << endl << Mine << endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            slot4 << a[i][j]<<endl;
    }
    slot4.close();
}
void slot1load(){
    ifstream slot1("slot1.txt",ios::in);
    if (!slot1) {
        change_color_rgb(250, 15, 15);
        cout << endl << "There is no slot";
        reset_color();
        cout <<endl<< "Press any key to continue in MainMenu...";
        getch();
    }
    else {
        slot1>>arrload[0];
        slot1>>arrload[1];
        slot1>>arrload[2];
        a = new int *[arrload[0]];
        for (int i=0;i<arrload[0];i++) {
            a[i] = new int[arrload[1]];
            for (int j=0;j<arrload[1];j++)
                slot1>>a[i][j];
        }
        slot1.close();
        LOAD= true;
        cout <<"Fuck"<<endl;
    }
}
void slot2load(){
    ifstream slot2("slot2.txt",ios::in);
    if (!slot2) {
        change_color_rgb(250, 15, 15);
        cout << endl << "There is no slot";
        reset_color();
        cout <<endl<< "Press any key to continue in MainMenu...";
        getch();
    }
    else {
        slot2>>arrload[0];
        slot2>>arrload[1];
        slot2>>arrload[2];
        a = new int *[arrload[0]];
        for (int i=0;i<arrload[0];i++) {
            a[i] = new int[arrload[1]];
            for (int j=0;j<arrload[1];j++)
                slot2>>a[i][j];
        }
        slot2.close();
        LOAD= true;
        cout <<"Fuck2"<<endl;
    }
}
void slot3load(){
    ifstream slot3("slot3.txt", ios::in);
    if (!slot3) {
        change_color_rgb(250, 15, 15);
        cout << endl << "There is no slot";
        reset_color();
        cout <<endl<< "Press any key to continue in MainMenu...";
        getch();
    }
    else {
        slot3 >> arrload[0];
        slot3 >> arrload[1];
        slot3 >> arrload[2];
        a = new int *[arrload[0]];
        for (int i=0;i<arrload[0];i++) {
            a[i] = new int[arrload[1]];
            for (int j=0;j<arrload[1];j++)
                slot3 >> a[i][j];
        }
        slot3.close();
        LOAD= true;
    }
}
void slot4load(){
    ifstream slot4("slot4.txt", ios::in);
    if (!slot4) {
        change_color_rgb(250, 15, 15);
        cout << endl << "Slot is empty...!"<<endl;
        reset_color();
        cout <<endl<< "Press any key to continue in MainMenu...";
        getch();
    }
    else {
        slot4 >> arrload[0];
        slot4 >> arrload[1];
        slot4 >> arrload[2];
        a = new int *[arrload[0]];
        for (int i=0;i<arrload[0];i++) {
            a[i] = new int[arrload[1]];
            for (int j=0;j<arrload[1];j++)
                slot4 >> a[i][j];
        }
        slot4.close();
        LOAD= true;
    }
}