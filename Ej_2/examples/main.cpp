#include "../headers/Drones.hpp"

int main() {
    SimDespegue simulacion;
    vector<jthread> drones;
    for (int i = 1; i < Drones + 1; ++i) {
        drones.push_back(jthread(&SimDespegue::Despegue, &simulacion, i));
    }

    return 0;
}