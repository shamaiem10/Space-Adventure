# SPACE ADVENTURE
A cosole based game coded in C++.

# Header Files:

1. <iostream>: Provides input/output functionalities (e.g., cout, cin).
2. <string>: Enables string manipulation.
3. <thread>: Allows for creating threads for concurrent execution.
4. <cstdlib>: Provides general utility functions (e.g., rand).
5. <conio.h>: Contains console input/output functions ).
6. <chrono>: For time measurements.
7. <unordered_map>: Used for storing riddles and their answers efficiently.
8. <random>: For generating random numbers.
9. <iomanip>: For input/output formatting.
10. <windows.h>: Provides Windows-specific functions .
11. <ctime>: Time manipulation functions.
    
# Function Prototypes:

void first_slide(): Displays the title screen of the game.
void second_slide(): Shows instructions and controls.
void story_slide(): Presents the game's story.
void game_loop(): The core gameplay loop.
void last_slide(): Potentially displays an ending screen.
void clear_screen(): Clears the console screen.
void win(): Celebrants the player's victory.
void lost(): Handles the player's defeat.
char getUserAnswer(): Gets user input for a riddle answer.

# Global Variables:
const int screenWidth = 100;: Defines the game screen width.
const int screenHeight = 32;: Defines the game screen height.
const int numEnemies = 5;: Sets the number of enemies.
int score = 0;: Tracks the player's score.
int level = 1;: Indicates the current level.
int life = 3;: Represents the player's remaining lives.

# Function Implementations:

1. clear_screen(): This function waits for a key press and then clears the screen based on the pressed key ('s' for clearing). It might be better to use system-specific calls for clearing the screen for wider portability.

2. first_slide(): Displays the game title, introduction message, and asks the user to press 'S' to start. It uses a loop with std::this_thread::sleep_for to create a delay between characters being printed.

3. second_slide(): Shows game controls and asks the user to press 'S' to start.

4. story_slide(): Presents the game's story using formatted text and delays.

# Structs:

Enemy: Represents an enemy object with x and y coordinates.
Rocket: Represents the player's rocket with x and y coordinates.
Booster: Represents a life booster with x and y coordinates.

# Other Functions:

1. gotoxy(int x, int y): This function likely positions the cursor at a specific location on the console screen (non-standard function, consider portability).
2. isCollision(const Rocket& rocket, const Enemy& enemy): Checks for collision between the rocket and an enemy using a simple bounding box approach.
3. isCollision(const Rocket& rocket, const Booster& booster): Checks for collision between the rocket and a booster using a bounding box approach.
4. drawBoundary(): Draws the game screen boundaries with dashes.
5. drawRocket(const Rocket& rocket): Draws the rocket on the screen using characters.
6. drawEnemy(const Enemy& enemy): Draws an enemy on the screen using characters.
7. drawLifeBooster(const Booster& booster): Draws a life booster on the screen using characters.
8. restartGame(Rocket& rocket, Enemy enemies[], Booster& booster): Resets the game by repositioning the rocket, enemies, and booster.
9. getUserAnswer(): Gets a character input from the user in lowercase.
10. askRiddle(int position): Randomly selects a riddle from a map, displays it, and gets the user's answer. It returns true if the answer is correct.

# Author
1. Shamaiem Shabbir
2. Maryam Sheraz
