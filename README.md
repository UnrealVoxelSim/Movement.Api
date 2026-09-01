# UnrealVoxelSim.Movement.Api

Public data contracts for deterministic continuous entity movement. Scalar arithmetic lives in `Math.Api`; position and
linear velocity values and components live in `Spatial.Api`.

An entity participating in grounded movement is composed with `PositionComponent`, `LinearVelocityComponent`,
`ProfileComponent`, and `GroundedComponent`. Movement attaches its own `InputComponent` when the entity first receives
valid intent; no other domain receives write or structural authority for that component.

`IIntentReceiver` is the synchronous movement-input capability. Controllers submit a desired velocity and jump request
for one entity and simulation tick; Movement validates the intent and is the sole writer and structural owner of the
public `InputComponent`. Other domains may receive read access to that component but never write or attach it directly.

Movement consumes only an input associated with the current tick, so a missing or stale controller update means neutral
input rather than a repeated command. The architecture does not support several controllers competing for the same pawn
in one phase; higher-level controllers delegate downward and composition selects the sole producer at each level.

`GroundedProfile` owns body dimensions and configurable rise/drop capabilities shared with navigation. Its collision
skin keeps the discrete one-voxel navigation footprint conservative while giving continuous collision enough clearance
to pass exact one-voxel openings without edge-contact oscillation.
