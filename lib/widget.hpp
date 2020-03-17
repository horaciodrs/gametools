#ifndef __GAME_WIDGET__

#include<string>
#include "object.hpp"

namespace GT{

    class Application;
    class Pantalla;

    class Widget{
        private:
            std::string Id;
            Application *App;
            Pantalla *Screen;
            bool Focus;
        public:
            Widget();
            ~Widget();
    }
}

#define __GAME_WIDGET__
#endif