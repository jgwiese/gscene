#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <cppassets/cppassets.h>
#include <vector>


namespace scene {
    class t_resource_manager {
    public:
        t_resource_manager();
        ~t_resource_manager();
        unsigned int add_mesh(t_mesh *p_mesh);
        t_mesh *get_mesh(u_int mesh_id);

    private:
        std::vector<t_mesh *> v_meshes;
    };
}

#endif // RESOURCE_MANAGER_H

