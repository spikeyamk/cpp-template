cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
project("cpp-template" C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory("deps")
add_subdirectory("src")

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
    elseif(MSVC)
        target_compile_options(${PROJECT_NAME} PRIVATE /W4)
    endif()
endif()

# Find Doxygen
find_package(Doxygen REQUIRED)

# Set the path for the Doxyfile.in template and the generated Doxyfile
set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/docs/Doxyfile)

# Check if Doxygen was found
if (DOXYGEN_FOUND)
    # Create the docs directory in the binary folder if it doesn't exist
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs)

    # Configure the Doxyfile.in template
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # Add a custom target to run Doxygen when 'make doc' is called
    add_custom_target(doc_doxygen
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
else ()
    message(WARNING "Doxygen not found. Documentation will not be generated.")
endif ()