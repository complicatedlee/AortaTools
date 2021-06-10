if(NOT SETUP_NVCC_CONFIG_DONE)

    set(SETUP_NVCC_CONFIG_DONE TRUE)
    get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
	
    if(isMultiConfig)	
		set(CUDA_NVCC_FLAGS_DEBUG ${CUDA_NVCC_FLAGS_DEBUG};-gencode;arch=compute_30,code=sm_30;-gencode;arch=compute_35,code=sm_35;
		    -gencode;arch=compute_52,code=sm_52;-gencode;arch=compute_50,code=compute_50;-std=c++11;-g;-lineinfo;-Xcompiler;-ggdb)
		set(CUDA_NVCC_FLAGS_RELEASE ${CUDA_NVCC_FLAGS_RELEASE};-gencode;arch=compute_30,code=sm_30;-gencode;arch=compute_35,code=sm_35;
		    -gencode;arch=compute_52,code=sm_52;-gencode;arch=compute_50,code=compute_50;-std=c++11;-O3;-DNDEBUG;-Xcompiler;-DNDEBUG)
			
		if (UNIX OR APPLE)
			list(APPEND CUDA_NVCC_FLAGS_DEBUG "--compiler-options -fPIC")
			list(APPEND CUDA_NVCC_FLAGS_RELEASE "--compiler-options -fPIC")
		else()
		    list(APPEND CUDA_NVCC_FLAGS_DEBUG "-Xcompiler /wd4819")
			list(APPEND CUDA_NVCC_FLAGS_RELEASE "-Xcompiler /wd4819")
		endif (UNIX OR APPLE)
		
    else()
		if (CMAKE_BUILD_TYPE STREQUAL "Debug")
			set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-gencode;arch=compute_30,code=sm_30;-gencode;arch=compute_35,code=sm_35;
			    -gencode;arch=compute_52,code=sm_52;-gencode;arch=compute_50,code=compute_50;-std=c++11;-g;-lineinfo;-Xcompiler;-ggdb)
		else()
			set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-gencode;arch=compute_30,code=sm_30;-gencode;arch=compute_35,code=sm_35;
			    -gencode;arch=compute_52,code=sm_52;-gencode;arch=compute_50,code=compute_50;-std=c++11;-O3;-DNDEBUG;-Xcompiler;-DNDEBUG)
		endif()
		
		if (UNIX OR APPLE)
			list(APPEND CUDA_NVCC_FLAGS "--compiler-options -fPIC")
		else()
		    list(APPEND CUDA_NVCC_FLAGS "-Xcompiler /wd4819")
		endif (UNIX OR APPLE)

    endif()
	
endif()