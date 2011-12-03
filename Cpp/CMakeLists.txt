project( pantillaCpp )
cmake_minimum_required(VERSION 2.8)

include_directories( ${CMAKE_BINARY_DIR} )

# Diviciones que puede contener el proyecto
set(DIVS "conf" "dep" "mod" "plug")

foreach(it ${DIVS})
    message("-> Buscando archivos ${it}")
    file(GLOB_RECURSE MODULOS "*_${it}.cmake")
    foreach(jt ${MODULOS})
        message(STATUS "Módulo: ${jt} encontrado")
        include(${jt})
    endforeach(jt)
endforeach(it)

# Opcional. Solo para la construcción del instalador
#           para Microsoft Windows.
include(CPack)
