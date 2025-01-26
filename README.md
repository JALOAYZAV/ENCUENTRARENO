# ENCUENTRARENO
# Juego de Encontrar al Reno en C++

## Descripción

Este proyecto es un juego interactivo desarrollado en C++ donde el jugador tiene que encontrar al reno escondido en un tablero. El juego utiliza un sistema de pistas basado en la proximidad del reno a la posición actual del jugador, lo que crea una experiencia de juego entretenida y desafiante. El tablero es una cuadrícula de 5x5 celdas, y el jugador puede moverse dentro de él para buscar al reno.

Cada vez que el jugador presiona la tecla Enter, el juego proporciona una pista sobre la cercanía del reno: 
- **"Caliente"** si el reno está muy cerca.
- **"Tibio"** si el reno está un poco más lejos.
- **"Frío"** si el reno está bastante lejos.
El jugador tiene 10 intentos para encontrar al reno. Si se queda sin intentos, el juego termina.

## Características

- **Tablero de 5x5**: El juego utiliza un tablero de 5 filas y 5 columnas donde se oculta el reno.
- **Movimientos del jugador**: El jugador puede moverse con las teclas W (arriba), A (izquierda), S (abajo) y D (derecha).
- **Pistas interactivas**: Cada vez que el jugador presiona Enter para hacer una selección, el juego ofrece una pista de acuerdo con la cercanía al reno.
- **10 intentos**: El jugador tiene un número limitado de intentos (10) para encontrar al reno.
- **Interfaz simple**: La interfaz es basada en texto, lo que facilita la ejecución en entornos como terminales o consolas.

## Requisitos

Para ejecutar este proyecto, necesitas:

- Un compilador C++ que soporte C++11 o superior. Algunos ejemplos son:
  - **GCC** (GNU Compiler Collection)
  - **Clang** (en sistemas macOS y Linux)
  - **Microsoft Visual Studio** (en Windows)
- El juego ha sido probado en **Windows** con el uso de `conio.h` para la detección de teclas, pero debería funcionar en otros sistemas con pequeños ajustes.

## Cómo Jugar

1. **Inicia el juego**: El juego comienza con el jugador en la esquina superior izquierda del tablero (posición `(0, 0)`).
2. **Mover al jugador**: El jugador puede moverse a través del tablero usando las teclas:
   - `W`: Moverse hacia arriba.
   - `A`: Moverse hacia la izquierda.
   - `S`: Moverse hacia abajo.
   - `D`: Moverse hacia la derecha.
3. **Verificar la ubicación**: Una vez que el jugador se haya movido, presiona `Enter` para hacer una selección de la celda actual y verificar si el reno está allí.
4. **Recibir pistas**: Después de cada intento, el juego proporciona una pista basada en la distancia entre el jugador y el reno:
   - **"Caliente"**: El reno está muy cerca.
   - **"Tibio"**: El reno está relativamente cerca.
   - **"Frío"**: El reno está bastante lejos.
5. **Objetivo**: El objetivo es encontrar al reno antes de que se acaben los intentos. Si el jugador encuentra al reno, gana el juego. Si se quedan sin intentos, el juego termina.

## Cómo Ejecutar el Proyecto

### Clonar el Repositorio

1. Clona este repositorio a tu máquina local usando el siguiente comando:

   ```bash
   git clone https://github.com/tu_usuario/nombre_del_repositorio.git

   Tablero:
[J] [-] [-] [-] [-] 
[-] [-] [-] [-] [-] 
[-] [-] [-] [-] [-] 
[-] [-] [-] [-] [-] 
[-] [-] [-] [-] [-] 

Intentos restantes: 10
Usa W/A/S/D para moverte y ENTER para seleccionar: 

***

