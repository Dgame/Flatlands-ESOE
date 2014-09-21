#ifndef SGL_WINDOW_HPP
#define SGL_WINDOW_HPP

#include <string>
#include <vector>
#include <SGL/Core/Init.hpp>
#include <SGL/Math/mat4.hpp>
#include <SGL/Math/vec2.hpp>
#include <SGL/Math/Vertex.hpp>

namespace sgl {
    class Texture;
    class Drawable;
    class Surface;
    enum class Geometry;

    enum class SwapMode {
        Immediate = 0,
        Synchronize = 1,
        LateSwapTearing = -1
    };

    class Window {
    public:
        enum Style {
            Fullscreen = SDL_WINDOW_FULLSCREEN,
            Desktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
            Shown = SDL_WINDOW_SHOWN,
            Hidden = SDL_WINDOW_HIDDEN,
            Borderless = SDL_WINDOW_BORDERLESS,
            Resizeable = SDL_WINDOW_RESIZABLE,
            Minimized = SDL_WINDOW_MINIMIZED,
            Maximized = SDL_WINDOW_MAXIMIZED,
            Focus = SDL_WINDOW_INPUT_GRABBED,
            InputFocus = SDL_WINDOW_INPUT_FOCUS,
            MouseFocus = SDL_WINDOW_MOUSE_FOCUS,
            HighDPI = SDL_WINDOW_ALLOW_HIGHDPI,

            Windowed = 0,

            Default = Shown | HighDPI
        };

    private:
        static int32 _count;
        bool _open;

        mat4x4 _projection;

        SDL_Window* _window;
        SDL_GLContext _context;

    public:
        explicit Window(uint16 width, uint16 height, const std::string&, Style style = Style::Default);
        explicit Window(const ShortRect&, const std::string&, Style style = Style::Default);
        Window(const Window&) = delete;

        virtual ~Window();

        void close() {
            _open = false;
        }

        bool isOpen() const {
            return _open;
        }

        Style getStyle() const;
        void toggle(Style style) const;

        mat4x4& getProjection() {
            return _projection;
        }

        void loadProjection() const;

        void setClearColor(const Color4b&) const;
        void clear() const;

        void setVisible(bool visible) const;
        void setBorder(bool enable) const;
        void setScreenSaver(bool enable) const;
        bool hasScreenSaver() const;
        void setIcon(const Surface&) const;
        void setSwapMode(SwapMode mode) const;
        SwapMode getSwapMode() const;

        void maximize() const;
        void minimize() const;
        void restore() const;
        void raise() const;

        void setPosition(int16 x, int16 y) const;
        void setPosition(const vec2s&) const;
        void setSize(uint16 width, uint16 height) const;
        void setRect(const ShortRect&) const;

        vec2s getPosition() const;
        ShortRect getRect() const;

        void setTitle(const std::string&) const;
        std::string getTitle() const;

        void draw(const Drawable&) const;
        void draw(Geometry geo, const mat4x4&, const std::vector<Vertex>&, const Texture*) const;
        void draw(Geometry geo, const mat4x4&, const Texture&, const Vertex*, uint16 vCount) const;
        void display() const;
    };
}

#endif