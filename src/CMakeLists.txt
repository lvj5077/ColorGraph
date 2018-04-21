ADD_LIBRARY( utilities utilities.cpp )

ADD_LIBRARY( colorGraph colorGraph.cpp )
TARGET_LINK_LIBRARIES( colorGraph utilities)

ADD_EXECUTABLE( main main.cpp )
TARGET_LINK_LIBRARIES( main colorGraph utilities)

ADD_EXECUTABLE( test test.cpp )
TARGET_LINK_LIBRARIES( test colorGraph utilities)