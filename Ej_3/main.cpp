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

mutex gen_tarea;
mutex proc_tarea;
queue<Tarea> tareas;
vector<jthread> sensores;
vector<Jthread> robots;
bool notificado = false;
condition_variable tarea_cond;

struct Tarea {
    int IdSensor;
    int IdTarea;
    string Descripcion; 
    Tarea(int idSensor, int idTarea)
        : IdSensor(idSensor), IdTarea(idTarea), Descripcion("Tarea " + to_string(idTarea)) {}
};

Tarea generar_tarea(int idSensor) {
    unique_lock<mutex> lock(gen_tarea);
    int idTarea = rand() % 100; 
    Tarea nuevaTarea(idSensor, idTarea);
    this_thread::sleep_for(chrono::milliseconds(175)); 
    cout << "Sensor " << idSensor << " ha generado la tarea " << idTarea << endl;
    tareas.push(nuevaTarea);
}

void procesar_tarea(int idRobot){
    unique_lock<mutex> lock(proc_tarea);
    while(!tareas.empty()){
        lock.lock();
        Tarea tarea = tareas.front();
        tareas.pop();
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Robot " << idRobot << " Termino de procesar la tarea " << tarea.Descripcion << " del sensor " << tarea.IdSensor << endl;
        lock.unlock();
\    }

}

void Monitoreo(){
    srand(time(0)); 
    for (int i = 0; i < 3; ++i) {
        sensores.push_back(jthread(&generar_tarea, i));
    }
    for (int i = 0; i < 3; ++i) {
        robots.push_back(jthread(&procesar_tarea, i));
    }

}