# Creating the static library
file(
     GLOB EXAMPLES_SOURCES
     *.cpp
)

foreach(example_source ${EXAMPLES_SOURCES})
    get_filename_component(example_name ${example_source} NAME_WE)
    add_executable(${example_name} ${example_source})
    set_target_properties(${example_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")
endforeach()