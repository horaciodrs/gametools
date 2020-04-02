#include <iostream>
#include <string>
#include <vector>

#include "menu.hpp"


void PantallaMenu::Init(void){

    this->App->AgregarImagen("img.gui.frame", "data/images/gui/frame.png");
    this->App->AgregarFuente("font.arcade", "data/fonts/arcade.ttf");
    //Agregar un metodo QuitarImagen para descargar los recursos cuando la pantalla muere!!!

	Frame = new GT::Object("Frame1", this->App);
    Frame->setX(this->App->GetScreenWidth()/2);
    Frame->setY(this->App->GetScreenHeight()/2);
    Frame->setImage(this->App->GetImage("img.gui.frame"));

    MyWidget = new GT::Widgets::Widget("widget.Test", this->App, this);
    MyWidget->setFocus(true);
    MyWidget->setX(15);

    MyLabel = new GT::Widgets::Label("label.Test", this->App, this);
    MyLabel->setX(Frame->getX() - Frame->getW()/2 + 40);
    MyLabel->setY(Frame->getY() - Frame->getH()/2 + 20);
    MyLabel->setFont("font.arcade");
    MyLabel->setText("Hola SFML, como estas?");
    MyLabel->setSize(40);
    MyLabel->setColor(sf::Color::White);

    lblTest = new GT::Widgets::Label("lbl.Test", this->App, this);
    lblTest->setX(MyLabel->getX() + MyLabel->getWidth());
    lblTest->setY(MyLabel->getY() + MyLabel->getHeight());
    lblTest->setFont("font.arcade");
    lblTest->setText("Este es un label de prueba...");
    lblTest->setSize(25);
    lblTest->setColor(sf::Color::Green);

    optionTest = new GT::Widgets::Option("option.Test", this->App, this);
    optionTest->setX(300);
    optionTest->setY(500);
    optionTest->setTitle("Controlador");
    optionTest->setSize(40);
    optionTest->setColor(sf::Color::White);

    MyLabel->Init();

}

void PantallaMenu::Render(){

    Frame->Draw();
    MyWidget->Draw();
    MyLabel->Draw();
    lblTest->Draw();
    optionTest->Draw();

}

void PantallaMenu::Salir(std::string pPantallaId){

    this->Running = false;
    this->App->SetPantallaActiva(pPantallaId);

}

void PantallaMenu::EventHandler(void){

    if(this->isKeyActive[GT::keyEscape]){
        this->Salir("");
    }

}

void PantallaMenu::OnWindowResize(void){

}

void PantallaMenu::End(){

    delete Frame;
    delete MyWidget;
    delete MyLabel;
    delete lblTest;

}

PantallaMenu::PantallaMenu(std::string pId, GT::Application *pApp) : Pantalla(pId, pApp){

}

PantallaMenu::~PantallaMenu(){
    End();
}
