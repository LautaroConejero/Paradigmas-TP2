#include "../headers/Drones.hpp" 

SimDespegue::SimDespegue() {}
SimDespegue::~SimDespegue() {}

void SimDespegue::Despegue(int dron) {
    z_turb[0].lock();
    cout << "\nDron " << dron << " esperando para despegar..." << endl;   
    z_turb[0].unlock();

    bool locked1 = z_turb[dron].try_lock();
    bool locked2 = z_turb[(dron % 5) + 1].try_lock();

    while (!locked1 || !locked2) {
        if (locked1) z_turb[dron].unlock();
        if (locked2) z_turb[(dron % 5) + 1].unlock();
        
        locked1 = z_turb[dron].try_lock();
        locked2 = z_turb[(dron % 5) + 1].try_lock();
    }

    cout << "\nDron " << dron << " despegando..." << endl;
    this_thread::sleep_for(chrono::seconds(5));

    cout << "\nDron " << dron << " alcanzo la altura de 10m" << endl;
    z_turb[dron].unlock();
    z_turb[(dron % 5) + 1].unlock();
    
    return;
}

