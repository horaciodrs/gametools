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

            //Caundo se cargan las opciones. Podemos calcular la opcion que requiere mas ancho.
            //para establecer el ancho destinado a las opciones. De esta forma vamos a poder
            //ubicar de forma correcta las flechas derecha e izquierda para controlar
            //la opcion seleccionada.
            
            maxWidthCalc();

        }

        void Option::maxWidthCalc(void){

            int maxWidth = 0;
            int anchoActual = 0;

            for(int i=0; i < Options.size(); i++){

                GT::Widgets::Label *auxLabel = new GT::Widgets::Label("lbl.width.aux", this->App, this->Screen);;

                auxLabel->setFont("font.arcade");
                auxLabel->setText(Options[i]);
                auxLabel->setSize(40);

                auxLabel->Init();

                anchoActual = auxLabel->getWidth();

                if(anchoActual > maxWidth){
        
                     maxWidth = anchoActual;

                }

                delete auxLabel;

            }

            optionMaxWidth = maxWidth;

        }

        void Option::selectOption(int pOption){

            selectedOption = pOption;

            //Puede ocurrir que se llame a esta funcion y todavía no este
            //creado el lblValue...
            //Habría que poner una validación o un try

            if((selectedOption >= 0) && (selectedOption < Options.size())){
                lblValue->setText(Options[selectedOption]);
            }else{
                lblValue->setText("");
                selectedOption = -1;
            }

        }

        void Option::selectOption(std::string pOption){

            bool Encontro = false;

            for(int i=0; i<Options.size(); i++){
                if(Options[i] == pOption){
                    Encontro = true;
                    selectedOption = i;
                    lblValue->setText(Options[i]);
                    break;
                }
            }

            if(!Encontro){
                lblValue->setText("");
                selectedOption = -1;
            }

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

            maxWidthCalc();

            lblValue = new GT::Widgets::Label("lbl.Vaue", this->App, this->Screen);
            lblValue->setX(X + this->Width - optionMaxWidth - Size);
            lblValue->setY(Y);
            lblValue->setFont("font.arcade");
            lblValue->setSize(Size);
            lblValue->setColor(textColor);

            selectOption(selectedOption);
            
            lblPrevious = new GT::Widgets::Label("lbl.Previous", this->App, this->Screen);
            lblPrevious->setX(X + this->Width - optionMaxWidth - Size*2);
            lblPrevious->setY(Y);
            lblPrevious->setFont("font.arcade");
            lblPrevious->setText("<");
            lblPrevious->setSize(Size);
            lblPrevious->setColor(textColor);

            lblNext = new GT::Widgets::Label("lbl.Next", this->App, this->Screen);
            lblNext->setX(X + this->Width);
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
            optionMaxWidth = 0;
            selectedOption = -1;

        }
        
        Option::Option(std::string pId, GT::Application *pApp, GT::Pantalla *Pantalla) : Widget(pId, pApp, Pantalla){

            Title = "Default Option";
            textColor = sf::Color::White;
            focusColor = sf::Color::White;
            Size = 40;
            setX(0);
            setY(0);
            optionMaxWidth = 0;
            selectedOption = -1;

        }
        
        Option::Option(std::string pId, std::string pTitle, GT::Application *pApp, GT::Pantalla *Pantalla) : Widget(pId, pApp, Pantalla){

            Title = pTitle;
            textColor = sf::Color::White;
            focusColor = sf::Color::White;
            Size = 40;
            setX(0);
            setY(0);
            optionMaxWidth = 0;
            selectedOption = -1;

        }
        
        Option::Option(std::string pId, std::string pTitle, std::vector<std::string> pOptions, GT::Application *pApp, GT::Pantalla *Pantalla) : Widget(pId, pApp, Pantalla){

            Title = pTitle;
            Options = pOptions;
            textColor = sf::Color::White;
            focusColor = sf::Color::White;
            Size = 40;
            setX(0);
            setY(0);
            optionMaxWidth = 0;
            selectedOption = -1;

        }
        
        Option::~Option(void){

            delete lblTitulo;
            delete lblValue;
            delete lblPrevious;
            delete lblNext;

            //Widget::~Widget(); No es necesario llamarlo manualmente.
            //Es decir, el destructor de la clase padre se ejecuta automaticamente.

        }

    }

}
