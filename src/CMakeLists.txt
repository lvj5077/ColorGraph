ADD_LIBRARY( colorGraph colorGraph.cpp )
ADD_LIBRARY( utilities utilities.cpp )

ADD_EXECUTABLE( main main.cpp )
TARGET_LINK_LIBRARIES( main colorGraph utilities)