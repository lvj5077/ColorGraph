ADD_LIBRARY( utilities utilities.cpp )

ADD_LIBRARY( colorGraph colorGraph.cpp )
TARGET_LINK_LIBRARIES( colorGraph utilities)

ADD_EXECUTABLE( main main.cpp )
TARGET_LINK_LIBRARIES( main colorGraph utilities)

ADD_EXECUTABLE( test test.cpp )
TARGET_LINK_LIBRARIES( test colorGraph utilities)

ADD_EXECUTABLE( input input.cpp )
TARGET_LINK_LIBRARIES( input)

ADD_EXECUTABLE( test2 test2.cpp )
TARGET_LINK_LIBRARIES( test2 colorGraph utilities)