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

            int options_width = 100;

            lblTitulo = new GT::Widgets::Label("lbl.Titulo", this->App, this->Screen);
            lblTitulo->setX(X);
            lblTitulo->setY(Y);
            lblTitulo->setFont("font.arcade");
            lblTitulo->setText(Title);
            lblTitulo->setSize(Size);
            lblTitulo->setColor(textColor);

            lblValue = new GT::Widgets::Label("lbl.Vaue", this->App, this->Screen);
            lblValue->setX(X + this->Width - options_width - Size);
            lblValue->setY(Y);
            lblValue->setFont("font.arcade");
            lblValue->setText("Opcion 1");
            lblValue->setSize(Size);
            lblValue->setColor(textColor);
            
            lblPrevious = new GT::Widgets::Label("lbl.Previous", this->App, this->Screen);
            lblPrevious->setX(X + this->Width - options_width - Size*2);
            lblPrevious->setY(Y);
            lblPrevious->setFont("font.arcade");
            lblPrevious->setText("<");
            lblPrevious->setSize(Size);
            lblPrevious->setColor(textColor);
            
            lblNext = new GT::Widgets::Label("lbl.Next", this->App, this->Screen);
            lblNext->setX(X + this->Width - Size);
            lblNext->setY(Y);
            lblNext->setFont("font.arcade");
            lblNext->setText(">");
            lblNext->setSize(Size);
            lblNext->setColor(textColor);
    

        }

        void Option::Draw(void){

            Widget::Draw();

            lblTitulo->Draw();
            lblValue->Draw();
            lblNext->Draw();
            lblPrevious->Draw();

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
            Size = 40;
            setX(0);
            setY(0);

        }
        
        Option::Option(std::string pId, GT::Application *pApp, GT::Pantalla *Pantalla) : Widget(pId, pApp, Pantalla){

            Title = "Default Option";
            textColor = sf::Color::White;
            focusColor = sf::Color::White;
            Size = 40;
            setX(0);
            setY(0);

        }
        
        Option::Option(std::string pId, std::string pTitle, GT::Application *pApp, GT::Pantalla *Pantalla) : Widget(pId, pApp, Pantalla){

            Title = pTitle;
            textColor = sf::Color::White;
            focusColor = sf::Color::White;
            Size = 40;
            setX(0);
            setY(0);

        }
        
        Option::Option(std::string pId, std::string pTitle, std::vector<std::string> pOptions, GT::Application *pApp, GT::Pantalla *Pantalla) : Widget(pId, pApp, Pantalla){

            Title = pTitle;
            Options = pOptions;
            textColor = sf::Color::White;
            focusColor = sf::Color::White;
            Size = 40;
            setX(0);
            setY(0);

        }
        
        Option::~Option(void){

            delete lblTitulo;
            delete lblValue;
            delete lblPrevious;
            delete lblNext;

            Widget::~Widget();

        }

    }

}
