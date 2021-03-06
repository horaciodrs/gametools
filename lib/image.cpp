#include <iostream>
#include "image.hpp"

namespace GT{

    void Image::Draw(int x, int y){
    	
        img->setTexture(*Imagen);

        sf::Vector2f centro;
        
        centro.x = img->getTextureRect().width / 2.f;
        centro.y = img->getTextureRect().height / 2.f;

        img->setOrigin(centro);

        img->setPosition(x, y);
        img->setScale(FactorScaleX, FactorScaleY);

        Window->draw(*img);

    }

    void Image::Draw(int x, int y, float angle){
        
        img->setTexture(*Imagen);
        sf::Vector2f centro;
        
        if(angle == 0){
            centro.x = img->getTextureRect().width / 2.f;
            centro.y = img->getTextureRect().height / 2.f;
        }else{
            centro.x = img->getTextureRect().width / 2.f;
            centro.y = img->getTextureRect().height / 2.f;
        }
        

        img->setOrigin(centro);
        
        img->rotate(angle*180/3.14);
        
        img->setPosition(x, y);

        img->setScale(FactorScaleX, FactorScaleY);
        
        Window->draw(*img);
        
    }

    void Image::Draw(int x, int y, int l, int t, int w, int h){
        
        img->setTexture(*Imagen);
        img->setTextureRect(sf::IntRect(l, t, w, h));

        sf::Vector2f centro;
        
        centro.x = img->getTextureRect().width / 2.f;
        centro.y = img->getTextureRect().height / 2.f;

        img->setOrigin(centro);
        
        img->setPosition(x, y);

        img->setScale(FactorScaleX, FactorScaleY);

        Window->draw(*img);

    }

    Image::Image(std::string pId, std::string pUrl, sf::RenderWindow *pWindow) : Id(pId), Url(pUrl), Window(pWindow){
        
        Imagen = new sf::Texture();
        img = new sf::Sprite();

    	if(!Imagen->loadFromFile(pUrl)){
    		Imagen = NULL;
    	}

        FactorScaleX = 1;
        FactorScaleY = 1;
    		
    }

    Image::Image(){
        FactorScaleX = 1;
        FactorScaleY = 1;
    }

    Image::~Image(){

    }

}
