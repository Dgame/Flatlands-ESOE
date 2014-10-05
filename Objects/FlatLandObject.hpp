#ifndef FLATLAND_OBJECT_HPP
#define FLATLAND_OBJECT_HPP

#include <iostream>
#include <SGL/Core/Types.hpp>
#include <SGL/Graphic/Sprite.hpp>
#include "../Config.hpp"

namespace sgl {
    class Window;
}

class Entity;
class Tile;
class Item;
class Stream;

class FlatLandObject {
protected:
    sgl::int8 _id;
    sgl::Sprite _sprite;

public:
    explicit FlatLandObject(sgl::Texture&);
    explicit FlatLandObject(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~FlatLandObject() { }

    sgl::int8 ID() const {
        return _id;
    }

    const sgl::vec2f& getPosition() const;

    void draw(const sgl::Window*) const;

    virtual void update() { }

    virtual void interactWith(Entity*) { }
    virtual void interactWith(Tile*) { }
    virtual void interactWith(Item*) { }
    virtual void interactWith(Stream*) { }
};

#endif // FLATLAND_OBJECT_HPP
