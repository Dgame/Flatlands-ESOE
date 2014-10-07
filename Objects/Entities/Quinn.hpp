#ifndef FLATLAND_QUINN_HPP
#define FLATLAND_QUINN_HPP

#include "../Entity.hpp"
#include "../Direction.hpp"

class Quinn : public Entity {
private:
    sgl::int16 _vertex_count = 0;

public:
    explicit Quinn(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Quinn() { }

    void move(Direction dir);

    sgl::int16 getVertexCount() const {
        return _vertex_count;
    }

    virtual void update() override;
    virtual void interactWith(Entity*) override;
    virtual void interactWith(Item*) override;
    virtual void interactWith(Stream*) override;
};

#endif // FLATLAND_QUINN_HPP

