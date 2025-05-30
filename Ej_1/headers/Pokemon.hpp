#pragma once
#include <iostream>
#include <string>
#include <memory>
using namespace std;


class Pokemon {
    private:
        string nombre;
        int experiencia;
    public:
        Pokemon(string nombre, int experiencia);
        string getNombre() const;
        int getExperiencia() const;
        bool operator==(const Pokemon& other) const;
        friend ostream& operator<<(ostream& os, const Pokemon& info);
        
};

class StudentHash {
    public:
        size_t operator()(const Pokemon& s) const;
};

