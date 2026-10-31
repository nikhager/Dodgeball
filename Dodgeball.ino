//Nik Hager


#include <MeggyJrSimple.h>                                                                              //Required code, line 1 of 2


struct Point                                                                                          //Code for making points
{
  int x;
  int y;
};
int counter = 0;                                                                                    //Set variable for turn counter
int score = 0;                                                                                      //Set variable to keep track of score
int ballthrow = 0;                                                                                  //Set variable to check if player is throwing a ball
Point player = {0,4};                                                                             //Set player starting point
int hp = 5;                                                                                   //Set variable for player health
Point opponent1 = {8,4};                                                                            //Set starting point for opponent 1
int hp1 = 3;                                                                                          //Set variable for opponent 1 health
Point opponent2 = {8,3};                                                                          //Set starting point for opponent 2
int hp2 = 3;                                                                                        //Set variable for opponent 2 health
Point opponent3 = {8,5};                                                                          //Set starting point for opponent 3
int hp3 = 3;                                                                                      //Set variable for opponent 3 health
Point opponent4 = {8,2};                                                                            //Set starting point for opponent 4
int hp4 = 3;                                                                                        //Set variable for opponent 4 health
Point boss = {8,1};                                                                                //Set variable for boss weak spot
int bosshp = 3;                                                                                    //Set variable for boss health
Point playerball = {1,4};                                                                         //Unused coordinates, but point is needed to keep track of the player's ball
int opponent1on = 0;                                                                              //Variable to check if opponent 1 is in the stage
int opponent2on = 0;                                                                                //Variable to check if opponent 2 is in the stage
int opponent3on = 0;                                                                                //Variable to check if opponent 3 is in the stage
int opponent4on = 0;                                                                                //Variable to check if opponent 4 is in the stage
int bosson = 0;                                                                                     //Variable to check if a boss is in the stage
int movement1 = 1;                                                                                 //Variable to check which direction CPU 1 is moving (0 = up, 1 = down, 2 = left, 3 = right)
int movement2 = 1;                                                                                 //Variable to check which direction CPU 2 is moving (0 = up, 1 = down, 2 = left, 3 = right)
int movement3 = 1;                                                                                 //Variable to check which direction CPU 3 is moving (0 = up, 1 = down, 2 = left, 3 = right)
int movement4 = 1;                                                                                 //Variable to check which direction CPU 4 is moving (0 = up, 1 = down, 2 = left, 3 = right)
int stage = 1;                                                                               //Variable to check what level the player is on
int ball1on = 0;                                                                                  //Variable to check if opponent 1's ball is being thrown
Point ball1 = {9,4};
int ball2on = 0;                                                                                  //Variable to check if opponent 2's ball is being thrown
Point ball2 = {9,3};
int ball3on = 0;                                                                                  //Variable to check if opponent 3's ball is being thrown
Point ball3 = {9,5};
int ball4on = 0;                                                                                  //Variable to check if opponent 4's ball is being thrown
Point ball4 = {9,2};
int YouLose = 0;                                                                                  //Variable to check if player lost
int BossStage = 1;                                                                                //Variable for boss's attack stages based on his hp
int b = 7;                                                                                        //Variables for BOSS letters
int o = 14;
int s1 = 20;
int s2 = 26;


void setup()                                                                                      //Setup
{
  MeggyJrSimpleSetup();                                                                           //Required code, line 2 of 2
  EditColor(DimRed, 17, 4, 2);                                                                    //Change DimRed to pink
  EditColor(Green, 0, 27, 0);                                                                     //Adjust green color
  EditColor(Blue, 4, 37, 21);                                                                     //Adjust blue color
  EditColor(White, 0, 13, 1);                                                                     //Adjust white color
  EditColor(Orange, 13, 26, 0);                                                                   //Adjust orange color
  EditColor(Red, 21, 0 , 0);                                                                      //Adjust red color
  delay(500);
  DrawPx(3,4,DimRed);
  DrawPx(4,4,DimRed);
  DrawPx(3,3,DimRed);
  DrawPx(4,3,DimRed);
  DisplaySlate();
  delay(200);
  DrawPx(2,3,DimRed);
  DrawPx(2,4,DimRed);
  DrawPx(3,5,DimRed);
  DrawPx(4,5,DimRed);
  DrawPx(3,2,DimRed);
  DrawPx(4,2,DimRed);
  DrawPx(5,3,DimRed);
  DrawPx(5,4,DimRed);
  DisplaySlate();
  delay(200);
  DrawPx(1,2,DimRed);
  DrawPx(2,2,DimRed);
  DrawPx(2,1,DimRed);
  DrawPx(3,1,DimRed);
  DrawPx(4,1,DimRed);
  DrawPx(5,1,DimRed);
  DrawPx(5,2,DimRed);
  DrawPx(6,2,DimRed);
  DrawPx(6,3,DimRed);
  DrawPx(6,4,DimRed);
  DrawPx(6,5,DimRed);
  DrawPx(5,5,DimRed);
  DrawPx(5,6,DimRed);
  DrawPx(4,6,DimRed);
  DrawPx(3,6,DimRed);
  DrawPx(2,6,DimRed);
  DrawPx(2,5,DimRed);
  DrawPx(1,5,DimRed);
  DrawPx(1,4,DimRed);
  DrawPx(1,3,DimRed);
  DisplaySlate();
  delay(200);
  for (int a = 0; a < 8; a++)
  {
    for (int b = 0; b < 8; b++)
    {
      DrawPx(a,b,DimRed);
    }
  }
  DrawPx(0,0,Dark);
  DrawPx(0,7,Dark);
  DrawPx(7,0,Dark);
  DrawPx(7,7,Dark);
  DisplaySlate();
  for (int c = 0; c < 8; c++)
  {
    for (int d = 0; d < 8; d++)
    {
      DrawPx(c,d,DimRed);
    }
  }
  DisplaySlate();
  Tone_Start(ToneC3, 400);
  delay(2000);
  ClearSlate();
  DrawCourt();                                                                                    //Draw the court
  StartSound();
  DisplaySlate();                                                                                 //Display player starting spot and field
}



void loop()                                                                                     //Start loop
{ 
  if (YouLose == 1)                                                                              //If the player dies flash a big red x on the screen (press any button to restart)
  {
    Loss();
  }
  
  
  if (YouLose == 0)                                                                            //If the player did not lose...
  {
    
    
    if (stage == 1)                                                                               //If it's stage 1...       (one CPU, slow movement, no balls, low HP)
    {
      SetAuxLEDs(1);                                                                              //Turn on 1 LED light
      if (counter == 0)                                                                           //If the timer is 0
      {
        opponent1on = 1;                                                                        //there is one opponent on the stage
        hp = 5;
        hp1 = 2;                                                                                    //Set opponent 1's hp to 2
        opponent1.x = 7;                                                                        //Set opponent x coord to 7
        DrawPlayer();                                                                          //Draw Player
        DrawPx(opponent1.x,opponent1.y,Green);                                                  //Draw opponent 1
        Draw1();                                                                                //Draw a 1 in the center of the screen to show it's stage 1
        DisplaySlate();                                                                         //Display the screen
        delay(2000);
      }
      if (counter%13 == 0)
      {
        CheckOpponentsOn();
      }
    }
    
    
    if (stage == 2)                                                                               //If it's stage 2...       (one CPU, fast movement, slow balls, low HP)
    {
      SetAuxLEDs(3);                                                                             //Turn on 2 LED lights
      if (counter == 0)                                                                           //If the timer is 0
      {
        opponent1.x = 7;                                                                          //reset opponent 1's coords
        opponent1.y = 4;
        opponent1on = 1;                                                                        //there is one opponent on the stage
        hp1 = 2;                                                                                 //Set opponent 1's hp to 3
        DrawPlayer();                                                                            //Draw Player
        DrawPx(opponent1.x,opponent1.y,Green);                                                  //Draw opponent 1
        Draw2();                                                                                //Draw a 2 in the center of the screen to show it's stage 2
        DisplaySlate();
        delay(2000);
      }
      if (counter%8 == 0)
      {
        CheckOpponentsOn();
      }
      if (opponent1on == 1)
      {
        if (counter%40 == 5)
        {
          ball1on = 1;
        }
      }
    }
    
    
    if (stage == 3)                                                                               //If it's stage 3...       (one CPU, fast movement, balls, medium HP)
    {
      SetAuxLEDs(7);                                                                              //Turn on 3 LED lights
      if (counter == 0)                                                                           //If the timer is 0
      {
        opponent1.x = 7;                                                                          //reset opponent 1's coords
        opponent1.y = 4;
        opponent1on = 1;                                                                        //there is one opponent on the stage
        hp1 = 3;                                                                                 //Set opponent 1's hp to 3
        DrawPlayer();                                                                            //Draw Player
        DrawPx(opponent1.x,opponent1.y,Green);                                                  //Draw opponent 1
        Draw3();                                                                                //Draw a 3 in the center of the screen to show it's stage 3
        DisplaySlate();
        delay(2000);
      }
      if (counter%8 == 0)
      {
        CheckOpponentsOn();
      }
      if (opponent1on == 1)
      {
        if (counter%30 == 5)
        {
          ball1on = 1;
        }
      }
    }
    
    
    if (stage == 4)                                                                            //If it's stage 4...            (two CPUs, fast movement, balls, medium HP)
    {
      SetAuxLEDs(15);                                                                              //Turn on 4 LED lights
      if (counter == 0)                                                                         //if the timer is 0
      {
        opponent1.x = 7;                                                                          //reset opponent 1's coords
        opponent1.y = 4;
        opponent2.x = 7;                                                                          //put opponent 2 onto the screen
        opponent1on = 1;                                                                          //there are two opponents on the stage
        opponent2on = 1;                  
        hp++;                                                                                      //increase player's hp by 1
        hp1 = 3;                                                                                    //reset the enemies' hp to 3
        hp2 = 3;
        DrawPlayer();                                                                              //Draw Player
        DrawPx(opponent1.x,opponent1.y,Green);                                                    //Draw opponent 1
        DrawPx(opponent2.x,opponent2.y,Green);                                                      //Draw opponent 2
        Draw4();                                                                                //Draw a 4 in the center of the screen to show it's stage 3
        DisplaySlate();                                                                            //Display the slate
        delay(2000);                                                                              //Wait a little
      }
      if (counter%8 == 0)
      {
        CheckOpponentsOn();
      }
      if (opponent1on == 1)
      {
        if (counter%40 == 5)
        {
          ball1on = 1;
        }
      }
      if (opponent2on == 1)
      {
        if (counter%44 == 5)
        {
          ball2on = 1;
        }
      }
    }
    
    
    if (stage == 5)                                                                              //If it's stage 5...          (three CPUs, fast movement, balls, medium HP)
    {
      SetAuxLEDs(31);                                                                            //Turn on 5 LED lights
      if (counter == 0)                                                                         //if the timer is 0
      {
        opponent1.x = 7;                                                                          //reset opponent 1's coords
        opponent1.y = 4;
        opponent2.x = 7;                                                                          //reset opponent 2's coords
        opponent2.y = 3;
        opponent3.x = 7;                                                                          //put opponent 3 onto the screen
        opponent1on = 1;                                                                          //there are three opponents on the stage
        opponent2on = 1;                  
        opponent3on = 1;
        hp1 = 3;                                                                                    //reset the enemies' hp
        hp2 = 3;
        hp3 = 3;
        DrawPlayer();
        DrawPx(opponent1.x,opponent1.y,Green);                                                    //Draw opponent 1
        DrawPx(opponent2.x,opponent2.y,Green);                                                      //Draw opponent 2
        DrawPx(opponent3.x,opponent3.y,Green);                                                      //Draw opponent 3
        Draw5();
        DisplaySlate();                                                                            //Display the slate
        delay(2000);                                                                              //Wait a little
      }
      if (counter%8 == 0)
      {
        CheckOpponentsOn();
      }
      if (opponent1on == 1)
      {
        if (counter%40 == 5)
        {
          ball1on = 1;
        }
      }
      if (opponent2on == 1)
      {
        if (counter%43 == 5)
        {
          ball2on = 1;
        }
      }
      if (opponent3on == 1)
      {
        if (counter%50 == 4)
        {
          ball3on = 1;
        }
      }
    }
    
    
    
    if (stage == 6)                                                                              //If it's stage 6...          (four CPUs, fast movement, balls, medium HP)
    {
      SetAuxLEDs(63);                                                                            //Turn on 6 LED lights
      if (counter == 0)                                                                         //if the timer is 0
      {
        opponent1.x = 7;                                                                          //reset opponent 1's coords
        opponent1.y = 4;
        opponent2.x = 7;                                                                          //reset opponent 2's coords
        opponent2.y = 3;
        opponent3.x = 7;                                                                          //reset opponent 3's coords
        opponent3.y = 5;
        opponent4.x = 7;                                                                          //put opponent 4 onto the screen
        opponent1on = 1;                                                                          //there are four opponents on the stage
        opponent2on = 1;                  
        opponent3on = 1;
        opponent4on = 1;
        hp1 = 2;                                                                                    //reset the enemies' hp
        hp2 = 2;
        hp3 = 2;
        hp4 = 2;
        DrawPlayer();
        DrawPx(opponent1.x,opponent1.y,Green);                                                    //Draw opponent 1
        DrawPx(opponent2.x,opponent2.y,Green);                                                      //Draw opponent 2
        DrawPx(opponent3.x,opponent3.y,Green);                                                      //Draw opponent 3
        DrawPx(opponent4.x,opponent4.y,Green);                                                      //Draw opponent 4
        Draw6();
        DisplaySlate();                                                                            //Display the slate
        delay(2000);                                                                              //Wait a little
      }
      if (counter%8 == 0)
      {
        CheckOpponentsOn();
      }
      if (opponent1on == 1)
      {
        if (counter%50 == 5)
        {
          ball1on = 1;
        }
      }
      if (opponent2on == 1)
      {
        if (counter%49 == 5)
        {
          ball2on = 1;
        }
      }
      if (opponent3on == 1)
      {
        if (counter%47 == 4)
        {
          ball3on = 1;
        }
      }
      if (opponent4on == 1)
      {
        if (counter%57 == 7)
        {
          ball4on = 1;
        }
      }
    }
                                
       
    if (stage == 7)                                                                              //If it's stage 7...          (four CPUs, fast movement, balls, high HP)
    {
      SetAuxLEDs(127);                                                                            //Turn on 7 LED lights
      if (counter == 0)                                                                         //if the timer is 0
      {
        opponent1.x = 7;                                                                          //reset opponent 1's coords
        opponent1.y = 4;
        opponent2.x = 7;                                                                          //reset opponent 2's coords
        opponent2.y = 3;
        opponent3.x = 7;                                                                          //reset opponent 3's coords
        opponent3.y = 5;
        opponent4.x = 7;                                                                          //reset opponent 4's coords
        opponent4.y = 2;
        opponent1on = 1;                                                                          //there are four opponents on the stage
        opponent2on = 1;                  
        opponent3on = 1;
        opponent4on = 1;
        hp1 = 3;                                                                                    //reset the enemies' hp
        hp2 = 3;
        hp3 = 3;
        hp4 = 3;
        DrawPlayer();
        DrawPx(opponent1.x,opponent1.y,Green);                                                    //Draw opponent 1
        DrawPx(opponent2.x,opponent2.y,Green);                                                      //Draw opponent 2
        DrawPx(opponent3.x,opponent3.y,Green);                                                      //Draw opponent 3
        DrawPx(opponent4.x,opponent4.y,Green);                                                      //Draw opponent 4
        Draw7();
        DisplaySlate();                                                                            //Display the slate
        delay(2000);                                                                              //Wait a little
      }
      if (counter%8 == 0)
      {
        CheckOpponentsOn();
      }
      if (opponent1on == 1)
      {
        if (counter%40 == 5)
        {
          ball1on = 1;
        }
      }
      if (opponent2on == 1)
      {
        if (counter%45 == 5)
        {
          ball2on = 1;
        }
      }
      if (opponent3on == 1)
      {
        if (counter%46 == 5)
        {
          ball3on = 1;
        }
      }
      if (opponent4on == 1)
      {
        if (counter%39 == 5)
        {
          ball4on = 1;
        }
      }
    }                            
                                
                                //stage 8 (boss)
    if (stage == 8)                                                                              //If it's stage 8...          (boss)
    {
      SetAuxLEDs(255);                                                                            //Turn on 8 LED lights
    }         
                                
                                
                                
                                
    
    
    if (stage != 8)
    {
      counter++;                            //add 1 to the counter
    }
    
    
    if (playerball.x > 7)                                                                        //when a ball is off the screen, the ball is no longer in the game
    {
      ballthrow = 0;
    }
    if (ball1.x < 0)
    {
      ball1on = 0;
    }
    if (ball2.x < 0)
    {
      ball2on = 0;
    }
    if (ball3.x < 0)
    {
      ball3on = 0;
    }
    if (ball4.x < 0)
    {
      ball4on = 0;
    }
    
    
    
    
    
    if (ballthrow == 0)                                                                          //if the ball isn't moving, reset its coordinates to the player's
    {
      playerball.x = player.x;
      playerball.y = player.y;
    }
    if (ball1on == 0)
    {
      ball1.x = opponent1.x;
      ball1.y = opponent1.y;
    }
    if (ball2on == 0)
    {
      ball2.x = opponent2.x;
      ball2.y = opponent2.y;
    }
    if (ball3on == 0)
    {
      ball3.x = opponent3.x;
      ball3.y = opponent3.y;
    }
    if (ball4on == 0)
    {
      ball4.x = opponent4.x;
      ball4.y = opponent4.y;
    }
    
    
    
    if (opponent1on == 0)                                                                      //if opponent 1 is not on, take him off the screen
    {
      opponent1.x = 8;
    }
    if (opponent2on == 0)                                                                      //if opponent 2 is not on, take him off the screen
    {
      opponent2.x = 8;
    }
    if (opponent3on == 0)                                                                      //if opponent 3 is not on, take him off the screen
    {
      opponent3.x = 8;
    }
    if (opponent4on == 0)                                                                      //if opponent 4 is not on, take him off the screen
    {
      opponent4.x = 8;
    }
    
    DrawCourt();
    
     
    
    
    
                      //CPU Collision Detection
    
    if (opponent1.x == opponent2.x)                                                            //if two opponents are standing in the same spot change their coords
    {
      if (opponent1.y == opponent2.y)
      {
        opponent1.x--;
        opponent1.y--;
      }
    }
    
    if (opponent1.x == opponent3.x)
    {
      if (opponent1.y == opponent3.y)
      {
        opponent1.x--;
        opponent1.y--;
      }
    }
    
    if (opponent1.x == opponent4.x)
    {
      if (opponent1.y == opponent4.y)
      {
        opponent1.x--;
        opponent1.y--;
      }
    }
    
    if (opponent2.x == opponent3.x)
    {
      if (opponent2.y == opponent3.y)
      {
        opponent2.x--;
        opponent2.y--;
      }
    }
    
    if (opponent2.x == opponent4.x)
    {
      if (opponent2.y == opponent4.y)
      {
        opponent2.x--;
        opponent2.y--;
      }
    }
    
    if (opponent3.x == opponent4.x)
    {
      if (opponent3.y == opponent4.y)
      {
        opponent3.x--;
        opponent3.y--;
      }
    }
    
    
    
    
    
    
    
    
    //BALL COLLISIONS
    
    if (opponent1.x == playerball.x)                                                          //if opponent 1 is hit by the ball, decrease its hp by 1 and take the ball off the screen
    {
      if (opponent1.y == playerball.y)
      {
        hp1--;
        Tone_Start(ToneB3, 100);
        ballthrow = 0;
      }
    }
    if (hp1 == 0)                                                                            //if opponent 1's hp is 0, take him out of the game
    {
      opponent1on = 0;
    }
    
    if (opponent2.x == playerball.x)                                                        //if opponent 2 is hit by the ball, decrease its hp by 1 and take the ball off the screen
    {
      if (opponent2.y == playerball.y)
      {
        hp2--;
        Tone_Start(ToneB3, 100);
        ballthrow = 0;
      }
    }
    if (hp2 == 0)                                                                             //if opponent 2's hp is 0, take him out of the game
    {
      opponent2on = 0;
    }
    
    
    
    if (opponent3.x == playerball.x)                                                        //if opponent 3 is hit by the ball, decrease its hp by 1 and take the ball off the screen
    {
      if (opponent3.y == playerball.y)
      {
        hp3--;
        Tone_Start(ToneB3, 100);
        ballthrow = 0;
      }
    }
    if (hp3 == 0)                                                                             //if opponent 3's hp is 0, take him out of the game
    {
      opponent3on = 0;
    }
    
    
    
    if (opponent4.x == playerball.x)                                                        //if opponent 4 is hit by the ball, decrease its hp by 1 and take the ball off the screen
    {
      if (opponent4.y == playerball.y)
      {
        hp4--;
        Tone_Start(ToneB3, 100);
        ballthrow = 0;
      }
    }
    if (hp4 == 0)                                                                             //if opponent 4's hp is 0, take him out of the game
    {
      opponent4on = 0;
    }
    
    
    if (boss.x == playerball.x)                                                        //if opponent 2 is hit by the ball, decrease its hp by 1 and take the ball off the screen
    {
      if (boss.y == playerball.y)
      {
        bosshp--;
        Tone_Start(ToneF6, 100);
        ballthrow = 0;
      }
    }
    if (bosshp == 0)
    {
       BossStage++;
    }
    
    
    if (player.x == ball1.x)                                                            //if the player is hit by a ball, decrease its hp by 1 and take the ball off the screen
    {
      if (player.y == ball1.y)
      {
        hp--;
        Tone_Start(ToneF3, 100);
        ball1on = 0;
      }
    }
    if (player.x == ball2.x)
    {
      if (player.y == ball2.y)
      {
        hp--;
        Tone_Start(ToneF3, 100);
        ball2on = 0;
      }
    }
    if (player.x == ball3.x)
    {
      if (player.y == ball3.y)
      {
        hp--;
        Tone_Start(ToneF3, 100);
        ball3on = 0;
      }
    }
    if (player.x == ball4.x)
    {
      if (player.y == ball4.y)
      {
        hp--;
        Tone_Start(ToneF3, 100);
        ball4on = 0;
      }
    }
    
    
    
    if (hp1 < 0)                                                                            //don't let the hps go below 0 so they dont come back on unexpectedly or become invincible
    {
      hp1 = 0;
    }
    if (hp2 < 0)
    {
      hp2 = 0;
    }
    if (hp3 < 0)
    {
      hp3 = 0;
    }
    if (hp4 < 0)
    {
      hp4 = 0;
    }
    if (bosshp < 0)
    {
      bosshp = 0;
    }
    if (hp < 0)
    {
      hp = 0;
    }
    
    
    
    
    
    
    CheckButtonsDown();                                                          //Check which buttons are down
    {
      if (Button_Up)                                                               //If the up button is down...
      {
        player.y++;                                                                //Make the player move up
      }
      if (Button_Down)                                                            //If the down button is down...
      {
        player.y--;                                                                //Make the player move down
      }
      if (Button_Left)                                                              //If the left button is down...
      {
        player.x--;                                                                  //Make the player move left
      }
      if (Button_Right)                                                              //If the right button is down...
      {
        player.x++;                                                                  //Make the player move right
      }
      if (Button_A)                                                                //If the A button is pressed
      {
        ballthrow = 1;                                                              //Make the player throw the ball
      }
    }  
    
    if (ballthrow == 1)                                                            //If the ball is being thrown
    {
      DrawPlayerBall();                                                            //Draw the ball
    }
    if (ball1on == 1)
    {
      ball1.x--;
      DrawPx(ball1.x, ball1.y, Yellow);
    }
    if (ball2on == 1)
    {
      ball2.x--;
      DrawPx(ball2.x, ball2.y, Yellow);
    }
    if (ball3on == 1)
    {
      ball3.x--;
      DrawPx(ball3.x, ball3.y, Yellow);
    }
    if (ball4on == 1)
    {
      ball4.x--;
      DrawPx(ball4.x, ball4.y, Yellow);
    }
    
    
    if (player.x > 3)                                                                //Don't allow the player to go over the court dividing line
    {
      player.x = 3;
    }
    if (player.x < 0)                                                            //Don't allow the player to go off the left of the screen
    {
      player.x = 0;  
    }
    if (player.y > 7)                                                              //Don't allow the player to go off the top of the screen
    {
      player.y = 7;
    }
    if (player.y < 0)                                                              //Don't allow the player to go off the bottom of the screen
    {
      player.y = 0;
    }
    if (opponent1on == 1)                                                          //If opponent 1 is on the screen...
    {
      DrawPx(opponent1.x, opponent1.y, Green);                                      //Draw opponent 1
    }
    if (opponent2on == 1)                                                          //If opponent 2 is on the screen...
    {
      DrawPx(opponent2.x, opponent2.y, Green);                                      //Draw opponent 2
    }
    if (opponent3on == 1)                                                          //If opponent 3 is on the screen...
    {  
      DrawPx(opponent3.x, opponent3.y, Green);                                      //Draw opponent 3
    }
    if (opponent4on == 1)                                                          //If opponent 4 is on the screen...
    {
      DrawPx(opponent4.x, opponent4.y, Green);                                      //Draw opponent 4
    }
    
    
    
    
    
    
    if (hp == 7)                                                                    //Draw player hp
    {
      DrawPx(0,7,Green);
      DrawPx(1,7,Green);
      DrawPx(2,7,Green);
      DrawPx(3,7,Green);
      DrawPx(4,7,Green);
      DrawPx(5,7,Green);
      DrawPx(6,7,Green);
    }
    if (hp == 6)
    {
      DrawPx(0,7,Green);
      DrawPx(1,7,Green);
      DrawPx(2,7,Green);
      DrawPx(3,7,Green);
      DrawPx(4,7,Green);
      DrawPx(5,7,Green);
    }
    if (hp == 5)
    {
      DrawPx(0,7,Green);
      DrawPx(1,7,Green);
      DrawPx(2,7,Green);
      DrawPx(3,7,Green);
      DrawPx(4,7,Green);
    }
    if (hp == 4)
    {
      DrawPx(0,7,Green);
      DrawPx(1,7,Green);
      DrawPx(2,7,Green);
      DrawPx(3,7,Green);
    }
    if (hp == 3)                                                                   
    {
      DrawPx(0,7,Green);
      DrawPx(1,7,Green);
      DrawPx(2,7,Green);
    }
    if (hp == 2)
    {
      DrawPx(0,7,Green);
      DrawPx(1,7,Green);
    }
    if (hp == 1)
    {
      DrawPx(0,7,Green);
    }
    
    
    
    DrawPlayer();                                                                  //Draw the player
    if (stage == 8)                                                                //Draw BOSS scrolling across screen
    {
      if (counter == 0)
      {
        delay(70);
        BossTitle();
        b--;
        o--;
        s1--;
        s2--;
        if (s2 == -8)
        {
          counter = 1;
        }
      }
        
      if (counter == 1)
      {
        for (int i = 0; i<8; i++)
        {
          DrawPx(7,i,Dark);
        }
        DisplaySlate();
        delay(500);
        counter = 2;
      }
        
      if (counter == 2)
      {
        for (int i = 0; i<8; i++)
        {
          DrawPx(7,i,Dark);
          DrawPx(6,i,Dark);
        }
        DisplaySlate();
        delay(500);
        counter = 3;
      }
        
      if (counter == 3)
      {
        for (int i = 0; i<8; i++)
        {
          DrawPx(7,i,Dark);
          DrawPx(6,i,Dark);
          DrawPx(5,i,Dark);
        }
        DisplaySlate();
        delay(500);
        counter = 4;
      }
        
      if (counter == 4)
      {
        for (int i = 0; i<8; i++)
        {
          DrawPx(7,i,Dark);
          DrawPx(6,i,Dark);
          DrawPx(5,i,Dark);
        }
        DrawPx(5,3,Blue);
        DrawPx(5,4,Blue);
        DrawPx(6,2,Blue);
        DrawPx(6,5,Blue);
        counter++;
      }
        
      if (counter > 4)
      {
        Boss1();
        DisplaySlate();
        delay(1000);
      }
    }
    DisplaySlate();                                                                //Display the slate
    delay(100);                                                                    //Wait a little
    ClearSlate();                                                                  //Clear the slate
    if (hp == 0)                                                                  //if the player's hp is 0
    {
      YouLose = 1;                                                                //the player loses
      DeadSound();
    }
    if (stage != 8)
    {
      EndStage();                                                                   //Check if the stage is finished
    }
  }
}


























//                \        /  |¯¯¯¯¯¯|  |  |¯¯¯¯¯\     /¯¯¯¯¯\
//                 \      /   |      |  |  |      \    |      
//                  \    /    |      |  |  |       |   \-----_
//                   \  /     |      |  |  |      /           |    
//                    \/      |______|  |  |_____/     \_____/




void DrawPlayer()                                                              //Drawing the player
{
  DrawPx(player.x, player.y, Red);                                              //Draw the player based on new coords
}

void DrawPlayerBall()                                                          //Drawing the ball
{  
  playerball.x++;                                                              //Increase x coord by 1 (to make ball move horizontally across screen)
  DrawPx(playerball.x, playerball.y, DimRed);                                  //Draw the new spot of the ball
}

void ball1throw()                                                                  //Drawing ball 1
{  
  playerball.x++;                                                              //Increase x coord by 1 (to make ball move horizontally across screen)
  DrawPx(playerball.x, playerball.y, DimRed);                                  //Draw the new spot of the ball
}

void DrawCourt()                                                                //Drawing the court
{
  for(int i = 0; i < 4; i++)                                                    //Color player side white
  {
    for(int j = 0; j < 8; j++)
    {
      DrawPx(i,j,White);
    }
  }
  for(int k = 4; k < 8; k++)                                                          //Color opponent side blue
  {
    for (int l = 0; l < 8; l++)
    {
      DrawPx(k,l,Blue);
    }
  }
}
  
  
  
  
  
void EndStage()                                                                //When a stage is completed...
{
  if (opponent1on == 0)                                                        //If all of the opponents are dead...
  {
    if (opponent2on == 0)
    {
      if (opponent3on == 0)
      {
        if (opponent4on == 0)
        {
          if (bosson == 0)
          {
            counter = 0;                                                      //Reset the counter
            stage++;                                                          //Go to the next stage
            player.x = 0;                                                     //Reset Player coords
            player.y = 4;
            delay(500);
            DrawCourt();                                                      //Draw the Court
            ball1on = 0;
            ball2on = 0;
            ball3on = 0;
            ball4on = 0;
          }
        }
      }
    }
  }
}





void CheckOpponentsOn()
{
  if (counter%1 == 0)                                                      //used to be 7, but i changed to make game flow better and to allow speed alterations
  {
    if (opponent1on == 1)                                                  //if opponent 1 is on..
    {
      if (movement1 == 0)                                                   //if he's moving up...
      {
        movement1 = random(10);                                              //move in a random direction
        if (opponent1.y > 5)                                              //if opponent 1's y coord is above 5...
        {
          opponent1.y--;                                                  //decrease y coord by 1
        }
        if (opponent1.y < 6)                                              //if y coord is below 6...
        {
          opponent1.y++;                                                  //increase y coord by 1
        }
      }
      if (movement1 == 1)                                                    //if he's moving down...
      {
        movement1 = random(10);                                              //move in a random direction
        if (opponent1.y > 2)                                              //if its y coord is above 2...
        {
          opponent1.y--;                                                   //move down 1
        }
        if (opponent1.y < 3)                                              //if its y coord is below 3...
        {
          opponent1.y++;                                                  //increase y coord by 1
        }
      }
      if (movement1 == 2)                                                 //if its moving left...
      {
        movement1 = random(10);                                          //move in a random direction
        opponent1.x--;                                                    //decrease x coord by 1
      }
      if (movement1 == 3)                                                  //if its moving right...
      {
        movement1 = random(10);                                            //move in a random direction
        opponent1.x++;                                                    //increase x coord by 1
      }
      if (movement1 > 3)                                                   //if movement1 variable > 3...  (since i say random 10 and there are only 4 direction choices)
      {
        movement1 = random(2);          //set the movement1 to either up or down   (this way there is a higher chance for the cpu to move up or down since there are more spaces vertically than horizontally)
      }
      
      
      if (opponent1.x > 7)                                                //if opponent 1 goes off the right of the screen...
      {
        movement1 = random(10);                                            //move him in a random direction
        opponent1.x = 6;                                                  //put him back on the screen
      }
      if (opponent1.x < 4)                                                //if opponent 1 goes over the central dividing line...
      {
        movement1 = random(10);                                            //move him in a random direction
        opponent1.x = 5;                                                  //put him back on his side
      }
      if (opponent1.y > 7)                                                //if opponent 1 goes off the top of the screen...
      {
        movement1 = random(10);                                            //move him in a random direction
        opponent1.y = 6;                                                  //put him back on the screen
      }
      if (opponent1.y < 0)                                                //if opponent 1 goes off the bottom of the screen...
      {
        movement1 = random(10);                                            //move him in a random direction
        opponent1.y = 1;                                                  //put him back on the screen
      }
    }
  }
  
  
  
  
  if (counter%1 == 0)                                                    //Same as above, but for opponent 2
  {
    if (opponent2on == 1)                                                
    {
      if (movement2 == 0)
      {
        movement2 = random(10);
        if (opponent2.y > 5)
        {
          opponent2.y--;
        }
        if (opponent2.y < 6)
        {
          opponent2.y++;
        }
      }
      if (movement2 == 1)
      {
        movement2 = random(10);
        if (opponent2.y > 2)
        {
          opponent2.y--;
        }
        if (opponent2.y < 3)
        {
          opponent2.y++;
        }
      }
      if (movement2 == 2)
      {
        movement2 = random(10);
        opponent2.x--;
      }
      if (movement2 == 3)
      {
        opponent2.x++;
        movement2 = random(10);
      }
      if (movement2 > 3)
      {
        movement2 = random(2);
      }
      if (opponent2.x > 7)
      {
        movement2 = random(10);
        opponent2.x = 6;
      }
      if (opponent2.x < 4)
      {
        movement2 = random(10);
        opponent2.x = 5;
      }
      if (opponent2.y > 7)
      {
        movement2 = random(10);
        opponent2.y = 6;
      }
      if (opponent2.y < 0)
      {
        movement2 = random(10);
        opponent2.y = 1;
      }
    }
  }
  
  
  if (counter%1 == 0)                                                    //Same as above, but for opponent 3
  {
    if (opponent3on == 1)                                                
    {
      if (movement3 == 0)
      {
        movement3 = random(10);
        if (opponent3.y > 5)
        {
          opponent3.y--;
        }
        if (opponent3.y < 6)
        {
          opponent3.y++;
        }
      }
      if (movement3 == 1)
      {
        movement3 = random(10);
        if (opponent3.y > 2)
        {
          opponent3.y--;
        }
        if (opponent3.y < 3)
        {
          opponent3.y++;
        }
      }
      if (movement3 == 2)
      {
        movement3 = random(10);
        opponent3.x--;
      }
      if (movement3 == 3)
      {
        opponent3.x++;
        movement3 = random(10);
      }
      if (movement3 > 3)
      {
        movement3 = random(2);
      }
      if (opponent3.x > 7)
      {
        movement3 = random(10);
        opponent3.x = 6;
      }
      if (opponent3.x < 4)
      {
        movement3 = random(10);
        opponent3.x = 5;
      }
      if (opponent3.y > 7)
      {
        movement3 = random(10);
        opponent3.y = 6;
      }
      if (opponent3.y < 0)
      {
        movement3 = random(10);
        opponent3.y = 1;
      }
    }
  }
  
  
  if (counter%1 == 0)                                                    //Same as above, but for opponent 4
  {
    if (opponent4on == 1)                                                
    {
      if (movement4 == 0)
      {
        movement4 = random(10);
        if (opponent4.y > 5)
        {
          opponent4.y--;
        }
        if (opponent4.y < 6)
        {
          opponent4.y++;
        }
      }
      if (movement4 == 1)
      {
        movement4 = random(10);
        if (opponent4.y > 2)
        {
          opponent4.y--;
        }
        if (opponent4.y < 3)
        {
          opponent4.y++;
        }
      }
      if (movement4 == 2)
      {
        movement4 = random(10);
        opponent4.x--;
      }
      if (movement4 == 3)
      {
        opponent4.x++;
        movement4 = random(10);
      }
      if (movement4 > 3)
      {
        movement4 = random(2);
      }
      if (opponent4.x > 7)
      {
        movement4 = random(10);
        opponent4.x = 6;
      }
      if (opponent4.x < 4)
      {
        movement4 = random(10);
        opponent4.x = 5;
      }
      if (opponent4.y > 7)
      {
        movement4 = random(10);
        opponent4.y = 6;
      }
      if (opponent4.y < 0)
      {
        movement4 = random(10);
        opponent4.y = 1;
      }
    }
  }
}








void Loss()
{
  ClearSlate();                                                                              //Clear the screen
  DisplaySlate();                                                                              //display it black
  delay(800);                                                                                 //wait a little
  DrawX();                                                                                    //Draw a big red X
  DisplaySlate();                                                                              //Display it
  delay(1500);                                                                                //Wait a little
  CheckButtonsDown();                                                                        //If a player presses any button, restart the game
  if (Button_A || Button_B || Button_Up || Button_Down || Button_Left || Button_Right)
  {
    YouLose = 0;
    stage = 0;                                                                               //EndStage() moves this to stage 1
    opponent1on = 0;
    opponent2on = 0;
    opponent3on = 0;
    opponent4on = 0;
    bosson = 0;
    ball1on = 0;                                                                             //Clear any balls still in flight
    ball2on = 0;
    ball3on = 0;
    ball4on = 0;
    ballthrow = 0;
    hp = 5;
    opponent1.y = 4;
    DrawCourt();
    DisplaySlate();
  }
}












                //DRAWING


void Boss1()                                                              //Draw Boss Stage 1
{
  for (int i = 0; i<8; i++)
  {
    DrawPx(7,i,Dark);
  }
  DrawPx(6,0,Dark);
  DrawPx(6,7,Dark);
  DrawPx(6,3,Dark);
  DrawPx(6,4,Dark);
  DrawPx(5,0,Dark);
  DrawPx(5,1,Dark);
  DrawPx(5,6,Dark);
  DrawPx(5,7,Dark);
}


void Draw1()
{
  DrawPx(2,1,Yellow);
  DrawPx(3,1,Yellow);
  DrawPx(4,1,Yellow);
  DrawPx(5,1,Yellow);
  DrawPx(6,1,Yellow);
  DrawPx(4,2,Yellow);
  DrawPx(4,3,Yellow);
  DrawPx(4,4,Yellow);
  DrawPx(4,5,Yellow);
  DrawPx(4,6,Yellow);
  DrawPx(3,5,Yellow);
  DrawPx(2,4,Yellow);
}
  
void Draw2()
{
  DrawPx(1,1,Yellow);
  DrawPx(2,1,Yellow);
  DrawPx(3,1,Yellow);
  DrawPx(4,1,Yellow);
  DrawPx(5,1,Yellow);
  DrawPx(6,1,Yellow);
  DrawPx(1,2,Yellow);
  DrawPx(1,3,Yellow);
  DrawPx(1,4,Yellow);
  DrawPx(2,4,Yellow);
  DrawPx(3,4,Yellow);
  DrawPx(4,4,Yellow);
  DrawPx(5,4,Yellow);
  DrawPx(6,4,Yellow);
  DrawPx(6,5,Yellow);
  DrawPx(6,6,Yellow);
  DrawPx(5,6,Yellow);
  DrawPx(4,6,Yellow);
  DrawPx(3,6,Yellow);
  DrawPx(2,6,Yellow);
  DrawPx(1,6,Yellow);
}

void Draw3()
{
  DrawPx(1,1,Yellow);
  DrawPx(2,1,Yellow);
  DrawPx(3,1,Yellow);
  DrawPx(4,1,Yellow);
  DrawPx(5,1,Yellow);
  DrawPx(6,1,Yellow);
  DrawPx(6,2,Yellow);
  DrawPx(6,3,Yellow);
  DrawPx(6,4,Yellow);
  DrawPx(5,4,Yellow);
  DrawPx(4,4,Yellow);
  DrawPx(3,4,Yellow);
  DrawPx(6,5,Yellow);
  DrawPx(6,6,Yellow);
  DrawPx(5,6,Yellow);
  DrawPx(4,6,Yellow);
  DrawPx(3,6,Yellow);
  DrawPx(2,6,Yellow);
  DrawPx(1,6,Yellow);
}

void Draw4()
{
  DrawPx(2,3,Yellow);
  DrawPx(2,4,Yellow);
  DrawPx(2,5,Yellow);
  DrawPx(2,6,Yellow);
  DrawPx(3,3,Yellow);
  DrawPx(4,3,Yellow);
  DrawPx(5,1,Yellow);
  DrawPx(5,2,Yellow);
  DrawPx(5,3,Yellow);
  DrawPx(5,4,Yellow);
  DrawPx(5,5,Yellow);
  DrawPx(5,6,Yellow);
}

void Draw5()
{
  DrawPx(1,1,Yellow);
  DrawPx(2,1,Yellow);
  DrawPx(3,1,Yellow);
  DrawPx(4,1,Yellow);
  DrawPx(5,2,Yellow);
  DrawPx(5,3,Yellow);
  DrawPx(4,4,Yellow);
  DrawPx(3,4,Yellow);
  DrawPx(2,4,Yellow);
  DrawPx(1,4,Yellow);
  DrawPx(1,5,Yellow);
  DrawPx(1,6,Yellow);
  DrawPx(2,6,Yellow);
  DrawPx(3,6,Yellow);
  DrawPx(4,6,Yellow);
  DrawPx(5,6,Yellow);
}

void Draw6()
{
  DrawPx(1,1,Yellow);
  DrawPx(1,2,Yellow);
  DrawPx(1,3,Yellow);
  DrawPx(1,4,Yellow);
  DrawPx(1,5,Yellow);
  DrawPx(1,6,Yellow);
  DrawPx(2,1,Yellow);
  DrawPx(3,1,Yellow);
  DrawPx(4,1,Yellow);
  DrawPx(5,1,Yellow);
  DrawPx(5,2,Yellow);
  DrawPx(5,3,Yellow);
  DrawPx(5,4,Yellow);
  DrawPx(2,4,Yellow);
  DrawPx(3,4,Yellow);
  DrawPx(4,4,Yellow);
  DrawPx(2,6,Yellow);
  DrawPx(3,6,Yellow);
  DrawPx(4,6,Yellow);
  DrawPx(5,6,Yellow);
}

void Draw7()
{
  DrawPx(2,6,Yellow);
  DrawPx(3,6,Yellow);
  DrawPx(4,6,Yellow);
  DrawPx(5,6,Yellow);
  DrawPx(5,5,Yellow);
  DrawPx(5,4,Yellow);
  DrawPx(5,3,Yellow);
  DrawPx(5,2,Yellow);
  DrawPx(5,1,Yellow);
}

void DrawX()
{
  DrawPx(0,0,Red);
  DrawPx(0,1,Red);
  DrawPx(1,0,Red);
  DrawPx(1,1,Red);
  DrawPx(1,2,Red);
  DrawPx(2,1,Red);
  DrawPx(2,2,Red);
  DrawPx(3,2,Red);
  DrawPx(2,3,Red);
  DrawPx(3,3,Red);
  DrawPx(4,3,Red);
  DrawPx(3,4,Red);
  DrawPx(4,4,Red);
  DrawPx(5,4,Red);
  DrawPx(4,5,Red);
  DrawPx(5,5,Red);
  DrawPx(6,5,Red);
  DrawPx(5,6,Red);
  DrawPx(6,6,Red);
  DrawPx(7,6,Red);
  DrawPx(6,7,Red);
  DrawPx(7,7,Red);
  DrawPx(7,0,Red);
  DrawPx(7,1,Red);
  DrawPx(6,0,Red);
  DrawPx(6,1,Red);
  DrawPx(6,2,Red);
  DrawPx(5,1,Red);
  DrawPx(4,2,Red);
  DrawPx(5,2,Red);
  DrawPx(5,3,Red);
  DrawPx(0,7,Red);
  DrawPx(1,7,Red);
  DrawPx(0,6,Red);
  DrawPx(1,6,Red);
  DrawPx(2,6,Red);
  DrawPx(1,5,Red);
  DrawPx(2,5,Red);
  DrawPx(2,4,Red);
  DrawPx(3,5,Red);
}

void BossTitle()
{
  if (b < 8)
  {
    if (b >= 0)
    {
      DrawPx(b,1,Yellow);
      DrawPx(b,2,Yellow);
      DrawPx(b,3,Yellow);
      DrawPx(b,4,Yellow);
      DrawPx(b,5,Yellow);
      DrawPx(b,6,Yellow);
    }
  }
  if (b+1 < 8)
  {
    if (b+1 >= 0)
    {
      DrawPx(b+1,1,Yellow);
      DrawPx(b+1,6,Yellow);
      DrawPx(b+1,4,Yellow);
    }
  }
  if (b+2 < 8)
  {
    if (b+2 >= 0)
    {
      DrawPx(b+2,1,Yellow);
      DrawPx(b+2,6,Yellow);
      DrawPx(b+2,4,Yellow);
    }
  }
  if (b+3 < 8)
  {
    if (b+3 >= 0)
    {
      DrawPx(b+3,1,Yellow);
      DrawPx(b+3,6,Yellow);
      DrawPx(b+3,4,Yellow);
    }
  }
  if (b+4 < 8)
  {
    if (b+4 >= 0)
    {
      DrawPx(b+4,1,Yellow);
      DrawPx(b+4,2,Yellow);
      DrawPx(b+4,3,Yellow);
      DrawPx(b+4,5,Yellow);
      DrawPx(b+4,6,Yellow);
    }
  }
  
  if (o < 8)
  {
    if (o >= 0)
    {
      DrawPx(o,1,Yellow);
      DrawPx(o,2,Yellow);
      DrawPx(o,3,Yellow);
      DrawPx(o,4,Yellow);
      DrawPx(o,5,Yellow);
      DrawPx(o,6,Yellow);
    }
  }
  if (o+1 < 8)
  {
    if (o+1 >= 0)
    {
      DrawPx(o+1,1,Yellow);
      DrawPx(o+1,6,Yellow);
    }
  }
  if (o+2 < 8)
  {
    if (o+2 >= 0)
    {
      DrawPx(o+2,1,Yellow);
      DrawPx(o+2,6,Yellow);
    }
  }
  if (o+3 < 8)
  {
    if (o+3 >= 0)
    {
      DrawPx(o+3,1,Yellow);
      DrawPx(o+3,6,Yellow);
      DrawPx(o+3,2,Yellow);
      DrawPx(o+3,3,Yellow);
      DrawPx(o+3,4,Yellow);
      DrawPx(o+3,5,Yellow);
      DrawPx(o+3,6,Yellow);
    }
  }
  
  if (s1 < 8)
  {
    if (s1 >= 0)
    {
      DrawPx(s1,1,Yellow);
      DrawPx(s1,4,Yellow);
      DrawPx(s1,5,Yellow);
      DrawPx(s1,6,Yellow);
    }
  }
  if (s1+1 < 8)
  {
    if (s1+1 >= 0)
    {
      DrawPx(s1+1,1,Yellow);
      DrawPx(s1+1,4,Yellow);
      DrawPx(s1+1,6,Yellow);
    }
  }
  if (s1+2 < 8)
  {
    if (s1+2 >= 0)
    {
      DrawPx(s1+2,1,Yellow);
      DrawPx(s1+2,4,Yellow);
      DrawPx(s1+2,6,Yellow);
    }
  }
  if (s1+3 < 8)
  {
    if (s1+3 >= 0)
    {
      DrawPx(s1+3,1,Yellow);
      DrawPx(s1+3,2,Yellow);
      DrawPx(s1+3,3,Yellow);
      DrawPx(s1+3,4,Yellow);
      DrawPx(s1+3,6,Yellow);
    }
  }
  
  if (s2 < 8)
  {
    if (s2 >= 0)
    {
      DrawPx(s2,1,Yellow);
      DrawPx(s2,4,Yellow);
      DrawPx(s2,5,Yellow);
      DrawPx(s2,6,Yellow);
    }
  }
  if (s2+1 < 8)
  {
    if (s2+1 >= 0)
    {
      DrawPx(s2+1,1,Yellow);
      DrawPx(s2+1,4,Yellow);
      DrawPx(s2+1,6,Yellow);
    }
  }
  if (s2+2 < 8)
  {
    if (s2+2 >= 0)
    {
      DrawPx(s2+2,1,Yellow);
      DrawPx(s2+2,4,Yellow);
      DrawPx(s2+2,6,Yellow);
    }
  }
  if (s2+3 < 8)
  {
    if (s2+3 >= 0)
    {
      DrawPx(s2+3,1,Yellow);
      DrawPx(s2+3,2,Yellow);
      DrawPx(s2+3,3,Yellow);
      DrawPx(s2+3,4,Yellow);
      DrawPx(s2+3,6,Yellow);
    }
  }
}






                      //SOUNDS (From Meggy Jr. example: Froggy Jr.)


void StartSound()
{
  byte i = 0;  
  unsigned int freqs[5] = { 7648,0,5730, 0,4048    };

  while (i < 5)
  {
    Tone_Start(freqs[i], 50); 
    while (MakingSound)   {}     
    i++;
  }
}

void DeadSound()
{
  Tone_Start(ToneB4, 100); 
  while (MakingSound)
    {}//Tone_Update(); 

  Tone_Start(0, 100); 
  while (MakingSound)
    {}//Tone_Update(); 

  Tone_Start(ToneB2, 300); 
  while (MakingSound)
    {}//Tone_Update(); 
}
