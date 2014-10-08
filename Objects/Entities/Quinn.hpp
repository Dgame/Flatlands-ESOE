#ifndef FLATLAND_QUINN_HPP
#define FLATLAND_QUINN_HPP

#include "../Entity.hpp"
#include "../Direction.hpp"

class Quinn : public Entity {
private:
    sgl::int16 _vertex_count = 0;

    bool _moving = false;
    const Stream* _stream = nullptr;

public:
    explicit Quinn(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Quinn() { }

    void move(Direction dir);

    sgl::int16 getVertexCount() const {
        return _vertex_count;
    }

    virtual bool catchItems() const override {
        return true;
    }

    virtual void update() override;

    virtual void interactWith(const Item*) override;
    virtual void interactWith(const Stream*) override;
};

#endif // FLATLAND_QUINN_HPP

