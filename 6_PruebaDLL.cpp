// 6_PruebaDLL.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <Windows.h>
#include <iostream>

int main()
{
    puts("Cargando dll");
    HINSTANCE   mydll = LoadLibrary(L"6_dll.dll");

    if (mydll != NULL)
    {
        puts("se cargo la DLL");
        typedef const char* (*GetCodeNameFunc)();
        GetCodeNameFunc getCodename = reinterpret_cast<GetCodeNameFunc>(GetProcAddress(mydll, "GetCodename"));
        if (getCodename != NULL)
        {
            const char* mensaje = getCodename();
            std::cout << "desde la dll" << mensaje << "\n";
        }
        else
        {
            typedef double (*sumarFunc)(double a, double b);
            sumarFunc sumar ) reinterpret_cast<sumarFunc>(GetProcAddress(mydll, "sumar"));

            if (sumar != NULL)
            {
                std::cout << "prueba de suma :" << sumar(3.1416, 1.414);
            }

            FreeLibrary(mydll);
        }
    }
    else
    {
        puts("No se pudo cargar la DLL: )");
    }
    
    
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
