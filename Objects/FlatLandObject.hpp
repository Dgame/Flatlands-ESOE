#ifndef FLATLAND_OBJECT_HPP
#define FLATLAND_OBJECT_HPP

#include <SGL/Core/Types.hpp>
#include <SGL/Graphic/Sprite.hpp>
#include "../DrawObject.hpp"

namespace sgl {
    class Texture;
}

class FlatLandObject : public DrawObject {
protected:
    sgl::Sprite _sprite;
    sgl::int8 _id;

public:
    explicit FlatLandObject(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~FlatLandObject() { }

    sgl::int8 TexID() const {
        return _id;
    }

    bool isEqual(sgl::int8 id) const {
        return (_id + 1) == id;
    }

    const sgl::vec2f& getPosition() const;
    void draw(const sgl::Window*) const override;
};

#endif // FLATLAND_OBJECT_HPP
