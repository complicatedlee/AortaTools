cmake_minimum_required(VERSION 3.14)

# suppress warning
cmake_policy(SET CMP0012 NEW)

# suppress windows warning from strcpy
if (WIN32)
  add_definitions("/D_CRT_SECURE_NO_WARNINGS /wd4996 /wd4463 /wd4505 /wd4819 -DNOMINMAX")
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif(WIN32)

# use customized find modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

project(AortaTools)

# 1) add c++ 11 support --std=c++11
# 2) to fix compilation problem: relocation R_X86_64_32 against
#    `.rodata' can not be used when making a shared object;
#    recompile with -fPIC
if(UNIX OR APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -Wall")
endif(UNIX OR APPLE)

# # find ITK
# find_package(ITK)
# if(ITK_FOUND)
#   include(${ITK_USE_FILE})
# else(ITK_FOUND)
#   message(FATAL_ERROR "ITK not found. Please set ITK_DIR")
# endif(ITK_FOUND)

# # add OPENMP
# find_package(OpenMP)
# if (OPENMP_FOUND)
#   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
# else (OPENMP_FOUND)
#   message(FATAL_ERROR "OpenMP not found.")
# endif()

# add root directory in include path
get_filename_component(PARENT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)
include_directories(${PARENT_DIR})

# set default build type
set(CMAKE_BUILD_TYPE Release CACHE STRING "Set default build type to release")

# set default debug and release output directory
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/Release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/lib/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/lib/Release)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/lib/Release)

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/lib/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/lib/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/lib/Debug)

# # add gflag
# find_package(gflags REQUIRED)
# if(NOT gflags_FOUND)
#   message(FATAL_ERROR "gflags not found. Please build gflags under md/3rd_party/gflags and set gflags_DIR")
# endif(NOT gflags_FOUND)

# # add glog
# find_package(glog REQUIRED)
# if(NOT glog_FOUND)
#   message(FATAL_ERROR "glog not found. Please build glog under md/3rd_party/glog and set glog_DIR")
# endif(NOT glog_FOUND)

# # copy SHARED lib from gflags and glog to release or debug folder
# if(UNIX)
#     file(GLOB gflags_LIBRARYS_RELEASE ${gflags_DIR}/lib/libgflags.so* ${gflags_DIR}/lib/libgflags_nothreads.so*)
#     file(GLOB gflags_LIBRARYS_DEBUG ${gflags_DIR}/lib/libgflags_debug.so* ${gflags_DIR}/lib/libgflags_nothreads_debug.so*)
#     file(GLOB glog_LIBRARYS_RELEASE ${glog_DIR}/libglog.so*)
#     file(GLOB glog_LIBRARYS_DEBUG ${glog_DIR}/libglogd.so*)
# endif(UNIX)

# if(WIN32)
#     file(GLOB gflags_LIBRARYS_RELEASE ${gflags_DIR}/bin/Release/gflags*)
#     file(GLOB gflags_LIBRARYS_DEBUG ${gflags_DIR}/bin/Debug/gflags*)
#     file(GLOB glog_LIBRARYS_RELEASE ${glog_DIR}/Release/glog*)
#     file(GLOB glog_LIBRARYS_DEBUG ${glog_DIR}/Debug/glog*)
# endif(WIN32)

# set(LOG_LIBRARY_RELEASE ${gflags_LIBRARYS_RELEASE} ${glog_LIBRARYS_RELEASE})
# set(LOG_LIBRARY_DEBUG ${gflags_LIBRARYS_DEBUG} ${glog_LIBRARYS_DEBUG})
# file(COPY ${LOG_LIBRARY_RELEASE} DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE})
# file(COPY ${LOG_LIBRARY_DEBUG} DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG})

set(TARGETS_CMAKE ${CMAKE_SOURCE_DIR}/cmake)

# enable testing
enable_testing()

# add submodules
# add_subdirectory(3rd_party)
# add_subdirectory(image3d)
# add_subdirectory(utils)
# add_subdirectory(mdmath)
# add_subdirectory(neuro)
# add_subdirectory(dicom)
# add_subdirectory(cuda_image)
# add_subdirectory(visualization)
# add_subdirectory(mesh3d)
# add_subdirectory(gpujpeg)
# add_subdirectory(md2_pybind11)
add_subdirectory(AortaTools)