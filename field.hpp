#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

#include "widgets.hpp"
#include <functional>
using namespace std;

class Field : public Widget{

    bool checked=false;
    function<void()> enter;
    char _content=' ';
public:

    inline Field(function<void()> Fun, int x, int y, int sx, int sy,char content): Widget(x,y,sx,sy),enter(Fun){checked=_checked();if(content!=' ')checked=true;_content=content;};
    virtual void draw() const;
    void handle(genv::event ev);
    inline int _checked(){return checked;}
    bool focusable() const override {return false;}
    void check(){checked=!checked;}
};

#endif // FIELD_HPP_INCLUDED
