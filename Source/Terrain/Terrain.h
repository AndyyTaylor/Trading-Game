// Copyright 2017 Andy Taylor
#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include "../Model.h"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

class Terrain {
 public:
    static const int SIZE = 800;
    static const int VERTEX_COUNT = 256;
    static const int MAX_HEIGHT = 200;
    static const int MAX_PIXEL_COLOUR = 256*256*256;

    Terrain(){};
    Terrain(int worldX, int worldY, int worldZ, float width, float height, float length);

    float getHeightAt(int x, int z);

    // At some point I need to modify my code to allow me pass around 'references'
    // const Model& getModel(){ return m_model; }
    Model model;  // m_ for privates?

    void updateDiv(float d);
    void generateBounds(std::vector<glm::vec3> vertices);
    void addAdjTerrain(Terrain t) {
        std::cout << "Adding" << std::endl;
        std::cout << t.minX << std::endl;
        std::cout << "Done" << std::endl;
        adjacent.push_back(t);
    }
    
    std::vector<float> self_bounds;

 protected:
    SDL_Surface* img;
    int worldX, worldY, worldZ;
    int maxX, minX, maxY, minY;
    float width, height, length;
    float div = 20;

    std::vector<Terrain> adjacent;
    std::vector<float> heights;

    void getRGB(SDL_Surface* img, int x, int y, int* r2, int* g2, int* b2);
    float getHeight(int x, int y);
    void addRectangle(std::vector<glm::vec3>* vertices, std::vector<glm::vec2>* uvs, float x, float y, float z, float w, float h, float l, float tw, float th, float tl);
    void addRectangle(std::vector<glm::vec3>* vertices, std::vector<glm::vec2>* uvs, float x, float y, float z, float w, float h, float l, float tw, float th, float tl, std::vector<float> bounds);
    void setupNormals(std::vector<glm::vec3>* normals, std::vector<glm::vec3> vertices);
};


#endif  /* TERRAIN_H */
