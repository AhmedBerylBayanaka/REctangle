#include <iostream>
#include "include/rectangle.hpp"
#include <stdlib.h>

using namespace std;

persegiPanjang::persegiPanjang()
{
}

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

    //if one rectangle is next to another
    if (this->xmin >= ora.xmax || ora.xmin >= this->xmax)
        return false;
 
    // If one rectangle is above other
    if (this->ymin >= ora.ymax || ora.ymin >= this->ymax)
        return false;
 
    return true;
}

persegiPanjang persegiPanjang::operator+(persegiPanjang const &ora)
{
    float MPx, MPy, l, w;
    if (*this == ora) //biar nunjuk nilai dari variable nya
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
            cout << "kedua persegi panjang tidak beririsan" << endl;
        }
}

persegiPanjang persegiPanjang::operator-(persegiPanjang const &ora)
{
 
 float MPx, MPy, l, w;
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
            cout << "kedua persegi panjang tidak beririsan" << endl;
        }
  
}

void persegiPanjang::operator++()
{
    float temp_l, temp_w, MPx, MPy;
    
    //nyari panjang dan lebar persegi panjang yang diminta
    temp_l = this->xmax - this->xmin;
    temp_w = this->ymax - this->ymin;

    //nyari titik tengah dari persegi panjang tsb
    MPx = temp_l/2 + this->xmin;
    MPy = temp_w/2 + this->ymin;

    //kini luasannya menjadi 2x nya
    temp_l *= 2;
    temp_w *= 2;

    //menentukan titik2 barunya
   this->xmax = MPx + temp_l/2;
    this->xmin = MPx - temp_l/2;

    this->ymin = MPy - temp_w/2;
    this->ymax = MPy + temp_w/2;
}

void persegiPanjang::operator++(int)
{
    float temp_l, temp_w, MPx, MPy;
    
    //nyari panjang dan lebar persegi panjang yang diminta
    temp_l = this->xmax - this->xmin;
    temp_w = this->ymax - this->ymin;

    //nyari titik tengah dari persegi panjang tsb
    MPx = temp_l/2 + this->xmin;
    MPy = temp_w/2 + this->ymin;

    //kini luasannya menjadi 2x nya
    temp_l *= 2;
    temp_w *= 2;

    //menentukan titik2 barunya
    this->xmax = MPx + temp_l/2;
    this->xmin = MPx - temp_l/2;

    this->ymin = MPy - temp_w/2;
    this->ymax = MPy + temp_w/2;
}

void persegiPanjang::operator--()
{
    float temp_l, temp_w, MPx, MPy;
    //nyari panjang dan lebar persegi panjang yang diminta
    temp_l = this->xmax - this->xmin;
    temp_w = this->ymax - this->ymin;

    //nyari titik tengah dari persegi panjang tsb
    MPx = temp_l/2 + this->xmin;
    MPy = temp_w/2 + this->ymin;

    //kini luasannya menjadi 0,5x nya
    temp_l /= 2;
    temp_w /= 2;

    //menentukan titik2 barunya
    this->xmax = MPx + temp_l/2;
    this->xmin = MPx - temp_l/2;

    this->ymin = MPy - temp_w/2;
    this->ymax = MPy + temp_w/2;
}

void persegiPanjang::operator--(int)
{
    float temp_l, temp_w, MPx, MPy;
    //nyari panjang dan lebar persegi panjang yang diminta
    temp_l = this->xmax - this->xmin;
    temp_w = this->ymax - this->ymin;

    //nyari titik tengah dari persegi panjang tsb
    MPx = temp_l/2 + this->xmin;
    MPy = temp_w/2 + this->ymin;

    //kini luasannya menjadi 0,5x nya
    temp_l /= 2;
    temp_w /= 2;

    //menentukan titik2 barunya
    this->xmax = MPx + temp_l/2;
    this->xmin = MPx - temp_l/2;

    this->ymin = MPy - temp_w/2;
    this->ymax = MPy + temp_w/2;
}


float persegiPanjang::operator[](int index)
{
    switch(index)
    {
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

void persegiPanjang::print()
{
    float temp_l, temp_w, MPx, MPy, area;
    //nyari panjang dan lebar persegi panjang yang diminta
    temp_l = this->xmax - this->xmin;
    temp_w = this->ymax - this->ymin;

    //nyari titik tengah dari persegi panjang tsb
    MPx = temp_l/2 + this->xmin;
    MPy = temp_w/2 + this->ymin;

    //luas persegi panjang
    area = temp_l*temp_w;

    cout << "titik tengah (x) : "  << MPx << endl;
    cout << "titik tengah (y) : "  << MPy<< endl;
    cout << "panjang : " << temp_l<< endl;
    cout << "lebar : "  << temp_w<< endl;
    cout << "Nilai xmin : " << this->xmin << endl;
    cout << "Nilai xmax : " << this->xmax << endl;
    cout << "Nilai ymin : " << this->ymin << endl;
    cout << "Nilai ymax : " << this->ymax << endl;
    cout << "Luasan persegi panjang : " << area << endl << endl;;
}