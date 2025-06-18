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

void generar_tarea(int idSensor);
void procesar_tarea(int idRobot);

// el mutex para proteger el acceso a la cola de tareas
mutex m_tarea;

// Definicion de la struct Tarea
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
bool tareasFinalizadas = false;
condition_variable cv;

void generar_tarea(int idSensor) {

    int cantTareas = rand() % 5 + 1; // random de tareas

    for (int i = 0; i < cantTareas; i++) {
        unique_lock<mutex> lock(m_tarea);

        int idTarea = rand() % 100 + 1; 
        Tarea nuevaTarea(idSensor, idTarea);
        tareas.push(nuevaTarea);
        cout << "Sensor " << idSensor << " ha generado la tarea " << idTarea << endl << endl;;

        cv.notify_all();
        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(175)); // sensores durmiendo
    }

    unique_lock<mutex> lock(m_tarea);
    sensorCompleto++;
    if (sensorCompleto == sensoresCantidad) {
        tareasFinalizadas = true; 
        cv.notify_all(); // ultimo sensor notifica que ya se temrino (no hay mas push en tareas)
    }
}

void procesar_tarea(int idRobot) {
    while(true) {
        unique_lock<mutex> lock(m_tarea);
        
        cv.wait(lock, []{return !tareas.empty() || tareasFinalizadas;}); // Espera hasta que haya tareas o todos los sensores hayan terminado

        if (tareas.empty() && tareasFinalizadas) break; // condicion que rompe el ciclo infinito

        Tarea tarea = tareas.front();
        tareas.pop();
        cout << "Robot " << idRobot << " Termino de procesar la tarea " << tarea.Descripcion << " del sensor " << tarea.IdSensor << endl << endl;

        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(250)); // robots durmiendo
    }
}

int main() {
    srand(time(0)); 
    for (int i = 0; i < sensoresCantidad; ++i) {
        sensores.push_back(jthread(&generar_tarea, i+1));
    }
    for (int i = 0; i < robotsCantidad; ++i) {
        robots.push_back(jthread(&procesar_tarea, i+1));
    }
    return 0;
}