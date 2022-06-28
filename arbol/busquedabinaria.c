void crearLoteDatos (const char* nombArch)
{
    t_dato loteDatos[15] = {{83, 10, 99.8, "Prod 1"},
                            {18, 8, 25.90, "Prod 2"},
                            {25, 19, 9.8, "Prod 3"},
                            {93, 1, 320.2, "Prod 4"},
                            {40, 9, 44.4, "Prod 5"},
                            {17, 10, 204.8, "Prod 6"},
                            {21, 16, 949.8, "Prod 7"},
                            {32, 30, 99.8, "Prod 8"},
                            {74, 1, 99.8, "Prod 9"},
                            {4, 10, 99.8, "Prod 10"},
                            {83, 10, 99.8, "Prod 11"},
                            {18, 8, 25.90, "Prod 12"},
                            {25, 19, 9.8, "Prod 13"},
                            {93, 1, 320.2, "Prod 14"},
                            {40, 9, 44.4, "Prod 15"}};

    FILE* pf = fopen(nombArch, "wb");
    if(pf == NULL)
    {
        puts("No se pudo crear el archivo.");
        return;
    }
    fwrite(&loteDatos, sizeof(t_dato),1,pf);
    fclose(pf);
}

void busquedaBinaria(FILE *arch, void *dato, unsigned tam){

}

void arbolBalanceadoDeArchivo(FILE *arch, tArbol *arbol){
    tNodo *ini, *fin, *medio;
    FILE *indices = fopen("indices.dat", "rb");
    int mayorIndice = arbolDeIndices(arbol, arch);
    archOrdenadoDeIndices(indices, arbol);
    vaciarArbol(tArbol *arbol);


}

int arbolDeIndices(tArbol *arbol, FILE *arch){
    t_dato dato;
    Indice pos;
    int index = 0;
    fread(&dato, sizeof(t_dato), 1, arch);
    while(feof(arch)){
        pos.pos = index;
        pos.clave = dato.claveProd;
        nuevaRama(arbol, &pos, sizeof(Indice))
        index += 1;
        fread(&dato, sizeof(t_dato), 1, arch);
    }
    return index;
}

void archOrdenadoDeIndices(FILE *arch, tArbol *arbol){
    if(*arbol == NULL){
        return;
    }
    t_dato dato;
    archOrdenadoDeIndices(&(*arbol)->menor, mostrar);
    extraerDatoArbol(arbol, dato, sizeof(dato), compararTdato);
    fwrite(&dato, sizeof(t_dato), 1, arch);
    archOrdenadoDeIndices(&(*arbol)->mayor, mostrar);
}
