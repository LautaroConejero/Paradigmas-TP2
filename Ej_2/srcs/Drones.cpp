#include "../headers/Drones.hpp" 

SimDespegue::SimDespegue() {}
SimDespegue::~SimDespegue() {}

void SimDespegue::Despegue(int dron) {
    z_turb[0].lock();
    cout << "\nDron " << dron << " esperando para despegar..." << endl;   
    z_turb[0].unlock();


    lock(z_turb[dron], z_turb[(dron % 5) + 1]);
    lock_guard<mutex> turb_izq(z_turb[dron], adopt_lock);
    lock_guard<mutex> turb_der(z_turb[(dron % 5) + 1], adopt_lock);

    z_turb[0].lock();
    cout << "\nDron " << dron << " despegando..." << endl;
    z_turb[0].unlock();

    this_thread::sleep_for(chrono::seconds(5));
    z_turb[0].lock();
    cout << "\nDron " << dron << " alcanzo la altura de 10m" << endl;
    z_turb[0].unlock();    
    return;
}

