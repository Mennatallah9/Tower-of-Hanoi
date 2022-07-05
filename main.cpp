#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
void   moveDisk(int, string, string, string,string[]);
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
int main(int argc, char* argv[]) {
    int disks,info;
system("cls");
printf(CYAN"\n\n  *********************************************************************************************************\n"RESET);
std::cout << MAGENTA R"(
 _ _ _                   ___    ___         ___                 __   _ _
| | | |_||_ _   _ _  _  |_ _|  |_ _|||  _  |_ _|      _  _   _ / _| | U |_    _  _ ()
| V V /o\///o\|/ \ \/o\  | /o\  | | | \/o\  | /o\\VV7/o\/_| /o\| ]  |   /o\ |/ \/o\||
 \_n_/\(L\\\_/L_n_n|\(   |_\_/  |_| Ln|\(   |_\_/ VV \( L|  \_/L|   |_n_\_,]L_n|\_/L|
 )"  RESET<< '\n';

printf(CYAN"\n\n  *********************************************************************************************************\n"RESET);
    cout <<  YELLOW "-> Play (Type 1)"RESET<< endl<<BLUE "-> Instructions (Type 2)"RESET<<endl;
    cout<<RED"-> Exit (Type 3)"RESET<<endl;

    printf("\n\n");
     repeat:
        cout<<"Enter:"<<endl;
     cin>>info;
     if(info==1)
    {

           system("cls");//ALY BTMS7
           printf(YELLOW"Type the number of disks you want: "RESET);
           cin>>disks;

    }
     else if(info==2)
     {
        cout<<CYAN"1-In this game, you have to answer with in the minimum allowed steps."RESET<<endl;
        cout<<CYAN"2-To move the disk, type the number of disk no space the number of the column you want "RESET<<endl<<CYAN"  for example: 1C"RESET<<endl;
        printf("\n");
        goto repeat;
     }
     else if(info==3)
     {
       return 0;
     }
     else{
        goto repeat;

    }
    string arr[100];
    int A=10,C =20, B=30;//Origin point =A, Wanted place= C, Helper = B
    printf(BLUE"\nTotal number of allowed moves is %.0lf \n"RESET, pow(2, disks) - 1);
    printf("\n");
    cout<<RED"Enter Start then Destination and finally Helper"RESET<<endl;
    string start,dest,help;
    cin>>start>>dest>>help;
    moveDisk(disks, start ,dest , help,arr);
    cout<<MAGENTA" you start from "RESET<<start<<MAGENTA" to "RESET<<dest<<MAGENTA" with help "RESET<<help;
    printf("\n\n\n");
    string ans;
    bool flag=true;

    for(int i=0;i<(pow(2,disks)-1);i++){//simplest solution
        cin>>ans;//move 1 to b
    if (ans == arr[i])
     {// compare user ans with the real answer
            flag=true;
        }
        else{
           flag=false;
           break;
        }

 }
    if(flag){
        cout<<BLUE"You win!! :D"RESET<<endl;

    }
    else{//flag==false
        cout<<RED"You lose...:("RESET<<endl;

    }

}
void moveDisk(int numberOfDisks, string originPin, string destinyPin, string auxiliaryPin,string arr[]){
    static int i=0;//count
    if(numberOfDisks == 1)
    {
     arr[i]=to_string(numberOfDisks)+destinyPin;
     i++;
}
    else {
        moveDisk((numberOfDisks - 1), originPin, auxiliaryPin, destinyPin, arr);
        arr[i]=to_string(numberOfDisks)+destinyPin;
        i++;
        moveDisk((numberOfDisks - 1), auxiliaryPin, destinyPin, originPin, arr);
    }
}
