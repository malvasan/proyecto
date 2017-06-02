#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<stdio.h>


#define TAMANO      20
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
        Bloque()
        {

            x=0;
            y=0;

        }
        void agregar(int new_x,int new_y,char new_c,bool new_pasar)
        {
            x=new_x;
            y=new_y;
            c='-';
            pasar=new_pasar;
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
                    if (a/2==1 && b/2==1){
                        char c='O';
                        bool v=false;
                        matriz[a][b].agregar(a,b,c,v);
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
};

int main()
{
    Pac_man paco;
    Matriz probar;
    probar.matriz[paco.x][paco.y].c=paco.c;
    bool game_over= false;
    while(!game_over)
    {
        if(kbhit())
        {
            int temp_x=paco.x;
            int temp_y=paco.y;
            char tecla=getch();
            if(tecla=='i'){
                paco.x=paco.x-1;
                if(paco.x<0)
                    paco.x=0;
            }
            else if(tecla=='k'){
                paco.x=paco.x+1;
                    if(paco.x>TAMANO-1)
                        paco.x=TAMANO-1;
            }

            else if(tecla=='j'){
                paco.y=paco.y-1;
                    if(paco.y<0)
                        paco.y=0;
            }
            else if(tecla=='l'){
                 paco.y=paco.y+1;
                    if(paco.y>TAMANO-1)
                        paco.y=TAMANO-1;
            }
            probar.matriz[temp_x][temp_y].c='-';
            probar.matriz[paco.x][paco.y].c=paco.c;
        }
        probar.imprimir_matriz();
        cout<<paco.x<<" "<<paco.y<<endl;
        Sleep(200);
        system("cls");

    }



}
