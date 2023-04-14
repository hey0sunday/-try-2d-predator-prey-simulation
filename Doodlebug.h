

#ifndef INC_11_DOODLEBUG_H
#define INC_11_DOODLEBUG_H

#include "Organism.h"

class Doodlebug : public Organism {
public:
    explicit Doodlebug(const Position &pos);

    Doodlebug();

    ~Doodlebug() override;

    char get_type() const override;

    void move(World &world) override;

    void breed(World &world) override;

    void starve(World &world) override;

    void print(ostream &outs) const override;

private:
    int breed_timer;
    int starve_timer;

    //find adjacent ants
    vector<Position> find_adjacent_ants(World &world);
};

#endif //INC_11_DOODLEBUG_H
