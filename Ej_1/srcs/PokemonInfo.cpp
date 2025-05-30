#include "../headers/PokemonInfo.hpp"

PokemonInfo::PokemonInfo(string t, string descrip, vector<int> EPN, vector<vector<pair<string, int>>> APN): tipo(t), descripcion(descrip), ExperienciaPorNivel(EPN), AtaquesPorNivel(APN) {}

string PokemonInfo::getTipo() const {return tipo;}

string PokemonInfo::getDescripcion() const {return descripcion;}

vector<int> PokemonInfo::getExp() const {return ExperienciaPorNivel;}

vector<vector<pair<string,int>>> PokemonInfo::getAtaques() const {return AtaquesPorNivel;}

ostream& operator<<(std::ostream& os, const PokemonInfo& info) {
    os << "Nombre: " << info.getTipo() << "\n";
    os << "Descripcion: " << info.getDescripcion() << "\n";
    for (int xp : info.getExp()) {
        
    }
    return os;
}