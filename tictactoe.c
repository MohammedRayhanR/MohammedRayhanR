//Tic Tac Toe:
#include <stdio.h>
#include<conio.h>
#include <string.h>
void updateTable(char arr[3][3]){
    printf(" %c | %c | %c\n",arr[0][0],arr[0][1],arr[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n",arr[1][0],arr[1][1],arr[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n",arr[2][0],arr[2][1],arr[2][2]);
}
int tracker(char a[3][3]){
    for(int i=0;i<3;i++){
        if((a[i][0]==a[i][1]&&a[i][2]==a[i][1]&&a[i][0]==a[i][2])&&(a[i][0]=='X'||a[i][0]=='O')){
            return 1;
        }
    }
    for(int i=0;i<3;i++){
        if((a[0][i]==a[1][i]&&a[2][i]==a[1][i]&&a[0][i]==a[2][i])&&(a[0][i]=='X'||a[0][i]=='O')){
            return 1;
        }
    }        
    if((a[0][0]==a[1][1]&&a[2][2]==a[1][1]&&a[0][0]==a[2][2])&&(a[0][0]=='X'||a[0][0]=='O')){
        return 1;
    }
    if((a[0][2]==a[1][1]&&a[2][0]==a[1][1]&&a[0][2]==a[2][0])&&(a[2][0]=='X'||a[2][0]=='O')){
        return 1;
    }
    return 0;
}
int main() {
    char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int visited[9]={0};
    int box;
    int count=0;
    char opt;
    int i,j;
    printf("Structure:\n");
    updateTable(arr);
    char lst[2];
    while(1){
    printf("Who plays first? 'X' or 'O'\n");
    scanf(" %c",&opt);
    if(opt=='X'||opt=='x'){
        strcpy(lst,"XO");
        break;
    }
    else if(opt=='O'||opt=='o'){
        strcpy(lst,"OX");
        break;
    }        
    else{
        printf("Enter valid one\n");
    }}
    do{
        printf("\a");
        printf("Player %d: \n",(count%2)+1);
        printf("Select a box: ");
        scanf("%d",&box);
        if(visited[box-1]==1){
            printf("It is already filled!!!\n");
            continue;
        }    
        if(box>0&&box<10){
            i=(box-1)/3;
            j=(box-1)%3;
        }   
        else{
            printf("Enter correct one(1 to 9)\n");
            continue;
        }    
        visited[box-1]=1;
        arr[i][j]=lst[count%2];
        if(tracker(arr)==1){
            printf("\nGame Over\n");
            printf("Player %d wins the game...\n",1+count%2);
            updateTable(arr);
            break;
        }   
        clrscr();
        updateTable(arr);
        count++;
    }while(count!=9);
    if(count==9){ printf("Match draw...\n");}
    return 0;
}