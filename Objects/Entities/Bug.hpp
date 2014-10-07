#ifndef FLATLAND_BUG_HPP
#define FLATLAND_BUG_HPP

#include "../Entity.hpp"
#include <SGL/Graphic/Texture.hpp>


class Bug : public Entity {
private:
    sgl::Texture _left_texture;
    sgl::Texture _right_texture;

public:
    explicit Bug(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Bug() { }

    virtual void update() override;
};

#endif // FLATLAND_BUG_HPP
