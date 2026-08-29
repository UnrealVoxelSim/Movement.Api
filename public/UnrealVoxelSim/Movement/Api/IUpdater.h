#pragma once

#include "UnrealVoxelSim/Simulation/Api/StepContext.h"

namespace UnrealVoxelSim::Movement::Api
{
	/* TODO This interface appears to belong to the simulation execution model,
 	* not to Movement.
 	*
 	* "Update" is not a Movement-specific capability. It expresses participation
 	* in the simulation step lifecycle: when a system runs, how often it runs,
 	* and what execution context it receives.
 	*
 	* Multiple modules currently define equivalent IUpdater interfaces and the
 	* simulation pipeline wires them together individually. This duplicates the
 	* same lifecycle contract across module boundaries and couples orchestration
 	* to module-specific APIs.
 	*
 	* Consider defining a single step-participant contract in Simulation.Api
 	* and letting systems that require simulation ticks implement it.
 	*/
	class IUpdater
	{
	public:
		virtual ~IUpdater() = default;
		virtual void Update(Simulation::Api::StepContext context) = 0;
	};
}
