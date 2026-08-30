#ifndef INC_2D_CITY_BUILDER_TEXTUREMANAGER_H
#define INC_2D_CITY_BUILDER_TEXTUREMANAGER_H

#include "raylib.h"
#include <unordered_map>
#include <string>

class TextureManager {
public:
    static TextureManager& GetInstance() {
        static TextureManager instance;
        return instance;
    }

    Texture2D& Get(const std::string& assetId);
    void Load(const std::string& assetId, const std::string& filePath);
    void UnloadAll();

private:
    TextureManager() = default;
    ~TextureManager() = default;

    // Delete copy/move semantics
    TextureManager(const TextureManager&) = delete;
    TextureManager(TextureManager&&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;
    TextureManager& operator=(TextureManager&&) = delete;

    std::unordered_map<std::string, Texture2D> cache;
};

#endif //INC_2D_CITY_BUILDER_TEXTUREMANAGER_H
