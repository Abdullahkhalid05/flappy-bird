#include <raylib.h>

#define height 800 
#define width 1000
#define ball_size 10
#define block_size 40
int posx = width/2;
int posy = height/2;
float row = 20;
float col =10;
int plus = 0;
int count = 0;
int val , val2 , newy ,newx;

void drawTowerUp(){
    for (int i = 0; i < val; i++)
    {
        for (int j = 0; j < 4; j++)
        {
               newx = (j + row) *block_size;
            DrawRectangle(newx, i * block_size , block_size ,block_size ,GREEN);
            if (newx < 0 || newx >= width) {
                row = 18; 
                val = GetRandomValue(3,14);  
                val2 = 16 - val;
            }
            
        }
        
    }
    
}
void drawTowerDown(){
    for (int i = 0; i < val2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
             newx = (j + row) *block_size;
             newy = (height-block_size) - (i * block_size);
            DrawRectangle(newx, newy , block_size ,block_size ,GREEN);
            if (newx < 0 || newx >= width) {
                row = 18; 
            }
            
        }
        
    }
    
}
int collision(){
    int ballright = posx + ball_size;
    int ballLeft = posx - ball_size;
    int balltop = posy - ball_size;
    int ballbottom = posy + ball_size;
    for (int i = 0; i < 4; i++)
    {
        int blockx = (i + row) * block_size;
        for (int j = 0; j < val; j++){
           int blocky = (j *block_size);
           if (ballright > blockx && ballLeft < blockx + block_size && 
                ballbottom > blocky && balltop < blocky + block_size){
               return 1;
           }
           
        }
        for (int j = 0; j < val2; j++){
            int blocky = (height-block_size) - (j * block_size);
            if (ballright > blockx && ballLeft < blockx + block_size && 
                ballbottom > blocky && balltop < blocky + block_size){
                return 1;
            }
            
        }
    }
    return 0;
}
int over = 0;
int main(){
    InitWindow(width,height,"tetris");
    SetTargetFPS(60);
    val = GetRandomValue(3,12);
    val2 = 16 - val;
    while (!WindowShouldClose())
    {
        if (!over){     
            count++;
            if (count>5)
            {
                row -= 0.5;
                count = 0;
                
            }
            posy += 4;
            if(collision()){
                over = 1;
            }
            
            if (IsKeyPressed(KEY_SPACE))
            {
                plus = 6;
                posy -= 70;
                count = 0;
            }
        }  

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawTowerUp();
        drawTowerDown();
        DrawCircle(posx,posy,ball_size,RED);
        if (over){
            DrawText("Game Over" , 400 , 400 , 40 , BLUE);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0 ;
    }
