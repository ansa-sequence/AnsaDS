cmake_minimum_required(VERSION 3.20)
project(AnsaDS-Tests)

set(CMAKE_TOOLCHAIN_FILE "E:\\Utils\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")
set(CMAKE_PREFIX_PATH "E:\\Utils\\vcpkg\\installed\\x64-windows")
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(AnsaDS-Tests
        BinaryTreeTest.cpp
        HeapTests.cpp
        VectorTests.cpp
        LinkedListTests.cpp
        MathTests.cpp
        PriorityQueueTests.cpp
        SearchingTests.cpp
        StackTest.cpp
        SetTests.cpp
        SortTests.cpp
)

include(GoogleTest)
target_link_libraries(AnsaDS-Tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
gtest_discover_tests(${PROJECT_NAME})
#set_tests_properties(AnsaDS-Tests PROPERTIES WORKING_DIRECTORY $<TARGET_FILE_DIR:AnsaDS-Tests>)
#add_test(AllTestsInMain AnsaDS-Tests)
