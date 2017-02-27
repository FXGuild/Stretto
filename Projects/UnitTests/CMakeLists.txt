cmake_minimum_required(VERSION 3.6)

# Set MSVC project name based on current directory name
get_filename_component(MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME PARENT_SCOPE)
message("Processing Stretto-${MODULE_NAME} project")

# Gather project source
file(GLOB SOURCE_FILES "Source/*.cpp")
source_group("Source Files" FILES ${SOURCE_FILES})

# Create static library MSVC project
add_library(${MODULE_NAME} ${SOURCE_FILES})
set_target_properties(${MODULE_NAME} PROPERTIES FOLDER Stretto)

# Add include directory
include_directories("${gtest_SOURCE_DIR}/include")
