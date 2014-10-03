#ifndef FLATLAND_BUG_HPP
#define FLATLAND_BUG_HPP

#include "../Entity.hpp"

class Bug : public Entity {
public:
    explicit Bug(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Bug() { }
};

#endif // FLATLAND_BUG_HPP
