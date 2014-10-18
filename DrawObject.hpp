#ifndef FLATLAND_DRAW_OBJECT_HPP
#define FLATLAND_DRAW_OBJECT_HPP

// TODO: Only in debug mode
#include <iostream>

namespace sgl {
    class Window;
}

class DrawObject {
public:
    virtual ~DrawObject() { }

    virtual void draw(const sgl::Window*) const = 0;
    virtual void update() { }
};

#endif // FLATLAND_DRAW_OBJECT_HPP
