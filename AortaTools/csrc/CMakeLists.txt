# set system files
file(GLOB SYSTEM_FILES core/*.h core/*.cpp)

source_group(md_image3d FILES ${MD_IMAGE3D_SRC} ${MD_IMAGE3D_ITK_SRC})
source_group(md_utility FILES ${MD_UTILITY_SRC})
# source_group(md_segmentation3d FILES ${MD_VSEG_SRC})
source_group(core_files FILES api.h api.cpp api_test.cpp ${SYSTEM_FILES})
source_group(md_logging FILES ${MD_LOGGING_SRC})
# source_group(md_neuro FILES ${MD_NEURO_SRC})

# portable shared library using rpaths (on linux)
if (UNIX)
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
endif(UNIX)

# aorta dll library
add_library(md_aorta_sys SHARED api.cpp api.h ${SYSTEM_FILES}
            ${MD_IMAGE3D_SRC} ${MD_UTILITY_SRC} 
			${MD_LOGGING_SRC} ${MD_IMAGE3D_ITK_SRC})
			
target_link_libraries(md_aorta_sys ${ITK_LIBRARIES}} glog::glog)

if (UNIX)
  set(MD_AORTA_SYS_RPATH "$ORIGIN/../Dependency" "$ORIGIN")
  set_target_properties(md_aorta_sys PROPERTIES INSTALL_RPATH "${MD_AORTA_SYS_RPATH}")
endif(UNIX)


add_executable(md_aorta_sys_test api.h api.cpp api_test.cpp utils/test_helpers.h utils/test_helpers.cpp 
               ${MD_IMAGE3D_ITK_SRC} ${MD_UTILITY_SRC})
target_link_libraries(md_aorta_sys_test md_aorta_sys ${ITK_LIBRARIES} glog::glog)

if (UNIX)
  set_target_properties(md_aorta_sys_test PROPERTIES INSTALL_RPATH "$ORIGIN")
endif(UNIX)

