cmake_minimum_required(VERSION 2.8)

project( examples )

find_package( OpenCV REQUIRED )
find_package( OpenGL )

if(OPENGL_FOUND)
  include_directories( ${OpenCV_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} )
else()
  include_directories( ${OpenCV_INCLUDE_DIRS} )
endif()

#########################
# FOR LEARNING OPENCV 3 #
#########################

###############
### COMPILE ###
###############

# COMPILE EXAMPLES
add_executable( test test.cpp )


# Can only build if you have Qt installed add_executable( example_09-05 example_09-05.cpp )



# NOW COMPILE SOME ANSWERS TO EXERCISES:

################
###   LINK   ###
################
# FIRST LINK EXAMPLES:
target_link_libraries(test ${OpenCV_LIBS} )

# Need Qt target_link_libraries( example_09-05 ${OpenCV_LIBS} )



# NOW LINK EXERCISES 

