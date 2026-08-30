//
// Created by johnc on 29/08/2026.
//

#include "TextureManager.h"

Texture2D& TextureManager::Get(const std::string& assetId)
{
    return cache[assetId];
}

void TextureManager::Load(const std::string& assetId, const std::string& filePath)
{
    if (cache.find(assetId) == cache.end())
    {
        TraceLog(LOG_INFO, "Texture Loaded: %s", assetId.c_str());
        cache[assetId] = LoadTexture(filePath.c_str());
    }
}

void TextureManager::UnloadAll()
{
    for (auto& pair : cache)
    {
        UnloadTexture(pair.second);
    }
    cache.clear();
}
