#include "Ant.h"

Ant::Ant(const Position &pos) : Organism(pos), breed_timer(0) {}

Ant::Ant() : Organism(), breed_timer(0) {}

Ant::~Ant() = default;

char Ant::get_type() const {
    return TYPE_ANT;
}

void Ant::move(World &world) {
    int direction = rand() % 4;
    Position curr_pos = get_position();
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
}

void Ant::breed(World &world) {
    if (breed_timer < ANT_BREED_INTERVAL) {
        return;
    }

    Position curr_pos = get_position();
    vector<Position> available_adjacent_cells = world.get_available_adjacent_cells(curr_pos);

    if (!available_adjacent_cells.empty()) {
        int random_pick = rand() % available_adjacent_cells.size();
        Position new_ant_pos = available_adjacent_cells[random_pick];

        world.set_organism(new_ant_pos, new Ant);
    }

    breed_timer = 0;
}

void Ant::starve(World &world) {}

void Ant::print(ostream &outs) const {
    outs << ANT_CHAR;
}