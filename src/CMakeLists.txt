# 1. Define the Library
# This command compiles all your HNSW source files into a single library
# target named "mdlex_lib".
add_library(mdlex_lib
        distance.cpp
        hnsw.cpp
        Graph.cpp
        VectorData.cpp
)

# This crucial line makes the header files visible. It tells CMake that
# any project linking against "mdlex_lib" should have the current
# directory (src) added to its include path. This is how main.cpp will
# find "#include "hnsw.h"".
target_include_directories(mdlex_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 2. Define the Executable
# This command creates an executable named "main_app" from main.cpp.
add_executable(main_app main.cpp)

# 3. Link Them Together
# This links your executable against your library, making all the HNSW
# code available to use in main.cpp.
target_link_libraries(main_app PRIVATE mdlex_lib)