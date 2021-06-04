set(AORTA_SOURCE_FILES landmark_heatmap.cpp)
set (AORTA_HEADER_FILES landmark_heatmap.h)

add_library(AortaTools STATIC ${AORTA_SOURCE_FILES} ${AORTA_HEADER_FILES})

# # add executable
# add_executable(landmark_heatmap landmark_heatmap.cpp)
# #target_link_libraries(landmark_heatmap_test landmark_heatmap)

# # add unit testing
# add_executable(landmark_heatmap_test landmark_heatmap_test.cpp)
# #target_link_libraries(image3d_transform_test md_image3d_itk md_image3d
# #  ${ITK_LIBRARIES})
# add_test(NAME landmark_heatmap_test
#          COMMAND $<TARGET_FILE:landmark_heatmap_test> 
#          ${CMAKE_SOURCE_DIR}/mdaorta/csrc/test_data)