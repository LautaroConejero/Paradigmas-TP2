#include "../headers/Pokedex.hpp"

int main() {
    Pokemon Pokemon1("Squirtle", 100);
    PokemonInfo PokemonInfo1("Agua", "Una tortuga pequeña que lanza chorros de agua.", {0, 400, 1000}, {{"Pistola Agua", 4}, {"Hidrobomba", 6}, {"Danza Lluvia", 5}});
    Pokemon Pokemon2("Bulbasaur", 270);
    PokemonInfo PokemonInfo2("Planta", "Tiene una semilla en su lomo que crece con el tiempo", {0, 300, 1100}, {{"Latigazo", 4}, {"Hoja Afilada", 6}, {"Rayo Solar", 5}});
    Pokemon Pokemon3("Charmander", 633);
    PokemonInfo PokemonInfo3("Fuego", "Una lagartija con una llama en su cola", {0, 250, 1300}, {{"Ascuas", 4}, {"Lanzallamas", 6}, {"Giro Fuego", 5}});

    Pokedex pokedex;
    pokedex.sumarPokemon(Pokemon1, PokemonInfo1);
    pokedex.sumarPokemon(Pokemon2, PokemonInfo2);
    pokedex.sumarPokemon(Pokemon3, PokemonInfo3);

    cout << endl;
    cout << "Mostrando todos los Pokemon en la Pokedex" << endl;
    pokedex.mostrarTodos();
    cout << endl;

    cout << "Mostrando Pokemon Squirtle:" << endl;
    pokedex.mostrarPokemon(Pokemon1);
    cout << endl;

    cout << "Mostrando Pokemon Pikachu:" << endl;
    Pokemon Pokemon4("Pikachu", 500);
    pokedex.mostrarPokemon(Pokemon4); // Este Pokemon no existe en la Pokedex
    cout << endl;

    
    cout << "Comprobando la funcionalidad de serializacion y deserializacion" << endl;
    Pokedex pokedex2("pokedex.bin");
    cout << endl;
    
    cout << "Mostrando La Pokedex cargada desde el archivo" << endl;
    pokedex2.mostrarTodos();
    cout << endl;

    pokedex2.sumarPokemon(Pokemon1, PokemonInfo1);
    pokedex2.sumarPokemon(Pokemon2, PokemonInfo2);
    pokedex2.sumarPokemon(Pokemon3, PokemonInfo3);
    cout << endl;

    cout << "Mostrando todos los Pokemon en la Pokedex cargada" << endl;
    pokedex2.mostrarTodos();
    cout << endl;

    return 0;
}