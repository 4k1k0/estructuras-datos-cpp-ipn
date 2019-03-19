#ifndef AKKO_H
#define AKKO_H

#include<unistd.h>
#include<time.h>
#ifdef _WIN32
#include<windows.h>
#endif

namespace Akko{
    
    void nombrePantalla(string nombre){
        #ifdef _WIN32
        	const char* n = nombre.c_str();
            SetConsoleTitle(n);
        #else
            char esc_start[] = { 0x1b, ']', '0', ';', 0 };
            char esc_end[] = { 0x07, 0 };
            cout << esc_start << nombre << esc_end;
        #endif
    }
    void limpiarPantalla(){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    void pausa(string msj){
        if(msj == "") msj = "Presiona Enter para continuar";
        cout << msj << endl;
        cin.get();
        cin.clear();
    }
    void esperar(double segundos){
        #ifdef _WIN32
            segundos *= 1000;
            int goal = (int) segundos + clock();
            while(goal > clock());
        #else
            segundos *= 1000000;
            int goal = (int) segundos;
            usleep(goal);
        #endif
    }
    void listaArchivos(string directorio, string extension){
        string cd;
        (directorio == "") ? cd = "" : cd = "cd " + directorio + " && ";
        (extension == "") ? extension = "" : extension = " *" + extension;
        #ifdef _WIN32
            cd += "dir /b" + extension;
            const char* a = cd.c_str();
            system(a);
        #else
            cd += "ls --color" + extension;
            const char* a = cd.c_str();
            system(a);
        #endif
    }
    
}

#endif
