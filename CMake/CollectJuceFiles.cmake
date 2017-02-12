cmake_minimum_required(VERSION 3.6)

if(__collect_juce_files)
	return()
endif()
set(__collect_juce_files YES)

set(JUCE_PROJUCER_PROGRAM_PATH "${CMAKE_SOURCE_DIR}/../ThirdParty/JUCE/Projucer.exe" CACHE FILEPATH "Path of Projucer executable")
set(JUCE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../ThirdParty/JUCE/modules" CACHE FILEPATH "Path of JUCE module root directory")

if(NOT EXISTS ${JUCE_PROJUCER_PROGRAM_PATH})
   message(FATAL_ERROR "Cannot find ${JUCE_PROJUCER_PROGRAM_PATH} - required to build from .jucer projects")
endif()

function(collect_juce_files _prjName _sourcedirvar _outputvariable)
	
	set(JUCE_PROJECT_NAME ${_prjName})
	set(JUCE_PROJECT_VERSION ${VERSION_SHORT})
	if (NOT JUCE_BUNDLE_IDENTIFIER)
		set(JUCE_BUNDLE_IDENTIFIER "com.${JUCE_PROJECT_NAME}")
	endif()
	
	message("Collecting JUCE files for '${_sourcedirvar}'")
	
	file(GLOB PROJUCER_PROJECT_LIST "*.jucer")
	list(LENGTH PROJUCER_PROJECT_LIST PROJUCER_PROJECTS_COUNT)

	if (NOT ${PROJUCER_PROJECTS_COUNT} EQUAL 1)
		message(FATAL_ERROR "Failed to collect JUCE files, directory must contain exactly one .jucer file")
	endif()
	
	list(GET PROJUCER_PROJECT_LIST 0 PROJUCER_PROJECT)
	
	message("Found Projucer project '${PROJUCER_PROJECT}'.")

	message("Configuring Projucer project")
	get_filename_component(PROJUCER_PROJECT_FILENAME ${PROJUCER_PROJECT} NAME)
	
	set(PROJUCER_PROJECT_CONFIGURED "${CMAKE_CURRENT_BINARY_DIR}/ProjucerFiles/${PROJUCER_PROJECT_FILENAME}")
	
	configure_file(${PROJUCER_PROJECT} ${PROJUCER_PROJECT_CONFIGURED})
	get_filename_component(PROJUCER_PROJECT_CONFIGURED_DIR ${PROJUCER_PROJECT_CONFIGURED} DIRECTORY)
	
	message("Resaving Projucer project")
	
	execute_process(COMMAND ${JUCE_PROJUCER_PROGRAM_PATH} --resave ${PROJUCER_PROJECT_CONFIGURED})
	
	if (NOT EXISTS ${PROJUCER_PROJECT_CONFIGURED_DIR}/JuceLibraryCode OR NOT EXISTS ${PROJUCER_PROJECT_CONFIGURED_DIR}/Builds)
		message(FATAL_ERROR "Failed to resave projucer project '${PROJUCER_PROJECT}'")
	endif()
	
	message("Project resave successful")

	file(GLOB JUCE_SOURCE_FILES 
		"${PROJUCER_PROJECT_CONFIGURED_DIR}/JuceLibraryCode/*.h"
		"${PROJUCER_PROJECT_CONFIGURED_DIR}/JuceLibraryCode/BinaryData.cpp")

	set(JUCE_RESOURCE_FILES "")
		
	file(GLOB JUCE_RESOURCE_FILES
		"${PROJUCER_PROJECT_CONFIGURED_DIR}/Builds/VisualStudio2015/resources.rc"
		"${PROJUCER_PROJECT_CONFIGURED_DIR}/Builds/VisualStudio2015/icon.ico")

	set(JUCE_FILES ${JUCE_SOURCE_FILES} ${JUCE_RESOURCE_FILES})
	
	set(${_outputvariable} ${JUCE_FILES} PARENT_SCOPE)
	set(PROJUCER_FILES_DIR ${PROJUCER_PROJECT_CONFIGURED_DIR} PARENT_SCOPE)
	
endfunction()




