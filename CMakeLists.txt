PROJECT (smprintf)

include_directories (src)

add_library (smprintf src/smprintf.cpp)

add_executable (test-smprintf test/test.cpp)
target_link_libraries (test-smprintf smprintf)
