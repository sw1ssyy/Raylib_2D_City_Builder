//
// Created by sw1ssyy on 29/08/2026.
//

#include "TextureManager.h"
#include "../Configs/AssetConfig.h"

Texture2D& TextureManager::Get(const std::string& assetId)
{
    return cache[assetId];
}


void TextureManager::Load(const std::string& assetId)
{
    if (cache.find(assetId) == cache.end())
    {
        TraceLog(LOG_INFO, "Texture Loaded: %s", assetId.c_str());
        cache[assetId] = LoadTexture(assetId.c_str());
    }
}

void TextureManager::LoadAll()
{
    Load(AssetConfig::FARM_CARD);
    Load(AssetConfig::FACTORY_CARD);
    Load(AssetConfig::HOUSE_CARD);
    Load(AssetConfig::SHOP_CARD);
    Load(AssetConfig::ICON_FARM);
    Load(AssetConfig::ICON_FACTORY);
    Load(AssetConfig::ICON_HOUSE);
    Load(AssetConfig::ICON_SHOP);
}

void TextureManager::UnloadAll()
{
    for (auto& pair : cache)
    {
        UnloadTexture(pair.second);
    }
    cache.clear();
}
