#ifndef MD_AORTA_SYS_API_H
#define MD_AORTA_SYS_API_H


/*! \brief Aorta analysis entrance
*
*  \param mask             Pointer of the segmentation mask (Image3d format)
*  \param results          Aortic analysis results structure pointer (function allocated memory)
*  \return                 ERROR CODE
*/
int AortaSystemAnalyze(void* mask, void** results);

/*! \brief  Pointer release function for aorta mask
*
*  \param mask             Pointer of the segmentation mask
*  \return                 ERROR CODE
*/
int AortaSystemReleaseMask(void* mask);

/*! \brief Pointer release function for aorta analysis results
*
*  \param result           Pointer of the analysis results
*  \return	               ERROR CODE
*/
int AortaSystemReleaseResult(void* result);

///////////////////////////////////////////////////////////////////////////////////////////////
// Refer the diameter/volume/length of aorta API
void GetAortaDiameter(void* result, double* aorta_diameters);
void GetAortaVolume(void* result, double* aorta_volumes);
void GetAortaLength(void* result, double* aorta_lengths);


#endif 