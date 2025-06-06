#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <fstream>
using namespace std;


class Pokemon {
    private:
        string nombre; // n
        int experiencia; // XP
    public:
        Pokemon() = default;
        Pokemon(string n, int XP);
        string getNombre() const;
        int getExperiencia() const;
        bool operator==(const Pokemon& other) const;
        friend ostream& operator<<(ostream& os, const Pokemon& info);
        void serializar(ostream& os) const;
        void deserializar(istream& is);
};

class PokemonHash {
    public:
        size_t operator()(const Pokemon& s) const;
};

