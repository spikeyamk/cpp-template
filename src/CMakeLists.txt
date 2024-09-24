add_subdirectory("submodule")

add_executable(${CMAKE_PROJECT_NAME}
    "app.cpp"
    "main.cpp"
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE submodule)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE nlohmann_json trielo)