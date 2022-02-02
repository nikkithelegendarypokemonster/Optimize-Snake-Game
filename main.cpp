// Online C++ compiler to run C++ program online
// Game snake game
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
using namespace std;
#define WIDTH 50
#define HEIGHT 20
int STATE=1;
//Elements
#define WALL "*"
#define HEAD "x"
#define TAIL "o"
#define FRUIT "f"
//fruits
int fruitX=rand()%WIDTH-1, fruitY=rand()%HEIGHT-1;
//snake position
int x=(WIDTH-1)/2;
int y=(HEIGHT-1)/2;
//snake body
int tailX[100],tailY[100];
int nTail;
//controls
enum direction{UP,LEFT,DOWN,RIGHT};
direction dir;
//scoring
int score=0;
void field(int width,int height){
    printf("Score: %d\n",score);
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            if(row==0 || row==height-1){
                printf("%s",WALL);
            }

            else{
              if(col==0 || col==width-1){
                  printf("%s",WALL);
              }else{
                  //draw fruit position
                  if(row==fruitY && col== fruitX){
                      printf("%s",FRUIT)d;
                  }
                  //here draw the snake position
                  else if(row==y && col== x){
                      printf("%s",HEAD);
                  }else{
                  bool print = false;
                  for (int k = 0; k< nTail ; k++) {
                        if (tailX [k] == col && tailY [k] == row) {
                        printf("%s",TAIL);
                        print=true;
                        }
                    }
                    if (!print) {
                       printf(" ");
                    }
                  }
              }
            }
        }
        printf("\n");
    }
}
void input(){
    if(kbhit()){
        switch(tolower(getch())){
            case 'w':
            //up position update
                dir=UP;
            break;
            case 'a':
            //left position update
                dir=LEFT;
            break;
            case 's':
            //down position update
                dir=DOWN;
            break;
            case 'd':
            //right position update
                dir=RIGHT;
            break;
        }
    }
}
void physic(){
    //handle tail control
    int prevX = tailX [0];
    int prevY = tailY [0];
    int prev2X, prev2Y;
    // 0 index represent the head
    tailX[0] = x;
    tailY[0] = y;
    //handle touch body gameover
    for(int body=0;body<nTail;body++){
        if((x+2==tailX[body]||x-2==tailX[body])&& y==tailY[body]){
            STATE=0;
        }
    }
    for(int i = 1;i < nTail ; i++) {
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y ;
    }
    //handle food and points control
    if((x==fruitX || x==fruitX+1 || x==fruitX-1) && y==fruitY){
        fruitX=rand()%((WIDTH-2 - 1)+1)+1;
        fruitY=rand()%((HEIGHT-2 - 1)+1)+1;
        nTail++;
        score++;
    }
    //handle controls
    switch(dir){
    case UP:
        y--;
    break;
    case DOWN:
        y++;
    break;
    case LEFT:
        x-=2;
    break;
    case RIGHT:
        x+=2;
    break;
    }
    if(x>WIDTH){
        x=1;
    }else if(x<=0){
        x=WIDTH-1;
    }
    if(y>HEIGHT){
        y=1;
    }else if(y<=0){
        y=HEIGHT-1;
    }

}
int main() {
    // Write C++ code here
    while(STATE){
        field(WIDTH,HEIGHT);
        input();
        physic();
        Sleep(100);
        system("cls");
   }
    return 0;
}
