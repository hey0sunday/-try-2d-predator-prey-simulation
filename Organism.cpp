

#include "Organism.h"

Organism::Organism(const Position &pos) : position(pos) {}

Organism::Organism() = default;

Organism::~Organism() = default;

Position Organism::get_position() const {
    return position;
}

void Organism::set_position(const Position &pos) {
    position.row = pos.row;
    position.col = pos.col;
}

void Organism::die(World &world) const {
    world.remove_organism(this);
}

ostream &operator<<(ostream &outs, const Organism &organism) {
    organism.print(outs);

    return outs;
}