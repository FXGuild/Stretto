cmake_minimum_required(VERSION 3.6)

# Set MSVC project name based on current directory name
get_filename_component(MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME PARENT_SCOPE)
message("Processing ${MODULE_NAME} project")
 
# Gather Juce headers
collect_juce_files("Stretto.${MODULE_NAME}" ${CMAKE_CURRENT_SOURCE_DIR} JUCE_FILES)
source_group("JUCE Files" FILES ${JUCE_FILES})

# Gather project headers
file(GLOB HEADER_FILES "Include/FXG/Stretto/GUI/Internal/*.h")
source_group("Header Files" FILES ${HEADER_FILES})

# Gather project source
file(GLOB SOURCE_FILES "Source/*.cpp")
source_group("Source Files" FILES ${SOURCE_FILES})

# Create MSVC executable
add_executable(${MODULE_NAME} ${JUCE_FILES} ${HEADER_FILES} ${SOURCE_FILES})

# Add dependecies
target_link_libraries(${MODULE_NAME} Juce)
target_link_libraries(${MODULE_NAME} Theory)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/Include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/ProjucerFiles/JuceLibraryCode)