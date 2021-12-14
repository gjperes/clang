do {
    i = pilha.topo->linha;
    j = pilha.topo->coluna;
    printf("i=%d j=%d\n", i, j);

    // if(mapa[i][j] == START)
    //     saida = 1;

    // preso = 1;

    if( (i - 1 > -1) && (mapa[i-1][j] != MURO) && (mapa[i-1][j] != CHECK) ) {
    // NORTE
        // chama função que verifica
        printf("entrou no norte\n");
        criaPilha(&pilha, (i-1), j);
        mapa[i-1][j] = CHECK;
        preso = 0;
    } else if( (j + 1 < LATERAL + 1) && (mapa[i][j+1] != MURO) && (mapa[i][j+1] != CHECK) ) {
    // LESTE
        // chama função que verifica
        printf("entrou no leste\n");
        criaPilha(&pilha, i, (j+1));
        mapa[i][j+1] = CHECK;
        preso = 0;
    } else if( (i + 1 < ALTURA + 1) && (mapa[i+1][j] != MURO) && (mapa[i+1][j] != CHECK) ) {
    // SUL
        // chama função que verifica
        printf("entrou no sul\n");
        criaPilha(&pilha, (i+1), j);
        mapa[i+1][j] = CHECK;
        preso = 0;
    } else if ( (j - 1 > -1) && (mapa[i][j-1] != MURO) && (mapa[i][j-1] != CHECK) ) {
    // OESTE
        // chama função que verifica
        printf("entrou no oeste\n");
        criaPilha(&pilha, i, (j-1));
        mapa[i][j-1] = CHECK;          
        preso = 0;
    }

    saida=1;

} while(!saida || !preso);