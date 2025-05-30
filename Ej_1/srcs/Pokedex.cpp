#include "../headers/Pokedex.hpp"

Pokedex::Pokedex() {}

bool Pokedex::existePokemon(const Pokemon& pokemon) const {
    return pokemons.find(pokemon) != pokemons.end();
}
void Pokedex::sumarPokemon(const Pokemon& pokemon, const PokemonInfo& info) {
    if (existePokemon(pokemon)) {
        cout << "El Pokemon ya existe en la Pokedex." << endl;
        return;
    }
    pokemons.insert(make_pair(pokemon, info));
}
void Pokedex::mostrarPokemon(const Pokemon& pokemon) const {
    if (!existePokemon(pokemon)) {
        cout << "El Pokemon " << pokemon.getNombre() <<  " no existe en la Pokedex." << endl;
        return;
    }
    cout << pokemon << endl;
    cout << pokemons.at(pokemon) << endl;
    return;
}

void Pokedex::mostrarTodos() const {
    for (const auto& pair : pokemons) {
        cout << pair.first << endl; 
        cout << pair.second << endl; 
    }
    return;
}

