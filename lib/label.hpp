#ifndef __GAME_LABEL__
#define __GAME_LABEL__

#include "widget.hpp"

namespace GT{

    class Label : public GT::Widget{

        private:
            std::string *Text;                      //Texto para mostrar.
            std::string *Font;                      //Id(string) de la fuente a utilizar.
            int Size;                               //Tamaño de la tipografía.

        public:
            /**SETTERS**/
            void setText(std::string pText);
            void setFont(std::string pFont);
            void setSize(int pSize);
            /**GETTERS**/
            std::string getText(void);
            std::string getFont(void);
            int getSize(void);
            int getWidth(void);
            int getHeight(void);


            virtual void Init(void);
            virtual void Draw(void);
            virtual void EventHandler(void);
            virtual void OnWindowResize(void);
            virtual void End(void);

            Label(void);
            Label(std::string pId, GT::Application *pApp, GT::Pantalla *Pantalla);
            Label(std::string pId, std::string pText, GT::Application *pApp, GT::Pantalla *Pantalla);
            virtual ~Label();

    };

}

#endif
