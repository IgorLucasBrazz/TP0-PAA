#include <stdio.h>
#include <stdlib.h>

int main(){
    int opcao1, opcao2, quant;
        opcao2 = 1;
        printf("-----------------GERADOR DE OBRA DE ARTE!!!------------------\n");
        printf("==============================================================\n");
        printf("| Escolha o tipo de figura a ser usada para criar a obra:    |\n");
        printf("| 1 - Asterisco Simples.                                     |\n");
        printf("| 2 - Simbolo de Soma com Asteriscos.                        |\n");
        printf("| 3 - Letra X com Asteriscos.                                |\n");
        printf("| 4 - Figuras Aleatórias.                                    |\n");
        printf("| 5 - Árvore                                                 |\n");
        printf("| 6 - Sair do programa.                                      |\n");
        printf("==============================================================\n");
        printf("\n");
        printf("\n");
        printf("Digite a opção de figura desejada: ");
        scanf("%d",&opcao1);
        

    while(1){      
        if(opcao1 == 6){
            printf("BYE!!!\n");
            exit(0);
        }     
        while (opcao2 == 1){

            printf("Digite a quantidade de figuras (menor ou igual a zero para quantidade aleatória): ");
            scanf("%d",&quant);
            printf("\n");
            
            if(quant > 100 && ( opcao1 == 1 || opcao1 == 2 || opcao1 == 3 || opcao1 == 4)){
                quant = 100;
            }
            else if(quant > 100 && (opcao1 == 5)){
                quant = (rand()%60)+1;
            }
            else if(quant <= 0){
                if(opcao1 == 5){
                    quant = (rand()%60)+1;
                }
                else{
                    quant = (rand()%100)+1;
                }
            }

            //Quadro
            int i,j;
            char quadro[20][80];
            for(i = 0; i < 20; i ++){
                for(j = 0; j < 80; j ++){
                    quadro[i][j]= ' ';
                }
            }
            for(i = 0; i < 20; i ++){
                quadro[i][0] = '|';
                quadro[i][79] = '|';
            }
            for(j = 0; j < 80; j++){
                quadro[0][j] = '-';
                quadro[19][j] = '-';
            }

            int var1, var2, var3, arte;
            switch (opcao1){
                case 1:
                    for (var1 = 0; var1 < quant; var1++)
                    {

                        var2 = (rand() % 18) + 1;
                        var3 = (rand() % 78) + 1;

                        while (quadro[var2][var3] == '*')
                        {
                            var2 = (rand() % 18) + 1;
                            var3 = (rand() % 78) + 1;
                        }
                        quadro[var2][var3] = '*';
                    }                    
                    break;

                case 2:
                    for (var1=0;var1<quant;var1++){
                        var2 = (rand()% 18) + 1;
                        var3 = (rand()% 78) + 1; 
                        while (quadro[var2][var3] == '*' || quadro[var2+1][var3] == '*' || quadro[var2-1][var3] == '*' || quadro[var2][var3+1] == '*' || quadro[var2][var3-1] == '*' || var2-1==0 || var2+1==19 || var3-1 ==0 || var3+1 == 79){ 
                            var2 = (rand()% 18) + 1;
                            var3 = (rand()% 78) + 1;
                        }
                        quadro[var2][var3] = '*';
                        quadro[var2+1][var3] = '*'; 
                        quadro[var2-1][var3] = '*';
                        quadro[var2][var3+1] = '*';
                        quadro[var2][var3-1] = '*';
                    }
                    break;

                    case 3:
                        for(var1 = 0; var1 < quant; var1++){
                            var2 = (rand()% 18) + 1;
                            var3 = (rand()% 78) + 1;
                            
                            while (quadro[var2][var3] == '*' || quadro[var2+1][var3] == '*' || quadro[var2-1][var3] == '*' 
                            || quadro[var2][var3+1] == '*' || quadro[var2][var3-1] == '*' || 
                            var2-1==0 || var2+1==19 || var3-1 ==0 || var3+1 == 79){ 
                            var2 = (rand()% 18) + 1;
                            var3 = (rand()% 78) + 1;
                            }

                            
                            quadro[var2][var3] = '*';
                            quadro[var2 - 1][var3 + 1] = '*';
                            quadro[var2 - 1][var3 - 1] = '*';
                            quadro[var2 + 1][var3 - 1] = '*';
                            quadro[var2 + 1][var3 + 1] = '*';
                        }
                        break;
                    case 4:
                        for (var1 = 0; var1 < quant; var1++){
                            var2 = (rand()%18) + 1;
                            var3 = (rand()%78) + 1;
                            arte =(rand()%3);

                            if(arte == 0){
                                while (quadro[var2][var3] == '*'){
                                    var2 = (rand()%18)+1;
                                    var3 = (rand()%78)+1;
                                }
                                quadro[var2][var3] = '*';
                            }

                            else if (arte == 1){
                                while(quadro[var2][var3] == '*' || quadro[var2+1][var3]=='*' || quadro[var2-1][var3] == '*'|| quadro[var2][var3+1]=='*' || quadro[var2][var3-1]=='*' || var2-1 == 0 || var2+1 == 19 || var3-1 == 0 || var3+1 == 79 ){
                                    var2 = (rand()% 18) + 1;
                                    var3 = (rand()% 78) + 1;
                                }
                                quadro[var2][var3] = '*';
                                quadro[var2+1][var3] = '*'; 
                                quadro[var2-1][var3] = '*';
                                quadro[var2][var3+1] = '*';
                                quadro[var2][var3-1] = '*';                                
                            }

                            else if (arte == 2){
                                while (quadro[var2][var3] == '*' || quadro[var2-1][var3+1] == '*' || quadro[var2-1][var3-1] == '*' || quadro[var2+1][var3-1]== '*' || quadro[var2+1][var3+1] == '*'|| var2-1 == 0 || var2+1 == 19 || var3-1 == 0 || var3+1 == 79 ){
                                    var2 = (rand()% 18) + 1;
                                    var3 = (rand()% 78) + 1;
                                }      
                                quadro[var2][var3] = '*';
                                quadro[var2-1][var3+1] = '*';
                                quadro[var2-1][var3-1] = '*';
                                quadro[var2+1][var3-1] = '*';
                                quadro[var2+1][var3+1] = '*';
                            }                            
                        }
                        break;

                    case 5:
                        for(var1 = 0; var1 < quant; var1++){
                            var2 = (rand()% 18) + 1;
                            var3 = (rand()% 78) + 1;

                            while (quadro[var2+1][var3] == '*' || quadro[var2+2][var3] == '*' || quadro[var2+2][var3] == '*' || quadro[var2+2][var3-1] == '*' ||
                            quadro[var2+3][var3] == '*' || quadro[var2+3][var3-1] == '*' || quadro[var2+3][var3-2] == '*' || quadro[var2+3][var3+1] == '*' || 
                            quadro[var2+3][var3+2] == '*' || quadro[var2+4][var3] == '|' || var3 - 1 == 0 || var3 == 0 ||
                            var3 + 1 == 0 || var3 - 2 == 0 || var3 + 2 == 0 ||var3 - 1 == 79 || var3 == 79 || var3 + 1 == 79 || 
                            var3 - 2 == 79 || var3 + 2 == 79 || var2 == 0 || var2+1 == 0 || var2+2 == 0 || var2+3 == 0 || var2+4 == 0 ||
                            var2 == 19 || var2+1 == 19 || var2+2 == 19 || var2+3 == 19 || var2+4 == 19){
                                var2 = (rand()% 18) + 1;
                                var3 = (rand()% 78) + 1;
                            }
                            quadro[var2+1][var3] = '*'; 
                            quadro[var2+2][var3] = '*'; 
                            quadro[var2+2][var3+1] = '*';
                            quadro[var2+2][var3-1] = '*';
                            quadro[var2+3][var3] = '*';
                            quadro[var2+3][var3-1] = '*';
                            quadro[var2+3][var3-2] = '*';
                            quadro[var2+3][var3+1] = '*';
                            quadro[var2+3][var3+2] = '*';
                            quadro[var2+4][var3] = '|';
                        }
                        break;
            }
            
            //Quadro -> Impressão
        for(i = 0; i < 20; i ++){
            for(j = 0; j < 80; j ++){
                printf("%c",quadro[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        printf("\n");

            printf("-----------------GERADOR DE OBRA DE ARTE!!!------------------\n");
            printf("==============================================================\n");
            printf("| Escolha o tipo de figura a ser usada para criar a obra:    |\n");
            printf("| 1 - Asterisco Simples.                                     |\n");
            printf("| 2 - Simbolo de Soma com Asteriscos.                        |\n");
            printf("| 3 - Letra X com Asteriscos.                                |\n");
            printf("| 4 - Figuras Aleatórias.                                    |\n");
            printf("| 5 - Árvore                                                 |\n");
            printf("| 6 - Sair do programa.                                      |\n");
            printf("==============================================================\n");
            printf("\n");
            printf("\n");
        
            printf("Digite a opção de figura desejada: ");
            scanf("%d",&opcao1);
            
            if (opcao1 == 6)
            {
                printf("BYE!!!\n");
                exit(0);
            }
            
        }
    }

}
