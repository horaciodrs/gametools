#include "game.hpp"
#include "menu.hpp"

void MyGame::Init(){

    PantallaMenu *Menu = new PantallaMenu("Pantalla.Menu", this);

    this->AgregarPantalla(Menu);

    this->SetPantallaActiva("Pantalla.Menu");

}

void MyGame::End(){
    
}

MyGame::MyGame(int w, int h, std::string title) : GT::Application(w, h, title){

}

MyGame::~MyGame(){
    End();
}