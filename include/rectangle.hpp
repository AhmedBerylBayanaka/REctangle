#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

using namespace std;

class persegiPanjang
{
    private:
        float xmin, xmax, ymin, ymax;

    public :
        persegiPanjang(float MPx, float MPy, float l, float w);
        bool operator==(persegiPanjang const &) const;
        persegiPanjang operator+(persegiPanjang const &);
        persegiPanjang operator-(persegiPanjang const &);
        void operator++();
        void operator--();
        float operator[](int);
        void print();
       /* persegiPanjang(int, int); 
        persegiPanjang operator+(persegiPanjang &);
        friend ostream& operator<<(ostream &, persegiPanjang &);*/
};

#endif