# la version de cmake à utiliser
cmake_minimum_required(VERSION 3.10)

# La version du C++ que l'on souhaite utiliser (dans notre cas C++17)
set(CMAKE_CXX_STANDARD 17)

# Le nom du projet
project(IMAC_project)

# On souhaite placer l'exécutable dans un sous-dossier "bin" au lieu de le mettre dans le dossier build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# On indique que l'on souhaite faire un exécutable avec nos deux fichiers .cpp
add_executable(Projet "src/Player.cpp" "src/main.cpp")

# le dossier contenant les fichiers d'en-tête pour notre executable helloImac
target_include_directories(Projet PUBLIC "src/")