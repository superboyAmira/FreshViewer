# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QtSceneDrawer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QtSceneDrawer_autogen.dir/ParseCache.txt"
  "QtSceneDrawer_autogen"
  )
endif()
