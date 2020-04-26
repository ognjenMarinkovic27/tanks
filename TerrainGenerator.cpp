#include "TerrainGenerator.h"
#include <math.h>
#include <iostream>

TerrainGenerator::TerrainGenerator() {
}

int TerrainGenerator::random(int x, int range) {
    int k = (x+seed)%range;
    return (int)(((k*k)%range * (k*k) %range)%range*k)%range;
}

int TerrainGenerator::getNoise(int x, int range) {

    int chunkSize=128;

    int chunkIndex = x/chunkSize;

    float prog = (x % chunkSize) / (float)chunkSize;

    float left_random = random(chunkIndex, range);
    float right_random = random(chunkIndex+1, range);

    float f=prog*3.1415927;
    float ft=(1-cos(f)) * 0.5;


    float noise = left_random*(1-ft) + right_random*ft;

    return round(noise);
}


void TerrainGenerator::generateTerrain(unsigned width, unsigned height, long long seed) {
    this->seed = seed;
    width/=tileSize;
    height/=tileSize;
    terrain = new bool* [width];
    for(int i=0;i<width;i++) {
        terrain[i] = new bool [height];
    }
    int k;

    int maxY = height*0.75;
    int minY = 50;

    for(int i=0;i<width;i++) {
        k = minY+getNoise(i, maxY-minY);
        heightMap.push_back(k);
        for(int j=0;j<height;j++) {
            if(j < k) terrain[i][j] = 1;
            else terrain[i][j] = 0;
        }
    }

}

void TerrainGenerator::destroyTerrain(int i, int k) {
    heightMap[i]-=k;
}

bool** TerrainGenerator::getTerrain() {
    return terrain;
}

int TerrainGenerator::getTileSize () {
    return tileSize;
}

std::vector<int> TerrainGenerator::getHeightMap () {
    return heightMap;
}
