#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <utility>
using namespace std;

class PokemonInfo {
    private:
        string tipo; // t
        string descripcion; // descip
        vector<int> ExperienciaPorNivel;  // EPN
        vector<pair<string,int>> AtaquesPorNivel; // APN

    public:
        PokemonInfo() = default;
        PokemonInfo(string t, string descrip, vector<int> EPN, vector<pair<string, int>> APN);
        string getTipo() const;
        string getDescripcion() const;
        vector<int> getExp() const;
        vector<pair<string,int>> getAtaques() const;
        friend ostream& operator<<(ostream& os, const PokemonInfo& info);
        void serializar(ostream& os) const;
        void deserializar(istream& is);
};