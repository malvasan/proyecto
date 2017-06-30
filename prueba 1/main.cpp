#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<stdio.h>


#define TAMANO      10
#define ARRIBA      72
#define ABAJO       80
#define IZQUIERDA   75
#define DERECHA     77


using namespace std;

bool seguir=true;
class Bloque
{
    protected:
        int x;
        int y;
    public:
        char c;
        bool pasar;
        int punto;
        Bloque()
        {

            x=0;
            y=0;
            punto=1;

        }
        void agregar(int new_x,int new_y,char new_c,bool new_pasar,int new_punto=1)
        {
            x=new_x;
            y=new_y;
            c='-';
            pasar=new_pasar;
            punto=new_punto;
        }
        void imprimir()
        {
            cout<<c;
        }
        char ret()
        {
            return c;
        }

};
class Matriz
{
    public:
        Bloque matriz[TAMANO][TAMANO];
        Matriz()
        {
            for (int a=0;a<TAMANO;a++){
                for (int b=0;b<TAMANO;b++){
                    char c='-';
                    bool v=true;
                    matriz[a][b].agregar(a,b,c,v);
                }
            }
            for (int a=0;a<TAMANO;a++){
                for (int b=0;b<TAMANO;b++){
                    if (a%2==0 && b%2==0){
                        char c='O';
                        bool v=false;
                        int p=0;
                        matriz[a][b].c=c;
                        matriz[a][b].pasar=v;
                        matriz[a][b].punto=p;
                    }
                }
            }
        }
        void imprimir_matriz()
        {
            for (int a=0;a<TAMANO;a++){
                for (int b=0;b<TAMANO;b++){
                    matriz[a][b].imprimir();
                }
            cout<<endl;
            }
        }
        bool ganar()
        {
            int suma=0;
            for (int a=0;a<TAMANO;a++){
                for (int b=0;b<TAMANO;b++){
                    suma+=matriz[a][b].punto;
                }
            }
            if(suma==0)
                return true;
            else
                return false;
        }
};

class Pac_man
{
    public:
        int x;
        int y;
        char c;
    Pac_man()
    {
        x=TAMANO/2;
        y=TAMANO/2;
        c='%';
    }
    void mover(Matriz &probar)
    {
        int temp_x=x;
        int temp_y=y;
        int tecla=getch();
        if(tecla==ARRIBA){
            x=x-1;
            if(probar.matriz[x][y].pasar==false)
                x=x+1;
            if(x<0)
                x=0;
        }
        else if(tecla==ABAJO){
            x=x+1;
            if(probar.matriz[x][y].pasar==false)
                x=x-1;
            if(x>TAMANO-1)
                x=TAMANO-1;
        }

        else if(tecla==IZQUIERDA){
            y=y-1;
            if(probar.matriz[x][y].pasar==false)
                y=y+1;
            if(y<0)
                y=0;
        }
        else if(tecla==DERECHA){
            y=y+1;
            if(probar.matriz[x][y].pasar==false)
               y=y-1;
            if(y>TAMANO-1)
                y=TAMANO-1;
        }
        probar.matriz[temp_x][temp_y].c='/';
        probar.matriz[x][y].c=c;
        probar.matriz[x][y].punto=0;
        system("cls");
    }

};

class Fantasma
{
    public:
        int x;
        int y;
        char c;
        Fantasma()
        {
            x=TAMANO/3;
            y=TAMANO/3;
            c='$';
        }
        bool chocar(Pac_man paco)
        {
            if(paco.x==x && paco.y==y)
                return true;
            else
                return false;
        }
        void mover(Matriz &probar,int tecla=0)
        {
        int temp_x=x;
        int temp_y=y;
        if(tecla==0)
            tecla=getch();
        else
            tecla;
        if(tecla==ARRIBA){
            x=x-1;
            if(probar.matriz[x][y].pasar==false)
                x=x+1;
            if(x<0)
                x=0;
        }
        else if(tecla==ABAJO){
            x=x+1;
            if(probar.matriz[x][y].pasar==false)
                x=x-1;
            if(x>TAMANO-1)
                x=TAMANO-1;
        }

        else if(tecla==IZQUIERDA){
            y=y-1;
            if(probar.matriz[x][y].pasar==false)
                y=y+1;
            if(y<0)
                y=0;
        }
        else if(tecla==DERECHA){
            y=y+1;
            if(probar.matriz[x][y].pasar==false)
               y=y-1;
            if(y>TAMANO-1)
                y=TAMANO-1;
        }
        if(probar.matriz[temp_x][temp_y].punto==1)
            probar.matriz[temp_x][temp_y].c='-';
        else
            probar.matriz[temp_x][temp_y].c='/';
        probar.matriz[x][y].c=c;
        }
        void cazar(Pac_man paco,Matriz &probar)
        {
            if (paco.x==x){
                if(paco.y<y){
                    if(probar.matriz[x][y-1].pasar==false){
                        if(x-1<0)
                            mover(probar,ABAJO);
                        else if(x+1>TAMANO)
                            mover(probar,ARRIBA);
                    }
                    else
                        mover(probar,IZQUIERDA);

                }
                else{
                    if(probar.matriz[x][y+1].pasar==false){
                        if(x-1<0)
                            mover(probar,ABAJO);
                        else if(x+1>TAMANO)
                            mover(probar,ARRIBA);
                    }
                    else
                        mover(probar,DERECHA);
                }
            }
            else if(paco.y==y){
                if(paco.x<x){
                    if(probar.matriz[x-1][y].pasar==false){
                        if(y-1<0)
                            mover(probar,DERECHA);
                        else if(y+1>TAMANO)
                            mover(probar,IZQUIERDA);
                    }
                    else
                        mover(probar,ARRIBA);

                }
                else{
                    if(probar.matriz[x+1][y].pasar==false){
                        if(y-1<0)
                            mover(probar,DERECHA);
                        else if(y+1>TAMANO)
                            mover(probar,IZQUIERDA);
                    }
                    else
                        mover(probar,ABAJO);
                }
            }
        }

};

int main()
{
    Pac_man paco;
    Fantasma fanta;
    Matriz probar;
    probar.matriz[paco.x][paco.y].c=paco.c;
    probar.matriz[fanta.x][fanta.y].c=fanta.c;
    bool game_over= false;
    probar.imprimir_matriz();
    while(!game_over)
    {
        paco.mover(probar);
        fanta.cazar(paco,probar);
        probar.imprimir_matriz();
        cout<<paco.x<<" "<<paco.y<<endl;
        Sleep(100);
        game_over=probar.ganar();
        if(game_over==true)
            break;
        game_over=fanta.chocar(paco);
    }



}
