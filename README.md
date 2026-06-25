## Pokemath
## DESCRIPCIÓN DEL PROYECTO:

Pokemath es una aplicación educativa que busca abordar la baja motivación de los jóvenes hacia el aprendizaje de las matemáticas. A través de la gamificación inspirada en la temática de Pokémon, el proyecto propone una forma interactiva y entretenida de practicar ejercicios matemáticos.

El juego se basa en un sistema de batallas donde los usuarios deben resolver ejercicios matemáticos para atacar a su oponente, combinando aprendizaje con dinámicas propias de los videojuegos.

## OBJETIVOS GENERALES:

Fomentar el interés de los jóvenes por las matemáticas mediante una herramienta educativa interactiva que permita mejorar sus habilidades de forma entretenida.

## OBJETIVOS ESPECÍFICOS:

Diseñar un juego tipo RPG basado en la temática de Pokémon, donde las batallas se desarrollen mediante ejercicios matemáticos.

Desarrollar ejercicios matemáticos adaptados al nivel del usuario y mejorar la interfaz del juego para facilitar la interacción y comprensión.

Incentivar la participación de los usuarios mediante un sistema de recompensas, progreso y desafíos.

## FUNCIONALIDAD DEL SISTEMA:

El usuario ingresa su nombre y selecciona un nivel de dificultad.
Luego,entrara al mundo donde se enfrenta a rivales en batallas donde el deberá resolver ejercicios matemáticos.

Si responde correctamente → ataca al rival
Si responde incorrectamente → recibe daño

El combate continúa hasta que la vida de uno de los jugadores llegue a cero.

## NIVELES DE DIFICULTAD:

Grado 1: Operaciones básicas.
Grado 2: Operaciones intermedias.
Grado 3: Operaciones más complejas. (en desarrollo)

## ESTADO DEL PROYECTO:

Actualmente, el proyecto se encuentra en desarrollo utilizando el lenguaje C.
Se ha implementado un sistema funcional de combate con ejercicios matemáticos nivel(grado1) y generación aleatoria de preguntas.

## TECNOLOGIA USADA:

Lenguaje de programación: C
Librerías estándar:
stdio.h
stdlib.h
time.h

## INSTALACION Y COMPILACION:

Compilación:

gcc main.c funciones.c -o pokemath

Ejecución:

./pokemath

## EVIDENCIA DE AVANCE HITO 1:

![Imagen](Captura%20de%20pantalla%202026-04-24%20134348.png)


## ESTRUCTURA DEL JUEGO:

main.c → Control principal del programa
funciones.c → Lógica del juego y ejercicios
funciones.h → Declaración de funciones

## ROLES:

Gabriel Norambuena: programador principal

Encargado de desarrollar la lógica central del juego, incluyendo el sistema de combate y la implementación de los ejercicios matemáticos.

Benjamin Vasquez: Diseño de ejercicios y dificultad

Encargado de crear y estructurar los ejercicios matemáticos, asegurando que se adapten a los distintos niveles de dificultad del juego.

Benjamin Navarrete: Organizacion y planificacion de proyecto

Responsable de coordinar el trabajo del equipo, definir objetivos, gestionar tiempos y asegurar el cumplimiento de los hitos del proyecto

Benjamin Ezquivel:Documentación y presentación

Responsable de la elaboración del README, informes y material de presentación, además de apoyar en la comunicación del proyecto.

## IMPACTO ESPERADO:

Se espera que Pokemath contribuya a mejorar la percepción de las matemáticas en los jóvenes, transformando el aprendizaje en una experiencia más dinámica, interactiva y motivadora.

## MEJORAS PARA EL HITO 2

Implementación completa del grado 3
Mayor variedad de ejercicios matemáticos
Sistema de puntuación y progreso
Interfaz gráfica
Incorporación de más elementos inspirados en Pokémon

## CAMBIOS ANTES DE TRANSFORMARLO EN C++
se le agrego un grado 3 que no estaba implementada een el hito 1.
se le implemento colores ascii para tener una mejora visual en el juego:
![Colores ANSI](colores-ascii.png)

## MIGRACION DE C A C++

-El Hito 1 fue desarrollado en C con tres archivos (main.c, funciones.c, funciones.h). Para el Hito 2 migramos completamente a C++ con diseño orientado a objetos.

Esta migración fue realizada con apoyo de Claude (IA). Partimos del código funcional del Hito 1 y usamos la herramienta para ayudarnos a restructurarlo en clases, ya que el equipo estaba en proceso de aprender POO en C++.

Las principales dificultades fueron entender cuándo usar herencia versus composición, y trabajar con `std::unique_ptr`, que no existe en C.

## CAMBIOS RESPECTO AL HITO 1
 Se completó el Grado 3 que estaba pendiente.
 Se agregaron colores ANSI para mejorar la experiencia visual.
 Se separó la lógica en clases con responsabilidades claras.
 El menú, la selección de grado y las instrucciones pasaron a la clase menu.

 ## CLASES PRINCIPALES Y RELACIONES
 Pregunta
->PreguntaSuma, PreguntaResta, PreguntaMultiplicacion, PreguntaDivision
->PreguntaAreaTriangulo, PreguntaPorcentaje, PreguntaEcuacionLineal, PreguntaDivisionDecimal
->PreguntaCuadratica, PreguntaPotencia, PreguntaSistemaEcuaciones, PreguntaRaizCuadrada, PreguntaLogaritmo
Grado
-> Grado1 → genera preguntas de Grado 1
-> Grado2 → genera preguntas de Grado 2
-> Grado3 → genera preguntas de Grado 3
Jugador→ nombre, vida, victorias
Combate→ orquesta el loop de combate usando Jugador y Grado
Menu→ pantalla de bienvenida, menú principal, selección de grado

## ESTRUCTURA DEL PROYECTO
src/
->main.cpp
-> Menu.h / Menu.cpp
-> Combate.h / Combate.cpp
-> Jugador.h / Jugador.cpp
-> Grado.h / Grado.cpp
-> Grado1.h / Grado1.cpp
-> Grado2.h / Grado2.cpp
-> Grado3.h / Grado3.cpp
-> Pregunta.h / preguntas.cpp
-> PreguntasGrado1.h / preguntagrado1.cpp
-> PreguntasGrado2.h / preguntagrado2.cpp
-> PreguntasGrado3.h / preguntagrado3.cpp
-> Colores.h

## COMPILACION
g++ -std=c++14 -o pokemath main.cpp Menu.cpp Combate.cpp Jugador.cpp Grado.cpp Grado1.cpp Grado2.cpp Grado3.cpp preguntas.cpp preguntagrado1.cpp preguntagrado2.cpp preguntagrado3.cpp

## EJECUCION
./pokemath

## EVIDENCIA DEL HITO 2 

## Pantalla de inicio

![Pantalla de inicio](pantalladeinicio.png)

## Instrucciones

![Instrucciones](instrucciones.png)

## Ejemplo de batalla

![Batalla](ejemplodebatalla.png)

## PROXIMOS PASOS DEL HITO 3
Sistema de puntuación persistente entre partidas
Mayor variedad de preguntas por grado
 Posible incorporación de elementos adicionales inspirados en Pokémon (ataques especiales, tipos, etc.)

## IMPLEMENTACION HITO 3:

Para el Hito 3 se implemento una interfaz grafica basica para Pokemath utilizando Qt Creator y Qt Designer.

La interfaz fue realizada con widgets arrastrables y permite jugar sin utilizar la consola.

## CAMBIOS REALIZADOS:

Se creo una interfaz grafica para el juego.

Se agregaron campos para ingresar el nombre del jugador y rival.

Se agrego un selector para elegir el grado de dificultad.

Se agregaron barras de vida para el jugador y rival.

Se agrego un espacio donde aparece la pregunta matematica.

Se agrego un campo para ingresar la respuesta.

Se agrego un segundo campo de respuesta para los sistemas de ecuaciones.

Se agrego un historial de batalla.

Se agrego una ventana emergente al finalizar el combate.

## WIDGETS UTILIZADOS:

QLabel.

QLineEdit.

QComboBox.

QPushButton.

QProgressBar.

QTextEdit.

QGroupBox.

## FUNCIONALIDAD DEL SISTEMA:

El usuario ingresa el nombre del jugador, el nombre del rival y selecciona un grado de dificultad.

Luego presiona el boton iniciar combate.

El programa genera una pregunta matematica segun el grado seleccionado.

Si responde correctamente ataca al rival.

Si responde incorrectamente recibe daño.

Si consigue tres respuestas correctas seguidas realiza un golpe doble.

El combate termina cuando la vida de uno de los jugadores llega a cero.

## CAMBIOS EN EL CODIGO:

Se agregaron los archivos:

mainwindow.h
mainwindow.cpp
mainwindow.ui
CMakeLists.txt

La clase MainWindow se encarga de controlar la interfaz grafica y el combate.

Tambien se agregaron funciones en la clase Pregunta para verificar las respuestas desde Qt sin utilizar la consola.

virtual int cantidadRespuestas() const;
virtual bool verificarRespuestas(float respuesta1, float respuesta2 = 0.0f) const;
COMPILACION:

El proyecto se compila desde Qt Creator utilizando CMake.

Para ejecutar el proyecto se debe abrir el archivo CMakeLists.txt, seleccionar el kit de Qt, configurar el proyecto y presionar Run.

## Evidencia de avances en hito 3
![interfaz](image.png)
