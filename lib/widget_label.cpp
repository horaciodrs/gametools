#include "label.hpp"

namespace GT{

    namespace Widgets{

        void Label::setColor(sf::Color pColor){

        fontColor = pColor;

        }

        sf::Color Label::getColor(void){

            return fontColor;

        }

        int Label::getWidth(void){

            return this->App->GetFont(*Font)->getWidth(*Text, Size);

        }

        int Label::getHeight(void){

        return this->App->GetFont(*Font)->getHeight(*Text, Size);

        }

        /**
         * Asigna el texto que muestra el Label.
         *
         * @param pText El texto a asignar.
         */
        void Label::setText(std::string pText){

            this->Text = new std::string(pText);

        }

        /**
         * Asigna la fuente a utilizar por el Label.
         *
         * @param pFont std::string con el Id de la fuente cargada previamente en la Aplicacion.
         */

        void Label::setFont(std::string pFont){

            this->Font = new std::string(pFont);

        }

        /**
         * Asigna el tamaño de la fuente que utilizará el Label.
         *
         * @param pSize El tamaño de la fuente.
         */

        void Label::setSize(int pSize){

            this->Size = pSize * this->App->getScaleFactorX();

        }

        /**
         * Retorna el texto que tiene asignado el Label.
         *
         * @return std::string con el texto del Label.
         */

        std::string Label::getText(void){

            return *this->Text;

        }

        /**
         *
         * Retorna el ID de la  fuente  que tiene asignada el Label.
         *
         * @return std::string con la fuente del Label.
         *
         */

        std::string Label::getFont(void){

            return *this->Font;

        }

        void Label::Init(void){

            Widget::Init();

        }


        void Label::Draw(void){

            Widget::Draw();

            this->App->EscribirTexto(*this->Font, *this->Text, this->Size, this->X, this->Y, this->fontColor);

        }


        void Label::EventHandler(void){

            Widget::EventHandler();

        }

        void Label::OnWindowResize(void){

            Widget::OnWindowResize();

        }

        void Label::End(void){

            Widget::End();

        }

        Label::Label(void) : Widget(){

        }

        Label::Label(std::string pId, GT::Application *pApp, GT::Pantalla *pPantalla) : Widget(pId, pApp, pPantalla){


        }

        Label::Label(std::string pId, std::string pText, GT::Application *pApp, GT::Pantalla *pPantalla) : Widget(pId, pApp, pPantalla){

            this->Text = new std::string(pText);

        }

        Label::~Label(void){

            Widget::~Widget();

        }

    }

}
