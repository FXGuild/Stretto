cmake_minimum_required(VERSION 3.6)

# Set MSVC project name based on current directory name
get_filename_component(MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME PARENT_SCOPE)
message("Processing ${MODULE_NAME} project")

# Gather project headers
file(GLOB HEADER_FILES "${CMAKE_SOURCE_DIR}/Include/FXG/Stretto/${MODULE_NAME}/*.h")
source_group("Header Files" FILES ${HEADER_FILES})

# Gather project source
file(GLOB SOURCE_FILES "Source/*.cpp")
source_group("Source Files" FILES ${SOURCE_FILES})
	
# Create static library MSVC project
add_library(${MODULE_NAME} ${HEADER_FILES} ${SOURCE_FILES})

# Add include directory
include_directories("${CMAKE_SOURCE_DIR}/Include")
