cmake_minimum_required(VERSION 3.6)

# Gather Juce headers
collect_juce_files("JUCE" ${CMAKE_CURRENT_SOURCE_DIR} JUCE_FILES)

# Gather project source
file(GLOB SOURCE_FILES "${PROJUCER_FILES_DIR}/JuceLibraryCode/*.cpp")

# Create static library MSVC project
add_library(Juce ${JUCE_FILES} ${SOURCE_FILES})

# Add include directory
target_include_directories(Juce PUBLIC ${JUCE_LIB_INCLUDE_DIR})