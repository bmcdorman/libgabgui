project(gabgui)
cmake_minimum_required(VERSION 2.8)

enable_testing()

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)
set(UI_DIR ${CMAKE_SOURCE_DIR}/ui)
set(QRC_DIR ${CMAKE_SOURCE_DIR}/rc)

################
# Gather files #
################

file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)

file(GLOB UIS ${UI_DIR}/*.ui)
file(GLOB QRCS ${RC_DIR}/*.qrc)

######
# Qt #
######

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

file(GLOB MOC_INCLUDES ${INCLUDE_DIR}/${CMAKE_PROJECT_NAME}/*.hpp)

qt5_wrap_ui(SOURCES ${UIS})
qt5_wrap_cpp(SOURCES ${MOC_INCLUDES})

###########
# Library #
###########

include_directories(${INCLUDE_DIR})

add_library(gabgui SHARED ${SOURCES})
target_link_libraries(gabgui gab)
qt5_use_modules(gabgui Widgets)

add_subdirectory(${TEST_DIR})

install(TARGETS gabgui LIBRARY DESTINATION lib)
install(DIRECTORY ${INCLUDE_DIR}/gabgui DESTINATION include)
