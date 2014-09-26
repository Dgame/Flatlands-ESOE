#include <iostream>
#include <SGL/all.hpp>
#include "TileMap.hpp"

int main() {
    sgl::Window wnd(800, 600, "Flatlands");

    TileMap map("media/map.tmx");

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

        wnd.draw(map);
        wnd.display();
    }
}
