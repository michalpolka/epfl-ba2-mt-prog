#ifndef GTKMM_BASIC_TIMER_H
#define GTKMM_BASIC_TIMER_H

#include <gtkmm.h>
#include <iostream>
#include <map>

class BasicTimer : public Gtk::Window
{
public:
    BasicTimer(int argc = 0, char* argv[] = nullptr);

private:
	Gtk::Box m_box, top_box,   bottom_box;
	Gtk::Button 	start_timer, stop_timer, quit_button;
	Gtk::Label  	text_label, data_label;
	
	// state variable to handle a single timer
	bool timer_added; 
	// state variable for the timer disconnect request
	bool disconnect; 
	// duration initialized in constructor
	const int timeout_value; 
	
	// button signal handlers
	void on_button_add_timer();
	void on_button_delete_timer();
	void on_button_quit();
	
	// Timer signal handler
	bool on_timeout();
};

#endif // GTKMM_BASIC_TIMER_H
