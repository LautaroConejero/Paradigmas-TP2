#include "../headers/PokemonInfo.hpp"

PokemonInfo::PokemonInfo(string t, string descrip, vector<int> EPN, vector<pair<string, int>> APN): tipo(t), descripcion(descrip), ExperienciaPorNivel(EPN), AtaquesPorNivel(APN) {}

string PokemonInfo::getTipo() const {return tipo;}

string PokemonInfo::getDescripcion() const {return descripcion;}

vector<int> PokemonInfo::getExp() const {return ExperienciaPorNivel;}

vector<pair<string,int>> PokemonInfo::getAtaques() const {return AtaquesPorNivel;}

ostream& operator<<(std::ostream& os, const PokemonInfo& info) {
    os << "Tipo: " << info.getTipo() << "\n";
    os << "Descripcion: " << info.getDescripcion() << "\n";
    for (size_t i = 0; i < info.getExp().size(); i++) {
        os << "Nivel " << i + 1 << ": " << info.getExp()[i] << " XP necesaria\n";
    }
    for (size_t i = 0; i < info.getAtaques().size(); i++) {
        os << "Ataque: " << info.getAtaques()[i].first << ", daño: " << info.getAtaques()[i].second << "\n";
    }
    return os;
}