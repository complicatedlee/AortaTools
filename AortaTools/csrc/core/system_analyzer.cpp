#include "AortaTools/csrc/core/system_analyzer.h"
#include "md/image3d/csrc/image3d_tools.h"
#include "md/utils/csrc/timer.h"
#include "md/utils/csrc/template_macros.h" //?
#include "md/image3d/csrc/image3d_connected_components.h"
#include "glog/logging.h"

namespace medvision {

AortaAnalyzer::AortaAnalyzer()
{
	InitData();
}

AortaAnalyzer::~AortaAnalyzer()
{}

void AortaAnalyzer::InitData()
{

	for (int i = 0; i < LANDMARK_NUM; i++){
		m_aorta_diameters[i] = 0.0;
	}
	for (int i = 0; i < LENGTH_NUM; i++) {
		m_aorta_lengths[i] = 0.0;
	}
	for (int i = 0; i < VOLUME_NUM; i++) {
		m_aorta_volumes[i] = 0.0;
	}

}

void AortaAnalyzer::CalculateLandmarks(void* mask)
{
	std::cout << "Calculate Landmarks" << std::endl;
	//Image3d* mask_cp = static_cast<Image3d*>(mask);  //Conversions between data types
	
    //1.Pick Largest Componect
	AortaParameters* aorta = new AortaParameters;
	aorta->PickLargestComponect(mask);

	
}


int AortaAnalyzer::Analyze(void* mask)
{
	InitData();
	//1. calculate landmarks of mask
	CalculateLandmarks(mask);

	//2. compute statistics
	return 1;
}


AortaParameters::AortaParameters()
{
}

AortaParameters::~AortaParameters()
{}

void AortaParameters::PickLargestComponect(void* mask)
{
	std::cout << "1. Pick Largest Componect" << std::endl;
	Image3d* mask_w = static_cast<Image3d*>(mask);
	PixelType ptype = mask_w->pixel_type();


	// create a label image of the same size as input image
	vec3d<int> imsize = (*mask_w).size();
	Image3d label_image, *label_imptr = nullptr;

	label_image.allocate(imsize[0], imsize[1], imsize[2], PT_INT);
	label_image.set_zeros();
	label_imptr = &label_image;
	
	// copy another mask_w
	Image3d* mask_w_copy = nullptr;
	try {
		mask_w_copy = new Image3d(*mask_w);
	}
	catch (std::bad_alloc&) {
		if (mask_w_copy != nullptr) {
			delete mask_w_copy;
			mask_w_copy = nullptr;
		}
	} 
	
	//convert mask to binary 
	ptypecall_1(convert_multi_label_mask_to_binary, ptype, *mask_w_copy);
	// pick largest component
	size_t ret = 0;
	ptypeassign_1(pick_largest_component, ptype, ret, *mask_w_copy, false);

	//compare mask_w and mask_w_copy


	//need to delete pointer
	delete mask_w_copy;

}
