

#ifndef INC_11_ANT_H
#define INC_11_ANT_H

#include "Organism.h"

class Ant : public Organism {
public:
    explicit Ant(const Position &pos);

    Ant();
    //destructor
    ~Ant() override;
    //get type of organism
    char get_type() const override;
    //move organism
    void move(World &world) override;
    //breed organism
    void breed(World &world) override;
    //starve organism
    void starve(World &world) override;
    //print organism
    void print(ostream &outs) const override;

private:
    int breed_timer;
};

#endif //INC_11_ANT_H
