#include "items.hpp"
#include "graphics.hpp"
#include <sstream>
using namespace genv;
void coloring(bool focused)
{
    if(focused)
    {
        gout<<color(0,0,255);
    }
    else
    {
        gout<<color(150,150,150);
    }
}
void arrow_up(int x,int size_x,int y,int size_y)
{
    gout<<move_to(x+size_x-size_y/2+size_y/6,y+size_y/2-size_y/6)
        <<line_to(x+size_x-size_y/4,y+size_y/6)
        <<line_to(x+size_x-size_y/6,y+size_y/2-size_y/6);
}
void arrow_down(int x,int size_x,int y,int size_y)
{
    gout<<move_to(x+size_x-size_y/2+size_y/6,y+size_y/6+size_y/2)
        <<line_to(x+size_x-size_y/4,y+size_y-size_y/6)
        <<line_to(x+size_x-size_y/6,y+size_y/6+size_y/2);
}
void spec_box(int x,int size_x,int y,int size_y)
{
    gout <<move_to(x, y) << box(size_x, size_y);
    gout << color(0,0,0) << move_to(x+1, y+1) << box(size_x-2, size_y-2);
}
void write_there(int x,int y,std::string s)
{
    gout << move_to(x+3,y+gout.cascent()+5);
    gout << text(s);
}
std::string int_to_string(int s)
{
    std::stringstream sss;
    sss<<s;
    std::string ss;
    sss>>ss;
    return ss;
}
void windows(int x,int size_x,int y,int size_y,int v,std::string s,bool focused)
{
    coloring(focused);
    spec_box(x,size_x,y,size_y);
    coloring(focused);
    gout << move_to(x+3,y+gout.cascent()+5) << text(s);
}
///uhtg2j Tóth András
