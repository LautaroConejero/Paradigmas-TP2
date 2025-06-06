#include "../headers/Pokedex.hpp"

Pokedex::Pokedex() {}

Pokedex::Pokedex(const string nombre_archivo) : nombreArchivo(nombre_archivo) {
    cargarDesdeArchivo();
}

bool Pokedex::existePokemon(const Pokemon& pokemon) const {
    if (pokemons.empty()) {
        cout << "La Pokedex esta vacia." << endl;
        return false;
    }
    return pokemons.find(pokemon) != pokemons.end();
}

void Pokedex::sumarPokemon(const Pokemon& pokemon, const PokemonInfo& info) {
    if (existePokemon(pokemon)) {
        cout << "El Pokemon ya existe en la Pokedex." << endl;
        return;
    }
    pokemons.insert(make_pair(pokemon, info));

    if (nombreArchivo.empty()) {
        return;
    }
    guardarEnArchivo();
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
    if (pokemons.empty()) {
        cout << "La Pokedex esta vacia." << endl;
        return;
    }

    for (const auto& pair : pokemons) {
        cout << pair.first << endl;

        cout << pair.second; 
        for (size_t i = 0; i < pair.second.getExp().size(); i++) {
            cout << "XP necesario para el nivel " << i + 1 << ": " << pair.second.getExp()[i] << " XP" << endl;
        }
        cout << endl;
    }
    return;
}

void Pokedex::guardarEnArchivo() const {
    ofstream file(nombreArchivo, ios::binary | ios::app);
    
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo para guardar la Pokedex." << endl;
        return;
    }
    for (const auto& pair : pokemons) {
        pair.first.serializar(file);
        pair.second.serializar(file);
    }
    file.close();
    cout << "Pokedex guardada en el archivo " << nombreArchivo << endl;
    return;
}

void Pokedex::cargarDesdeArchivo() {
    ifstream file(nombreArchivo, ios::binary);
    if (!file.is_open()) {
        cout << "El archivo No pudo abrirse" << endl;
        return;
    }
    while (file.peek() != EOF) {
        Pokemon pokemon;
        PokemonInfo pokemoninfo;

        pokemon.deserializar(file);
        pokemoninfo.deserializar(file);
        pokemons.insert(make_pair(pokemon, pokemoninfo));
    }
}