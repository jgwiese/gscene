#include "../include/material.h"
#include <fstream>
#include <iostream>
#include <sstream>


namespace scene {

t_material::t_material(std::string path_material) {
    std::ifstream f(path_material);
    std::string line, word;

    while (std::getline(f, line)) {
        std::istringstream iss(line);
        while (iss >> word) {
            if (word.compare("Kd") == 0) {
                float r, g, b;
                iss >> r >> g >> b;
                this->diffuse[0] = r;
                this->diffuse[1] = g;
                this->diffuse[2] = b;
                this->diffuse[3] = 1.0;
                break;
            }
        }
    }

    // TODO: just for now
    this->texture_id = -1;
}

unsigned int t_material::get_texture_id() {
    return this->texture_id;
}

glm::vec4 t_material::get_diffuse() {
    return this->diffuse;
}

}

