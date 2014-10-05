#include <iostream>
#include <SGL/all.hpp>
#include "Level.hpp"

int main() {
    sgl::Window wnd(1024, 768, "Quinn Quadrat - Ein Schrecken ohne Ecken");
    wnd.setSwapInterval(sgl::SwapInterval::Immediate);

    sgl::Font fnt("media/arial.ttf", 16);
    sgl::Text fps(fnt);
    fps.setPosition(1024 - 40, 8);

    sgl::Surface quinn("media/Quinn.png");
    quinn.setAsIcon();

    Level level;
    level.load();

    sgl::Event event;
    while (wnd.isOpen()) {
        wnd.clear();

        while (sgl::PollEvent(&event)) {
            switch (event.type) {
                case sgl::Event::Quit:
                    wnd.close();
                break;

                case sgl::Event::KeyDown:
                    if (event.key.key == sgl::Key::Esc)
                        wnd.close();
                break;
            }
        }

        fps.setData(sgl::GetFPS());

        level.update();
        level.draw(&wnd);

        wnd.draw(fps);

        wnd.display();
    }
}
