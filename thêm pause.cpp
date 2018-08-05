#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
using namespace std;
/*bool gameOver;
int x,y,fruitX,fruitY,score;
const int width = 20;
const int height = 20;
enum eDirec{STOP =0,LEFT,RIGHT,UP,DOWN};
eDirec dir;
void setup(){
    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand()%width;
    fruitY = rand()%height;
    score = 0;
}
void input(){
    if(_kbhit()){
        switch(_getch()){
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void draw(){

    /*
printf("Enter the size of block <height,width>:");
scanf("%d""%d",&height,&width);
    system("cls");
for (int i=0;i<=height;i++){
    for (int j=0;j<=width;j++){
        if (i==0||i==height){
            cout<<"+ ";}
        else{
            if(j==0||j==width)
                cout<<"+ ";
            if(i==y && j==x)
                cout<<"O ";
            else if(i==fruitY&&j==fruitX)
                cout<<"F ";
            else
                cout<<"  ";}}

    cout<<"\n";
}
            cout<<"GAME START! \t\t\t Score:";

}
void logic(){
    switch(dir){
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if(x>width || x<0 || y> height || y<0)
        gameOver = true;
    if(x==fruitX && y==fruitY){
        score += 10;
        fruitX = rand()%width;
        fruitY = rand()%height;
        if(fruitX == 0 || fruitX == width)
            fruitX++;
        if(fruitY == 0 || fruitY == height)
            fruitY++;
    }
}
int main()
{
    setup();
   while(!gameOver){
        draw();
        input();
        logic();
        Sleep(20);
    }
    return 0;
}*/

bool gameOver,paused,resume;
int i,j,k,x,y,fruitX,fruitY,fruitXdie,fruitYdie,bigfruitX,bigfruitY,score,moves=0;
int nTail=0;
int tailX[100],tailY[100];
const int width = 20;
const int height = 20;
enum eDirec{STOP =0,LEFT,RIGHT,UP,DOWN};
eDirec dir;

void setup(){
    srand(time(NULL));
    gameOver = false;
    paused=false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand()%width;
    fruitY = rand()%height;

    /*fruitXdie = 5;
    fruitYdie = 5;
    while(fruitX==fruitXdie && fruitY==fruitYdie || fruitXdie ==0 || fruitXdie==width|| fruitYdie==0 || fruitYdie==height){
        fruitXdie = rand()%width;
        fruitYdie = rand()%height;
    }*/
    score = 0;
}
void clearScreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}



void input(){
    if(kbhit()){
        char strInput = getch();
        switch(strInput){
        case 'a':
            dir = LEFT;
             moves++;
            break;
        case 'd':
            dir = RIGHT;
             moves++;
            break;
        case 'w':
            dir = UP;
             moves++;
            break;
        case 's':
            dir = DOWN;
             moves++;
            break;
        case 'x':
            gameOver = true;
            break;
        case 'p':
        	paused=true;
        	system("pause");
        	break;
        }
    }
}
void draw(){

    /*
printf("Enter the size of block <height,width>:");
scanf("%d""%d",&height,&width);*/
    clearScreen();
for (int i=0;i<=height;i++){
    for (int j=0;j<=width;j++){
        if (i==0||i==height){
            printf("  ");}
        /*else if (i == height && j == width)
            printf(" + +");*/
        else{
            if(j==0||j==width)
                printf("  ");
            if(y>=height){
                y=1;
            }
            if(y<1) {
                y=height-1;
            }
            if(x>=width){
                x=0;
            }
            if(x<0) {
                x=width-1;
            }
            if(i==y && j==x)
                printf(" %c ",254);
            else if(i==fruitY&&j==fruitX)
              /*  SetConsoleTextAttribute()*/
                printf("F");
            else {
				if(i==fruitYdie && j==fruitXdie)
                    printf("D");
            	else if(i==bigfruitY && j==bigfruitX)
                    printf("E");
            	else{
            		bool print=false;
            		for(k=0;k<nTail;k++){
            			if (tailX[k]==j && tailY[k]==i){
            				printf("%c",248);
            				print=true;
						}
						else print=false;
					}
					if (!print){
						printf("  ");
					}
                	
			 	}
            	
				
			}
		}
	}

    printf("\n");
}
            printf("GAME START! \t\t\t Score: %d \t Tails: %d", score, nTail);

}
void logic(){
	int prevX=tailX[0];
	int prevY=tailY[0];
	int tmpX,tmpY;
	tailX[0]=x;
	tailY[0]=y;
	for (i=1;i<nTail;i++){
		tmpX=tailX[i];
		tmpY=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=tmpX;
		prevY=tmpY;
	}
    switch(dir){
    case LEFT:
        x--;

        break;
    case RIGHT:
        x++;

        break;
    case UP:
        y--;

        break;
    case DOWN:
        y++;

        break;
    default:
        break;
    }
   /* if(fruitX==x && fruitY==y) {
        score+=10;
        fruitX = rand()%width;
        fruitY = rand()%height;
        if (fruitX==0)
            fruitX++;
        if (fruitX==width)
            fruitX--;
        if (fruitY==0)
            fruitY++;
        if (fruitY==height)
            fruitY--;
    }*/
    if(moves>4){
        bigfruitX=100;
        bigfruitY=100;
    }
    if(fruitXdie==x && fruitYdie==y){
        gameOver=true;
    }
    else if(fruitX==x&&fruitY==y){
        fruitXdie = 100;
        fruitYdie = 100;
        score++;
        moves=0;
        fruitX = rand()%width;
        fruitY = rand()%height;
        nTail++;
        if (fruitX==0)
            fruitX++;
        if (fruitX==width)
            fruitX--;
        if (fruitY==0)
            fruitY++;
        if (fruitY==height)
            fruitY--;
        if(score%10==0 && score!=0){
            fruitXdie = rand()%width;
            fruitYdie = rand()%height;
    	}
        if(score%20==0 && score!=0)
            bigfruitX = rand()%width;
            bigfruitY = rand()%height;
            if(bigfruitX==fruitXdie && bigfruitY==fruitYdie){
                    bigfruitX++;
                    bigfruitY++;
			}
        /*while(fruitX==fruitXdie && fruitY==fruitYdie || fruitXdie ==0 || fruitXdie==width|| fruitYdie==0 || fruitYdie==height){
        if(score%10==0){
            fruitXdie = rand()%width;
            fruitYdie = rand()%height;
            }
        }*/}
        else if(x==bigfruitX && y==bigfruitY){
        	score+=5;
        	bigfruitX = 100;
        	bigfruitY = 100;
        	fruitXdie = 100;
        	fruitYdie = 100;
    	}
}
void load(){
    int r,c,q;
	printf("\t\t\t\tWelcome to snake game.\n");
    printf("\t\t\t\t      Loading...\n\t\t\t\t");
    for(r=1;r<=21;r++){
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",177);}
    getch();
}
void gameover(){
	system("cls");
	printf("\t\t\t\tGame over!\n (Press any key to exit the game)");
	getch();}




int main()
{
    ShowConsoleCursor(false);
    setup();
    load();
    while(!gameOver)
	{
		Sleep(35);
        draw();
        input();
        logic();
}
	gameover();
    return 0;
}

