# Versión de CMake, campo requerido
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(Ej_1)

# Definir el estandar de C++
set(CMAKE_CXX_STANDARD 17)

# Activar todos los warnings
add_compile_options(-Wall -Wextra -pedantic)

# Los archivos fuente todos juntos
file(GLOB SOURCES "srcs/*.cpp" "examples/main.cpp")

# Crear el ejecutable
add_executable(EJ1 ${SOURCES})

# Indica los directorios de las librerías y headers
target_include_directories(EJ1 PRIVATE
${CMAKE_SOURCE_DIR}/headers)

# Especifica la carpeta donde se creará el ejecutable
set_target_properties(EJ1 PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
