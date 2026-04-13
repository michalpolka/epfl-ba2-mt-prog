#include <string>
#include <gtkmm.h>

class MyWindow : public Gtk::Window
{
public:
	MyWindow(std::string name);
};

MyWindow::MyWindow(std::string name)
{
	set_title(name);
}

int main(int argc, char* argv[])
{
	std::string init(argc>1?argv[1]:argv[0]);
	
	// le mot auto demande au compilateur de déterminer le type de la variable app
	auto app = Gtk::Application::create();
		
	// le premier paramètre argc prend la valeur 1 pour ne pas utiliser argv plus loin
	return app->make_window_and_run<MyWindow>(1, argv,init);
}
