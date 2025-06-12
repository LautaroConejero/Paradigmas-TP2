#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

#define Drones 1

class SimDespegue{   
    private:
        mutex z_turb[Drones + 1]; // mutex para controlar el despegue de los drones, el 0 es para mensajes generales
    public:
        SimDespegue();
        ~SimDespegue();
        void Despegue(int dron);
};