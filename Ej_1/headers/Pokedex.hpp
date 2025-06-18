#pragma once

#include <unordered_map>
#include "Pokemon.hpp"
#include "PokemonInfo.hpp"


class Pokedex {
    private:
        unordered_map<Pokemon, PokemonInfo, PokemonHash> pokemons;
        string nombreArchivo;
    
    public:
        Pokedex();
        Pokedex(const string nombre_archivo);
        bool existePokemon(const Pokemon& pokemon) const;
        void sumarPokemon(const Pokemon& pokemon, const PokemonInfo& info);
        void mostrarPokemon(const Pokemon& pokemon) const;
        void mostrarTodos() const;
        void guardarEnArchivo(const Pokemon& pokemon, const PokemonInfo& info) const;
        void cargarDesdeArchivo();
};