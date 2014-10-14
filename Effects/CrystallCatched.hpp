#ifndef FLATLAND_CRYSTALL_CATCHED_HPP
#define FLATLAND_CRYSTALL_CATCHED_HPP

#include <SGL/Graphic/Text.hpp>
#include <SGL/System/StopWatch.hpp>
#include "Effect.hpp"

class CrystallCatched : public Effect {
private:
    sgl::int16 _updates = 0;

    sgl::Font _font;
    sgl::Text _text;

    sgl::StopWatch _clock;

public:
    explicit CrystallCatched(sgl::int16 value, const sgl::vec2s&);
    virtual ~CrystallCatched() { }

    bool isValid() const override {
        return _updates < 12;
    }

    void update() override;
    void draw(const sgl::Window*) const override;
};

#endif // FLATLAND_CRYSTALL_CATCHED_EFFECT_HPP
