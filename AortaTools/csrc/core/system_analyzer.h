#ifndef MD_SYSTEM_ANALYZER_H
#define MD_SYSTEM_ANALYZER_H

#include "md/image3d/csrc/image3d.h"

namespace medvision {

const int LANDMARK_NUM = 9;
const int VOLUME_NUM = 8;  //The volume between two landmarks
const int LENGTH_NUM = 8;  //The volume between two landmarks

class AortaAnalyzer
{
private:
	double m_aorta_diameters[LANDMARK_NUM];
	double m_aorta_volumes[VOLUME_NUM];
	double m_aorta_lengths[LENGTH_NUM];

public:
	
	/*! \brief constructor */
	AortaAnalyzer();

	/*! \brief destructor */
	~AortaAnalyzer();

	const double* aorta_diameters() const { return m_aorta_diameters; }
	const double* aorta_volumes() const { return m_aorta_volumes; }
	const double* aorta_lengths() const { return m_aorta_lengths; }

	/*! \init data*/
	void InitData();

	/*! \aorta analyze */
	int Analyze(void* mask);
	
	/*! \calculate landmarks of mask */
	void CalculateLandmarks(void* mask);

	/*! \brief compute statistics */
	void ComputeStatistics();

	
};


class AortaParameters
{
private:
	Image3d mask_copy;
	Image3d mask_except_arch;
	Image3d centerline_except_arch;

public:
	/*! \brief constructor */
	AortaParameters();

	/*! \brief destructor */
	~AortaParameters();

	void PickLargestComponect(void* mask);
	void GenerateCenterline();
	void SmoothingCenterline();
};

}

#endif