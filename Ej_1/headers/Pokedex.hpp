#pragma once
#include <unordered_map>
#include "Pokemon.hpp"
#include "PokemonInfo.hpp"


class Pokedex {
    private:
        unordered_map<Pokemon, PokemonInfo, PokemonHash> pokemons;
    public:
        Pokedex();
        bool existePokemon(const Pokemon& pokemon) const;
        void sumarPokemon(const Pokemon& pokemon, const PokemonInfo& info);
        void mostrarPokemon(const Pokemon& pokemon) const;
        void mostrarTodos() const;
};