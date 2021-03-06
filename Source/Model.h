// Copyright 2017 Andy Taylor
#ifndef MODEL_H_
#define MODEL_H_

#include <GL/glew.h>
#include "Entity.h"
#include <vector>
#include <string>

class Model {
 public:
    Model();

    void draw();

    void bind();
    void unbind();

    void loadModel(const char* path);
    void loadVertices(std::vector<glm::vec3> v, std::vector<glm::vec2> u, std::vector<glm::vec3> n, std::string filename);

    void setupBuffers(std::string filename);

    Entity entity;  // temporary

 protected:
    GLuint m_vao;
    GLuint TextureID;

    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;
};



#endif /* MODEL_H_ */
