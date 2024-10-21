cmake_minimum_required (VERSION 3.2)

if (WIN32)
    set(MODELICA_PLATFORM win64)
elseif (APPLE)
    set(MODELICA_PLATFORM darwin64)
else ()
    set(MODELICA_PLATFORM linux64)
endif ()

project (CallbacksImplementation)

set(CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_STANDARD 14)
add_definitions(-UNDEBUG)

add_library(CallbacksImplementation SHARED
    CallbacksImplementation.h
    CallbacksImplementation.cpp
)

target_include_directories(CallbacksImplementation PRIVATE
    ../ModelicaUtilities/Resources/Include
)

install(TARGETS CallbacksImplementation DESTINATION ${CMAKE_SOURCE_DIR}/../ModelicaUtilities/Resources/Library/${MODELICA_PLATFORM})
