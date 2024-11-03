set(PLONS_LIBRARY_EXAMPLES
)

function(add_example source executable)
    add_executable(${executable} ${source})
    target_link_libraries(${executable} plons_library)
endfunction()

foreach(example ${PLONS_LIBRARY_EXAMPLES})
    set(example_source "${CMAKE_CURRENT_SOURCE_DIR}/${example}.cpp")
    string(REPLACE "/" "_" example_executable ${example})
    add_example(${example_source} ${example_executable})
endforeach()
