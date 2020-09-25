#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
int width=40;
int height=40;
int x,y,foodx,foody,score=0,gameover,flag,counttail;
int tailx[100],taily[100];
void setup()
{
    gameover=0;
    x=width/2;
    y=height/2;
    foodx=23;
    foody=25;
}
void draw()
{
        system("cls");
	for(int i=0;i<width;i++)
	{
		for(int j=0;j<height;j++)
                                        {     if(i==0 || i==height-1 ||  j==0 || j==width-1)    printf("#");   

                                                                                                                                                                                                          
			else
			{
			if(i==x && j==y)
			{
				printf("0");
			}
			else if(i==foodx && j==foody)
			{
				printf("F");
			}
			else
			{
				int ch=0;
				for(int k=0;k<counttail;k++)
				{
					if(i==tailx[k] && j==taily[k])
					{
						
						printf("o");
						ch=1;
					}
				}
				if(ch==0)
				printf(" ");
			}
			}
                                                                       
}
                printf("\n");
	
      }
     
      printf("score : %d",score);
}
void load(){
    int row,col,r,c,q;
    printf("loading...");
    for(r=1;r<=20;r++){
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",177);}
    getch();
}
void print()
{
 
   system("cls");
   printf("\tWelcome to the mini Snake game.(press any key to continue)\n");
  getch();
   system("cls");
   printf("\tGame instructions:\n");


                                                                  
   printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");      
   printf("\n\nPress any key to play game...");
   if(getch()==27)
   exit(0);
}
void record(){
char c;
   char plname[20],nplname[20],cha;
   int i,j,px;
   FILE *info;
   info=fopen("record.txt","a+");
   scanf("%c",&c);
   system("cls");
   printf("Enter your name\n");
   scanf("%[^\n]s",plname);
   fprintf(info,"Player Name :%s\n",plname);
    //for date and time
   time_t mytime;
  mytime = time(NULL);
  fprintf(info,"Played Date:%s",ctime(&mytime));
     fprintf(info,"Score:%d\n",score);//call score to display score
   for(i=0;i<=50;i++)
   fprintf(info,"%c",'_');
                                                                         
   fprintf(info,"\n");                                               
   fclose(info);
   printf("wanna see past records press 'y'\n");
   cha=getch();
   system("cls");
   if(cha=='y'){
   info=fopen("record.txt","r");
   do{
       putchar(c=getc(info));
       }while(c!=EOF);}
     fclose(info);
}
  

void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			 case 'a':flag=1;
				   break;
			 case  's':flag=2;
				   break;
		         case  'w':flag=3;
				   break;
			                                 
                                case  'd':flag=4;                                                                                              
				   break;
		         case 'x':gameover=1;
				  break;
				   
		}
                 
	}
}
void logic()
{
     int prevx=tailx[0];
	int prevy=taily[0];
	int prev2x,prev2y;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<counttail;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
                tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
	switch(flag)
	  {                                                   
 		case 1:y--;
			  break;
	                   
		case 2:x++;
			   break;
	                   
		case 3:x--;
			break;
		case 4:y++;
			  break;
	        default:break;
	}
	if(x<0 || x>width || y<0 || y>height)
	{
		gameover=1;
	}
	if(x==foodx && y==foody)
	{
		foodx=rand() % width;
		foody=rand() % height;
		score+=10;
		counttail++;
	}
                  for(int i=0;i<counttail;i++)
                   {
                            
                                                                

                           if(x==tailx[i] && y==taily[i])
                               {                                           
                                              gameover=1;
                               }
                   }

}
int main()
{
     long double i;
     print();
     load();
     setup();
     while(!gameover)
     {
     draw();
     printf("\033[?25l");
     input();
     logic();
      for(i=0;i<=(100000000);i++);
     }
     system("cls");
     


                                                                     
printf("\n\n\n\n                                                     $$$$$$$####################################$$$$$$$$$\n ");
     printf("                                                                            GAME OVER                         \n");
     printf("                                                      $$$$$$$$$$$####################################$$$$$$$$\n");
     record();
return 0;
}
