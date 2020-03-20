#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include <iostream>
#include <math.h>
#include "application.hpp"
#include "image.hpp"

namespace GT{

	//class Application;

	class Object{

		protected:
			std::string Id;			//Id para colecion de Objectos.
			int x;					//Posicion x.
			int y;					//Posicion y.
			int w;					//Ancho del objeto.
			int h;					//Alto del objeto.
			int dx;
			int dy;
			float angle;			//Angulo de la imagen.
			float FactorScaleX;
			float FactorScaleY;
			GT::Image *Image;		//Puntero al Asset;
			GT::Application *App;	//Puntero a la aplicacion.
		public:
			/*SETTERS*/
			void setFactorScaleX(float sx);
            void setFactorScaleY(float sy);
			void setImage(GT::Image *pImage);
			void setX(int pX){x = pX;}
			void setY(int pY){y = pY;}
			void setApplication(GT::Application *pApp){App = pApp;}
			void setAngle(float pAngle){angle = pAngle;}
			/*GETTERS*/
			GT::Image *getImage(void){return Image;}
			std::string getId(void){return Id;}
			std::string getImageId(void){return Image->getId();}
			int getX(){return x;}
			int getY(){return y;}
			int getW(){return w;}
			int getH(){return h;}
			float getAngle(){return angle;}
			float getDistance(GT::Object *AnotherObject);
			/*CHANGE POSITION*/
			void changeX(int increment);
			void changeY(int increment);
			void changeAngle(float increment);
			void calculateDiferencial(int Velocidad);
			void moveByAngle(int Velocidad);
			bool CheckCollision(GT::Object *AnotherObject);
			void followObject(GT::Object *AnotherObject, int Velocidad);
			void Draw(int x, int y);
			void Draw(int x,int y,int l,int t,int w,int h);
			virtual void EventHandler(sf::Event *event);
			virtual void Draw();
			Object(std::string pId);
			Object(std::string pId, GT::Application *pApp);
			virtual ~Object(){};

	};

}

#endif
