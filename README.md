# UnrealVoxelSim.Movement.Api

Public data contracts for deterministic continuous entity movement. Scalar arithmetic lives in `Math.Api`; position and
linear velocity values and components live in `Spatial.Api`.

An entity participating in grounded movement is composed with `PositionComponent`, `LinearVelocityComponent`,
`MovementProfileComponent`, `GroundedComponent`, and `MovementInputComponent`. The composition root attaches these
components; Movement has no registration API and no private duplicate entity state.

`MovementInputComponent` is the explicit single-controller handoff. Its one authoritative producer writes the desired
velocity and jump request for a specific simulation tick. Movement consumes only an input stamped for the current tick,
so a missing or stale controller update means neutral input rather than a repeated command. The architecture does not
support several controllers competing for the same pawn in one phase; higher-level controllers delegate downward and
the composition root chooses the sole producer at each level.

`GroundedProfile` owns body dimensions and configurable rise/drop capabilities shared with navigation. Its collision
skin keeps the discrete one-voxel navigation footprint conservative while giving continuous collision enough clearance
to pass exact one-voxel openings without edge-contact oscillation.
