#!/bin/bash

# Verifica si se pasó el nombre del archivo como argumento
if [ "$#" -ne 1 ]; then
    echo "Uso: $0 <nombre_del_programa_sin_extension>"
    exit 1
fi

# Asigna el primer argumento a una variable
PROGRAM_NAME=$1

# Define la ruta de la carpeta Compilados relativa al directorio donde se ejecuta el script
# Asegúrate de que esta ruta sea correcta respecto a la ubicación desde donde ejecutas el script
COMPILE_DIR="./Compilados"

# Compila el programa con mpicc y coloca el ejecutable en la carpeta Compilados
mpicc -o "${COMPILE_DIR}/${PROGRAM_NAME}" "${PROGRAM_NAME}.c" -I/opt/homebrew/include -L/opt/homebrew/lib -lmpi

# Verifica si la compilación fue exitosa
if [ $? -eq 0 ]; then
    # Ejecuta el programa con 3 procesos desde la carpeta Compilados
    mpiexec -np 3 "${COMPILE_DIR}/${PROGRAM_NAME}"
else
    echo "La compilación falló."
fi
