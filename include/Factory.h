#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <string>
#include "StaticObject.h"
#include "MovingObject.h"  //??'למה לא מכיר את המחלקה
#include <SFML/Graphics.hpp>



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
    const auto& map = getMap();

    // Check in the map of StaticObjects
    for (const auto& pair : map) {
        if (pair.first == color) {
            return true;
        }
    }
    return false;
}

template<class ObjectType>
inline bool Factory<ObjectType>::registerObject(sf::Color object, p2Fnc fnc)
{
    //Insert the object to the map (color, function)
    Factory::getMap().emplace(object, fnc);
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