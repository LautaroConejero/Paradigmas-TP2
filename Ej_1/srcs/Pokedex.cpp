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
    for (size_t i = 0; i < pokemons.at(pokemon).getExp().size(); i++) {
        if (pokemons.at(pokemon).getExp()[i] > pokemon.getExperiencia()) {
            cout << "XP necesario para la proxima evolucion: " << pokemons.at(pokemon).getExp()[i] << " XP" << " (Nivel: " << i+1 << ")" << endl;
            break;
        }
    }
    cout << pokemons.at(pokemon) << endl;
    return;
}

void Pokedex::mostrarTodos() const {
    for (const auto& pair : pokemons) {
        cout << pair.first << endl;

        for (size_t i = 0; i < pair.second.getExp().size(); i++) {
            if (pair.second.getExp()[i] > pair.first.getExperiencia()) {
                cout << "XP necesario para la proxima evolucion: " << pair.second.getExp()[i] << " XP" << " (Nivel: " << i+1 << ")" << endl;
                break;
            }
        }
        cout << pair.second << endl; 
    }
    return;
}

