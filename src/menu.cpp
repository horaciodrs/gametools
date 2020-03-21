#include <iostream>
#include <string>
#include <vector>

#include "menu.hpp"
#include "../lib/object.hpp"

void PantallaMenu::Init(void){

    this->App->AgregarImagen("img.gui.frame", "data/images/gui/frame.png");
    //Agregar un metodo QuitarImagen para descargar los recursos cuando la pantalla muere!!!

	Frame = new GT::Object("Frame1", this->App);
    
    Frame->setX(this->App->GetScreenWidth()/2);
    Frame->setY(this->App->GetScreenHeight()/2);

    Frame->setImage(this->App->GetImage("img.gui.frame"));

}

void PantallaMenu::Render(){
    
    Frame->Draw();

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
    
}

PantallaMenu::PantallaMenu(std::string pId, GT::Application *pApp) : Pantalla(pId, pApp){

}

PantallaMenu::~PantallaMenu(){
    End();
}
