#include "../headers/Drones.hpp" 

Simulacion::Simulacion() {
}

void Simulacion::iniciarSimulacion() {
    for (int dron = 0; dron < 5; dron++) {
        z_turb[0].lock();
        cout << "Dron " << dron << "esperando para despegar..." << endl;   
        z_turb[0].unlock();
        
        bool locked1 = z_turb[dron].try_lock();
        bool locked2 = z_turb[dron + 1].try_lock();
        if (locked1 && locked2) {
            cout << "Dron " << dron << " despegando..." << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << "Dron " << dron << " alcanzo la altura de 10m" << endl;
            z_turb[dron].unlock();
            z_turb[dron + 1].unlock();
        } else {
            if (locked1) z_turb[dron].unlock();
            if (locked2) z_turb[dron + 1].unlock();
        }
    }
    return;
}

