#include <stdio.h>
#include <stdlib.h>
#include "stl.h"
//TODO: provjere za fileove da li je null i za malloc takoder !! na sve vjezbe



int main() {

    /* ---- vrati_objekt3D PROVJERA ---- */
    FILE *fp1 = fopen("primjerbin.stl", "rb"); //read binary
    Objekt3D *objekt3d = vrati_objekt3D(fp1);
    fclose(fp1);
    /* ---- zapisi_u_binarnu PROVJERA ---- */
    FILE *fp2 = fopen("primjerbin2.stl", "wb");
    zapisi_u_binarnu(objekt3d, fp2);
    fclose(fp2);
    /* ---- zapisi_u_tekstualnu PROVJERA ---- */
    FILE *fp3 = fopen("primertxt2.stl", "w+");
    zapisi_u_tekstualnu(objekt3d, fp3);
    fclose(fp3);
    /* ---- izbrisi_objekt3d PROVJERA ---- */
    izbrisi_objekt3d(objekt3d);
    /* ---- izbrisi_objekt3d PROVJERA ---- */
    FILE *fp4 = fopen("primjertxt.stl", "r");
    citaj_tekstualnu(fp4);
    fclose(fp4);    
    return 0;
}
