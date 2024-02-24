project(dessin)
cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wpedantic)
endif()

find_package(BISON)
find_package(FLEX)


include_directories(parser expressions figures attributs couleur ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB EXPRESSION_HEADERS
    expressions/contexte.hh
    expressions/expression.hh
    expressions/expressionBinaire.hh
    expressions/expressionUnaire.hh
    expressions/expressionTernaire.hh
    expressions/constante.hh
    expressions/variable.hh
    )


add_library(expressions
    expressions/contexte.cc
    expressions/expressionBinaire.cc
    expressions/expressionUnaire.cc
    expressions/expressionTernaire.cc
    expressions/constante.cc
    expressions/variable.cc
    ${EXPRESSION_HEADERS}
    )

file(GLOB FIGURE_HEADERS
    figures/forme.hh
    figures/rectangle.hh
    figures/ligne.hh
    figures/chemin.hh
    figures/formeSimpleCoord.hh
    figures/carre.hh
    figures/triangle.hh
    figures/cercle.hh
    figures/ellipse.hh
    figures/texte.hh
    figures/contexte_forme.hh
    figures/couleur.hh
    )

add_library(figures
    figures/forme.cc
    figures/rectangle.cc
    figures/ligne.cc
    figures/chemin.cc
    figures/formeSimpleCoord.cc
    figures/carre.cc
    figures/triangle.cc
    figures/cercle.cc
    figures/ellipse.cc
    figures/texte.cc
    figures/contexte_forme.cc
    ${FIGURE_HEADERS}
    )

file(GLOB ATTRIBUT_HEADERS
    attributs/attribut.hh
    attributs/attributCouleur.hh
    attributs/attributInt.hh
    attributs/stroke.hh
    attributs/fill.hh
    attributs/epaisseur.hh
    attributs/opacite.hh
    attributs/rotation.hh
    )


add_library(attributs
    attributs/attributCouleur.cc
    attributs/attributInt.cc
    attributs/stroke.cc
    attributs/fill.cc
    attributs/epaisseur.cc
    attributs/opacite.cc
    attributs/rotation.cc
    ${ATTRIBUT_HEADERS}
    )

file(GLOB COULEUR_HEADERS
    couleur/couleur.hh
    couleur/couleur_hex.hh
    couleur/couleur_nom.hh
    couleur/couleur_rgb.hh
    )


add_library(couleur
    couleur/couleur.cc
    couleur/couleur_hex.cc
    couleur/couleur_nom.cc
    couleur/couleur_rgb.cc
    ${COULEUR_HEADERS}
    )

BISON_TARGET(parser parser/parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp VERBOSE ${CMAKE_CURRENT_BINARY_DIR}/automate.txt)
FLEX_TARGET(scanner parser/scanner.ll  ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
ADD_FLEX_BISON_DEPENDENCY(scanner parser)
add_executable(${PROJECT_NAME}
    parser/main.cc
    parser/driver.hh
    parser/driver.cc
    parser/scanner.hh
    parser/scanner.ll
    parser/parser.yy
    ${BISON_parser_OUTPUTS}
    ${FLEX_scanner_OUTPUTS}
)
target_link_libraries(${PROJECT_NAME} expressions figures attributs couleur)

target_link_libraries(expressions figures attributs couleur)
