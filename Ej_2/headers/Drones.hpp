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

class SimDespegue{   
    private:
        mutex z_turb[6]; 
    public:
        SimDespegue();
        ~SimDespegue();
        void Despegue(int dron);
};