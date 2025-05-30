#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <vector>
#include <utility>
using namespace std;

class PokemonInfo {
    private:
        string tipo;
        string descripcion;
        vector<int> ExperienciaPorNivel; 
        vector<vectorpair<string,int>> AtaquesPorNivel;

    public:
        PokemonInfo(string tipo, string descripcion, unordered_map<int, int> EPN, unordered_map<int, vector<pair<string, int>>> APN);
        string getTipo() const;
        string getDescripcion() const;
        vector<int> getExp() const;
        vector<vectorpair<string,int>> getAtaques(int nivel) const;
        friend ostream& operator<<(ostream& os, const PokemonInfo& info);
};