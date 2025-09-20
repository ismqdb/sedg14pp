#include "./21. fractal.hpp"

none box(i32, i32, i32){}

none star(i32 x, i32 y, i32 r){
    if(r > 0){
        star(x-r, y+r, r/2);
        star(x+r, y+r, r/2);
        star(x-r, y-r, r/2);
        box(x, y, r);
    }
}