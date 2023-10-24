# gscene library
* use a general shape class instead of just meshes.
* use a resource manager and not load shapes multiple times.
* scene objects should have a unique id or name.

# structure for pathtracing
* array structure with all faces instead of distributed on heap.
* vertex- or face-wise materials.
* acceleration structure contains array-indices.

# supporting both
* meshes / renderobject separation done in renderer, since renderer specific
    * transformation of element-wise material to textures. then rendering supports textures only.
    * or voxel-wise instead of textures?

# moving objects
* objects should be moved explicitely.
    * raytracer needs the transformed geometry.
    * rasterizer needs just the transformation matrix for the shader.
