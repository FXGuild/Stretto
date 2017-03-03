cmake_minimum_required(VERSION 3.6)

# Set MSVC project name based on current directory name
get_filename_component(MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME PARENT_SCOPE)
message("Processing Stretto-${MODULE_NAME} project")

# Gather project source
file(GLOB SOURCE_FILES "Source/*.cpp")
source_group("Source Files" FILES ${SOURCE_FILES})

# Create static library MSVC project
add_executable(${MODULE_NAME} ${SOURCE_FILES})
set_target_properties(${MODULE_NAME} PROPERTIES FOLDER Stretto)

# Set command line system
SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES LINK_FLAGS -SUBSYSTEM:CONSOLE)

# Add include directory
include_directories("${gtest_SOURCE_DIR}/include")
include_directories("${CMAKE_SOURCE_DIR}/Include")

# Add dependant libraries
target_link_libraries(${MODULE_NAME} gtest_main)
target_link_libraries(${MODULE_NAME} Piece)
target_link_libraries(${MODULE_NAME} Theory)