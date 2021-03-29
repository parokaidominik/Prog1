/*
g++ drill3.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "Point.h"
#include <iostream>
#include <string>

using namespace Graph_lib;

int main(){

//Ablak
 const Point tl {100, 100};
    Simple_window win {tl, 800, 1000, "Ablak"};

//A rács
    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x = x_grid; x < x_size; x += x_grid)
        grid.add(Point{x, 0}, Point{x, y_size}); 
    for (int y = y_grid; y < y_size; y += y_grid)
        grid.add(Point{0, y}, Point{x_size, y});

    grid.set_color(Color::red);

    win.attach(grid);

//Pirosra befestés
    Vector_ref<Rectangle> rects;
    for (int i = 0; i < x_size; i += x_grid) {
        rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rects[rects.size() - 1].set_color(Color::invisible);
        rects[rects.size() - 1].set_fill_color(Color::red);
        win.attach(rects[rects.size() - 1]);
    }

//3 kép hozzáadás(200x200)
    Image kep1 {Point{0,300}, "kep.jpg"};
    Image kep2 {Point{300,600}, "kep.jpg"};
    Image kep3 {Point{500,100}, "kep.jpg"};

    win.attach(kep1);
    win.attach(kep2);
    win.attach(kep3);
    win.wait_for_button();

//A 100x100 as kép ami megy
    Image szaz {Point{0,0}, "szaz.jpg"};
    win.attach(szaz);
    win.wait_for_button();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            szaz.move(100, 0);
            win.wait_for_button();
        }
        szaz.move(-700, 100);
        win.wait_for_button();
    }

   
}