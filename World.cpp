#include "World.h"
#include "Ant.h"
#include "Doodlebug.h"

World::World() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = nullptr;
        }
    }

    for (int i = 0; i < INITIAL_DOODLEBUGS; i++) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;

        while (grid[row][col] != nullptr) {
            row = rand() % GRID_SIZE;
            col = rand() % GRID_SIZE;
        }

        grid[row][col] = new Doodlebug({row, col});
    }

    for (int i = 0; i < INITIAL_ANTS; i++) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;

        while (grid[row][col] != nullptr) {
            row = rand() % GRID_SIZE;
            col = rand() % GRID_SIZE;
        }

        grid[row][col] = new Ant({row, col});
    }
}

World::~World() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != nullptr) {
                delete grid[i][j];
            }
        }
    }
}

bool World::is_cell_available(const Position &pos) const {
    return (0 <= pos.row) && (pos.row < GRID_SIZE) && (0 <= pos.col) && (pos.col < GRID_SIZE) &&
           (grid[pos.row][pos.col] == nullptr);
}

vector<Position> World::get_available_adjacent_cells(const Position &curr_pos) const {
    vector<Position> available_adjacent_cells;
    vector<Position> candidates = {
            {curr_pos.row - 1, curr_pos.col},
            {curr_pos.row + 1, curr_pos.col},
            {curr_pos.row,     curr_pos.col - 1},
            {curr_pos.row,     curr_pos.col + 1}
    };

    for (Position pos: candidates) {
        if (is_cell_available(pos)) {
            available_adjacent_cells.push_back(pos);
        }
    }

    return available_adjacent_cells;
}

void World::simulate_one_time_step() {
    vector<Organism *> ants;
    vector<Organism *> doodlebugs;

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if ((grid[i][j] != nullptr) && (grid[i][j]->get_type() == TYPE_DOODLEBUG)) {
                doodlebugs.push_back(grid[i][j]);
            }
        }
    }

    for (Organism *doodlebug_ptr: doodlebugs) {
        doodlebug_ptr->move(*this);
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if ((grid[i][j] != nullptr) && (grid[i][j]->get_type() == TYPE_ANT)) {
                ants.push_back(grid[i][j]);
            }
        }
    }

    for (Organism *ant_ptr: ants) {
        ant_ptr->move(*this);
    }

    for (Organism *doodlebug_ptr: doodlebugs) {
        doodlebug_ptr->breed(*this);
    }

    for (Organism *doodlebug_ptr: doodlebugs) {
        doodlebug_ptr->starve(*this);
    }

    for (Organism *ant_ptr: ants) {
        ant_ptr->breed(*this);
    }
}

Organism *World::get_organism(const Position &pos) const {
    if ((0 <= pos.row) && (pos.row < GRID_SIZE) && (0 <= pos.col) && (pos.col < GRID_SIZE)) {
        return grid[pos.row][pos.col];
    } else {
        return nullptr;
    }
}

void World::set_organism(const Position &pos, Organism *organism_ptr) {
    grid[pos.row][pos.col] = organism_ptr;
    organism_ptr->set_position(pos);
}

void World::move_organism(const Position &curr_pos, const Position &next_pos) {
    grid[next_pos.row][next_pos.col] = grid[curr_pos.row][curr_pos.col];
    grid[next_pos.row][next_pos.col]->set_position(next_pos);
    grid[curr_pos.row][curr_pos.col] = nullptr;
}

void World::remove_organism(const Organism *organism_ptr) {
    Position pos = organism_ptr->get_position();
    grid[pos.row][pos.col] = nullptr;
    delete organism_ptr;
}

void World::display() const {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == nullptr) {
                cout << EMPTY_SPACE_CHAR;
            } else {
                cout << *grid[i][j];
            }

            cout << ' ';
        }

        cout << '\n';
    }
}
