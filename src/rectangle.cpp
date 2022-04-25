#include <iostream>
#include "include/rectangle.hpp"

using namespace std;

persegiPanjang::persegiPanjang(float MPx, float MPy, float l, float w)
{
    this->xmin = MPx - l/2;
    this->xmax = MPx + l/2;

    this->ymin = MPy - w/2;
    this->ymax = MPy + w/2;
}

bool persegiPanjang::operator==(persegiPanjang const &ora) const // other rectangle availabe
{

    if (this->xmin == this->xmax || this->ymax == this->ymin || ora.xmin == ora.xmax || ora.ymax == ora.ymin) 
        return false;

    if (this->xmin >= ora.xmax || ora.xmin >= this->xmax)
        return false;
 
    // If one rectangle is above other
    if (this->ymin >= ora.ymax || ora.ymin >= this->ymax)
        return false;
 
    return true;
}

persegiPanjang persegiPanjang::operator+(persegiPanjang const &ora)
{
    if (*this == ora) //biar nunjuk variable nya
    {
        persegiPanjang temp(0,0,0,0);

        //update x
        temp.xmin = min(this->xmin, ora.xmin);
        temp.xmax = max(this->xmax, ora.xmax);

        //update y
        temp.ymin = min(this->ymin, ora.ymin);
        temp.ymax = max(this->ymax, ora.ymax);

        return temp;
    }
    else 
        {
            cout << "mboten overlap mazzee" << endl;
        }
}

persegiPanjang persegiPanjang::operator-(persegiPanjang const &ora)
{
 
    if (*this == ora) //biar nunjuk variable nya
    {
        persegiPanjang temp(0,0,0,0);

        //update x
        temp.xmin = max(this->xmin, ora.xmin);
        temp.xmax = min(this->xmax, ora.xmax);

        //update y
        temp.ymin = max(this->ymin, ora.ymin);
        temp.ymax = min(this->ymax, ora.ymax);

        return temp;
    }
    else 
        {
            cout << "mboten overlap mazzee" << endl;
        }
  
}

void persegiPanjang::operator++()
{
    float temp_l, temp_w, MPx, MPy, temp_xmin, temp_xmax, temp_ymin, temp_ymax;
    temp_l = xmax - xmin;
    temp_w = ymax - ymin;

    temp_l *= 2;
    temp_w *= 2;

    MPx = temp_l/2 + xmin;
    MPy = temp_w/2 + ymin;

    temp_xmax = MPx + temp_l/2;
    temp_xmin = MPx - temp_l/2;

    temp_ymin = MPy - temp_w/2;
    temp_ymax = MPy + temp_w/2;
}

void persegiPanjang::operator--()
{
    float temp_l, temp_w, MPx, MPy, temp_xmin, temp_xmax, temp_ymin, temp_ymax;
    temp_l = xmax - xmin;
    temp_w = ymax - ymin;

    temp_l /= 2;
    temp_w /= 2;

    MPx = temp_l/2 + xmin;
    MPy = temp_w/2 + ymin;

    temp_xmax = MPx + temp_l/2;
    temp_xmin = MPx - temp_l/2;

    temp_ymin = MPy - temp_w/2;
    temp_ymax = MPy + temp_w/2;
}


float persegiPanjang::operator[](int index)
{
    switch(index){
        case 1 :
            return this->xmin;
            break;

         case 2 :
            return this->xmax;
            break;

         case 3:
            return this->ymin;
            break;
            
         case 4 :
            return this->ymax;
            break;
    }
}
