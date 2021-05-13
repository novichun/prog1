/*
    g++ ch12drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
try{

	using namespace Graph_lib;

    int xmax = 1280;
    int ymax = 720;
	
	Simple_window win {Point{100,100}, xmax ,ymax, "My window"};  

	win.wait_for_button();

	Axis xa {Axis::x,Point{20,300},280,10, "x axis"};   

	win.attach(xa);
	xa.set_color(Color::blue);
	win.set_label("X tengely");
    win.wait_for_button();

    Axis ya {Axis::y, Point{150,300}, 280, 10, "y axis"};  
    ya.set_color(Color::cyan);                
    ya.label.set_color(Color::dark_red);     
    win.attach(ya);
    win.set_label("y tengely");
    win.wait_for_button();

    Function sine {sin,0,100,Point{20,150},1000,50,50};   
    win.attach(sine);win.set_label("Sinus gorbe");
    sine.set_color(Color::blue);
    win.wait_for_button();

    Polygon poly;
    poly.add(Point{300,200});      
    poly.add(Point{350,100});
    poly.add(Point{400,200});
    poly.set_color(Color::red);
    poly.set_style(Line_style(Line_style::dash,2));
    win.attach(poly);

    win.set_label("Polygon 1");
    win.wait_for_button();

    Rectangle r{Point{200,200}, 100,50};
    win.attach(r);
    win.set_label("negyzet");
    win.wait_for_button();

    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50}); 
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    win.attach(poly_rect);
    win.set_label("Alakzatok");
    win.wait_for_button();
    poly_rect.add(Point{50,75});
    win.set_label("Alakzatok 2");
    win.wait_for_button();

r.set_fill_color(Color::yellow);       
poly.set_style(Line_style(Line_style::dash,4)); 
poly_rect.set_style(Line_style(Line_style::dash,2));
poly_rect.set_fill_color(Color::cyan);
win.set_label("Kitoltes");
win.wait_for_button();

Text t {Point{350,250}, "Hello! :)"};
t.set_color(Color::green);
win.attach(t);
win.set_label("Szoveg");
win.wait_for_button();

Image ii {Point{200,50},"badge.jpg"};      
win.attach(ii);
win.set_label("kep");
win.wait_for_button();

ii.move(180,250);
win.set_label("mozgatas");
win.wait_for_button();

Circle c {Point{100,200},50};
c.set_style(Line_style(Line_style::dash,3));
c.set_fill_color(Color::magenta);
Mark m {Point{100,200},'x'};

ostringstream oss;

Text sizes {Point{100,20},oss.str()};

Ellipse e {Point{200,500}, 100, 50};
    e.set_fill_color(Color::red);

win.attach(c);
win.attach(m);
 win.attach(e);
 win.attach(sizes);
win.set_label("vege");
win.wait_for_button();


}
catch(exception& e){
	return 1;
}
catch(...){
	return 2;
}