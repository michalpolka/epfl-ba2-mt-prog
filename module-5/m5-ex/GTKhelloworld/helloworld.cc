#include "helloworld.h"
#include <iostream>

HelloWorld::HelloWorld()
    : m_butt("Quit")   // creates a new button with label "Hello World".
{
	// Sets the margin around the button.
	m_butt.set_margin(20);

	// When the button receives the "clicked" signal, it will call the
	// on_button_clicked() method defined below.
	m_butt.signal_clicked().connect(sigc::mem_fun(*this,
                                                    &HelloWorld::on_button_clicked));
	
	// This packs the button into the Window (a container).
	set_child(m_butt);
}

HelloWorld::~HelloWorld()
{
}

void HelloWorld::on_button_clicked()
{
	static unsigned count(0);
	
	std::cout << ++count << " Hello World \a" << std::endl;
	exit(1);
}
