#ifndef FLATLAND_ITEM_HPP
#define FLATLAND_ITEM_HPP

#include "FlatLandObject.hpp"

class Item : public FlatLandObject {
public:
    explicit Item(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Item() { }

    virtual sgl::int8 getValue() const = 0;
};

#endif // FLATLAND_ITEM_HPP
