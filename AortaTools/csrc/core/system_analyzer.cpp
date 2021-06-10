#include "AortaTools/csrc/core/system_analyzer.h"
#include "md/image3d/csrc/image3d_tools.h"
#include "md/utils/csrc/timer.h"
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
}

void AortaAnalyzer::ComputeStatistics()
{
	std::cout << "Compute Statistics" << std::endl;

}

int AortaAnalyzer::Analyze(void* mask)
{
	InitData();
	//1. calculate landmarks of mask
	CalculateLandmarks(mask);

	//2. compute statistics
	//ComputeStatistics();
	return 1;
}


AortaParameters::AortaParameters(void* mask)
{
	PickLargestComponect(mask);
}

AortaParameters::~AortaParameters()
{}



}
