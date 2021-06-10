#include <iostream>
#include "md/image3d/csrc/image3d.h"
#include "md/image3d/csrc/image3d_tools.h"
#include "md/image3d/csrc/itk/image3d_io.h"
#include "md/utils/csrc/timer.h"
#include "AortaTools/csrc/api.h"

using namespace medvision;

int main()
{	
	const char* mask_path = "E:\\CppFiles\\moving.nii.gz";

	std::cout << "Begin to read mask ..." << std::endl;

	Image3d mask;
	if (!read_image(mask_path, mask)) {
		std::cerr << "fail to read image from " << mask_path << std::endl;
		return -1;
	}
	mask.cast(PT_SHORT);


	void* result = nullptr;

	std::cout << "Begin to analyze mask ..." << std::endl;

	AortaSystemAnalyze(&mask, &result);
	std::cin.get();
}