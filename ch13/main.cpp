// g++ main.cpp ./Graph.cpp ./Window.cpp ./GUI.cpp ./Simple_window.cpp -o main `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point beginning {100,100};
	int win_x=800, win_y=1000;

	Simple_window win (beginning,win_x,win_y,"Drill");





	int grid_x=100;
	int grid_y=100;

	Lines grid;

	for(int x=grid_x;x<win_x;x+=grid_x)
	{
		grid.add(Point{x,0},Point(x,win_y-200));
	}

	for(int y=grid_y;y<win_y;y+=grid_y)
	{
		grid.add(Point{0,y},Point(win_x,y));
	}	

	win.attach(grid);





	Vector_ref<Graph_lib::Rectangle> reds;

	for(int i=0;i<8;i++)
	{
		reds.push_back(new Rectangle {Point{i*100,i*100}, 100, 100});
		reds[i].set_fill_color(Color::red);
		win.attach(reds[i]);
	}






	Image pic1 {Point{400,100}, "android.jpg"};
	win.attach(pic1);
	Image pic2 {Point{600,300}, "android.jpg"};
	win.attach(pic2);
	Image pic3 {Point{100,400}, "android.jpg"};
	win.attach(pic3);
	Image pic4 {Point{300,600}, "android.jpg"};
	win.attach(pic4);

	Image pontok{Point{0,0}, "pontok.jpg"};
	win.attach(pontok);

	win.wait_for_button();





	int rows_done=0;
	while(true)
	{
		for(int i=0;i<7;i++)
		{
			pontok.move(100,0);
			win.wait_for_button();
		}
		if(rows_done==7)
		{
			rows_done=0;
			pontok.move(-700,-700);
		}
		else
		{
			pontok.move(-700,100);
			rows_done++;
		}
		win.wait_for_button();
	}


	
	

	win.wait_for_button();
}