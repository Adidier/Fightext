SET(KALIUM_UTIL_HEADERS
			MathUtil.h

)
SET(KALIUM_UTIL_SOURCE
			MathUtil.cpp
)

include_directories(
    #${COCOS}/include
	#${GLEW_FOLDER}/include
)

ADD_LIBRARY(KaliumUtil  ${KALIUM_UTIL_HEADERS} ${KALIUM_UTIL_SOURCE}   )

