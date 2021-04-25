#ifndef PERSON_H
#define PERSON_H

#include <string>

class animal
{
public:
    std::string name;
    //std::string changeNmae;
    std::string species;
    
    static int currentID ;  // the next id number to give out
    
    animal(std::string aSpecies) ;       // animals are allocated a unique ID on creation,
    // the first animal has ID 1, the second animal is 2 and so on
    
    void set_name(std::string aName);     // change the animal's name
    std::string get_species();
    std::string get_name();
    int get_ID();
    
};
#endif
