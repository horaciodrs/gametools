#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Font.hpp>
#include "image.hpp"
#include "font.hpp"
#include "sound.hpp"
#include "object_manager.hpp"
#include "pantalla.hpp"

namespace GT{

	class Pantalla;

	class Application{

		private:
			int Width;
			int Height;
			sf::RenderWindow *Window;
			ObjectManager<GT::Pantalla *> Pantallas;
            ObjectManager<GT::Image> Images;
            ObjectManager<GT::Sound> Sounds;
            ObjectManager<GT::Font> Fonts;
			GT::Pantalla *PantallaActiva;
		public:
			friend class GT::Pantalla;
			bool doIt(int prov, int range);
			void UpdateScreenWidth(int w){Width = w;}
			void UpdateScreenHeight(int h){Height = h;}
			int GetScreenWidth(void){return Width;}
			int GetScreenHeight(void){return Height;}
			GT::Pantalla *GetPantallaActiva(void){return PantallaActiva;}
            GT::Image *GetImage(std::string pId);
            GT::Font *GetFont(std::string pId);
            void PlaySound(std::string pId, int volumen, bool loop);
			void StopSound(std::string pId);
			sf::RenderWindow *GetRenderWindow(void){return Window;}
			void SetPantallaActiva(std::string pId);
            void AgregarImagen(std::string pId, std::string pUrl);
            void AgregarSonido(std::string pId, std::string pUrl);
            void AgregarFuente(std::string pId, std::string pUrl);
			void AgregarPantalla(GT::Pantalla *p);
			void EscribirTexto(std::string fontId, std::string srt, int size, int x, int y);
			void EscribirTexto(std::string fontId, std::string srt, int size, int x, int y, sf::Color color);
			void Init(void);
			void Run(void);
			Application(int w, int h, std::string title);
			~Application();

	};

}

#endif
