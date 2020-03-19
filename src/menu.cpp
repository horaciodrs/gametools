#include <iostream>
#include <string>
#include <vector>

#include "menu.hpp"
#include "../lib/object.hpp"

void PantallaMenu::Init(void){

	
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

void PantallaMenu::Render(void){


}

void PantallaMenu::OnWindowResize(void){


}

void PantallaMenu::End(){
    
}

PantallaMenu::PantallaMenu(std::string pId, GT::Application *pApp) : Pantalla(pId, pApp){

}

PantallaMenu::~PantallaMenu(){
    End();
}
