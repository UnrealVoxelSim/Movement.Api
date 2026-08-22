# UnrealVoxelSim.Movement.Api

Engine- and storage-independent contracts for deterministic continuous entity movement. Authoritative coordinates and
velocities use signed Q32.32 fixed point. `GroundedProfile` owns body dimensions and configurable rise/drop capabilities
shared with navigation. Its collision skin keeps the discrete one-voxel navigation footprint conservative while giving
continuous collision enough clearance to pass exact one-voxel openings without edge-contact oscillation.

External controllers and navigation following submit transient batched `Intent` values. Movement applies them only when
the composition root invokes `IUpdater`; no AI task or navigation path vocabulary enters this API.
