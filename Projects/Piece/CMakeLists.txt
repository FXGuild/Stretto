cmake_minimum_required(VERSION 3.6)

# Set MSVC project name based on current directory name
get_filename_component(MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME PARENT_SCOPE)
message("Processing ${MODULE_NAME} project")

# Gather Juce headers
collect_juce_files("Stretto.${MODULE_NAME}" ${CMAKE_CURRENT_SOURCE_DIR} JUCE_FILES)
source_group("JUCE Files" FILES ${JUCE_FILES})

# Gather project headers
file(GLOB HEADER_FILES "${CMAKE_SOURCE_DIR}/Include/FXG/Stretto/${MODULE_NAME}/*.h")
source_group("Header Files" FILES ${HEADER_FILES})

# Gather project source
file(GLOB SOURCE_FILES "Source/*.cpp")
source_group("Source Files" FILES ${SOURCE_FILES})
	
# Create static library MSVC project
add_library(${MODULE_NAME} ${JUCE_FILES} ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(${MODULE_NAME} PROPERTIES FOLDER Stretto)

# Add dependencies
target_link_libraries(${MODULE_NAME} Juce)
target_link_libraries(${MODULE_NAME} Utils)

# Add include directory
include_directories("${CMAKE_SOURCE_DIR}/Include")
include_directories(${CMAKE_CURRENT_BINARY_DIR}/ProjucerFiles/JuceLibraryCode)

