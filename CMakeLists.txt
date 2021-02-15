# CMAKE version of Ubuntu 16.04 is 3.5.
cmake_minimum_required(VERSION 3.5)
project(test)

set(SRC)
set(INCL)
set(LINKLIBS)
set(COMPILE_OPTION)

list(APPEND SRC
	test.cpp
	json.hpp
	Config.h
	jsonConfig.h
  )
list(APPEND INCL
	.
  )
list(APPEND LINKLIBS
  )
list(APPEND COMPILE_OPTION
  )

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME}    PRIVATE    ${INCL}  )
target_link_libraries(${PROJECT_NAME} ${LINKLIBS})
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTION} )
set_target_properties(${PROJECT_NAME} PROPERTIES  CXX_STANDARD 17 )