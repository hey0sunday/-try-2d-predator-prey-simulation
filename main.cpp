#include <iostream>
#include "World.h"

using namespace std;

int main() {
// generate random numbers
    srand(time(0));
// create a world
    World world;
    int time = 0;
// simulate the world
    while (true) {
        cout<<"------------------------------------------------------------"<<endl;
        cout << "World at time = " << time << ":" << endl;
        world.display();
        cout << "\nPress ENTER to continue, \"q\" to quit...";
        char ch;
        cin.get(ch);
        if (ch == 'q') {
            break;
        }

        world.simulate_one_time_step();
        time++;
    }

}
