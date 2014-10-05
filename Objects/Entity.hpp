#ifndef FLATLAND_ENTITY_HPP
#define FLATLAND_ENTITY_HPP

#include "FlatLandObject.hpp"

class Entity : public FlatLandObject {
public:
    explicit Entity(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Entity() { }

    void move(float cx, float cy);
    void move(const sgl::vec2f&);

    virtual void interactWith(Item*) override;
};

#endif
