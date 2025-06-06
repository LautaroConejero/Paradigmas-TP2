#include "../headers/PokemonInfo.hpp"

PokemonInfo::PokemonInfo(string t, string descrip, vector<int> EPN, vector<pair<string, int>> APN): tipo(t), descripcion(descrip), ExperienciaPorNivel(EPN), AtaquesPorNivel(APN) {}

string PokemonInfo::getTipo() const {return tipo;}

string PokemonInfo::getDescripcion() const {return descripcion;}

vector<int> PokemonInfo::getExp() const {return ExperienciaPorNivel;}

vector<pair<string,int>> PokemonInfo::getAtaques() const {return AtaquesPorNivel;}

ostream& operator<<(std::ostream& os, const PokemonInfo& info) {
    os << "Tipo: " << info.getTipo() << "\n";
    os << "Descripcion: " << info.getDescripcion() << "\n"; 
    for (size_t i = 0; i < info.getAtaques().size(); i++) {
        os << "Ataque " << i+1 << ": " << info.getAtaques()[i].first << ", daño: " << info.getAtaques()[i].second << "\n";
    }
    return os;
}

void PokemonInfo::serializar(ostream& os) {
    size_t tipo_length = tipo.size();
    os.write(reinterpret_cast<const char*>(&tipo_length), sizeof(tipo_length));
    os.write(tipo.c_str(), tipo_length);

    size_t descripcion_length = descripcion.size();
    os.write(reinterpret_cast<const char*>(&descripcion_length), sizeof(descripcion_length));
    os.write(tipo.c_str(), descripcion_length);

    size_t exp_size = ExperienciaPorNivel.size();
    os.write(reinterpret_cast<const char*>(&exp_size), sizeof(exp_size));   
    os.write(reinterpret_cast<const char*>(const_cast<int*>(ExperienciaPorNivel.data())), exp_size * sizeof(int));

    size_t ataques_size = AtaquesPorNivel.size();
    os.write(reinterpret_cast<const char*>(&ataques_size), sizeof(ataques_size));
    for (const auto& ataque : AtaquesPorNivel) {
        size_t ataque_name_length = ataque.first.size();
        os.write(reinterpret_cast<const char*>(&ataque_name_length), sizeof(ataque_name_length));
        os.write(ataque.first.c_str(), ataque_name_length);
        os.write(reinterpret_cast<const char*>(&ataque.second), sizeof(ataque.second));
    }
    return;

}

void PokemonInfo::deserializar(istream& is) {
    size_t tipo_length;
    is.read(reinterpret_cast<char*>(&tipo_length), sizeof(tipo_length));
    tipo.resize(tipo_length);
    is.read(&tipo[0], tipo_length);

    size_t descripcion_length;
    is.read(reinterpret_cast<char*>(&descripcion_length), sizeof(descripcion_length));
    descripcion.resize(descripcion_length);
    is.read(&descripcion[0], descripcion_length);

    size_t exp_size;
    is.read(reinterpret_cast<char*>(&exp_size), sizeof(exp_size));
    ExperienciaPorNivel.resize(exp_size);
    is.read(reinterpret_cast<char*>(ExperienciaPorNivel.data()), exp_size * sizeof(int));

    size_t ataques_size;
    is.read(reinterpret_cast<char*>(&ataques_size), sizeof(ataques_size));
    AtaquesPorNivel.resize(ataques_size);

    for (size_t i = 0; i < ataques_size; ++i) {
        size_t ataque_name_length;
        is.read(reinterpret_cast<char*>(&ataque_name_length), sizeof(ataque_name_length));
        AtaquesPorNivel[i].first.resize(ataque_name_length);
        is.read(&AtaquesPorNivel[i].first[0], ataque_name_length);
        is.read(reinterpret_cast<char*>(&AtaquesPorNivel[i].second), sizeof(AtaquesPorNivel[i].second));
    }
    return;
}