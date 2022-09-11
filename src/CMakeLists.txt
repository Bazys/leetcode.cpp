aux_source_directory(. EXECUTABLE)
include_directories(${CMAKE_SOURCE_DIR}/include)

foreach (T_FILE_NAME ${EXECUTABLE})
    string(REGEX REPLACE ".cpp" "" EXECUTABLE_NAME ${T_FILE_NAME})
    string(REGEX REPLACE "\\.\\/[0-9]+\\." "" EXECUTABLE_NAME ${EXECUTABLE_NAME})
    add_executable(${EXECUTABLE_NAME} ${T_FILE_NAME})
    target_link_libraries(
            ${EXECUTABLE_NAME}
            PRIVATE
            leetcode
            ${CMAKE_THREAD_LIBS_INIT}
            gtest_main
    )
    include(GoogleTest)
    gtest_discover_tests(${EXECUTABLE_NAME})
endforeach ()
