#include<cstdlib>
#include<iostream>
#include<climits>


bool IsBigEndian()
{
   /* short *s ;
    s= (short*)malloc(sizeof(short)); //2 bytes are allocated here
    *s ='AB';
    char* p;
    p=(char*)s;
    std::cout <<*p <<std::endl;*/
    int n = 1;
    //if(*p == 'A') 
    if(*(char *)&n == 1) return false;
    else return true;

}

template <typename T>
T swapEndian(T u)
{
    
    static_assert (CHAR_BIT == 8, "CHAR_BIT != 8");

    union
    {
        T u;
        unsigned char u8[sizeof(T)]; //byte array
    } source, dest;

    source.u = u;

    for (size_t k = 0; k < sizeof(T); k++)
        dest.u8[k] = source.u8[sizeof(T) - k - 1]; //beautifull use of union

    return dest.u;
}
