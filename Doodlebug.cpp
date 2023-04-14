#include "Doodlebug.h"

Doodlebug::Doodlebug(const Position &pos) : Organism(pos), breed_timer(0), starve_timer(0) {}

Doodlebug::Doodlebug() : Organism(), breed_timer(0), starve_timer(0) {}

Doodlebug::~Doodlebug() = default;

char Doodlebug::get_type() const {
    return TYPE_DOODLEBUG;
}

void Doodlebug::move(World &world) {
    Position curr_pos = get_position();
    vector<Position> adjacent_ants = find_adjacent_ants(world);

    if (!adjacent_ants.empty()) {
        int random_pick = rand() % adjacent_ants.size();
        Position target_ant_pos = adjacent_ants[random_pick];

        world.get_organism(target_ant_pos)->die(world);
        world.move_organism(curr_pos, target_ant_pos);
        breed_timer++;
        starve_timer = 0;
    } else {
        int direction = rand() % 4;
        Position next_pos = curr_pos;

        switch (direction) {
            case MOVE_UP:
                next_pos.row--;
                break;
            case MOVE_DOWN:
                next_pos.row++;
                break;
            case MOVE_LEFT:
                next_pos.col--;
                break;
            case MOVE_RIGHT:
                next_pos.col++;
                break;
            default:
                break;
        }

        if (world.is_cell_available(next_pos)) {
            world.move_organism(curr_pos, next_pos);
        }

        breed_timer++;
        starve_timer++;
    }
}

void Doodlebug::breed(World &world) {
    if (breed_timer < DOODLEBUG_BREED_INTERVAL) {
        return;
    }

    Position curr_pos = get_position();
    vector<Position> available_adjacent_cells = world.get_available_adjacent_cells(curr_pos);

    if (!available_adjacent_cells.empty()) {
        int random_pick = rand() % available_adjacent_cells.size();
        Position new_doodlebug_pos = available_adjacent_cells[random_pick];

        world.set_organism(new_doodlebug_pos, new Doodlebug);
    }

    breed_timer = 0;
}

void Doodlebug::starve(World &world) {
    if (starve_timer < DOODLEBUG_STARVE_INTERVAL) {
        return;
    }

    die(world);
}

void Doodlebug::print(ostream &outs) const {
    outs << DOODLEBUG_CHAR;
}

vector<Position> Doodlebug::find_adjacent_ants(World &world) {
    Position curr_pos = get_position();
    vector<Position> adjacent_ants;
    vector<Position> candidates = {
            {curr_pos.row - 1, curr_pos.col},
            {curr_pos.row + 1, curr_pos.col},
            {curr_pos.row,     curr_pos.col - 1},
            {curr_pos.row,     curr_pos.col + 1}
    };

    for (Position pos: candidates) {
        Organism *organism_ptr = world.get_organism(pos);

        if ((organism_ptr != nullptr) && (organism_ptr->get_type() == TYPE_ANT)) {
            adjacent_ants.push_back(pos);
        }
    }

    return adjacent_ants;
}