#include "../headers/Drones.hpp"

int main() {
    SimDespegue simulacion;
    vector<jthread> drones;
    for (int i = 1; i < 6; ++i) {
        drones.push_back(jthread(&SimDespegue::Despegue, &simulacion, i));
    }

    return 0;
}