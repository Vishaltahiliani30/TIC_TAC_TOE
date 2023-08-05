#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
char moves[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char cur_move = 'O';
int lower=0,upper=8;
int count = 0,pcount=0;
char p1[100], p2[100];
void start(){
    printf("\n\t   *****Tic Tac Toe*****\n\n");
    int i,j;
    printf("\n\n");
    printf("\t\t %c | %c | %c\n",moves[0][0],moves[0][1],moves[0][2]);
    printf("\t\t-----------\n");
    printf("\t\t %c | %c | %c\n",moves[1][0],moves[1][1],moves[1][2]);
    printf("\t\t-----------\n");
    printf("\t\t %c | %c | %c\n",moves[2][0],moves[2][1],moves[2][2]);

     
    
    for(i=0;i<3;i++){ 
        for(j=0;j<3;j++){
            moves[i][j] = ' ';
        }
    }
}

int random_num(){
    int num = (rand() % (upper - lower + 1))+lower;
    return num;
}

void change_turn(){
    if(cur_move == 'O')
        cur_move = 'X';
    else
        cur_move = 'O';
    printf("\n\t      Current Turn : %c\n",cur_move);
}
void store_move(int index){
    int x,y,flag = 1;
    switch (index)
    {
    case 1:
        x=0;
        y=0;    
        break;
    case 2:
        x=0;
        y=1;
        break;
    case 3:
        x=0;
        y=2;    
        break;
    case 4:
        x=1;
        y=0;
        break;
    case 5:
        x=1;
        y=1;
        break;
    case 6:
        x=1;
        y=2;
        break;
    case 7:
        x=2;
        y=0;
        break;
    case 8:
        x=2;
        y=1;
        break;
    case 9:
        x=2;
        y=2;
        break;
    default:
        printf("\n\t      Enter The Valid Number ");
        flag = 0;
        break;
    }
    if(flag){
        if(moves[x][y] == ' '){
            moves[x][y] = cur_move;
            count++;
            if(count>=5)
                check_winner();
            change_turn();
            print_moves();
        }else{
            printf("\n\t      Current Turn : %c\n",cur_move);
            print_moves();
            printf("\n\t      The Selected Slot Is Already Taken\n");        
        }
    }
}

void displayWinner(char cur_move) {
    if(cur_move == 'O')
        printf("\n\t      ** Name : %s **",p1);
    else
        printf("\n\t      ** Name : %s **",p2);
}

void check_winner(){
    int i;
    //for horizontal checks
    for(i=0;i<3;i++){
    
        if(moves[i][0] == moves[i][1] && moves[i][1] == moves[i][2] && moves[i][0] != ' '){
            print_moves();
            printf("\n\t      ** Winner : %c **",cur_move);
            displayWinner(cur_move);
            exit(1);
        }

    }
    //for column checks
    for (i=0;i<3;i++)
    {
        if(moves[0][i] == moves[1][i] && moves[1][i] == moves[2][i] && moves[0][i] != ' '){
            print_moves();
            printf("\n\t      ** Winner Is: %c **",cur_move);
            displayWinner(cur_move);
            exit(1);
        }
    }
    //for cross check
    if((moves[0][0] == moves[1][1] && moves[2][2] == moves[1][1]) && (moves[0][0] != ' ' && moves[1][1] != ' ' && moves[2][2] != ' ')){
            print_moves();
            printf("\n\t      ** Winner Is : %c **",cur_move);
            displayWinner(cur_move);
            exit(1);
    }else if((moves[0][2] == moves[1][1] && moves[2][0] == moves[1][1]) && (moves[0][2] != ' ' && moves[1][1] != ' ' && moves[2][0] != ' ')){
            print_moves();
            printf("\n\t      ** Winner Is: %c **",cur_move);
            displayWinner(cur_move);
            exit(1);
    }else if(count==9){
            print_moves();
            printf("\n\t        Match Draw...!!!");
            exit(1);
    }
}

void print_moves(){

    printf("\n\n");
    printf("\t\t %c | %c | %c\n",moves[0][0],moves[0][1],moves[0][2]);
    printf("\t\t-----------\n");
    printf("\t\t %c | %c | %c\n",moves[1][0],moves[1][1],moves[1][2]);
    printf("\t\t-----------\n");
    printf("\t\t %c | %c | %c\n",moves[2][0],moves[2][1],moves[2][2]);

}

int main()
{
    start();
    int index;
    do
    {
        printf("\t\n      Enter the number of players : ");
        scanf("%d",&pcount);
        printf("\n");
         printf("enter name of player 1:\n");
             scanf("%s", p1);
        if(pcount == 2){
            pcount = 0;
            
        
             printf("enter name of player 2:\n");
             scanf("%s", p2);
         }
        //  else if(pcount==1){   
        //      pcount =0;
        //     printf("enter name of player 1:\n");
        //     scanf("%s", p1);

        // }
         else{
            if(pcount != 1){
                 
    
   
                printf("\t      Enter the valid number\n");
            }
        }
    } while (pcount>2);
     // printf("enter name of player 1:\n");
     //        scanf("%s", p1);

    printf("\n\t      Current Turn : %c\n",cur_move);
    while(1)
    {   
        // else if(pcount==1){   
        //      pcount =0;
           

        // }
        if(pcount && count%2==1){
            index = random_num();
        }else{
            printf("\n\t      Enter The Index : ");
            scanf("%d",&index);
        }
        printf("\n\t     --------------------\n");
        store_move(index);
    }
    
    return 0;
}