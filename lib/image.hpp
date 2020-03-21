#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

#include <SFML/Graphics.hpp>

namespace GT{

    class Image{
        
        private:
            std::string Id;
            std::string Url;
            sf::Texture *Imagen;
            sf::Sprite *img;
            sf::RenderWindow *Window;
            float FactorScaleX;
            float FactorScaleY;
        public:
            void setFactorScaleX(float sx){FactorScaleX = sx;}
            void setFactorScaleY(float sy){FactorScaleY = sy;}
            std::string getId(){return Id;}
            std::string getUrl(){return Url;}
            int getWidth(){return Imagen->getSize().x;}
            int getHeight(){return Imagen->getSize().y;}
            sf::Texture* getImage(void){return Imagen;}
            void Draw(int x, int y);
            void Draw(int x, int y, float angle);
            void Draw(int x, int y, int l, int t, int w, int h);
            Image(std::string pId, std::string pUrl, sf::RenderWindow *pWindow);
            Image();
            ~Image();

    };

}

#endif
