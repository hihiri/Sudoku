#include "field.hpp"
#include "graphics.hpp"
using namespace genv;

void Field::draw() const
{
    if(fix==0){
            if(checked==0){
                coloring(_focused);
                spec_box(_x,_size_x,_y,_size_y);
                coloring(_focused);
            }else
            {
                gout<<color(211,15,10)<<move_to(_x,_y)<<box(_size_x,_size_y)
                <<color(0,255,0)<<move_to(_x+1,_y+1)<<box(_size_x-2,_size_y-2)<<color(0,0,0);
            }
    }else
    {
        gout<<color(211,15,10)<<move_to(_x,_y)<<box(_size_x,_size_y)
        <<color(255,255,255)<<move_to(_x+1,_y+1)<<box(_size_x-2,_size_y-2)<<color(0,0,0);
    }
    gout << move_to(_x+_size_x/2-3,_y+_size_y/2+3);
    gout << text(_content);

}
void Field::handle(event ev)
{
        if(_focused)
        {
               if(ev.keycode>='0' &&ev.keycode<='9' && !fix&& !checked)
                {
                    _content=ev.keycode;
                }
            if(ev.keycode==key_enter)
                {
                    checked=!checked;
                }
        }
}
///uhtg2j Tóth András
