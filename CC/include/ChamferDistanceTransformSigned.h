//##########################################################################
//#                                                                        #
//#                               CCLIB                                    #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU Library General Public License as       #
//#  published by the Free Software Foundation; version 2 of the License.  #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#          COPYRIGHT: EDF R&D / TELECOM ParisTech (ENST-TSI)             #
//#                                                                        #
//##########################################################################

#ifndef SIGNED_CHAMFER_DISTANCE_TRANSFORM_HEADER
#define SIGNED_CHAMFER_DISTANCE_TRANSFORM_HEADER

//Local
#include "CCCoreLib.h"
#include "Grid3D.h"
#include "MathTools.h"

namespace CCLib
{

class GenericProgressCallback;
class NormalizedProgress;

//! Class to compute a signed Chamfer distance field on a 3D grid
class CC_CORE_LIB_API ChamferDistanceTransformSigned : public Grid3D<float>, public MathTools
{

public:

	//! Initializes the grid
	/** This memory for the grid must be explicitelty reserved prior to any action.
		'Zero' cells must be initialized with setValue(0).
		\return true if the initialization succeeded
	**/
	inline bool init(const Tuple3ui& gridSize, float maxDist = 4096.0f) { return Grid3D<GridElement>::init(gridSize.x, gridSize.y, gridSize.z, 1, maxDist); }

	//! Computes the Chamfer distance on the whole grid
	/** Propagates the distances on the whole grid. The 'zeros' should
		have already been initialized before calling this method (see
		ChamferDistanceTransformSigned::setZero).
		\param progressCb progress callback (optional)
		\return success
	**/
	bool propagateDistance(GenericProgressCallback* progressCb = 0);

};

}

#endif //SIGNED_CHAMFER_DISTANCE_TRANSFORM_HEADER
