#include <iostream>
#include <SGL/all.hpp>
#include "Level.hpp"
#include "Objects/Entities/Quinn.hpp"

int main() {
    sgl::Window wnd(1024, 768, "Quinn Quadrat - Ein Schrecken ohne Ecken");
    wnd.setSwapInterval(sgl::SwapInterval::Immediate);

    sgl::Font fnt("media/arial.ttf", 16);
    fnt.setStyle(sgl::Font::Style::Bold);

    sgl::Text fps_show(fnt);
    fps_show = "FPS: ";
    fps_show.setPosition(1024 - 100, 8);

    sgl::Text vert_show(fnt);
    vert_show = "Vertex Count: ";
    vert_show.setPosition(1024 - 310, 8);

    sgl::Text fps(fnt);
    fps.setPosition(1024 - 60, 8);

    sgl::Text vert(fnt);
    vert.setPosition(1024 - 200, 8);

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
                    else if (event.key.key == sgl::Key::Left)
                        level.getQuinn()->move(Direction::Left);
                    else if (event.key.key == sgl::Key::Right)
                        level.getQuinn()->move(Direction::Right);

                    if (event.key.key == sgl::Key::Up)
                        level.getQuinn()->jump();
                break;
            }
        }

        fps.setData(sgl::GetFPS());
        vert.setData(level.getQuinn()->getVertexCount());

        level.update();
        level.draw(&wnd);

        wnd.draw(fps_show);
        wnd.draw(fps);
        wnd.draw(vert_show);
        wnd.draw(vert);

        wnd.display();
    }
}
