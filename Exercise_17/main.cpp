#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int enemyY[2]; // Array to store the Y positions of the enemies
int enemyX[2]; // Array to store the X positions of the enemies
int enemyFlag[2]; // Array to store the flags indicating if enemies are active

char car[4][4] = // The player's car representation
{
    {'$','$', '$', '$'},
    {'$','$', '$', '$'},
    {'$','$', '$', '$'},
    {'$','$', '$', '$'}
};

int carPos = WIN_WIDTH/2; // Starting position of the car
int score = 0; // Player's score

void gotoxy(int x, int y) // Function to set the cursor position
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) // Function to set cursor visibility and size
{
    if(size == 0)
        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console,&lpCursor);
}

void drawBorder() // Function to draw the game area border
{
    for(int i=0; i<SCREEN_HEIGHT; i++)
    {
        for(int j=0; j<17; j++)
        {
            gotoxy(0+j,i);
            cout<<"#"; // Left border
            gotoxy(WIN_WIDTH-j,i);
            cout<<"#"; // Right border
        }
    }
    for(int i=0; i<SCREEN_HEIGHT; i++)
    {
        gotoxy(SCREEN_WIDTH,i);
        cout<<"#"; // Bottom border
    }
}

void genEnemy(int ind) // Function to generate an enemy car
{
    enemyX[ind] = 17 + rand()%(33); // Randomly set X position for the enemy
}

void drawEnemy(int ind) // Function to draw an enemy car
{
    if( enemyFlag[ind] == true )
    {
        gotoxy(enemyX[ind], enemyY[ind]);
        cout<<"****"; // Drawing the enemy car
        gotoxy(enemyX[ind], enemyY[ind]+1);
        cout<<" ** ";
        gotoxy(enemyX[ind], enemyY[ind]+2);
        cout<<"****";
        gotoxy(enemyX[ind], enemyY[ind]+3);
        cout<<" ** ";
    }
}

void eraseEnemy(int ind) // Function to erase an enemy car
{
    if( enemyFlag[ind] == true )
    {
        gotoxy(enemyX[ind], enemyY[ind]);
        cout<<"    "; // Clear the enemy car
        gotoxy(enemyX[ind], enemyY[ind]+1);
        cout<<"    ";
        gotoxy(enemyX[ind], enemyY[ind]+2);
        cout<<"    ";
        gotoxy(enemyX[ind], enemyY[ind]+3);
        cout<<"    ";
    }
}

void resetEnemy(int ind) // Function to reset an enemy's position
{
    eraseEnemy(ind); // Clear the enemy from the screen
    enemyY[ind] = 1; // Reset Y position
    genEnemy(ind); // Generate a new X position
}

void drawCar() // Function to draw the player's car
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            gotoxy(j+carPos, i+22); // Draw each part of the car
            cout<<car[i][j];
        }
    }
}

void eraseCar() // Function to erase the player's car
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            gotoxy(j+carPos, i+22); // Clear the car from the screen
            cout<<" ";
        }
    }
}

int collision() // Function to check for collisions
{
    if( enemyY[0]+4 >= 23 ) // Check if enemy is close to the player's car
    {
        if( enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9  )
        {
            return 1; // Collision detected
        }
    }
    return 0; // No collision
}

void gameover() // Function to display game over message
{
    system("cls");
    cout<<endl;
    cout<<"\t\t--------------------------"<<endl;
    cout<<"\t\t-------- Game Over -------"<<endl;
    cout<<"\t\t--------------------------"<<endl<<endl;
    cout<<"\t\tPress any key to go back to menu.";
    getch(); // Wait for a key press
}

void updateScore() // Function to update and display the score
{
    gotoxy(WIN_WIDTH + 7, 5);
    cout<<"Score: "<<score<<endl;
}

void instructions() // Function to display game instructions
{
    system("cls");
    cout<<"Instructions";
    cout<<"\n----------------";
    cout<<"\n Avoid Cars by moving left or right. ";
    cout<<"\n\n Press 'a' to move left";
    cout<<"\n Press 'd' to move right";
    cout<<"\n Press 'escape' to exit";
    cout<<"\n\nPress any key to go back to menu";
    getch(); // Wait for a key press
}

void play() // Function to start and manage the game
{
    carPos =  -1 + WIN_WIDTH / 2; // Reset car position
    score = 0; // Reset score
    enemyFlag[0] = 1; // Activate first enemy
    enemyFlag[1] = 0; // Deactivate second enemy
    enemyY[0] = enemyY[1] = 1; // Initialize enemy Y positions

    system("cls");
    drawBorder(); // Draw borders
    updateScore(); // Display score
    genEnemy(0); // Generate first enemy
    genEnemy(1); // Generate second enemy

    gotoxy(WIN_WIDTH + 7, 2);
    cout<<"Car Game"; // Display game title
    gotoxy(WIN_WIDTH + 6, 4);
    cout<<"----------"; // Display game separator
    gotoxy(WIN_WIDTH + 6, 6);
    cout<<"----------";
    gotoxy(WIN_WIDTH + 7, 12);
    cout<<"Control ";
    gotoxy(WIN_WIDTH + 7, 13);
    cout<<"-------- ";
    gotoxy(WIN_WIDTH + 2, 14);
    cout<<" A Key - Left";
    gotoxy(WIN_WIDTH + 2, 15);
    cout<<" D Key - Right";

    gotoxy(18, 5);
    cout<<"Press any key to start"; // Prompt to start the game
    getch(); // Wait for a key press
    gotoxy(18, 5);
    cout<<"                      "; // Clear prompt

    while(1)
    {
        if(kbhit()) // Check if a key is pressed
        {
            char ch = getch();
            if( ch=='a' || ch=='A' ) // Move left
            {
                if( carPos > 18 )
                    carPos -= 4;
            }
            if( ch=='d' || ch=='D' ) // Move right
            {
                if( carPos < 50 )
                    carPos += 4;
            }
            if(ch==27) // Exit if 'escape' is pressed
            {
                break;
            }
        }

        drawCar(); // Draw player's car
        drawEnemy(0); // Draw first enemy
        drawEnemy(1); // Draw second enemy

        if( collision() == 1 ) // Check for collision
        {
            gameover(); // Show game over message
            return;
        }

        Sleep(50); // Pause for a short time
        eraseCar(); // Erase player's car
        eraseEnemy(0); // Erase first enemy
        eraseEnemy(1); // Erase second enemy

        if( enemyY[0] == 10 )
            if( enemyFlag[1] == 0 )
                enemyFlag[1] = 1; // Activate second enemy after first reaches Y position 10

        if( enemyFlag[0] == 1 )
            enemyY[0] += 1; // Move first enemy down

        if( enemyFlag[1] == 1 )
            enemyY[1] += 1; // Move second enemy down

        if( enemyY[0] > SCREEN_HEIGHT-4 ) // Reset enemy if it moves off the screen
        {
            resetEnemy(0);
            score++; // Increase score
            updateScore(); // Update displayed score
        }
        if( enemyY[1] > SCREEN_HEIGHT-4 ) // Reset enemy if it moves off the screen
        {
            resetEnemy(1);
            score++; // Increase score
            updateScore(); // Update displayed score
        }
    }
}

int main() // Main function
{
    setcursor(0,0); // Hide cursor
    srand( (unsigned)time(NULL)); // Seed the random number generator

    do
    {
        system("cls"); // Clear screen

        gotoxy(10,5);
        cout<<" -------------------------- "; // Main menu title
        gotoxy(10,6);
        cout<<" |        Car Game        | ";
        gotoxy(10,7);
        cout<<" --------------------------";
        gotoxy(10,9);
        cout<<"1. Start Game"; // Start game option
        gotoxy(10,10);
        cout<<"2. Instructions"; // Instructions option
        gotoxy(10,11);
        cout<<"3. Quit"; // Quit option
        gotoxy(10,13);
        cout<<"Select option: "; // Prompt for option

        char op = getche(); // Get user's choice

        if( op=='1') play(); // Start game if 1 is chosen
        else if( op=='2') instructions(); // Show instructions if 2 is chosen
        else if( op=='3') exit(0); // Exit if 3 is chosen

    } while(1); // Loop back to menu

    return 0; // Exit the program
}
