//HEADERFILES
#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>
#include <conio.h>
#include <chrono>
#include <unordered_map>
#include <random>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;

//SOME FUNCTION PROTOTYPES:
void first_slide();
void second_slide();
void game_loop();
void last_slide();
void clear_screen();
void win();
void lost();
char getUserAnswer();

//GLOBAL VARIABLES:
const int screenWidth = 100;
const int screenHeight = 32;
const int numEnemies = 5;
int score = 0;
int level = 1;
int life = 3;

//Function for clearing the screen in a more defined manner
void clear_screen()
{
    while (!_kbhit()) {
        // Do nothing, wait for a key press
    }
    char key = _getch(); // Retrieve the key pressed
    if (key == 's' || key == 'S') {
        system("cls");
    }
}

void first_slide() {
    string title = R"( 
 .     *  .    ----------------------------------------------------------------------------------------------------------------------------     .     *    
    .         |       _____ ____   ____    __    ___           ____  ___    __ __    ___  ____   ______  __ __  ____     ___      __       |       .      
       .  *   |      / ___/|    \ /    |  /  ]  /  _]         /    ||   \  |  |  |  /  _]|    \ |      ||  |  ||    \   /  _]    |  |      |            .
   *          |     (   \_ |  o  )  o  | /  /  /  [_         |  o  ||    \ |  |  | /  [_ |  _  ||      ||  |  ||  D  ) /  [_     |  |      |    *         
     .        |      \__  ||   _/|     |/  /  |    _]        |     ||  D  ||  |  ||    _]|  |  ||_|  |_||  |  ||    / |    _]    |__|      |           *
        *     |      /  \ ||  |  |  _  /   \_ |   [_         |  _  ||     ||  :  ||   [_ |  |  |  |  |  |  :  ||    \ |   [_      __       |       .
  *           |      \    ||  |  |  |  \     ||     |        |  |  ||     | \   / |     ||  |  |  |  |  |     ||  .  \|     |    |  |      |   *         .  
       .      |       \___||__|  |__|__|\____||_____|        |__|__||_____|  \_/  |_____||__|__|  |__|   \__,_||__|\_||_____|    |__|      |         *     
  .       *   |                                                                                                                            |     .         
      *        ----------------------------------------------------------------------------------------------------------------------------    *       *
)";
    cout << "   .         .      .       . * .    .         .      .       .   *   .        .         .      .       .   *   . .         .      .       .   *   .\n";
    cout << "   .         .    *.    .         .      .       .   *   .        .         .      .       .   *   . .         .      .       .   *   .     .       *\n";
    cout << " " << title << endl;
    string game_load = R"( 
                   /\                                                                                                           /\  
                 .'  '.                                                                                                       .'  '.
                /======\                      __                                                                             /======\
               ;:.  _   ;                    /__  _  __   _   o  _    |   _  _  _| o __    _                                ;:.  _   ;
               |:. (_)  |                    \_| (_| ||| (/_  | _>    |__(_)(_|(_| | | |  (_| o  o  o  o                    |:. (_)  |
               |:.  _   |                                                                 __|                               |:.  _   |
               |:. (_)  |                                                                                                   |:. (_)  |
               ;:.      ;                                     PRESS 'S' TO START                                            ;:.      ;
             .' \:.    / `.                                                                                               .' \:.    / '.
            /.-'':._.'`-.  \                                                                                             /.-'':._.''-.  \
            |/    /||\    \|                                                                                             |/    /||\    \|
)";
    clear_screen();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "   .         .      .       .   *   .     ";
            if (i == 5 && j == 4) {

                cout << game_load << endl;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    clear_screen();
}


void second_slide()


{
    string game_controls = R"(.       *                     .     .     *                     .            *               .          . *    .     *  
                        *                 _    _  ___  ____  ____        __  __    __    _  _  __  __    __    __
        *    .   *              . *      (  )(  )/ __)( ___)(  _ \      (  \/  )  /__\  ( \( )(  )(  )  /__\  (  )    *         *      .    .   *   .
            .       .    *                )(__)( \__ \ )__)  )   /       )    (  /(__)\  )  (  )(__)(  /(__)\  )(__
       *                            *    (______)(___/(____)(_)\_)      (_/\/\_)(__)(__)(_)\_)(______)(__)(__)(____)       *       .    *         *   . 
         .     *       .    .   *                 .         .          *      .  *                .        *                 .    *          *      
        .       .  *          *                 .         .          *      .  *                .        *          *      .    *       *            *  )";
    cout << "   .   *        .    *.    .         .      .       .   *   .        .         .      .       .   *   . .         .      .       .   *   .  *  ";
    string controls = R"(
                .                        ----------------------------------------------------------------------       *     .         *           .   . * 
      *         *    .       *       .  |                                                                      |
                 .   *                  |  >> PRESS THE 'S' KEY TO START THE GAME...                           |  *     .      *   .       .      .  *  .
    *  .     ,*              .       *  |  >> PRESS THE 'M' KEY TO LAUNCH A MISSILE...                         | 
          .              *              |  >> PRESS THE 'D' KEY TO MOVE ROCKET TOWARDS RIGHT...                |     *     .   *       *       *  .   *
   *    *      *    .          *        |  >> PRESS THE 'A' KEY TO MOVE ROCKET TOWARDS LEFT...                 |
                                    *   |  >> SAVE YOURSELF FROM THE ASTEROIDS OR ELSE YOU WILL LOSE A LIFE    | .         .    .     .      *   .  .
          .    *      *                 |  >> COLLECT '<3' BOOSTERS TO GAIN LIVES                              |. *           *
     .      *   .       .      .  *  .  |  >> AFTER EACH LEVEL YOU WILL HAVE TO SOLVE A RIDDLE TO PROCEED      |     .   *        .     *      . .     *
                                        |  >> COMPLETE ALL THREE LEVELS AND SOLVE ALL THE RIDDLES TO WIN       |
        *      .    *          *        |  >> FAILURE IN ANSWERING A RIDDLE CORRECTLY OR LOSING ALL THE LIVES  |   *   .       *       .     *      *
                                    .   |     WILL MAKE YOU LOSE THE GAME                                      |           .
                                        |  >> KEEP THE ROCKET MOVING TO INCREASE THE SCORE                     |
                                        |                                                                      |
        _..._        .        .          ----------------------------------------------------------------------    .  *          *     .      . *    .  *   
      .'     '.      _    *    .             .      *    .    .*     *         *                .       . *          .  * *    .        
     /    .-""-\   _/ \       .   *    .             .      *    .    .*     *         *                .       . *          .  *   .    *   .  *       *
   .-|   /:.   |  |   |                         *       *                       .           . *                 .     *                            .
   |  \  |:.   /.-'-./             *     .       *            *               *       .               . *    .             .      *    .       *
   | .-'-;:__.'    =/                                                                                                                              *     .
   .'=  *=|NASA _.='       .    *    .     *          *             .         *                 *                  *                      *      .
  /   _.  |    ;      *    .             .                 *    .    .*     *         *                  .       . *          .  * *    .    *          *
 ;-.-'|    \   |
/   | \    _\  _\       *    .             .      *                .    .*     *         *                .       . *          .  * *    .  *  .  *    * .
\__/'._;.  ==' ==\          *    .                  .    .*                    *           *                .       . *          .  *
         \    \   |     *    .               *     .   .              .    .*               *         *                .       . *          .   *     *  .        
   *     /    /   /               *    .             *             .          .*             *         *                      .       . *     .         
     .   /-._/-._/     *    .             .      *    .    .*     *               *                .       . *          .  *       *            *       *
   *     \   `\  \    *    .                       .      *    .    .*     *                      *                .       . *          .  *        *    .
          `-._/._/ )";

    cout << "   .   *        .    *.    .         .      .       .   *   .        .         .      .       .   *   . .       *  .     *  .     *    . .   *\n";
    cout << game_controls;
    cout << controls;


    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    clear_screen();


}

void story_slide()
{
    string title = R"(.       *                     .     .     *                     .            *               .          . *    .     *  
          *              *                 
       .     .     *              ____    __    ___  _  _  ___  ____  _____  __  __  _  _  ____     ___  ____  _____  ____  _  _   *               *
                         .       (  _ \  /__\  / __)( )/ )/ __)(  _ \(  _  )(  )(  )( \( )(  _ \   / __)(_  _)(  _  )(  _ \( \/ )            *
   *     *    .   *     .    *    ) _ < /(__)\( (__  )  (( (_-. )   / )(_)(  )(__)(  )  (  )(_) )  \__ \  )(   )(_)(  )   / \  /       *          *
                                 (____/(__)(__)\___)(_)\_)\___/(_)\_)(_____)(______)(_)\_)(____/   (___/ (__) (_____)(_)\_) (__)            .
       *       .    *         *   .                                                                                                                   .
   *      .     *       .    .   *                 .         .          *      .  *                .        *                 .    *          *      
        .       .  *          *                 .         .          *      .  *                .        *          *      .    *       *            *  )";
    cout << "   .   *        .    *.    .         .      .       .   *   .        .         .      .       .   *   . .         .      .       .   *   .  *  ";
    string story = R"(
                .                ---------------------------------------------------------------------------------     *     .         *           
      *         *    .       *  |                                                                                 |
                                |             YOU ARE CAPTAIN JACK, LEADING A PIONEERING MISSION                  |
      .                         |  TO A POTENTIALLY HABITABLE EXOPLANET. RESPONSIBLE FOR MANEUVERING THE ROCKET,  |                *      .
          *         .      *    |  YOU AND YOUR CREW ENCOUNTER A PERILOUS ASTEROID BELT BEFORE REACHING           |        *                  *
                                |  YOUR DESTINATION. THIS VAST AND TREACHEROUS EXPANSE PROVES TO BE A SIGNIFICANT |                 .
    *      .      *             |  THREAT TO THE MISSION'S SUCCESS. NAVIGATING THROUGH THE ASTEROID BELT,         |
            .         *         |  UNEXPECTED CHALLENGES ARISE. YOU MUST AVOID THE ASTEROIDS AND ANSWER THE       |          *               .       *
          .                     |  RIDDLES OF THE ALIENS TO ADVANCE FURHTER.THIS JOURNEY IS A TEST OF YOUR HAND   |
                                |  COORDINATION SKILLS AND WIT. TO REACH THE EXOPLANET, YOU MUST SUCCESSFULLY     |                   *
      *         *      *        |  NAVIGATE THE ENTIRE ASTEROID BELT, ANSWERING RIDDLES CORRECTLY, OR FACE A      |      *                    *  
                                |                               TERRIBLE FATE.                                    |               *
          *                     |                                                                                 |
      .        .                 ---------------------------------------------------------------------------------          *     .      . *    .  *  
    *     _    *    .             .      *    .    .*     *         *                .       . *          .  * *    .        
            .   *    .             .      *    .    .*     *         *                .       . *          .  *   .    *   .  *       *      .
                            *       *                       .           . *                 .     *                            .     .               *
      *       *     .       *            *               *       .               . *    .             .      *    .       *                *
                                                                                                                             *     .               .   *
       .    *    .     *          *             .         *                 *                  *                      *      .                 *
      *    .             .                 *    .    .*     *         *                  .       . *          .  * *    .    *          *            *
                                                                                                                                               .         
 *     *    .             .      *                .    .*     *         *                .       . *          .  * *    .  *  .  *    * .                *
          *    .                  .    .*                    *           *                .       . *          .  *                              *
     *    .               *     .   .              .    .*               *         *                .       . *          .   *     *  .                 .
   *                *    .             *             .          .*             *         *                      .       . *     .                    *
     .       *    .             .      *    .    .*     *               *                .       . *          .  *       *            *       *
   .       *    .             .      *    .    .*     *               *                .       . *          .  *       *            *       *)";

    cout << "   .   *        .    *.    .         .      .       .   *   .        .         .      .       .   *   . .       *  .     *  .     *    . .   *\n";
    cout << title;
    cout << story;
    cout << "   .         .    *.    .         .      .       .   *   .        .         .      .       .   *   . .         .  *    . .   *   .  *   .   *.\n";


    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    clear_screen();


}

struct Enemy
{
    int x;
    int y;
};

struct Rocket
{
    int x;
    int y;
};
struct Booster
{
    int x;
    int y;
};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool isCollision(const Rocket& rocket, const Enemy& enemy)
{
    // Simple bounding box collision detection
    return (rocket.x + 6 >= enemy.x && rocket.x <= enemy.x + 6 &&
        rocket.y + 7 >= enemy.y && rocket.y <= enemy.y + 2);
}


bool isCollision(const Rocket& rocket, const Booster& booster)
{
    // Simple bounding box collision detection
    return (rocket.x + 6 >= booster.x && rocket.x <= booster.x + 2 &&
        rocket.y + 7 >= booster.y && rocket.y <= booster.y);
}



void drawBoundary()
{
    for (int i = 0; i < screenWidth + 2; ++i) {
        gotoxy(i, 0);
        cout << "-";
        gotoxy(i, screenHeight + 1);
        cout << "-";
    }

    for (int i = 1; i < screenHeight + 2; ++i) {
        gotoxy(0, i);
        cout << "|";
        gotoxy(screenWidth + 1, i);
        cout << "|";
    }
}



void drawRocket(const Rocket& rocket)
{

    gotoxy(rocket.x, rocket.y);
    cout << "      |       " << endl;
    gotoxy(rocket.x, rocket.y + 1);
    cout << "     / \\      " << endl;
    gotoxy(rocket.x, rocket.y + 2);
    cout << "    /___\\     " << endl;
    gotoxy(rocket.x, rocket.y + 3);
    cout << "   |.'''.|    " << endl;
    gotoxy(rocket.x, rocket.y + 4);
    cout << "   |'._.'|    " << endl;
    gotoxy(rocket.x, rocket.y + 5);
    cout << " ,'|  |  |`.  " << endl;
    gotoxy(rocket.x, rocket.y + 6);
    cout << "/  |  |  |  \\" << endl;
    gotoxy(rocket.x, rocket.y + 7);
    cout << "|,-'--|--'-.| " << endl;
}







void drawEnemy(const Enemy& enemy)
{
    gotoxy(enemy.x, enemy.y);
    cout << "  *****  " << endl;
    gotoxy(enemy.x, enemy.y + 1);
    cout << " ******* " << endl;
    gotoxy(enemy.x, enemy.y + 2);
    cout << "  ***** " << endl;
}


void drawLifeBooster(const Booster& booster)
{
    gotoxy(booster.x, booster.y);
    cout << "<3" << endl;
}



void restartGame(Rocket& rocket, Enemy enemies[], Booster& booster)

{
    // Reset rocket position
    rocket.x = screenWidth / 2;
    rocket.y = screenHeight - 8;

    // Reset enemy positions
    for (int i = 0; i < numEnemies; ++i) {
        enemies[i].x = rand() % screenWidth;
        enemies[i].y = 0;
    }

    // Reset booster position
    booster.x = rand() % screenWidth;
    booster.y = 0;
}


unordered_map<string, char> riddleBank = {
    {"I am the beginning of the end and the end of time and space. What am I? a) The letter E  b) The number zero c) Darkness", 'a'},
    {"People have stepped on me, but not many. I never stay full for long. What am I?   a) The moon b) A shadow c) A staircase", 'a'},
    {"Large as a mountain, small as a pea, Endlessly swimming in a waterless sea. What am I? a) Icebergs b) Asteroids c) Sand grains", 'b'},
    {"Blacker than black, colder than cold, some things out here are worth more than gold. What is it? a) Space b) A black hole c) The universe",'a'},
    {"How are prisoners like astronauts ? a) Both like isolation b) Both wear uniforms c) Both are interested in outer space",'c'},
    {"What is an astronaut’s favorite part of a computer? a) The space bar b) The control panel c) The mouse.",'a'}
};

char getUserAnswer() {
    char userAnswer;
    cin >> userAnswer;
    return tolower(userAnswer);
}

bool askRiddle(int position) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, riddleBank.size() - 1);

    int riddleIndex = dis(gen);
    auto it = std::next(begin(riddleBank), riddleIndex);

    string riddle = it->first;
    char correctAnswer = it->second;
    cout << endl;
    cout << endl;
    string art = R"(




                       ___  _       _    _                             _              _          _                 _                           _  
                      |_ _|<_> ___ | |__| | ___   _ _  ___  _ _  _ _  | |_  _ _  ___ <_>._ _   _| |_  ___   ___  _| | _ _  ___ ._ _  ___  ___ | | 
                       | | | |/ | '| / /| |/ ._> | | |/ . \| | || '_> | . \| '_><_> || || ' |   | |  / . \ <_> |/ . || | |<_> || ' |/ | '/ ._>|_/ 
                       |_| |_|\_|_.|_\_\|_|\___. `_. |\___/`___||_|   |___/|_|  <___||_||_|_|   |_|  \___/ <___|\___||__/ <___||_|_|\_|_.\___.<_> 
                                                 <___'                                                                                            



)";
    cout << art;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "              To proceed further you must answer my riddle correctly or you shall fall to your death." << endl << endl << endl;
    cout << "             " << riddle << endl;
    cout << endl;
    cout << "                                                       " << "a)  option A" << endl;
    cout << "                                                       " << "b)  option B" << endl;
    cout << "                                                       " << "c)  option C" << endl;




    cout << "                                                       " << "Choose an option(a, b, or c) : ";
    char userAnswer = getUserAnswer();

    if (userAnswer == correctAnswer) {
        Rocket rocket;
        score += 1;
        drawRocket(rocket);
        game_loop();
        return true;
    }

    else {

        return false;
        // Handle game over scenario if the answer is wrong
    }
}



void game_loop()
{
    system("mode con: lines=32 cols=100");
    system("title Falling Enemies Game");

    srand(static_cast<unsigned>(time(nullptr)));

    char startKey;


    string starts = R"(








                                            ____  ____  ____  ___  ___   /___/   ____  _____    ___  ____   __    ____  ____    
                                           (  _ \(  _ \( ___)/ __)/ __)  / __)  (_  _)(  _  )  / __)(_  _) /__\  (  _ \(_  _)             
                                            )___/ )   / )__) \__ \\__ \  \__ \    )(   )(_)(   \__ \  )(  /(__)\  )   /  )(      
                                           (__)  (_)\_)(____)(___/(___/  (___/   (__) (_____)  (___/ (__)(__)(__)(_)\_) (__) 





             _
           /(_))
         _/   /
        //   /
       //   /
       /\__/
       \O_/=-.
   _  / || \  ^o
   \\/ ()_) \.
    ^^ <__> \()
      //||\\
     //_||_\\  
    // \||/ \\
   //   ||   \\
  \/    |/    \/
  /     |      \
 /      |       \
        |

)";


    int position = 130;


    cout << starts;

    do {
        Sleep(2000);
        startKey = _getch();
    } while (startKey != 's');

    Rocket rocket;
    rocket.x = screenWidth / 2;
    rocket.y = screenHeight - 8;  // Adjusted for the new rocket drawing

    Enemy enemies[numEnemies];
    for (int i = 0; i < numEnemies; ++i) {
        enemies[i].x = rand() % screenWidth;
        enemies[i].y = 0;
    }

    Booster booster;
    booster.x = rand() % screenWidth;
    booster.y = 0;

    bool answeredCorrectly;
    while (life > 0 && score < 300)
    {
        if (score == 50 || score == 150 || score == 300)
        {
            system("cls");
            answeredCorrectly = askRiddle(position);

            if (!answeredCorrectly)
            {
                system("cls");
                last_slide();
                lost();
                exit(0);
            }
            else {
                score += 1;
                break;
            }
            break;
        }
        else
        {

            system("cls");
            drawBoundary();
            drawRocket(rocket);
            drawLifeBooster(booster);

            // Update enemies' positions
            for (int i = 0; i < numEnemies; ++i) {
                drawEnemy(enemies[i]);
                enemies[i].y++;

                if (enemies[i].y >= screenHeight) {
                    enemies[i].y = 0;
                    enemies[i].x = rand() % screenWidth;
                }

                // Check for collision with the rocket
                if (isCollision(rocket, enemies[i])) {
                    life--;

                    // Move enemies back up
                    for (int j = 0; j < numEnemies; ++j) {
                        enemies[j].y = 0;
                    }

                    // Reset rocket position or handle collision logic
                    rocket.x = screenWidth / 2;
                    rocket.y = screenHeight - 8;
                    string lifeee = R"(
                                                           ___   _   _         _    __  ___             
                                                       |    |   |_  |_    |   / \  (_    |           
                                                       |_  _|_  |   |_    |_  \_/  __)   |   o  o  o  
                                                                                                                            
 )";


                    // Display a message and wait for a moment
                    cout << lifeee << endl;


                    Sleep(2000);
                }

                // Booster falls less frequently
                booster.y += (rand() % 4 == 0) ? 1 : 0;
                if (booster.y >= screenHeight) {
                    booster.y = 0;
                    booster.x = rand() % screenWidth;
                }

                // Check for collision with the life booster
                if (isCollision(rocket, booster)) {
                    life++;
                    // Move the booster to a new position
                    booster.x = rand() % screenWidth;
                    booster.y = 0;
                }
            }

            if (_kbhit()) {
                char ch = _getch();
                switch (ch) {
                case 'a':
                    rocket.x = max(1, rocket.x - 1);
                    score++;
                    break;
                case 'd':
                    rocket.x = min(screenWidth - 6, rocket.x + 1);
                    score++;
                    break;
                }
            }
        }

        // Display the score
        gotoxy(screenWidth + 5, screenHeight / 2);
        cout << "LEVEL:   " << level << endl;
        cout << endl;
        gotoxy(screenWidth + 5, (screenHeight / 2) + 1);
        cout << "LIFE :   " << life << endl;
        cout << endl;
        gotoxy(screenWidth + 5, (screenHeight / 2) + 2);
        cout << "SCORE:   " << score << endl;

        // LEVEL TRACKING (can create a separate function for it)
        // speed is increasing as level(score) is increasing
        // for lower difficulty level you only need to score 50 in level 1
        if (score <= 50) {
            level = 1;

            Sleep(80);
        }
        // for level 2 you need to score 100 (in level 2 and a total of 150)
        else if (score >= 51 && score <= 150) {
            level = 2;
            Sleep(50);
        }
        // for level 3 you need to score 150 (in level 3 and a total of 300) (adjust that in overall game logic)
        else {
            level = 3;
            Sleep(20);
        }
    }

    if (score == 300 && life>0) {
        system("cls");
        cout << "Congratulations! You answered all riddles correctly and scored above 300! You Win" << endl;

        win();
        // Add a delay before restarting the game
        Sleep(2000);

        exit(0);
    }
    else {
        // Display the game over screen
        system("cls");
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "Your score is off the charts, and by 'off,' I mean it's practically in outer space! " << score << endl;

        last_slide();
        lost();
        // Add a delay before restarting the game
        Sleep(2000);

        // Restart the game
        restartGame(rocket, enemies, booster);
    }

}


void last_slide()
{

    string title = R"(
.     *  .                                    -------------------------------------------------------------------------    *         *         *      *
    .       *     .           *       .      |                                                                         |      *    .              *      *
                       *      .              |               _______      ___      .___  ___.  _______                 |              *      .     .  *
    *       *          *    .       *        |              /  _____|    /   \     |   \/   | |   ____|                |       *    .         *          .
       .                                     |             |  |  __     /  ^  \    |  \  /  | |  |__                   |   .                       .      
       *              *      *   .           |             |  | |_ |   /  /_\  \   |  |\/|  | |   __|                  |     *    *    *     .            *
   .     .       *                           |             |  |__| |  /  _____  \  |  |  |  | |  |____                 |       .            *            *     * 
      *      .         *     .       *       |              \______| /__/     \__\ |__|  |__| |_______|                |    *      *     .
                  .             *            |                                                                         |        .                 *      *    .  
        *     *       *           .          |              ______   ____    ____  _______ .______                     |    *   .     *             
    *                         *   .          |             /  __  \  \   \  /   / |   ____||   _  \                    |        *          .  *        *.    *
    .       *            *        *          |            |  |  |  |  \   \/   /  |  |__   |  |_)  |                   |          *          .    
                    *       .                |            |  |  |  |   \      /   |   __|  |      /                    |   *    .      .    *    .         *   .
     *  .     *      .         *    *        |            |  `--'  |    \    /    |  |____ |  |\  \----.               |        *   .           .          *
     .                    * .     *          |             \______/      \__/     |_______|| _| `._____|               |    *  .           .  *       *   .
     *  .         *                          |                                                                         |              *       .      *  .  
           *           *         * .         |                                                                         |    *      *         *  
                                              -------------------------------------------------------------------------
)";


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "   .     *    .      .    .   *   .    .   .    ";
            if (i == 5 && j == 4) {
                cout << title;
            }
        }
    }
}
void win() {

    string win = R"(
.     *  .                                    -------------------------------------------------------------------------    *         *         *      *
    .       *     .           *       .      |                                                                         |      *    .      *        *   
       *                *      .             |                    ____    ____  ______    __    __                     |
               *              *        *     |                    \   \  /   / /  __  \  |  |  |  |                    |      *    .    *     *      *
   *      *   .          *         *         |                     \   \/   / |  |  |  | |  |  |  |                    |                 .
       .            *                        |                      \_    _/  |  |  |  | |  |  |  |                    |             *             *
             *             .   *      *      |                        |  |    |  `--'  | |  `--'  |                    |     *        .     *          
      *    .             *                   |                        |__|     \______/   \______/                     |         *              *
                 *    .            *         |                                                                         |      .     .      *          *
            *               *                |                  ____    __    ____  __  .__   __.     __               |       *                    .
      *         *       *      .     *       |                  \   \  /  \  /   / |  | |  \ |  |    |  |              |            *         *
             .          .                    |                   \   \/    \/   /  |  | |   \|  |    |  |              |         .   *                     
         *       *            *              |                    \            /   |  | |  . `  |    |  |              |     *             *         .
                        *           *        |                     \    /\    /    |  | |  |\   |    |__|              |         .     *           *
     *        .    *          .              |                      \__/  \__/     |__| |__| \__|    (__)              |             .         .     *                                       |              *       .      *  .  
           *           *         * .         |                                                                         |    *      *         *        .
                                              -------------------------------------------------------------------------
)";

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    clear_screen();
    clear_screen();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "   .         .      .       .   *   .     ";
            if (i == 5 && j == 4) {
                cout << win;
            }
        }
    }

}
void lost() {

    string lost = R"(
.     *  .                                    ---------------------------------------------------------------------------    *         *         *      *
    .       *     .           *       .      |                                                                           |      *    .      *        *   
       *                *      .             |                      ____    ____  ______    __    __                     |
               *              *        *     |                      \   \  /   / /  __  \  |  |  |  |                    |      *    .    *     *      *
   *      *   .          *         *         |                       \   \/   / |  |  |  | |  |  |  |                    |                 .
       .            *                        |                        \_    _/  |  |  |  | |  |  |  |                    |             *             *
             *             .   *      *      |                          |  |    |  `--'  | |  `--'  |                    |     *        .     *          
      *    .             *                   |                          |__|     \______/   \______/                     |         *              *
                 *    .            *         |                                                                           |      .     .      *          *
            *               *                |                 ___          ______      _________    ,___________,       |
      *         *       *      .     *       |                 | |         /  __  \    |   ______|   |___________|       |               .       *
                                             |                 | |        |  |  |  |   |  |______         |  |           |
             .          .                    |                 | |        |  |  |  |   |_____    |        |  |           |  * .  .  *        *           .
                        *           *        |                 | |______  |  '__'  |   ,_____|   |        |  |           |                *           .
     *        .    *          .              |                 |________|  \______/    |_________|        |__|           |        .           *
           *           *         * .         |                                                                           |  *           .    *          .
                                              ---------------------------------------------------------------------------        *      .       .
)";
    clear_screen();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "   .         .      .       .   *   .     ";
            if (i == 5 && j == 4) {
                cout << lost;
            }
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    clear_screen();
}




int main()
{
    first_slide();
    story_slide();
    second_slide();
    game_loop();
    return 0;
}


