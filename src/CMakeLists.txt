# SET("OpenCV_DIR" "/home/jin/Packages/opencv-2.4.13/build")
# FIND_PACKAGE( OpenCV REQUIRED )
# include_directories(/usr/include/eigen3)


# ADD_LIBRARY( imageOperators imageOperators.cpp )

# ADD_EXECUTABLE( main main.cpp )
# TARGET_LINK_LIBRARIES( main )

# ADD_EXECUTABLE( undirect undirect.cpp )
# TARGET_LINK_LIBRARIES( undirect )

ADD_EXECUTABLE( input input.cpp )
TARGET_LINK_LIBRARIES( input )

ADD_EXECUTABLE( pss pss.cpp )
TARGET_LINK_LIBRARIES( pss )

ADD_EXECUTABLE( testMatrix testMatrix.cpp )
TARGET_LINK_LIBRARIES( testMatrix )

ADD_EXECUTABLE( colorGraph colorGraph.cpp )
TARGET_LINK_LIBRARIES( colorGraph )