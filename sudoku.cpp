#include "loop.hpp"
#include "gameMaster.hpp"
#include "field.hpp"
#include "vectors.hpp"
#include <time.h>
#include <stdlib.h>
using namespace std;
using namespace genv;

int XX=25,YY=25;

int main()
{
    srand (time(NULL));
    vector<feladat> v=vect();
    gout.open(XX*9+9+300,YY*9+9);
    gout<<color(211,15,10)<<move_to(0,0)<<box(XX*9+8,YY*9+8);
    vector<Widget*> vv;
    int r=rand()%4;
    for(int k=0;k<9;k++){
    for(int i=0;i<9;i++){
            int z1,z2;
    if(i>2){z1=4;if(i>5){z1=6;}}else{z1=2;}
    if(k>2){z2=4;if(k>5){z2=6;}}else{z2=2;}
    Field *f=new Field([](){},XX*i+z1,YY*k+z2,XX,YY,v[r].v[i*9+k]);
    vv.push_back(f);
    }
    }
    gout<<color(250,250,250)<<move_to(XX*9+9+5,15)<<text("Ures mezokbe belekattintva irhatsz")
    <<move_to(XX*9+9+5,45)<<text("Enterrel lezárhatod az adott ")
    <<move_to(XX*9+9+5,60)<<text("mezot hogy ne tudd irni.")
    <<move_to(XX*9+9+5,75)<<text("Visza is tudod allitani irhatora.")
    <<move_to(XX*9+9+5,115)<<text("Szabalyok:")
    <<move_to(XX*9+9+5,130)<<text("Minden szambol pontosan egy van")
    <<move_to(XX*9+9+5,145)<<text("minden sorban, oszlopban es 3x3ban.")
    <<move_to(XX*9+9+5,180)<<text("A jateknak vege van ha mindent")
    <<move_to(XX*9+9+5,195)<<text("helyesen veglegesitesz.");
    loop(vv);
    return 0;
}
///uhtg2j Tóth András
