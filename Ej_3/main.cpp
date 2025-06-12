#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <random>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>
using namespace std;

#define sensoresCantidad 3
#define robotsCantidad 3


mutex gen_tarea;
mutex proc_tarea;

struct Tarea {
    int IdSensor;
    int IdTarea;
    string Descripcion; 
    Tarea(int idSensor, int idTarea): IdSensor(idSensor), IdTarea(idTarea), Descripcion("Tarea " + to_string(idTarea)) {}
};

// containers 
queue<Tarea> tareas;
vector<jthread> sensores;
vector<jthread> robots;

// lo del condition
int sensorCompleto = 0;
condition_variable cv;

void generar_tarea(int idSensor) {
    unique_lock<mutex> lock(gen_tarea);

    int cantTareas = rand() % 5 + 1; // --> Cambiarlo o modificar para intentar de que no se repitan por si alguna vez pasa mistriosamente;
    for (int i = 0; i < cantTareas; i++) {
        unique_lock<mutex> lock(gen_tarea);
        this_thread::sleep_for(chrono::milliseconds(175)); // sensores duermiendo

        int idTarea = rand() % 100 + 1; 
        Tarea nuevaTarea(idSensor, idTarea);
        tareas.push(nuevaTarea);
        cout << "Sensor " << idSensor << " ha generado la tarea " << idTarea << endl;

        cv.notify_one(); // se avisa de una tarea disponible a un thread (robot)
    }

    sensorCompleto++; // el sensor i-esimmo ya temrino de crear las n tareas (suma 1 a la cuenta para tener registro de cuantos sensores terminaron)
    cv.notify_all(); // al terminar avisa a todos los threads (robots) que las tareas ya etsan disponibles para hacerlas
}

void procesar_tarea(int idRobot) {
    while(true) {
        unique_lock<mutex> lock(proc_tarea);

        cv.wait(lock, []{return !tareas.empty() || sensorCompleto == sensoresCantidad;}); // Espera hasta que haya tareas o todos los sensores hayan terminado

        if (tareas.empty() && sensorCompleto == sensoresCantidad) break; // condicion que rompe el ciclo infinito

        Tarea tarea = tareas.front();
        tareas.pop();
        cout << "Robot " << idRobot << " Termino de procesar la tarea " << tarea.Descripcion << " del sensor " << tarea.IdSensor << endl;

        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(250)); // robots durmiendo
    }
}

void Monitoreo() {
    for (int i = 0; i < sensoresCantidad; ++i) {
        sensores.push_back(jthread(&generar_tarea, i+1));
    }
    for (int i = 0; i < robotsCantidad; ++i) {
        robots.push_back(jthread(&procesar_tarea, i+1));
    }

}

int main() {
    srand(time(0)); 
    Monitoreo();
    return 0;
}