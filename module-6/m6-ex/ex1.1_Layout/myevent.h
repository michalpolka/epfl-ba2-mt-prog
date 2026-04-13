#ifndef GTKMM_MY_EVENT_H
#define GTKMM_MY_EVENT_H

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/drawingarea.h>

class MyEvent : public Gtk::Window
{
public:
	MyEvent();

private:
	// GUI layout
	Gtk::Box m_Main_Box;
	Gtk::Box m_Panel_Box;
	Gtk::Box m_Buttons_Box;
	Gtk::Frame m_Panel_Frame;
	Gtk::Button m_Button_Draw;
	Gtk::Button m_Button_Clear;
	Gtk::DrawingArea m_Area;

	bool draw ; // current drawing state

	//Button Signal handlers:
	void on_button_clicked_clear();
	void on_button_clicked_draw();

	// DrawingArea signal handler:
	void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, 
		         int width, int height);
};

#endif // GTKMM_MY_EVENT_H
