#ifndef __GAME_WIDGET__
#define __GAME_WIDGET__

#include<string>
#include "application.hpp"
#include "pantalla.hpp"

namespace GT{

    namespace Widgets{

        class Widget{
            protected:
                std::string Id;
                Application *App;
                Pantalla *Screen;
                Widget *Parent;
                bool Focus;
                bool Focusable;
                int X;
                int Y;
                int Width;
                int Height;
            public:
                /**SETTERS**/
                void setParent(GT::Widget *pParent);
                void setApplication(GT::Application *pApp);
                void setPantalla(GT::Pantalla *pPantalla);
                void setFocus(bool pFocus){Focus = pFocus;}
                void setFocusable(bool pFocusable){Focusable = pFocusable;}
                void setY(int pY){Y = pY;}
                void setX(int pX){X = pX;}
                void setWidth(int pWidth){Width = pWidth;}
                void setHeight(int pHeight){Height = pHeight;}
                /**GETTERS**/
                GT::Widget *getParent(void){return Parent;}
                GT::Application *getApplication(void){return App;}
                GT::Pantalla *getPantalla(void){return Screen;}
                bool getFocus(void){return Focus;}
                bool getFocusable(void){return Focusable;}
                int getY(void){return Y;}
                int getX(void){return X;}
                virtual int getWidth(void){return Width;}
                virtual int getHeight(void){return Height;}

                virtual void Init(void);
                virtual void Draw(void);
                virtual void EventHandler(void);
                virtual void OnWindowResize(void);
                virtual void End(void);

                Widget(std::string pId, GT::Application *pApp, GT::Pantalla *pPantalla);
                Widget();
                virtual ~Widget();
        };

    }

}

#endif
