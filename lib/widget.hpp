#ifndef __GAME_WIDGET__
#define __GAME_WIDGET__

#include<string>
#include "application.hpp"
#include "pantalla.hpp"

namespace GT{

    class Widget{
        private:
            std::string Id;
            Application *App;
            Pantalla *Screen;
            Widget *Parent;
            bool Focus;
            bool Focusable;
            int Left;
            int Top;
            int Width;
            int Height;
        public:
            /**SETTERS**/
            void setParent(GT::Widget *pParent);
            void setApplication(GT::Application *pApp);
            void setPantalla(GT::Pantalla *pPantalla);
            void setFocus(bool pFocus){Focus = pFocus;}
            void setFocusable(bool pFocusable){Focusable = pFocusable;}
            void setTop(int pTop){Top = pTop;}
            void setLeft(int pLeft){Left = pLeft;}
            void setWidth(int pWidth){Width = pWidth;}
            void setHeight(int pHeight){Height = pHeight;}
            /**GETTERS**/
            GT::Widget *getParent(void){return Parent;}
            GT::Application *getApplication(void){return App;}
            GT::Pantalla *getPantalla(void){return Screen;}
            bool getFocus(void){return Focus;}
            bool getFocusable(void){return Focusable;}
            int getTop(void){return Top;}
            int getLeft(void){return Left;}
            int getWidht(void){return Width;}
            int getHeight(void){return Height;}

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

#endif
