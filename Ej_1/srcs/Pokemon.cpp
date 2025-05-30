#include "../headers/Pokemon.hpp"

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

bool Pokemon::operator==(const Pokemon& other) const {return nombre == other.getNombre();}

ostream& operator<<(std::ostream& os, const Pokemon& info) {
    os << "Nombre: " << info.getNombre() << "\n";
    os << "Experiencia: " << info.getExperiencia();
    return os;
}

size_t PokemonHash::operator()(const Pokemon& s) const {
    return hash<string>()(s.getNombre());
}