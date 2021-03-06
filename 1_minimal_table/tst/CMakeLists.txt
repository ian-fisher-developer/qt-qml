project(minimal_table_tests LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui)

qt_add_executable(minimal_table_tests
    ../src/MinimalTableModel.cpp
    ../src/MinimalTableModel.h
    MinimalTableModelTests.cpp
)

set_target_properties(minimal_table_tests PROPERTIES
    MACOSX_BUNDLE TRUE
)

target_link_libraries(minimal_table_tests PUBLIC
    Qt::Core
    Qt::Gui
    gtest_main
)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include(GoogleTest)
gtest_discover_tests(minimal_table_tests)
