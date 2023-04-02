/*This game tells the user to guess any number between 0 to 100 and gives output if the Guessed number is correct.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int main(){
    int cho;
    int numb,guessnumb; 
    do{
        system("COLOR 02");
        printf("\t\t\t-----MENU-----\n");
        printf("\t\t\t1. Let's Play\n");
        printf("\t\t\t2. Exit\n");
        printf("\t\t\tEnter Your Choice Here :");
        scanf("%d",&cho);
         int countguess=1;
        switch(cho){
            case 1:
            
            printf("\n");
            srand(time(0));
            numb=rand()%100;
            do{
                printf("\t\t\t----Guess the Number Between 0 to 100----\n");
                printf("\t\t\t");
                scanf("%d",&guessnumb);
                if (guessnumb<numb){
                    printf("\t\t\tYour Guessed Number is Smaller\n");
                    printf("\t\t\tEnter Higher Number Plzz\n");
                }
                 else if (guessnumb>numb){
                    printf("\t\t\tYour Guessed Number is Greater\n");
                    printf("\t\t\tEnter Lower Number Plzz\n");
                }
                else{
                    printf("\t\t\tCongo!!!That's Right\n");
                    printf("\t\t\tYou Guessed the Correct Number in %d attempts\n",countguess);
                }
                countguess++;
            }while(guessnumb!=numb);
            break;

            case 2:
            printf("\t\t\t****Thanks For Visiting****\n");
            break;

            default:
            printf("\t\t\tWrong Choice_Plzz Enter Again\n");
            break;
        }
    }while(cho!=2);
    return 0;
    getch();
}
