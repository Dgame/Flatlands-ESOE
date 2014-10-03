#ifndef FLATLAND_QUINN_HPP
#define FLATLAND_QUINN_HPP

#include "../Entity.hpp"

class Quinn : public Entity {
public:
    explicit Quinn(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Quinn() { }
};

#endif // FLATLAND_QUINN_HPP

