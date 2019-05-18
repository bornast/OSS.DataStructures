#include <stdio.h>
#include <stdlib.h>
#include "stl.h"

Objekt3D* vrati_objekt3D(FILE *fp) {
    //printf("trokut %d",sizeof(Trokut)); //TODO: 32 bitni kompajler kompjalira 2^4 bitova znaci 4 bajta zato cita po 4 bajta strukture
    Objekt3D *objekt3d = (Objekt3D*)malloc(sizeof(Objekt3D));
    fseek( fp, 80, SEEK_SET ); //postavi na poziciju 80 u fajlu
    fread(&(objekt3d->n), sizeof(unsigned int), 1, fp); //prva 4 bajta nakon 80 pozicije su ukupni broj trokuta
    int i = 0;
    objekt3d->niz_trokuta = (Trokut*)malloc(objekt3d->n * sizeof(Trokut));
    while(fread(&objekt3d->niz_trokuta[i++], 50, 1, fp)); //idi kroz linije po 50 bajtova i spremaj u trokut(trokuta gdje su prva 3 broja normala, sljedecih 9 vrhovi xyz i onda jedan short broj za boju -- ukupno 50 bajtova)
    return objekt3d;
}

void zapisi_u_binarnu(Objekt3D *objekt3d, FILE *fp) {

    //za provjere funkcionira li https://www.onlinehexeditor.com/ https://www.viewstl.com/
    int nula[20] = {0}; //sve ostale ce popunit s nulama
    fwrite(nula, sizeof(int), 20, fp);
    fwrite(&objekt3d->n, sizeof(unsigned int), 1, fp);
    for(int i = 0; i < objekt3d->n; i++) {
        fwrite(&objekt3d->niz_trokuta[i].ni, sizeof(float), 1, fp);
        fwrite(&objekt3d->niz_trokuta[i].nj, sizeof(float), 1, fp);
        fwrite(&objekt3d->niz_trokuta[i].nk, sizeof(float), 1, fp);
        for(int j = 0; j < 3; j++) {
            fwrite(&objekt3d->niz_trokuta[i].vrhovi[j].x, sizeof(float), 1, fp);
            fwrite(&objekt3d->niz_trokuta[i].vrhovi[j].y, sizeof(float), 1, fp);
            fwrite(&objekt3d->niz_trokuta[i].vrhovi[j].z, sizeof(float), 1, fp);
        }
        fwrite(&objekt3d->niz_trokuta[i].boja, sizeof(unsigned short), 1, fp);
    }
}

void zapisi_u_tekstualnu(Objekt3D *objekt3d, FILE *fp) {

    char solid_name[] = "BORNA";
    fprintf(fp, "solid %s\n", solid_name);
    for(int i = 0; i < objekt3d->n; i++) {
        fprintf(fp, "facet normal %f %f %f\n", objekt3d->niz_trokuta[i].ni, objekt3d->niz_trokuta[i].nj, objekt3d->niz_trokuta[i].nk);
        fprintf(fp, "outer loop\n");
        for(int j = 0; j < 3; j++) {
            fprintf(fp, "vertex %f %f %f\n", objekt3d->niz_trokuta[i].vrhovi[j].x, objekt3d->niz_trokuta[i].vrhovi[j].y, objekt3d->niz_trokuta[i].vrhovi[j].z);
        }
        fprintf(fp,"endloop\n");
    }
    fprintf(fp, "endsolid %s", solid_name);
}

void izbrisi_objekt3d(Objekt3D *objekt3d) {
    if(objekt3d != NULL){
      free(objekt3d->niz_trokuta);
      free(objekt3d);
    }
}

Objekt3D* citaj_tekstualnu(FILE *fp) {
    char str[1000];
}
