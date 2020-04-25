#include <vector>

class TerrainGenerator {
    long long seed;
    int width, height;
    int tileSize = 1;
    bool** terrain;
    std::vector<int> heightMap;

    int random(int x, int range);
    int getNoise(int x, int range);


    public:
        TerrainGenerator();
        void generateTerrain(unsigned width, unsigned , long long seed);
        bool** getTerrain();
        std::vector<int> getHeightMap();
        int getTileSize();
};
