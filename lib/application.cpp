#include "application.hpp"
#include "configfile.h"

namespace GT{

    bool Application::doIt(int prov, int range){

        int sorteo = rand() % range;

        if(prov > sorteo){
            return true;
        }

        return false;

    }

	void Application::PlaySound(std::string pId, int volumen, bool loop){

		Sounds.Get(pId)->Play(volumen, loop);

	}

    void Application::StopSound(std::string pId){
        Sounds.Get(pId)->Stop();
    }

    void Application::EscribirTexto(std::string fontId, std::string str, int size, int x, int y, sf::Color color){

		GT::Font *Fnt = this->Fonts.Get(fontId);

		Fnt->Draw(str, size, x, y, 0, color);

	}

	void Application::EscribirTexto(std::string fontId, std::string str, int size, int x, int y){

		GT::Font *Fnt = this->Fonts.Get(fontId);

		Fnt->Draw(str, size, x, y);

	}

	void Application::SetPantallaActiva(std::string pId){

        if(pId == ""){
            
            if(PantallaActiva != NULL){
                PantallaActiva->End();
            }

            PantallaActiva = NULL;

        }else{
            
            if(PantallaActiva != NULL){
                PantallaActiva->End();
            }
		    
            PantallaActiva = Pantallas.Get(pId);
        }

	}

    GT::Image* Application::GetImage(std::string pId){

        return Images.Get(pId);

    }

    GT::Font* Application::GetFont(std::string pId){

        return Fonts.Get(pId);

    }

    void Application::AgregarImagen(std::string pId, std::string pUrl){

        GT::Image i(pId, pUrl, Window);

        Images.Add(i);

    }

    void Application::AgregarFuente(std::string pId, std::string pUrl){

        GT::Font i(pId, pUrl, Window);

        Fonts.Add(i);

    }

    void Application::AgregarSonido(std::string pId, std::string pUrl){

        GT::Sound s(pId, pUrl);

        Sounds.Add(s);

    }

	void Application::AgregarPantalla(GT::Pantalla *p){

		Pantallas.Add(p);

	}

	void Application::Run(void){

        while(PantallaActiva != NULL){

            PantallaActiva->Init();
			
            PantallaActiva->Run();
		    
        }

	}

	void Application::Init(void){
        //Esta función es virtual. Se define en la
        //clase heredada.

	}

	Application::Application(std::string title){

        ConfigFile GameSettings("game.cfg");

		Width = GameSettings.Value("graphics", "width");
		Height = GameSettings.Value("graphics", "height");
        int FrameRateLimit = GameSettings.Value("graphics", "limitfps");
        std::string VerticalSync = GameSettings.Value("graphics", "limitfps");
        std::string FullScreen = GameSettings.Value("graphics", "fullscreen");

        if(FullScreen == "true"){
            Window = new sf::RenderWindow(sf::VideoMode(Width, Height), title, sf::Style::Fullscreen);
        }else{
            Window = new sf::RenderWindow(sf::VideoMode(Width, Height), title, sf::Style::Default);
        }
		
		Window->setFramerateLimit(FrameRateLimit);

        if(VerticalSync == "true"){
            Window->setVerticalSyncEnabled(true);
        }else{
            Window->setVerticalSyncEnabled(false);
        }

        DesignWidth = Width;
        DesignHeight = Height;
		
		PantallaActiva = NULL;

	}

	Application::~Application(){
		delete Window;
	}

}
