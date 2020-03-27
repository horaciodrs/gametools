#ifndef __WIDGET_OPTION__
#define __WIDGET_OPTION__

#include "widget.hpp"
#include "label.hpp"

namespace GT{

    namespace Widget{

        class Option : public GT::Widget{

            private:
                std::string Title;
                int Size;
                sf::Color textColor;
                sf::Color focusColor;
                std::vector<std::string> Options;
                GT::Label lblTitulo;
                GT::Label lblValue;
                GT::Label lblPrevious;
                GT::Label lblNext;

            public:
                void setSize(int pSize);
                void setTitle(std::string pTitle);
                void setColor(sf::Color pColor);
                void setFocusColor(std::Color pColor);
                void setOptions(std::vector<std::string> pOpciones);
                void Run(string *refSelectedOption);    //Funcion encargada de controlar la seleccion de opciones.

                
                virtual void Init(void);
                virtual void Draw(void);
                virtual void OnWindowResize(void);
                virtual void EventHandler(void);
                virtual void End(void);

                Option(void);
                ~Option(void);

        };

    }

}

#endif
