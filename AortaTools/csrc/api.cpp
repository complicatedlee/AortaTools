#include "AortaTools/csrc/api.h"
#include "AortaTools/csrc/core/system_analyzer.h"
#include "md/image3d/csrc/image3d.h"
#include "md/image3d/csrc/image3d_tools.h"
#include "md/image3d/csrc/itk/image3d_io.h"
#include "md/utils/csrc/timer.h"
#include "glog/logging.h"

using namespace medvision;

int AortaSystemAnalyze(void* mask, void** results)
{
	std::cout << "Aorta system analyze..." << std::endl;
}

int AortaSystemReleaseMask(void* mask)
{
	std::cout << "Release mask..." << std::endl;
}

int AortaSystemReleaseResult(void* result)
{
	std::cout << "Release result..." << std::endl;
}