#ifndef FLATLAND_OBJECT_HPP
#define FLATLAND_OBJECT_HPP

#include <iostream>
#include <SGL/Core/Types.hpp>
#include <SGL/Graphic/Sprite.hpp>

const sgl::int16 TILE_SIZE = 32;

namespace sgl {
    class Window;
}

class Entity;
class Item;

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

    void draw(const sgl::Window*) const;
    virtual void update();

    virtual void interactWith(Entity*);
    virtual void interactWith(Item*);
};

#endif // FLATLAND_OBJECT_HPP
