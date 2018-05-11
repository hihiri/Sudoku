#include "loop.hpp"
#include <fstream>
using namespace std;
using namespace genv;
void loop(vector<Widget*>& v)
{
    event ev;
    int focus = -1;
    ///elõre olvasás
    for(int i=0; i<v.size(); i++)
    {
        v[i]->draw();
    }
    v[0]->focus();
    //////////////////////////////
    gin.timer(200);
    while(gin >> ev )
    {
        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (int i=0; i<v.size(); i++)
            {
                if (v[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                    v[i]->focus();
                }
                else
                {
                    v[i]->unfocus();
                }
            }
        }
        if(ev.keycode==key_tab)
        {
            for (int i=0; i<v.size(); i++)
            {
                if (v[i]->get_focus())
                {
                    v[i]->unfocus();
                    if(i<v.size()-1)
                    {
                        v[i+1]->focus();
                        focus=i+1;
                    }
                    else
                    {
                        v[0]->focus();
                        focus=0;
                    }
                    i++;
                }
            }
        }
        if (focus!=-1)
        {
            v[focus]->handle(ev);
        }
        /*if(ev.keycode==key_enter)
        {
            ofstream l;
            l.open("eredmeny.txt");
            for(int k=0;k<v.size();k++)
            {
                l<<k+1<<" widget erteke: "<<v[k]->eredmeny()<<endl;
            }
            l <<"Ez az aktualis widget aktualis erteke enter nyomasara:"<<endl<< v[focus]->eredmeny();
            l.close();
        }*/
        for(int i=0; i<v.size(); i++)
        {
            v[i]->draw();
        }
        gout << refresh<<color(0,0,0)<<move_to(0,0)<<box(799,599);

    }
}
///uhtg2j Tóth András
