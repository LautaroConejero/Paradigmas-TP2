#include "../headers/Drones.hpp" 

SimDespegue::SimDespegue() {}
SimDespegue::~SimDespegue() {}

void SimDespegue::Despegue(int dron) {
    z_turb[0].lock();
    cout << "\nDron " << dron << " esperando para despegar..." << endl;   
    z_turb[0].unlock();

    if (Drones == 1){ // Por si quiere volar un solo dron

        cout << "\nDron " << dron << " despegando..." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        cout << "\nDron " << dron << " alcanzo la altura de 10m" << endl;
        
        return;
    }

    scoped_lock lock(z_turb[dron], z_turb[(dron % Drones) + 1]);
   
    z_turb[0].lock();
    cout << "\nDron " << dron << " despegando..." << endl;
    z_turb[0].unlock();

    this_thread::sleep_for(chrono::seconds(5));
    z_turb[0].lock();
    cout << "\nDron " << dron << " alcanzo la altura de 10m" << endl;
    z_turb[0].unlock();    

    return;
}

