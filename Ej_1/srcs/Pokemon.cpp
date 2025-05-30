#include "Pokemon.hpp"

Pokemon::Pokemon(string nombre, int experiencia){
    if (experiencia < 0) {
        experiencia = 0;
    }
}

aa