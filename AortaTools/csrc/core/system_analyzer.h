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
	double aorta_diameters[LANDMARK_NUM];
	double aorta_volumes[VOLUME_NUM];
	double aorta_lengths[LENGTH_NUM];

public:
	/*! \brief constructor */
	AortaAnalyzer();

	/*! \brief destructor */
	~AortaAnalyzer();

	/*! \aorta analyze */
	int Analyze(void* mask);

};
}

#endif