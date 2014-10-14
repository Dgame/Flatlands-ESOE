#include "Background.hpp"
#include <sstream>
#include <SGL/Graphic/Surface.hpp>
#include <SGL/Window/Window.hpp>
#include "Config.hpp"

Background::Background(sgl::uint16 level) {
    std::stringstream buf;
    buf << "media/level_";
    buf << level;
    buf << ".png";

    sgl::Surface bg(buf.str());
    if (!bg) {
        std::cerr << "Could not load level background. Try to load default..." << std::endl;
        bg.loadFromFile(DEFAULT_BACKGROUND);
    }

    _bg.load(bg);
    _background.setTexture(_bg);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist_n(2, 6);

    const sgl::uint16 n = dist_n(mt);

    for (sgl::uint16 i = 0; i < n; i++) {
        std::uniform_int_distribution<> dist_which(1, 3);
        const sgl::uint16 which = dist_which(mt);

        _clouds.push_back(std::unique_ptr<Cloud>(new Cloud(which)));
    }
}

void Background::update() {
    for (std::unique_ptr<Cloud>& cloud : _clouds) {
        cloud->update();
    }
}

void Background::draw(const sgl::Window* wnd) const {
    wnd->draw(_background);

    for (const std::unique_ptr<Cloud>& cloud : _clouds) {
        cloud->draw(wnd);
    }
}
