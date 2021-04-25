#include <iostream>
#include <string>
#include "animal.h"

animal::animal(std::string aSpecies){
    species=aSpecies;
    currentID++;
    
}
void animal::set_name(std::string aName){
    name=aName;
}
std::string animal::get_species(){
    return species;
}

std::string animal::get_name(){
    return name;
}

int animal::get_ID(){
    return currentID;
    
}

int animal::currentID = 0 ;
