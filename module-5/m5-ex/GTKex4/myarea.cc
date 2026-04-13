#include "myarea.h"
#include <cairomm/context.h>
#include <math.h>

#include "../../../../../../../Library/Developer/CommandLineTools/SDKs/MacOSX26.sdk/usr/include/math.h"
#include "../../../../../../../Library/Developer/CommandLineTools/SDKs/MacOSX26.sdk/usr/include/math.h"

MyArea::MyArea()
{
  set_draw_func(sigc::mem_fun(*this, &MyArea::on_draw));
}

MyArea::~MyArea()
{
}

void MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr,
                      int width, int height)
{
	// changing the background color to black
	cr->set_source_rgb(1., 1., 1.);
	cr->paint();

	cr->set_line_width(7.0);
	
	// draw red lines out from the center of the window
	cr->set_source_rgb(1., 0.0, 0.0);

	// E
	cr->move_to(7, 7);
	cr->line_to(7, 20);
	cr->move_to(7, 26);
	cr->line_to(7, 40);
	cr->stroke();

	cr->set_line_width(6.0);
	cr->move_to(10.5,10);
	cr->line_to(26.5,10);
	cr->move_to(10.5,23);
	cr->line_to(23.5,23);
	cr->move_to(10.5,37);
	cr->line_to(26.5,37);
	cr->stroke();

	// P
	cr->set_line_width(7.0);
	cr->move_to(33.5, 7);
	cr->line_to(33.5, 40);
	cr->move_to(37,10.5);
	cr->line_to(44,10.5);
	cr->arc(44,17.5,7,3*M_PI/2,M_PI/2);
	cr->move_to(37,24.5);
	cr->line_to(44,24.5);
	cr->stroke();

	// F
	cr->move_to(65, 7);
	cr->line_to(65, 20);
	cr->move_to(65, 26);
	cr->line_to(65, 40);
	cr->stroke();

	cr->set_line_width(6.0);
	cr->move_to(68.5,10);
	cr->line_to(84.5,10);
	cr->move_to(68.5,23);
	cr->line_to(81.5,23);
	cr->stroke();


	cr->stroke();
}
