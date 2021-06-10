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
	int error_code;
	std::cout << "Aorta system analyze..." << std::endl;
	AortaAnalyzer* system = new AortaAnalyzer;
	error_code = system->Analyze(mask);

	*results = system;
	return error_code;
}

int AortaSystemReleaseMask(void* mask)
{
	std::cout << "Release mask..." << std::endl;
	AortaAnalyzer* mask_w = static_cast<AortaAnalyzer*>(mask);
	if (mask_w != nullptr) {
		delete mask_w;
	}
	return 1;
}

int AortaSystemReleaseResult(void* result)
{
	std::cout << "Release result..." << std::endl;
	AortaAnalyzer* result_w = static_cast<AortaAnalyzer*>(result);
	if (result_w != nullptr) {
		delete result_w;
	}
	return 1;
}

void GetAortaDiameter(void* result, double* aorta_diameters)
{
	//AortaAnalyzer* analyzer = static_cast<AortaAnalyzer*>(result); 
	
}
void GetAortaVolume(void* result, double* aorta_volumes)
{
}
void GetAortaLength(void* result, double* aorta_lengths)
{
}