#ifndef FLATLAND_CRYSTALL_HPP
#define FLATLAND_CRYSTALL_HPP

#include "../Item.hpp"

class Crystall : public Item {
private:
    sgl::int16 _value;

public:
    explicit Crystall(sgl::int16 val, sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Crystall() { }

    virtual Effect* getEffect() const override;
    virtual sgl::int16 getValue() const override;
};

#endif // FLATLAND_CRYSTALL_HPP
