#ifndef FLATLAND_ITEM_HPP
#define FLATLAND_ITEM_HPP

#include "FlatLandObject.hpp"

class Item : public FlatLandObject {
public:
    explicit Item(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Item() { }
};

#endif // FLATLAND_ITEM_HPP
