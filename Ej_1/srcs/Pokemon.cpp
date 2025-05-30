#include "Pokemon.hpp"

Pokemon::Pokemon(string n, int XP){
    nombre = n;
    
    if (XP < 0) {
        experiencia = 0;
    } else {
        experiencia = XP;
    }
}

string Pokemon::getNombre() const {return nombre;}

int Pokemon::getExperiencia() const {return experiencia;}

bool Pokemon::operator==(const Pokemon& other) const {return nombre == other.getNombre();}  // otra alternativa es usar los getters

ostream& operator<<(std::ostream& os, const Pokemon& info) {
    os << "Nombre: " << info.getNombre() << "\n";
    os << "Experiencia: " << info.getExperiencia() << "\n";
    return os;
}