#include "widget.hpp"

namespace GT{

    void Widget::Init(void){
        //Esta funcion es virtual.
        //Se debe declarar en la clase hija.

    }


    void Widget::Draw(void){
        //Esta funcion es virtual.
        //Se debe declarar en la clase hija.

    }


    void Widget::EventHandler(void){
        //Esta funcion es virtual.
        //Se debe declarar en la clase hija.

    }

    void Widget::OnWindowResize(void){
        //Esta funcion es virtual.
        //Se debe declarar en la clase hija.

    }

    void Widget::End(void){
        //Esta funcion es virtual.
        //Se debe declarar en la clase hija.

    }

    Widget::Widget(std::string pId, GT::Application *pApp, GT::Pantalla *pPantalla){


        Id = pId;
        App = pApp;
        Screen = pPantalla;

    }


    Widget::Widget(){

    }

    Widget::~Widget(){

    }

}
