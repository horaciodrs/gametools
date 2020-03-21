#include "game.hpp"
#include "menu.hpp"

void MyGame::Init(){

    this->setDesignWidth(1280);
    this->setDesignHeight(720);
    
    PantallaMenu *Menu = new PantallaMenu("Pantalla.Menu", this);

    this->AgregarPantalla(Menu);

    this->SetPantallaActiva("Pantalla.Menu");

}

void MyGame::End(){
    
}

MyGame::MyGame(std::string title) : GT::Application(title){

}

MyGame::~MyGame(){
    End();
}