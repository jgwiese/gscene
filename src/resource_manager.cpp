#include "../include/resource_manager.h"
#include <iostream>


namespace scene {
    t_resource_manager::t_resource_manager() {
        this->v_meshes = std::vector<t_mesh *>();
    }

    t_resource_manager::~t_resource_manager() {

    }

    unsigned int t_resource_manager::add_mesh(t_mesh *p_mesh) {
        this->v_meshes.push_back(p_mesh);
        return this->v_meshes.size() - 1;
    }

    t_mesh *t_resource_manager::get_mesh(u_int mesh_id) {
        return this->v_meshes[mesh_id];
    }
}

