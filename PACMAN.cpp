#define _WIN32_WINNT 0x0500
#define ARRIBA     72      // NUMEROS ASOCIADOS A LAS FLECHAS DEL TECLADO
#define IZQUIERDA  75
#define DERECHA    77
#define ABAJO      80
#define ESC        27
#define ENTER      13

#include <exception>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <thread>
#include <mutex>
#include <mmsystem.h>

using namespace std;
std::mutex mtx;

#include "Graphics.cpp"
#include "Sonidos.cpp"

#include "Mapa.cpp"
#include "Fantasmas.cpp"
#include "PacmanJugador.cpp"
#include "Juego.cpp"

#include "Disenos.cpp"
#include "Puntuaciones.cpp"

int main(){
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, 600, 600, TRUE);
    Puntuaciones points;
    int puntos,opc;
    string gamertag;

    do{
        system("cls");
        thread hilo1(start);
        hilo1.detach();
        opc = imprimirMenu();
        switch(opc){
            case 1: puntos = juego();
                    gamertag = obtenerNombre();
                    points.registrarPuntuacion(gamertag,puntos);
                    break;
            case 2: system("cls");
                    disenoScores();
                    points.obtenerScores();
                    gotoxy(3,39);
                    cout << "Presione cualquier tecla para regresar..." ;
                    getch();
                    break;
            case 3: break;
        }
    }while(opc != 3);
    thread hilo2(death);
    hilo2.join();
    cout << endl << endl << endl;
    system("pause");
    return 0;
}

