#ifndef RESOURCEMAPS_HH
#define RESOURCEMAPS_HH

#include "core/basicresources.h"

namespace student {

namespace ConstResourceMaps {

const Course::ResourceMap EMPTY = {};

// Building - Mine
const Course::ResourceMap MINE_BUILD_COST = {
    {Course::BasicResource::MONEY, 50},
    {Course::BasicResource::FOOD, 100},
    {Course::BasicResource::WOOD, 50},
    {Course::BasicResource::STONE, 100}
};
const Course::ResourceMap MINE_PRODUCTION = {
    {Course::BasicResource::MONEY, 5},
    {Course::BasicResource::STONE, 10}
};

// Bomb
const Course::ResourceMap BOMB_BUILD_COST = {
    {Course::BasicResource::MONEY, 30},
    {Course::BasicResource::FOOD, 30},
    {Course::BasicResource::WOOD, 30},
    {Course::BasicResource::STONE, 30}
};
 // Tile - Desert
const Course::ResourceMap DESERT_BP = {
    {Course::BasicResource::MONEY, 0},
    {Course::BasicResource::FOOD, 0},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 1},
    {Course::BasicResource::ORE, 0},
};
const Course::ResourceMap LAKE_BP = {
    {Course::BasicResource::MONEY, 2},
    {Course::BasicResource::FOOD, 5},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 0},
    {Course::BasicResource::ORE, 0},
};

// tile - Hill
const Course::ResourceMap HILL_BP = {
    {Course::BasicResource::MONEY, 3},
    {Course::BasicResource::FOOD, 0},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 3},
    {Course::BasicResource::ORE, 3},
};
// Worker - Engineer
const Course::ResourceMapDouble ENG_WORKER_EFFICIENCY = {
    {Course::MONEY, 2.00},
    {Course::FOOD, 2.00},
    {Course::WOOD, 2.00},
    {Course::STONE, 2.00},
    {Course::ORE, 2.00}
};

const Course::ResourceMap ENG_RECRUITMENT_COST = {
    {Course::MONEY, 100},
    {Course::FOOD, 25}
};
// Worker - Fisher
const Course::ResourceMapDouble FISHER_EFFICIENCY = {
    {Course::MONEY, 1.00},
    {Course::FOOD, 30.00},
    {Course::WOOD, 0.00},
    {Course::STONE, 0.00},
    {Course::ORE, 0.00}
};

const Course::ResourceMap FISHER_RECRUITMENT_COST = {
    {Course::MONEY, 50},
    {Course::FOOD, 25},
    {Course::WOOD, 100}
};

} //namespace ResourceMaps
} //namespace student
#endif // RESOURCEMAPS_HH
