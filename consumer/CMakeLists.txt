add_executable(consumer main.cpp TerminalUI.cpp TerminalUI.hpp)

target_link_libraries(consumer PRIVATE common)