#ifndef FLATLAND_ITEM_HPP
#define FLATLAND_ITEM_HPP

#include "FlatLandObject.hpp"

class Item : public FlatLandObject {
private:
    bool _active = true;

public:
    explicit Item(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Item() { }

    bool isActive() const {
        return _active;
    }

    void disable() {
        _active = false;
    }

    virtual sgl::int8 getValue() const = 0;
};

#endif // FLATLAND_ITEM_HPP
