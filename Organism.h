

#ifndef INC_11_ORGANISM_H
#define INC_11_ORGANISM_H
#ifndef ORGANISM_H
#define ORGANISM_H

#include <iostream>
#include "World.h"
#include "Position.h"

using namespace std;

class World;

class Organism {
public:
    explicit Organism(const Position &pos);

    Organism();

    virtual ~Organism();

    Position get_position() const;

    void set_position(const Position &pos);

    virtual char get_type() const = 0;

    virtual void move(World &world) = 0;

    virtual void breed(World &world) = 0;

    virtual void starve(World &world) = 0;

    void die(World &world) const;
    //print organism
    virtual void print(ostream &outs) const = 0;
    //overload << operator
    friend ostream &operator<<(ostream &outs, const Organism &organism);

private:
    Position position{};
};

#endif


#endif //INC_11_ORGANISM_H
