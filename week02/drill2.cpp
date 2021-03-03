/*
g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double){
    return 1;
}

int main(){
    using namespace Graph_lib;

    Point tl {100,100};

    int xmax =1280;
    int ymax=720;

    Simple_window win {tl, xmax, ymax, "Ablak"};
    
    int x_orig=xmax/2;
    int y_orig=ymax/2;

    int rmin=-11;
    int rmax=11;

    int n_points=400;

    Polygon poly;
    poly.add(Point{1000,600});
    poly.add(Point{750,400});
    poly.add(Point{650,550});
    poly.set_color(Color::dark_green);
    poly.set_style(Line_style(Line_style::dash,5));
    poly.set_fill_color(Color::dark_yellow);

    win.attach(poly);

    Closed_polyline cpoly;
    cpoly.add(Point{300,200});
    cpoly.add(Point{100,200});
    cpoly.add(Point{100,100});
    cpoly.add(Point{300,100});
    cpoly.add(Point{350,150});
    cpoly.set_style(Line_style(Line_style::solid,3));

    win.attach(cpoly);

    Circle c{Point(400,200),50};
    Ellipse e{Point{400,200},75,25};
    c.set_style(Line_style(Line_style::solid,4));
    e.set_style(Line_style(Line_style::solid,4));
    c.set_color(Color::dark_red);
    e.set_color(Color::dark_red);

    win.attach(c);
    win.attach(e);

    Image ii{Point{200,400},"index.jpeg"};

    win.attach(ii);

    Text t{Point{800,250},"Nagyon hosszu szoveg"};
    t.set_font_size(30);
    t.set_font(Font::times_italic);

    win.attach(t);

    Rectangle r(Point{300,300},150,50);
    r.set_fill_color(Color::magenta);

    win.attach(r);
    
    Point origo{x_orig, y_orig};
           
    int xlenght=xmax-40;
    int ylenght=ymax-40;

    int xscale=30 , yscale=30;

    Function s(cos,0,100,origo,n_points,xscale,yscale);
    s.set_color(Color::dark_blue);
    s.set_style(Line_style::solid);

    Axis x{Axis::x,Point{20,y_orig},xlenght, xlenght/xscale, "x"};
    Axis y{Axis::y,Point{x_orig,ylenght + 20},ylenght, xlenght/yscale, "y"};

    x.set_color(Color::red);
    y.set_color(Color::red);

    x.label.set_color(Color::dark_blue);
    y.label.set_color(Color::dark_blue);

    win.attach(x);
    win.attach(y);
    win.attach(s);

    win.wait_for_button();
}