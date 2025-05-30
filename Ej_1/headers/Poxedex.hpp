#pragma once

#include "Pokemon.hpp"
#include "PokemonInfo.hpp"

class Pokedex {
    private:
        unordered_map<Pokemon, PokemonInfo> pokemons;
    public:
        Pokedex();
        void sumarPokemon(const Pokemon& pokemon, const PokemonInfo& info);
        bool existePokemon(const Pokemon& pokemon) const;
        void mostrarPokemon(const Pokemon& pokemon) const;
        void mostrarTodos() const;
};