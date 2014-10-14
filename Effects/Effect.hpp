#ifndef FLATLAND_EFFECT_HPP
#define FLATLAND_EFFECT_HPP

#include "../DrawObject.hpp"
#include <SGL/Math/vec2.hpp>

class Effect : public DrawObject {
protected:
    sgl::vec2s _position;

public:
    explicit Effect(const sgl::vec2s&);
    virtual ~Effect() { }

    virtual bool isValid() const {
        return true;
    }
};

#endif // FLATLAND_EFFECT_HPP
