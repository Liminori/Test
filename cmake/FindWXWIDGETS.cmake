#
# Try to find WXWIDGETS library and include path.
# Once done this will define
#
# WXWIDGETS_FOUND
# WXWIDGETS_INCLUDE_PATH
# WXWIDGETS_LIBRARY
# 

if (MINGW)
    FIND_PATH( WXWIDGETS_INCLUDE_PATH wx/wxprec.h
        ${DEPENDENCIES_PATH}/wxwidgets/include
    )

    FIND_LIBRARY( WXWIDGETS_LIBRARY
        NAMES libwxbase30u 
        PATHS
        ${DEPENDENCIES_PATH}/wxwidgets/lib/gcc_dll
    )
	
	FIND_LIBRARY( WXWIDGETS_LIBRARY_2
        NAMES libwxmsw30u 
        PATHS
        ${DEPENDENCIES_PATH}/wxwidgets/lib/gcc_dll
    )
	
	
	INSTALL(
		DIRECTORY ${DEPENDENCIES_PATH}/wxwidgets/lib/gcc_dll
		DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
		FILES_MATCHING PATTERN "*.dll"
	)

elseif (MSVC)
    FIND_PATH( WXWIDGETS_INCLUDE_PATH wx/wxprec.h
        ${DEPENDENCIES_PATH}/wxwidgets/include
    )
	
    FIND_LIBRARY( WXWIDGETS_LIBRARY
        NAMES wxbase30u_gcc_custom wxmsw30u_aui_gcc_custom
        PATHS
        ${DEPENDENCIES_PATH}/wxwidgets/lib/gcc_dll
    )
	
	INSTALL(
		DIRECTORY ${DEPENDENCIES_PATH}/wxwidgets/lib/gcc_dll
		DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
		FILES_MATCHING PATTERN "*.dll"
	)
	
elseif(UNIX)
    FIND_PATH( WXWIDGETS_INCLUDE_PATH wx/wxprec.h
        ${DEPENDENCIES_PATH}/wxwidgets/include
    )

    #FIND_LIBRARY( WXWIDGETS_LIBRARY
        #NAMES WXWIDGETS
        #PATHS
        #${DEPENDENCIES_PATH}/WXWIDGETS/unix/lib/static
   #)
	
	#INSTALL(
		#DIRECTORY ${DEPENDENCIES_PATH}/WXWIDGETS/unix/bin/
		#DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
		#FILES_MATCHING PATTERN "*.dll"
	#)

else()

    FIND_PATH(WXWIDGETS_INCLUDE_PATH wx/wxprec.h)
    FIND_LIBRARY(WXWIDGETS_LIBRARY
        NAMES WXWIDGETS
    PATH_SUFFIXES dynamic)

endif ()



SET(WXWIDGETS_FOUND "NO")
if (WXWIDGETS_INCLUDE_PATH AND WXWIDGETS_LIBRARY)
	SET(WXWIDGETS_LIBRARIES ${WXWIDGETS_LIBRARY})
	SET(WXWIDGETS_FOUND "YES")
    message("EXTERNAL LIBRARY 'WXWIDGETS' FOUND")
    message("WXWIDGETS_LIBRARY: " ${WXWIDGETS_LIBRARY})
    message("WXWIDGETS_INCLUDE_PATH: " ${WXWIDGETS_INCLUDE_PATH})
else()
    message(SEND_ERROR "ERROR: EXTERNAL LIBRARY 'WXWIDGETS' NOT FOUND")
endif (WXWIDGETS_INCLUDE_PATH AND WXWIDGETS_LIBRARY)
