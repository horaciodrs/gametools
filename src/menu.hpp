#ifndef __PANTALLA_MENU__
#define __PANTALLA_MENU__

#include "../lib/object_manager.hpp"
#include "../lib/object.hpp"
#include "../lib/pantalla.hpp"
#include "../lib/widget.hpp"
#include "../lib/widget_label.hpp"

class PantallaMenu : public GT::Pantalla{

	private:
		GT::Object *Frame;
        GT::Widgets::Widget *MyWidget;
        GT::Widgets::Label *MyLabel;
        GT::Widgets::Label *lblTest;

	public:
		void Init(void);
		void Render(void);
		void EventHandler(void);
        void Salir(std::string pPantallaId);
		void OnWindowResize(void);
        void End(void);
		PantallaMenu(std::string pId, GT::Application *pApp);
		~PantallaMenu();

};

#endif
