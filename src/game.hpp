#ifndef __MY_GAME__
#define __MY_GAME__

#include "../lib/application.hpp"
#include "../lib/pantalla.hpp"

class MyGame : public GT::Application{
    private:
        
    public:
        void Init(void);
        void End(void);
        MyGame(int w, int h, std::string title);
        ~MyGame();
};

#endif