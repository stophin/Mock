cmake_minimum_required(VERSION 3.15)
project(GtestLearnLLT)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11 -lpthread -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCONFIG_LLT -fprofile-arcs -ftest-coverage")
set(THIRD_PARTY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty)
set(GOOGLETEST_PATH googletest-release-1.8.0)
set(MOCKCPP_PATH mockcpp-master)
link_directories(${THIRD_PARTY_PATH}/${MOCKCPP_PATH}/mockcpp/build/src
                ${THIRD_PARTY_PATH}/${GOOGLETEST_PATH}/build/googlemock
                ${THIRD_PARTY_PATH}/${GOOGLETEST_PATH}/build/googlemock/gtest)

#${THIRD_PARTY_PATH}/googletest/
include_directories(${THIRD_PARTY_PATH}/${GOOGLETEST_PATH}/googlemock/include/
        ${THIRD_PARTY_PATH}/${GOOGLETEST_PATH}/googletest/include/
        ${THIRD_PARTY_PATH}/${MOCKCPP_PATH}/mockcpp/include/
        ${THIRD_PARTY_PATH}/${MOCKCPP_PATH}/mockcpp/3rdparty/
        ${THIRD_PARTY_PATH}/${GOOGLETEST_PATH}/googlemock/
        ${CMAKE_CURRENT_SOURCE_DIR}/../include/
        ${CMAKE_CURRENT_SOURCE_DIR}/stubs/)

#${THIRD_PARTY_PATH}/googletest/src/gtest-all.cc
set(SRC_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/func.c
        #${CMAKE_CURRENT_SOURCE_DIR}/../src/main.c
        ${CMAKE_CURRENT_SOURCE_DIR}/stubs/my_stubs.c
        ${THIRD_PARTY_PATH}/${GOOGLETEST_PATH}/googlemock/src/gmock-all.cc
        src/gtest_ut.cpp
        src/main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_executable(GtestLearnLLT ${SRC_FILES})
target_link_libraries(GtestLearnLLT libmockcpp.a libgmock.a libgtest.a)


add_custom_target(run DEPENDS GtestLearnLLT)
add_custom_command(TARGET run
PRE_BUILD 
COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/GtestLearnLLT.exe)








