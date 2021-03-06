# The MIT License (MIT)
#
# Copyright (c) 2015 Yu Jing <yu@argcv.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
PROJECT(argcv_seed)
# REQUIRE
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

# some useful variables  http://www.cmake.org/Wiki/CMake_Useful_Variables

#SET(CMAKE_INSTALL_PREFIX $ENV{HOME}/.local/)
SET(GLO_VERSION_MAJOR 0)
SET(GLO_VERSION_MINOR 0.1)

SET(VERSION 0.1)
SET(CMAKE_INCLUDE_DIRECTORIES_BEFORE on)
SET(CMAKE_INCLUDE_CURRENT_DIR on)
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH on)

SET(CMAKE_MACOSX_RPATH ON)


MESSAGE(STATUS "CMAKE_INSTALL_PREFIX " ${CMAKE_INSTALL_PREFIX})
MESSAGE(STATUS "CMAKE_MACOSX_RPATH " ${CMAKE_MACOSX_RPATH})
MESSAGE(STATUS "BINARY_DIR " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "SOURCE_DIR " ${PROJECT_SOURCE_DIR})

# general flags 
# SET(CMAKE_C_FLAGS "$ENV{CFLAGS}  -Wall -g -ggdb --std=c99 -v")
SET(CMAKE_C_FLAGS "$ENV{CFLAGS}  -Wall -g -ggdb --std=c99")
#SET(CMAKE_CXX_FLAGS " $ENV{CXXFLAGS}  -Wall -g -ggdb --std=c++11")
SET(CMAKE_CXX_FLAGS " $ENV{CXXFLAGS}  -Wall -g -ggdb --std=c++11")
# debug cmake  -DCMAKE_BUILD_TYPE=debug ..
SET(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS}  -Wall -g -ggdb --std=c99")
SET(CMAKE_CXX_FLAGS_DEBUG " $ENV{CXXFLAGS}  -Wall -g -ggdb --std=c++11")
# release cmake  -DCMAKE_BUILD_TYPE=release ..
SET(CMAKE_C_FLAGS_RELEASE " $ENV{CFLAGS}  -Wall  -O3 --std=c99")
SET(CMAKE_CXX_FLAGS_RELEASE " $ENV{CXXFLAGS} -Wall -O3 --std=c++11")

SET (RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")



# there may no need to link system library && system include

# INCLUDE DIRECTORIES
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# LINK DIRECTORIES
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# ADD LIB ARGCV
#SOME OPTIONS USAGE MAY SETTED HERE
#SET(OPTIONS_USE_EXTERNAL_LEVELDB NO)
#OPTION(OPTIONS_USE_EXTERNAL_CURL "OPTIONS_USE_EXTERNAL_CURL" OFF)
ADD_SUBDIRECTORY(lib/argcv)
MESSAGE(STATUS "INCLUDE SEARCH : ARGCV_INCLUDE_DIR " ${ARGCV_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${ARGCV_INCLUDE_DIR})
MESSAGE(STATUS "LINK SEARCH : ARGCV_LIB_DIR " ${ARGCV_LIB_DIR})
LINK_DIRECTORIES(${ARGCV_LIB_DIR})


LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")
LIST(APPEND CMAKE_MODULE_PATH ${ARGCV_CMAKE_MODULE_PATH})

MESSAGE(STATUS "CMAKE_MODULE_PATH " ${CMAKE_MODULE_PATH})

INCLUDE(ExternalProject) # IF NEED EXTEND PROJECT


ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(src)

CONFIGURE_FILE(config.ini ${PROJECT_BINARY_DIR}/config.ini )


#SET(RESOURCE_DIR ${PROJECT_SOURCE_DIR}/res)
# CONFIGURE_FILE(${RSOURCE_DIR}/config.ini ${PROJECT_BINARY_DIR}/config.ini )
# CONFIGURE_FILE(${RSOURCE_DIR}/stopwords.txt ${PROJECT_BINARY_DIR}/stopwords.txt )
#CONFIGURE_FILE(${PROJECT_SOURCE_DIR}/run.sh ${PROJECT_BINARY_DIR}/run.sh )
#CONFIGURE_FILE(${PROJECT_SOURCE_DIR}/config.ini ${PROJECT_BINARY_DIR}/config.ini )

#EXEC_PROGRAM("cp -r ${PROJECT_SOURCE_DIR}/res/dict.db ${PROJECT_BINARY_DIR}")
# FILE  COPY : http://www.cmake.org/cmake/help/v2.8.10/cmake.html#command%3afile
# OLD VERSION , FILE COPY CAN SEE: http://stackoverflow.com/questions/697560/how-to-copy-directory-from-source-tree-to-binary-tree
#FILE(COPY ${PROJECT_SOURCE_DIR}/res/dict.db DESTINATION ${PROJECT_BINARY_DIR})

#ADD_TEST(evolution ${EXECUTABLE_OUTPUT_PATH}/percimpl evo )
#ENABLE_TESTING()



