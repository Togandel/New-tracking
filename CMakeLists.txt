#CmakeList pour projet opencv

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project ("Projet")

add_executable (Projet 
	       main.cpp
	       traitement.cpp
	       trackedPoint.cpp


)

set(EXECUTABLE_OUTPUT_PATH bin)


find_package(	OpenCV
		REQUIRED
)


link_directories(${OpenCV_LIBRARY_DIRS})
include_directories(${OpenCV_INCLUDE_DIR} include)
target_link_libraries(Projet ${OpenCV_LIBRARIES})






	       
