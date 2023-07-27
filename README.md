# gscene library
* use a general shape class instead of just meshes
* use a resource manager and not load shapes multiple times
* i think i should not use t_object from assets as a member/basis for t_scene_object? or maybe it is good?
* add correct transformation of objects, like rotations
    * objects need to have its own model matrix: translations define its origin and it can have its own rotation and scaling for example.
    * but they also have a world model matrix: where is there position in the scene.
