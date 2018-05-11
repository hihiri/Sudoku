#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED
#include "graphics.hpp"
#include "items.hpp"
class Widget
{
protected:
    bool _focused;
    int _x, _y, _size_x, _size_y;
public:
    Widget(int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() const {};
    virtual void handle(genv::event ev) = 0;
    virtual bool focusable() const;
    virtual void focus();
    virtual void unfocus();
    virtual bool get_focus() const;
    virtual std::string eredmeny()const {}
};
#endif // WIDGETS_HPP_INCLUDED
///uhtg2j Tóth András
