ADD_SUBDIRECTORY(core)
ADD_SUBDIRECTORY(util)
ADD_SUBDIRECTORY(base)

#ADD_SUBDIRECTORY(ia)
#ADD_SUBDIRECTORY(multiplayer)
#ADD_SUBDIRECTORY(network)
#ADD_SUBDIRECTORY(save)
#ADD_SUBDIRECTORY(ui)

include_directories(
	base/
	core/
)

set(KALIUM_SRC
  kalium.cpp
#  main/HelloWorldScene.cpp
#  main/HelloWorldScene.h
#  main/AppMacros.h
#  main/AppDelegate.h
#  main/AppDelegate.cpp
)

if(WIN32)
	set(KALIUM_WIN32 
	  main/win32/main.cpp
	  main/win32/main.h
	)
	set(KALIUM_LINK
	  libcocos2d
	  glew32
	  glfw3
	  opengl32
	  Ws2_32
	  freetype250
	  libchipmunk
	  libiconv
	  libjpeg
	  libpng
	  libtiff
	  libwebp
	  libzlib
	  websockets  
	  )
elseif(APPLE)
	set(KALIUM_LINK
	  libcocos2d
	  )
else()
	set(KALIUM_ANDROID
	  main/android/main.cpp
	)
endif()


if(WIN32)
	add_executable(
		Kalium
		WIN32
		${KALIUM_SRC}
		${KALIUM_WIN32}
		${KALIUM_MAIN_HEADERS}
		${KALIUM_MAIN_SOURCE}
	)
	target_link_libraries(
	KaliumBase
	KaliumCore		
	KaliumUtil
	${KALIUM_LINK}
	)
elseif(APPLE)
else()
	message(${CMAKE_CURRENT_SOURCE_DIR}/libs/)
	link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/)
	add_library(Kalium  
		${KALIUM_ANDROID}
		${KALIUM_SRC}
		${KALIUM_MAIN_HEADERS}
		${KALIUM_MAIN_SOURCE}
	
	)
	target_link_libraries(Kalium KaliumCore KaliumBase  KaliumUtil  ${KALIUM_LINK} )
endif()











