#ifndef __WIDGET_OPTION__
#define __WIDGET_OPTION__

#include "widget.hpp"
#include "widget_label.hpp"

namespace GT{

    namespace Widgets{

        class Option : public GT::Widget{

            private:
                std::string Title;
                int Size;
                sf::Color textColor;
                sf::Color focusColor;
                std::vector<std::string> Options;
                GT::Label *lblTitulo;
                GT::Label *lblValue;
                GT::Label *lblPrevious;
                GT::Label *lblNext;

            public:
                void setSize(int pSize);
                void setTitle(std::string pTitle);
                void setColor(sf::Color pColor);
                void setFocusColor(sf::Color pColor);
                void setOptions(std::vector<std::string> pOptions);
                void Run(void);

                
                virtual void Init(void);
                virtual void Draw(void);
                virtual void OnWindowResize(void);
                virtual void EventHandler(void);
                virtual void End(void);

                Option(void);
                Option(std::string pId, GT::Application *pApp, GT::Pantalla *Pantalla);
                Option(std::string pId, std::string pTitle, GT::Application *pApp, GT::Pantalla *Pantalla); 
                Option(std::string pId, std::string pTitle, std::vector<std::string> pOptions, GT::Application *pApp, GT::Pantalla *Pantalla);
                ~Option(void);

        };

    }

}

#endif
