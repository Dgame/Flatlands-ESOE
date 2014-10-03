#ifndef ITEM_HPP
#define ITEM_HPP

#include "FlatLandObject.hpp"

class Item : public FlatLandObject {
public:
    explicit Item(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Item() { }
};

#endif // ITEM_HPP
