#include "widget_option.hpp"

namespace GT{

    namespace Widgets{

        
        void Option::setSize(int pSize){
            Size = pSize;
        }

        void Option::setTitle(std::string pTitle){

            Title = pTitle;

        }
        
        void Option::setColor(sf::Color pColor){

           textColor = pColor;

        }

        void Option::setFocusColor(sf::Color pColor){

            focusColor = pColor;

        }
        
        void Option::setOptions(std::vector<std::string> pOptions){

            Options = pOptions;

        }
        
        void Option::Run(void){

            
        
        }
                
        void Option::Init(void){

            Widget::Init();

            lblTitulo = new GT::Widgets::Label("lbl.Titulo", this->App, this->Screen);
            lblTitulo->setX(X);
            lblTitulo->setY(Y);
            lblTitulo->setFont("font.arcade");
            lblTitulo->setText(Title);
            lblTitulo->setSize(40);
            lblTitulo->setColor(textColor);

        }

        void Option::Draw(void){

            Widget::Draw();

            lblTitulo->Draw();

        }
        
        void Option::OnWindowResize(void){

            Widget::OnWindowResize();

        }
        
        void Option::EventHandler(void){

            Widget::EventHandler();

        }

        void Option::End(void){

            Widget::End();

        }

        Option::Option(void){

            Title = "Default Option";
            textColor = sf::Color::White;
            focusColor = sf::Color::White;
            setX(0);
            setY(0);

        }
        
        Option::Option(std::string pId, GT::Application *pApp, GT::Pantalla *Pantalla) : Widget(pId, pApp, Pantalla){

            Title = "Default Option";
            textColor = sf::Color::White;
            focusColor = sf::Color::White;
            setX(0);
            setY(0);

        }
        
        Option::Option(std::string pId, std::string pTitle, GT::Application *pApp, GT::Pantalla *Pantalla) : Widget(pId, pApp, Pantalla){

            Title = pTitle;
            textColor = sf::Color::White;
            focusColor = sf::Color::White;
            setX(0);
            setY(0);

        }
        
        Option::Option(std::string pId, std::string pTitle, std::vector<std::string> pOptions, GT::Application *pApp, GT::Pantalla *Pantalla) : Widget(pId, pApp, Pantalla){

            Title = pTitle;
            Options = pOptions;
            textColor = sf::Color::White;
            focusColor = sf::Color::White;
            setX(0);
            setY(0);

        }
        
        Option::~Option(void){

            delete lblTitulo;

            Widget::~Widget();

        }

    }

}
