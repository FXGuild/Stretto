cmake_minimum_required(VERSION 3.6)

# Add CMake module directory
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake ${CMAKE_MODULE_PATH})

# Import modules
include(GetGitRevisionDescription)
include(CollectJuceFiles)

# Get current version from git
git_describe(VERSION --tags --dirty=-dirty)
string(REGEX REPLACE "^v([0-9]+)\\..*"                        "\\1" VERSION_MAJOR    "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*"                  "\\1" VERSION_MINOR    "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.([0-9]+).*"         "\\1" VERSION_PATCH    "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.[0-9]+-([0-9]+).*"  "\\1" VERSION_REVISION "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.[0-9]+-[0-9]+-(.*)" "\\1" VERSION_SHA1     "${VERSION}")

# Create version number (X.X.X)
set(VERSION_SHORT "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# Append revision number if there is one (X.X.X.Y)
if (NOT ${VERSION_REVISION} MATCHES ${VERSION_SHA1})
    set(VERSION_SHORT "${VERSION_SHORT}.${VERSION_REVISION}")
endif()

# Create MSCVC solution
project(Stretto)

#Use solution folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Set Juce lib include directory
set(JUCE_LIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/../ThirdParty/JUCE/modules)

# Only keep Debug and Release configs
if(CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_CONFIGURATION_TYPES Debug Release)
	set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING "Reset the configurations to what we need" FORCE)
endif()

# Set solution flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std:c++latest")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -D_NDEBUG")
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG ${CMAKE_SHARED_LINKER_FLAGS_DEBUG} " /NODEFAULTLIB:\"libcmt.lib\" /NODEFAULTLIB:\"msvcrt.lib\"")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG ${CMAKE_EXE_LINKER_FLAGS_DEBUG} " /NODEFAULTLIB:\"libcmt.lib\" /NODEFAULTLIB:\"msvcrt.lib\"")
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} " /SUBSYSTEM:WINDOWS")

# Download and unpack googletest at configure time
configure_file(Projects/UnitTests/CMakeLists.txt.in ${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . RESULT_VARIABLE result WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build . RESULT_VARIABLE result WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Tell Google Test that were have at least C++11
add_definitions(-D GTEST_LANG_CXX11)
    
# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)
set_target_properties(gmock      PROPERTIES FOLDER GoogleTest)
set_target_properties(gmock_main PROPERTIES FOLDER GoogleTest)
set_target_properties(gtest      PROPERTIES FOLDER GoogleTest)
set_target_properties(gtest_main PROPERTIES FOLDER GoogleTest)
                 
# Create projects
add_subdirectory(Projects)