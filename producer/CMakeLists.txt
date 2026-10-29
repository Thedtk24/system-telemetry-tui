add_executable(producer main.cpp SystemSimulator.cpp SystemSimulator.hpp)

target_link_libraries(producer PRIVATE common)