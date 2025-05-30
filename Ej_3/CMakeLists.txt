# Versión de CMake, campo requerido
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(Ej_3)

# Definir el estandar de C++
set(CMAKE_CXX_STANDARD 17)

# Activar todos los warnings
add_compile_options(-Wall -Wextra -pedantic)

# Los archivos fuente todos juntos
file(GLOB SOURCES "srcs/*.cpp" "examples/main.cpp")

# Crear el ejecutable
add_executable(EJ3 ${SOURCES})

# Indica los directorios de las librerías y headers
target_include_directories(EJ3 PRIVATE
${CMAKE_SOURCE_DIR}/include)

# Especifica la carpeta donde se creará el ejecutable
set_target_properties(EJ3 PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
