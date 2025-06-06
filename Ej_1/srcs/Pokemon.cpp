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

void Pokemon::serializar(ostream& os) const {
    size_t nombre_length = nombre.size();
    os.write(reinterpret_cast<const char*>(&nombre_length), sizeof(nombre_length));
    os.write(nombre.c_str(), nombre_length);

    os.write(reinterpret_cast<const char*>(&experiencia), sizeof(experiencia));

    return;
}

void Pokemon::deserializar(istream& is) {
    size_t nombre_length;
    is.read(reinterpret_cast<char*>(&nombre_length), sizeof(nombre_length));
    nombre.resize(nombre_length);
    is.read(&nombre[0], nombre_length);

    is.read(reinterpret_cast<char*>(&experiencia), sizeof(experiencia));

    return;
}