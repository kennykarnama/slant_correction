
cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(slant_correction)

find_package( 

OpenCV REQUIRED 
)

FIND_PACKAGE( Boost 1.67 COMPONENTS program_options REQUIRED )





include_directories(
header
/usr/local/include
/usr/include
library
/usr/local
)

add_executable(
	slant_correction
	source/main.cpp
	source/projection.cpp
	source/slant.cpp
	source/descriptive_stats.cpp
	source/help.cpp

)

LINK_DIRECTORIES(
/user/local/lib
/usr/lib
/usr/local
)

target_link_libraries( slant_correction ${OpenCV_LIBS} ${Boost_LIBRARIES} -lboost_random -lboost_filesystem -lboost_system -O2 -larmadillo -llapack -lblas -lpthread -lmysqlcppconn -lfann)

