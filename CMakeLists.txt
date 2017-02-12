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

# Set Juce lib include directory
set(JUCE_LIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/../ThirdParty/JUCE/modules)

# Only keep Debug and Release configs
if(CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_CONFIGURATION_TYPES Debug Release)
	set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING "Reset the configurations to what we need" FORCE)
endif()

# Set solution flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -D_NDEBUG")
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG ${CMAKE_SHARED_LINKER_FLAGS_DEBUG} " /NODEFAULTLIB:\"libcmt.lib\" /NODEFAULTLIB:\"msvcrt.lib\"")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG ${CMAKE_EXE_LINKER_FLAGS_DEBUG} " /NODEFAULTLIB:\"libcmt.lib\" /NODEFAULTLIB:\"msvcrt.lib\"")
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} " /SUBSYSTEM:WINDOWS")

# Create projects
add_subdirectory(Projects)