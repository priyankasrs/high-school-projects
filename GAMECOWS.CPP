#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
void main()
{

     clrscr();
     void display();
     display();
     void menu();
     menu();

     getch();

     }

     void display()
     {
      cout<<"HELLO!WELCOME TO THIS WITFUL GAME OF.......\n\n\n\a\a\a\a\a\a";



     cout<<"\t*** *** *   * *** ' *   * ' **** *  * *    *    ***\n";
     cout<<"\t*   * * *   * *     * * *   *  * *  * *    *    *  \n";
     cout<<"\t*   * * * * * ***   *  **   **** *  * *    *    ***\n";
     cout<<"\t*** ***  * *    *   *   *   *  * **** **** ****   *\n";
     cout<<"\t  	      ***           ****                ***\n";


     }

     void instruct()
     {
     clrscr();
     cout<<"A SAMPLE OF THE GAME IS GIVEN:-\n";
     cout<<"SUPPOSE COMP. THINKS OF THE WORD 'game'\n";
     cout<<"HERE ARE THE WORDS YOU GIVE:-\nread-0 cows 2 bulls";
     cout<<"\nmaid-1 cows 1 bulls\nsing-0 cows 0 bulls\nfame-3 cows 0 bulls\nname-3 cows 0 bulls\ngame-YOU WIN!\n";

     }

     void game()
     {

     int num=1;

     do
     {
     clrscr();
     int n=15,numb;
     cout<<"HI PEOPLE!NOW,I AM GOING TO PLAY WITH YOU THIS WONDERFUL GAME OF COWS AND BULLS.HOPE YOU ENJOY THIS GAME!\n\a\a\a";
     randomize();
     numb=random(n);

     char s[15][5]={"auto","game","zeal","read","self","life","help","seat","fake","quit","lame","what","plus","mark","bean"};
     char word[5],w[5];
     strcpy(word,s[numb]);


     cout<<"your time starts now!\a";

     for(int i=0;i<10;i++)
     {
     int c=0,b=0,h=0;
     u:cout<<"enter word"<<i+1;
     gets(w);
     int z=0,x=0;
     for(z=0;z<5;z++)
     if(w[z]==w[z+1])
     x++;



     if(strcmp(word,w)==0)
     {
     cout<<"you win\a\a\a";
     break;
     }
     else

     {
     for(h=0;h<4;h++)
     {
     if(word[h]==w[h])
     c++;
     for(int k=0;k<4;k++)
     if(word[h]==w[k]&&h!=k)
     b++;
     }
      }

     cout<<c<<"cows "<<b<<"bulls";


     }



     if(i==10)
     {
     cout<<"\nsorry better luck next time\n";
     cout<<"\nyour word was ";
     puts(s[numb]);
     }

     cout<<"\ndo u want to continue(1)?\n";
     cin>>num;

       }while(num==1);


     }

     void subscribe()
     {
     clrscr();
     cout<<"\nTO SUBSCRIBE THIS GAME,CONTACT:S.PRIYANKA,GRAPHICS DESIGNER,11 A,DAV,GOPALAPURAM\n";
     }

     void menu()
     {

     int ch;
    x: void game();
     void instruct();
     void subscribe();
     cout<<"\n\n\t\t1.INSTRUCTIONS\n\t\t2.GAME\n\t\t3.SUBSCRIPTION\n\t\t4.EXIT\n";
     cin>>ch;
     if(ch==1)
     instruct();
     if(ch==2)
     game();
     if(ch==3)
     subscribe();
     if(ch>3)
     {
     cout<<"wrong choice";
     exit(0);
     }


     goto x;

   }







