#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;

const int WIDTH = 100, HEIGHT = 70;
const int INI_WIDTH = 60, INI_HEIGHT = 30;
const int LIMIT = 80;
const int SLEEP_TIME = 400 * 1000;  // 0.2 seconds in microseconds.

// If an occupied cell has zero or one neighbor, it dies of loneliness.
// If it has more than three neighbors, it dies of overcrowding.
void death(char world[][WIDTH], int height, int width, int livingNeighbors);
// If an empty cell has exactly three occupied neighbor cells, 
// there is a birth of a new cell to replace the empty cell.
void birth(char world[][WIDTH], int height, int width, int livingNeighbors);

bool inRange(int height, int width, int x, int y);
bool isAlive(char world[][WIDTH], int height, int width, int x, int y);
int countLivingNeighbors(char world[][WIDTH], int height, int width);
void nextGeneration(char world[][WIDTH]);
void copyWorlds(char oldWorld[][WIDTH], char newWorld[][WIDTH]);
void printWorld(char world[][WIDTH]);
void initializeWorld(char world[][WIDTH]);


int main() {
    char world[HEIGHT][WIDTH];
    // Randomly assign life or death to the world.
    initializeWorld(world);
    printWorld(world);

    for (int i = 0; i < LIMIT; i++) {
        usleep(SLEEP_TIME);
        nextGeneration(world);
        printWorld(world);
    }
    
    return 0;
}

void death(int livingNeighbors) {
    
}

void nextGeneration(char world[][WIDTH]) {
    char newWorld[HEIGHT][WIDTH];
    for (int height = 0; height < HEIGHT; height++) {
        for (int width = 0; width < WIDTH; width++) {
            int livingNeighbors = countLivingNeighbors(world, height, width);
            if (world[height][width] == 'X') {
                // Determine if cell dies or not.
                death(newWorld, height, width, livingNeighbors);
            } else if (world[height][width] == ' ') {
                // Determine whether cell is born or not.
                birth(newWorld, height, width, livingNeighbors);
            } else {
                cerr << "There is an error in nextGeneration() \n";
            }
        }
        // cout << endl;
    }
    copyWorlds(world, newWorld);
}

bool inRange(int height, int width, int x, int y) {
    bool biggerZero = ((height + y) >= 0) && ((width + x) >= 0);
    bool smallerMax = ((height + y) < HEIGHT) && ((width + x) < WIDTH);
    return (biggerZero && smallerMax);
}

bool isAlive(char world[][WIDTH], int height, int width, int x, int y) {
    return (world[height + y][width + x] == 'X');
}

int countLivingNeighbors(char world[][WIDTH], int height, int width) {
    int livingNeighbors = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (inRange(height, width, x, y)) {
                if (!((x == 0) && (y == 0))) {
                    if (isAlive(world, height, width, x, y)) {
                        livingNeighbors++;
                    }
                }
            }
        }
    }
    // cout << livingNeighbors;
    return livingNeighbors;
}


// If an occupied cell has zero or one neighbor, it dies of loneliness.
// If it has more than three neighbors, it dies of overcrowding.
void death(char world[][WIDTH], int height, int width, int livingNeighbors) {
    if (livingNeighbors == 0 || livingNeighbors == 1 || livingNeighbors > 3) {
        world[height][width] = ' ';
    } else {
        world[height][width] = 'X';
    }
    // cout << world[height][width];
}

// If an empty cell has exactly three occupied neighbor cells, 
// there is a birth of a new cell to replace the empty cell.
void birth(char world[][WIDTH], int height, int width, int livingNeighbors) {
    if (livingNeighbors == 3) {
        world[height][width] = 'X';
    } else {
        world[height][width] = ' ';
    }
    // cout << world[height][width];
}

void printWorld(char world[][WIDTH]) {
    for (int width = -1; width <= WIDTH; width++) {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < HEIGHT; i++) {
        cout << "|";
        for (int j = 0; j < WIDTH; j++) {
            cout << world[i][j];
        }
        cout << "|";
    cout << endl;
    }
    for (int width = -1; width <= WIDTH; width++) {
        cout << "-";
    }
    cout << "\n\n";
}
 void copyWorlds(char oldWorld[][WIDTH], char newWorld[][WIDTH]) {
    for (int height = 0; height < HEIGHT; height++) {
        for (int width = 0; width < WIDTH; width++) {
            oldWorld[height][width] = newWorld[height][width];
        }
    }
}

void initializeWorld(char world[][WIDTH]) {
    // Randomly assign life or death to the world.
    srand(time(NULL));
    for (int height = 0; height < HEIGHT; height++) {
        for (int width = 0; width < WIDTH; width++) {
            int lifeInt = 0;
            if ((height <= INI_HEIGHT) && (width <= INI_WIDTH)) {
                lifeInt = rand() % 2;
            }
            if (lifeInt == 1) {
                world[height][width] = 'X';
            } else {
                world[height][width] = ' ';
            }
        }
    }
}

