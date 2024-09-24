add_subdirectory("submodule")

add_library("${CMAKE_PROJECT_NAME}_lib"
    "app.cpp"
    "returns_true.cpp"
)

target_link_libraries("${CMAKE_PROJECT_NAME}_lib" PRIVATE submodule)
target_link_libraries("${CMAKE_PROJECT_NAME}_lib" PRIVATE nlohmann_json trielo)

# Create the test executable
add_executable("${CMAKE_PROJECT_NAME}_tests" test/test_top.cpp)  # Your test file(s)

# Link the GoogleTest libraries
target_link_libraries("${CMAKE_PROJECT_NAME}_tests" gtest gtest_main)

# Link your project library (if you are testing your own code)
target_link_libraries("${CMAKE_PROJECT_NAME}_tests" "${CMAKE_PROJECT_NAME}_lib")

# Add the test to CTest
add_test(NAME "${CMAKE_PROJECT_NAME}_tests" COMMAND "${CMAKE_PROJECT_NAME}_tests")

add_executable(${CMAKE_PROJECT_NAME} "main.cpp")
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_PROJECT_NAME}_lib")