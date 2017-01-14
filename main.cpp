//
//  main.cpp
//  homework2
//
//  Created by Jeremy on 4/9/16.
//  Copyright (c) 2016 Jeremy. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//種族代號A,B,C...
class Background{

    protected:
    
    static char ranking[100];//9種種族的順序
    char rankingtemp[100];//9種種族的順序的暫存
    int checkRanking[1000];//檢查是否有重複
    char MissonRandSpecies[4];//三種種族當任務卡片
    int checkMission[1000];//檢查是否有重複

    
    public:
    Background(int numberofspecies){
        int check;
        for (int i=0;i<100 ; i++) {
            ranking[i]=0;
        }
        for (int i=0;i<1000 ; i++) {
            checkRanking[i]=0;
            checkMission[i]=0;
        }
        for (int i=1; i<4; i++) {
            MissonRandSpecies[i]=check=rand()%numberofspecies+1+64;
            if (checkMission[check]==1){i=i-1;continue;
            }
            else checkMission[check]=1;

        }
    };
    //設定9種種族的順序
    void SetRanking(int numberofspecies){
        
        int temp;
        for (int i =1; i<numberofspecies+1; i++) {
            ranking[i]=temp=rand()%numberofspecies+1+64;//rand 設定ＡＢＣ...順序
            if (checkRanking[temp]==1){i=i-1;continue;
            }
            else checkRanking[temp]=1;
            
        }
    
    }

    //輸出原始順序
    void PrintInitialSpeciesOrder(){
            cout << "\nThe initial order of the species:\n";
            cout << "\t";
        for (int i =1; i<10; i++) {
            cout << ranking[i] << "\t";

        }
            cout << "\n";
    }
    
};

class Player : public Background{

    private:
    int totalpoint;//玩家總分
    int remaining_first_card;//剩餘卡片ㄧ的張數
    int remaining_second_card;//剩餘卡片二的張數
    int remaining_third_card;//剩餘卡片三的張數
    int remaining_last_card;//剩餘卡片四的張數
    int remaining_eliminate_card;//剩餘卡片五的張數
    int temp;
    
    public:
    
    Player(int numberofspecies):Background(numberofspecies){
        totalpoint=0;
        remaining_first_card=2;
        remaining_second_card=1;
        remaining_third_card=1;
        remaining_last_card=1;
        remaining_eliminate_card=2;
        temp = numberofspecies;//存放現在場上有幾個species

    };
    void Delay(int a){
        int c,d;
        for ( c = 1 ; c <= 12767*a ; c++ )
            for ( d = 1 ; d <= 16767*a ; d++ )
            {};
        
    }
    void SetRanking(int numberofspecies){
        for (int i =1; i<numberofspecies+1; i++) {
            rankingtemp[i] = ranking[i];
        }
    }
    char Intruction(){
        char CardChoice;
        cout << "Enter the number of the card which you want to use:" << "\n\n";
        cout << "1 : exchange the selected species to the first place" << "\n";
        cout << "2 : exchange the selected species to the second place" << "\n";
        cout << "3 : exchange the selected species to the third place" << "\n";
        cout << "4 : exchange the selected species to the last place" << "\n";
        cout << "5 : eliminate the species which is at the last place" << "\n";
        cin  >> CardChoice ;
        return CardChoice;
        
    }
    //種族選擇
    int SpeciesChoice(char CardChoice,int computermode){
        
        int specieschoice;
        if (CardChoice == 49) {
            if (remaining_first_card != 0) {
                    cout << "\nEnter the order of the species which you want to exchange(1~9):" << "\n";
                if (computermode !=1) {
                    cin >> specieschoice ;
                }else{
                    specieschoice = rand()%temp+1;
                }
                    remaining_first_card--;
                    return specieschoice;
            }
            else{
                cout << "No more remaining card!!" << "\n";
                Delay(1);
                return 1;
            }
        }
        if (CardChoice == 50) {
            if (remaining_second_card != 0) {
                cout << "\nEnter the order of the species which you want to exchange(1~9):" << "\n";
                if (computermode !=1) {
                    cin >> specieschoice ;
                }else{
                    specieschoice = rand()%temp+1;
                }
                remaining_second_card--;
                return specieschoice;
            }
            else{
                cout << "No more remaining card!!" << "\n";
                Delay(1);
                return 1;
            }
        }
        if (CardChoice == 51) {
            if (remaining_third_card != 0) {
                cout << "\nEnter the order of the species which you want to exchange(1~9):" << "\n";
                if (computermode !=1) {
                    cin >> specieschoice ;
                }else{
                    specieschoice = rand()%temp+1;
                }
                remaining_third_card--;
                return specieschoice;
            }
            else{
                cout << "No more remaining card!!" << "\n";
                Delay(1);
                return 1;
            }
        }
        if (CardChoice == 52) {
            if (remaining_last_card != 0) {
                cout << "\nEnter the order of the species which you want to exchange(1~9):" << "\n";
                if (computermode !=1) {
                    cin >> specieschoice ;
                }else{
                    specieschoice = rand()%temp+1;
                }
                remaining_last_card--;
                return specieschoice;
            }
            else{
                cout << "No more remaining card!!" << "\n";
                Delay(1);
                return 1;
            }
        }
        if (CardChoice == 53) {
            if (remaining_eliminate_card != 0) {
                
                remaining_eliminate_card--;

            }
            else{
                cout << "No more remaining card!!" << "\n";
                Delay(1);
                return 1;
            }

        }
        return 0;
    }
    //檢查卡是否都用完
    char Determine_remaining_card(){
        if (remaining_first_card ==0 && remaining_second_card ==0 && remaining_third_card ==0 &&remaining_third_card ==0 && remaining_last_card ==0 &&
            remaining_eliminate_card ==0) {
            cout << "NO MORE REMAINING CARD FOR CARD(1~5)!!" << "\n";
            Delay(1);
            return 'n';
        }else{
            return 'y';
        }
    }
    void Exchange_to_first(int choice){
        int temp;
        if (choice != 1) {
            temp = rankingtemp[1];
            rankingtemp[1] = rankingtemp[choice];
            rankingtemp[choice] = temp;
        }
    }
    void Exchange_to_second(int choice){
        int temp;
        if (choice != 1) {
            temp = rankingtemp[2];
            rankingtemp[2] = rankingtemp[choice];
            rankingtemp[choice] = temp;

        }
    }
    void Exchange_to_third(int choice){
        int temp;
        if (choice != 1) {
            temp = rankingtemp[3];
            rankingtemp[3] = rankingtemp[choice];
            rankingtemp[choice] = temp;

        }
    }
    void Exchange_to_last(int choice){
        int temp_ranking;
        if (choice != 1) {
            temp_ranking = rankingtemp[choice];
            for (int i = choice; i<temp; i++) {
            rankingtemp[i] = rankingtemp[i+1];
            }
            rankingtemp[temp] = temp_ranking;
        }
    }
    void Eliminate_the_last_card(int choice){
        
        if (choice != 1) {
            rankingtemp[temp] = 0;
            temp--;
        }
    }
    //算最後總分
    int Determine(){
    
        if (rankingtemp[1] == MissonRandSpecies[1])totalpoint = totalpoint+3;
        if (rankingtemp[2] == MissonRandSpecies[1] || rankingtemp[2] == MissonRandSpecies[2])totalpoint = totalpoint+2;
        if (rankingtemp[3] == MissonRandSpecies[1] || rankingtemp[3] == MissonRandSpecies[2] || rankingtemp[3] == MissonRandSpecies[3])totalpoint = totalpoint+1;
        return totalpoint;
    }
    //輸出玩家現在的順序
    void print(){
            cout << "\n\t";
        for (int i =1; i<10; i++) {
            cout << rankingtemp[i] << "\t";
        }
        cout << "\n\n";
        cout << "\n\nMissionCard\n";
        for (int i =1; i<4; i++) {
            cout << MissonRandSpecies[i];
            if (i==1) {
                cout << "    At the (1,2,3)place get (+3,+2,+1)point" << "\n";
            }
            if (i==2) {
                cout << "    At the (2,3)place get (+2,+1)point" << "\n";
            }
            if (i==3) {
                cout << "    At the (3)place get (+1)point" << "\n";
            }
            
        }
        cout << "\n\n";

    }
};



char Background::ranking[100] = {0};

int main() {
    
    int player_totalpoint,computer_totalpoint,computer_yesorno,computer_CardChoice,computer_specieschoice,c=80;
    char CardChoice,specieschoice,leftorno;
    Background b(9);
    Player player(9),computer(9);
    
    srand(time(NULL));
    b.SetRanking(9);//設定順序有9個種族
    b.PrintInitialSpeciesOrder();

//玩家模式
    leftorno = 'y';
    player.SetRanking(9);
    while (leftorno == 'y') {
        for (int i =0; i<c; i++) {cout << "-" ;}cout<<"\n";
        cout << "Player:" << "\n";
        player.print();
        CardChoice = player.Intruction();
        specieschoice = player.SpeciesChoice(CardChoice,0);
        if (CardChoice == 49) player.Exchange_to_first(specieschoice);
        if (CardChoice == 50) player.Exchange_to_second(specieschoice);
        if (CardChoice == 51) player.Exchange_to_third(specieschoice);
        if (CardChoice == 52) player.Exchange_to_last(specieschoice);
        if (CardChoice == 53) player.Eliminate_the_last_card(specieschoice);
        leftorno = player.Determine_remaining_card();
        for (int i =0; i<c; i++) {cout << "-";}cout<<"\n";
    }
    
    for (int i =0; i<c; i++) {cout << "-";}cout<<"\n";
    cout << "Player:" << "\n";
    player.print();
    player_totalpoint=player.Determine();
    cout << "The final score for player:" << player_totalpoint << "\n";
    for (int i =0; i<c; i++) {cout << "-";}cout<<"\n";
    
    
//電腦模式
    leftorno = 'y';
    computer.SetRanking(9);
    while (leftorno == 'y') {
        for (int i =0; i<c; i++) {cout << "-";}cout<<"\n";
        cout <<"\n\n"<<"Computer:" << "\n";
        computer.print();
        computer_CardChoice = rand()%5+1+48;
        computer_specieschoice = computer.SpeciesChoice(computer_CardChoice,1);
        if(computer_CardChoice == 49){computer.Exchange_to_first(computer_specieschoice);}
        if(computer_CardChoice == 50){computer.Exchange_to_second(computer_specieschoice);}
        if(computer_CardChoice == 51){computer.Exchange_to_third(computer_specieschoice);}
        if(computer_CardChoice == 52){computer.Exchange_to_last(computer_specieschoice);}
        if(computer_CardChoice == 53){computer.Eliminate_the_last_card(computer_specieschoice);}
        
        leftorno = computer.Determine_remaining_card();
        for (int i =0; i<c; i++) {cout << "-" ;}cout<<"\n";
    }
    
    for (int i =0; i<c; i++) {cout << "-";}cout<<"\n";
    cout << "\n\n"<<"Computer:" << "\n";
    computer.print();
    computer_totalpoint=computer.Determine();
    for (int i =0; i<c; i++) {cout << "-";}cout<<"\n";
    
//輸出總結果
    for (int i =0; i<c; i++) {cout << "-";}cout<<"\n";
    cout << "\n\n"<<"Computer:" << "\n";
    computer.print();
    cout << "Player:" << "\n";
    player.print();
    
    cout << "The final score for player:" << player_totalpoint << "\n";
    cout << "The final score for computer:" << computer_totalpoint << "\n";
    for (int i =0; i<c; i++) {cout << "-";}cout<<"\n";
    
    if (player_totalpoint > computer_totalpoint) {cout << "The Player win!!!" << "\n";}
    else if (player_totalpoint == computer_totalpoint){cout << "Tie!!!" << "\n";}
    else{cout << "The computer win!!!" << "\n";}
        
    return 0;
    
}












