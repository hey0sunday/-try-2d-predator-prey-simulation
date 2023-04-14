

#ifndef INC_11_WORLD_H
#define INC_11_WORLD_H

#include "Position.h"

#include <vector>

using namespace std;

class Organism;

class World {
public:
    World();

    ~World();
    //check if cell is available
    bool is_cell_available(const Position &pos) const;
    //get available adjacent cells
    vector<Position> get_available_adjacent_cells(const Position &curr_pos) const;
    //simulate one time step
    void simulate_one_time_step();
    //get organism from grid
    Organism *get_organism(const Position &pos) const;
    //set organism to grid
    void set_organism(const Position &pos, Organism *organism_ptr);
    //move organism to next position
    void move_organism(const Position &curr_pos, const Position &next_pos);
    //remove organism from grid
    void remove_organism(const Organism *organism_ptr);
    //display grid
    void display() const;

private:
    //initialize grid
    Organism *grid[GRID_SIZE][GRID_SIZE]{};
};


#endif //INC_11_WORLD_H
