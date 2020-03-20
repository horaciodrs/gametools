#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "src/game.hpp"
#include "lib/object_manager.hpp"

int main(int argc, char const** argv){

	MyGame *App = new MyGame("Mi Juego en SFML");

	App->Init();

	App->Run();

	delete App;

	return EXIT_SUCCESS;

}
