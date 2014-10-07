#ifndef FLATLAND_OBJECT_HPP
#define FLATLAND_OBJECT_HPP

#include <iostream>
#include <SGL/Core/Types.hpp>
#include <SGL/Graphic/Sprite.hpp>

namespace sgl {
    class Window;
}

class FlatLandObject {
protected:
    sgl::int8 _id;
    sgl::Sprite _sprite;

public:
    explicit FlatLandObject(sgl::Texture&);
    explicit FlatLandObject(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~FlatLandObject() { }

    sgl::int8 TexID() const {
        return _id;
    }

    bool isEqual(sgl::int8 id) const {
        return (_id + 1) == id;
    }

    const sgl::vec2f& getPosition() const;
    void draw(const sgl::Window*) const;

    virtual void update() { }
};

#endif // FLATLAND_OBJECT_HPP
