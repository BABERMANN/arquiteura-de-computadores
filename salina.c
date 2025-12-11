char * calcula_oscilacao(char ** array_cidades, float ** temperaturas){
    int * oscila;
    int i,j;
    oscila = (int*)malloc((quantidade_registros+1)*sizeof(int));
    int maior_temp,menor_temp, oscilacao = 0;
    for(i = 0;i < quantidade_registros; i++){
        oscila[i] = oscilacao;
        maior_temp = -100;
        menor_temp = 100;
        oscilacao = 0;
        for(j = 0;j < 7; j ++){
          
            if (temperaturas[i][j] < menor_temp){
            menor_temp = temperaturas[i][j];

        }else if(temperaturas[i][j] > maior_temp){
            maior_temp = temperaturas[i][j];
        }
         oscilacao = maior_temp - menor_temp;
        }

        }

      int x,maior_oscila = -100,indice_maior;
      for(x = 0; x < quantidade_registros + 1;x++){
        if(oscila[x] > maior_oscila){
        maior_oscila = oscila[x];
        indice_maior = x;
        }
    }

    return array_cidades[indice_maior];

    }
