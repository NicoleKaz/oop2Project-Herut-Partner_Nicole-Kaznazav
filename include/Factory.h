#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include "StaticObject.h"
#include "MovingObject.h" 


struct ColorComparator
{
    // Operator function to compare two sf::Color objects
    bool operator()(const sf::Color& color1, const sf::Color& color2) const {
        // Compare the integer representations of the colors
        // This compares the colors based on their RGB values
        return color1.toInteger() < color2.toInteger();
    }
};

template<class ObjectType>
class Factory
{
public:
    using p2Fnc = std::unique_ptr<ObjectType>(*)(b2World& world, sf::Vector2f location);
    static bool registerObject(sf::Color, p2Fnc);
	static std::unique_ptr<ObjectType> createObject(sf::Color color, b2World& world, sf::Vector2f location);
    static bool isExist(sf::Color color);

private:
    static auto& getMap()
    {
        static std::map<sf::Color, p2Fnc, ColorComparator> map;
        return map;
    }
};


template<class ObjectType>
inline bool Factory<ObjectType>::isExist(sf::Color color)
{
    return getMap().find(color) != getMap().end();
}

template<class ObjectType>
inline bool Factory<ObjectType>::registerObject(sf::Color object, p2Fnc fnc)
{
    //Insert the object to the map (color, function)
    getMap().emplace(object, fnc);
    return true;
}

template<class ObjectType>
inline std::unique_ptr<ObjectType> Factory<ObjectType>::createObject(sf::Color object_color, b2World& world, sf::Vector2f position)
{
    auto iter = Factory::getMap().find(object_color);

    if (iter == Factory::getMap().end())
    {
        return nullptr;
    }
    return iter->second(world, position);
}