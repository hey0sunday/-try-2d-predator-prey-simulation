
#ifndef TEST_CONFIG_H
#define TEST_CONFIG_H

// The following constants are used to configure the simulation.
const int MOVE_UP = 0;
const int MOVE_DOWN = 1;
const int MOVE_LEFT = 2;
const int MOVE_RIGHT = 3;

//the size of the grid
const int GRID_SIZE = 20;
//the number of ants and doodlebugs
const int INITIAL_ANTS = 100;
const int INITIAL_DOODLEBUGS = 10;

//the number of steps to run the simulation
const int ANT_BREED_INTERVAL = 4;
const int DOODLEBUG_BREED_INTERVAL = 10;
const int DOODLEBUG_STARVE_INTERVAL = 2;

//the characters used to display the grid
const char EMPTY_SPACE_CHAR = '-';
const char ANT_CHAR = 'o';
const char DOODLEBUG_CHAR = 'X';

//the types used to identify organisms
const char TYPE_ANT = 'A';
const char TYPE_DOODLEBUG = 'D';


#endif //TEST_CONFIG_H
