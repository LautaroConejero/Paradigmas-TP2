#include "../headers/Drones.hpp"

int main() {
    Simulacion simulacion;
    vector<jthread> drones;
    for (int i = 0; i < 6; ++i) {
        drones.emplace_back(&Simulacion::iniciarSimulacion, &simulacion, i);
    }
    return 0;
}