#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>   // Para usar abs (valor absoluto)
#include <conio.h> // Para detectar teclas (Windows)

using namespace std;

// Función para mostrar el tablero
void mostrarTablero(char tablero[][5], int filas, int columnas, int jugadorFila, int jugadorColumna) {
    cout << "\nTablero:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (i == jugadorFila && j == jugadorColumna) {
                cout << "[J] "; // Jugador
            } else {
                cout << "[" << tablero[i][j] << "] "; // Espacio del tablero
            }
        }
        cout << endl;
    }
}

// Función para calcular y devolver la pista
string obtenerPista(int jugadorFila, int jugadorColumna, int renoFila, int renoColumna) {
    int distancia = abs(jugadorFila - renoFila) + abs(jugadorColumna - renoColumna);

    if (distancia == 0) {
        return "¡Has encontrado al reno!";
    } else if (distancia == 1) {
        return "¡Caliente! El reno está muy cerca.";
    } else if (distancia <= 3) {
        return "Tibio. Estás acercándote.";
    } else {
        return "Frío. El reno está lejos.";
    }
}

int main() {
    const int FILAS = 5, COLUMNAS = 5;
    char tablero[FILAS][COLUMNAS];
    int renoFila, renoColumna;
    int jugadorFila = 0, jugadorColumna = 0; // Posición inicial del jugador
    int intentos = 10;
    bool encontrado = false;

    srand(static_cast<unsigned>(time(0))); // Semilla para números aleatorios

    // Inicializar tablero
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            tablero[i][j] = '-';
        }
    }

    // Ubicar al reno en una posición aleatoria
    renoFila = rand() % FILAS;
    renoColumna = rand() % COLUMNAS;

    cout << "\033[1;36m¡Bienvenido al juego de ENCONTRAR AL RENO!\033[0m\n";
    cout << "El reno está escondido en el tablero. Usa las teclas:\n";
    cout << "  W = Arriba\n  A = Izquierda\n  S = Abajo\n  D = Derecha\n";
    cout << "Presiona ENTER para seleccionar una celda y verificar si está el reno.\n";
    cout << "¡Buena suerte!\n";
    system("pause"); // Espera a que el jugador presione una tecla

    while (intentos > 0 && !encontrado) {
        // Mostrar el tablero actualizado
        mostrarTablero(tablero, FILAS, COLUMNAS, jugadorFila, jugadorColumna); 

        cout << "\nIntentos restantes: " << intentos;
        cout << "\nUsa W/A/S/D para moverte y ENTER para seleccionar: ";
        char movimiento = _getch(); // Detecta una tecla sin necesidad de presionar Enter

        // Limpiar la pantalla solo cuando se mueve el jugador
        if (movimiento == 'w' || movimiento == 'W' || movimiento == 's' || movimiento == 'S' ||
            movimiento == 'a' || movimiento == 'A' || movimiento == 'd' || movimiento == 'D') {
            system("cls");
        }

        // Mover al jugador según la tecla presionada
        if (movimiento == 'w' || movimiento == 'W') {
            if (jugadorFila > 0) --jugadorFila;
        } else if (movimiento == 's' || movimiento == 'S') {
            if (jugadorFila < FILAS - 1) ++jugadorFila;
        } else if (movimiento == 'a' || movimiento == 'A') {
            if (jugadorColumna > 0) --jugadorColumna;
        } else if (movimiento == 'd' || movimiento == 'D') {
            if (jugadorColumna < COLUMNAS - 1) ++jugadorColumna;
        } else if (movimiento == '\r') { // Enter presionado
            // Verificar si el jugador encontró al reno
            if (jugadorFila == renoFila && jugadorColumna == renoColumna) {
                encontrado = true;
                tablero[jugadorFila][jugadorColumna] = 'R'; // Mostrar al reno
                mostrarTablero(tablero, FILAS, COLUMNAS, jugadorFila, jugadorColumna); // Actualizar tablero con reno
                cout << "\n\033[1;32m¡Felicidades! 🦌 Has encontrado al reno escondido.\033[0m\n";
            } else {
                tablero[jugadorFila][jugadorColumna] = 'X'; // Marcar intento fallido
                mostrarTablero(tablero, FILAS, COLUMNAS, jugadorFila, jugadorColumna); // Actualizar tablero
                cout << "\n\033[1;31mNo está aquí. Sigue buscando...\033[0m\n";

                // Mostrar la pista después de seleccionar
                cout << "Pista: " << obtenerPista(jugadorFila, jugadorColumna, renoFila, renoColumna) << endl;

                --intentos;
            }
        } else {
            cout << "\nMovimiento inválido. Usa solo W/A/S/D o ENTER.";
        }
    }

    if (!encontrado) {
        cout << "\n\033[1;31mTe has quedado sin intentos. El reno estaba en (" << renoFila << ", " << renoColumna << ").\033[0m\n";
    }

    cout << "\nGracias por jugar. ¡Hasta la próxima!\n";
    return 0;
}
