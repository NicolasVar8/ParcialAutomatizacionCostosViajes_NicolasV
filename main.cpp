#include <iostream>
#include <string>

using namespace std;

int calcularTotal(int distancia[], int costo[], int viajes) {
    int total = 0;
    for (int i = 0; i < viajes; i++) {
        total = total + (distancia[i] * costo[i]);
    }
    return total;
}

int calcularPromedio(int distancia[], int viajes) {
    int promedio = 0;
    int total = 0;
    for (int i = 0; i < viajes; i++) {
        total = total + distancia[i];
    }
    promedio = total / viajes;
    return promedio;
}

int validarDato(int dato) {
    while (dato < 0) {
        cout << "Dato invalido. Ingrese un valor positivo: ";
        cin >> dato;
    }
    return dato;
}

int main() {
    string nombres[10];
    int conductores, viajes;
    int distancia[10][10];
    int costo[10][10];
    int totalviajes[10];
    int promedioviajes[10];

    cout << "Ingrese el numero de conductores: ";
    cin >> conductores;

    while (conductores > 10 || conductores <= 0) {
        cout << "Ingrese un numero valido de conductores (1-10): ";
        cin >> conductores;
    }

    for (int i = 0; i < conductores; i++) {
        cout << "==== CONDUCTOR #" << i + 1 << " ====" << endl;
        cout << "Nombre: ";
        cin >> nombres[i];
        cout << "Numero de viajes realizados: ";
        cin >> viajes;

        while (viajes > 10 || viajes <= 0) {
            cout << "Ingrese un numero valido de viajes (1-10): ";
            cin >> viajes;
        }

        for (int j = 0; j < viajes; j++) {
            cout << "Viaje #" << j + 1 << ":" << endl;
            cout << "  Distancia (km): ";
            cin >> distancia[i][j];
            distancia[i][j] = validarDato(distancia[i][j]);
            cout << "  Costo por km($): ";
            cin >> costo[i][j];
            costo[i][j] = validarDato(costo[i][j]);
        }

        totalviajes[i] = calcularTotal(distancia[i], costo[i], viajes);
        promedioviajes[i] = calcularPromedio(distancia[i], viajes);
    }

    int indiceMayor = 0;
    for (int i = 1; i < conductores; i++) {
        if (totalviajes[i] > totalviajes[indiceMayor]) {
            indiceMayor = i;
        }
    }

    cout << endl;
    cout << "Nombre del conductor - Total ganado - Promedio distancia" << endl;
    cout << "--------------------------------------------------------" << endl;

    for (int i = 0; i < conductores; i++) {
        cout << nombres[i] << " - " << totalviajes[i] << " - " << promedioviajes[i] << endl;
    }

    cout << endl << "El conductor con mayor ingreso es: " << nombres[indiceMayor]
         << " con un total de $" << totalviajes[indiceMayor] << endl;

    return 0;
}
