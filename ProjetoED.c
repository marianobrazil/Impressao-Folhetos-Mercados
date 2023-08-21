#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*================================================
    INTEGRANTES DO GRUPO
    Gabriel Marino - 247455
    Gabriela Vitorino - 184438
    Matheus Roberto Mariano - 246029
    Tauan Rodrigues Assunção de Jesus - 247599 
=================================================*/


//------------------------------------------------------------------------------
#define tamanho 2 // tamanho maximo da FILA
#define tamanho2 5 //tamanho colunas

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES

    Dicionário da semana;
    Segunda = 1; Terça = 2; Quarta = 3; Quinta = 4; Sexta = 5
------------------------------------------------------------------------------*/
typedef struct no_ls
{
    char dado[100];
    struct no_ls *prox;
} Tno_ls;

int Inicializar_LS(Tno_ls **P_inicio);
int Inserir_inicio_LS(Tno_ls **P_inicio, int info);
int Remover_inicio_LS (Tno_ls **inicio);
int Remover_fim_LS (Tno_ls **inicio);
int Remover_meio_LS (Tno_ls **inicio, int pos);
int Inserir_fim_LS(Tno_ls **P_inicio, char info[100]);
int Inserir_meio_LS(Tno_ls **P_inicio, int info, int pos);
int Remover_inicio_LS(Tno_ls **P_inicio);
int Listar_LS (Tno_ls *inicio, int posicao);
int Obter_pos_LS(Tno_ls *CP_inicio, int dado, int *pos);
int Obter_Tamanho_LS(Tno_ls *CP_inicio, int *tam);
int Inverte_LS(Tno_ls **P_inicio);
int cadastrarNovoFolheto(Tno_ls *mtrFolhetos[tamanho][tamanho2], int lin, int col, Tno_ls *inicio);
int removerLista(Tno_ls **inicio);

/* -----------------------------------------------------------------------------
Estrutura pilha
------------------------------------------------------------------------------*/
typedef struct no_pilha
{
    Tno_ls *folheto;
    struct no_pilha *prox;
} Tno_pilha;
int Inicializar_pilha(Tno_pilha **inicio);
int Inicializar2_pilha(Tno_pilha **inicio);
int Inserir_topo(Tno_pilha **inicio, Tno_ls *folheto);
int Remover_topo(Tno_pilha **inicio);
int Obter_topo(Tno_pilha *inicio);
int Verifica_vazio(Tno_pilha *inicio, int *resp);
int Juntar_pilhas(Tno_pilha **P1, Tno_pilha **P2, Tno_pilha **P3);

/* -----------------------------------------------------------------------------
Estrutura FILA ESTATICA
------------------------------------------------------------------------------*/
typedef struct fila
{
    Tno_pilha *pilhas[2];
    int inicio, fim;
} T_FILA;
int inicializa(T_FILA *f);
int verifica_vazio(T_FILA f);
int remover(T_FILA *f);
int verifica_cheio(T_FILA f);
int insere(T_FILA *f, Tno_pilha *inicio);
int listar(T_FILA f);

//------------------------------------------------------------------------------
//Limpa o buffer do teclado
void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int main(int argc, char const *argv[])
{
    int opcaoMenu;     /* receber a opcao do usuario do menu principal*/
    int opcaosubmenu1; /* receber a opcao do usuario do submenu mercado*/
    int opcaosubmenu2; /* receber a opcao do usuario do submenu folheto*/
    int opcaosubmenu3; /* receber a opcao do usuario do submenu modificando folheto do submenu folheto*/
    Tno_ls *mtrFolhetos[tamanho][tamanho2]; /* matriz que armazena os folhetos */
    int erro; /* valor de erro retornado pelas funcoes */
    int contadorLista = 0;
    int indicemercado;
    int indicefolheto = 0, indicefolheto2 = 0, col = 0, posExclusao = 0;
	Tno_ls *ini;
    char dado[100];
	Tno_pilha *iniPilhaMercado1;
    Tno_pilha *iniPilhaMercado2;

	T_FILA s;
    
    do
    {
        system("cls");
        printf("-----------------------------------------------------------------------\n");
        printf("Trabalho de Estrutura de Dados I\n");
        printf("Gerenciamento de Mercados e Folhetos para Impressao\n");
        printf("-----------------------------------------------------------------------\n");
        printf("\nEscolha uma opcao do menu: \n\n");
        printf("1 - Gerenciar Folhetos e Imprimir\n");
        printf("0 - Sair \n\n");
        scanf("%d", &opcaoMenu); /* Ler a opcao do usuario */
        switch (opcaoMenu)
        {
        case 1:
            do
            {
                system("cls");
                printf("Escolha uma opcao do sub-menu: \n\n");
                printf("1 - Cadastrar Novo Folheto \n");
                printf("2 - Modificar Folheto Existente\n");
                printf("3 - Consultar Todos os Folhetos de um Mercado \n");
                printf("4 - Remover Folheto Especifico \n");
                printf("5 - Remover Todos os Folhetos de um mercado \n");
                printf("6 - Imprimir folhetos \n");
                printf("0 - Voltar \n\n");
                scanf("%d", &opcaosubmenu2);
                switch (opcaosubmenu2)
                {
                case 1:
                    do{
                        printf("\nDigite para qual mercado voce deseja criar um novo folheto (1 ou 2): ");
                        scanf("%d", &indicemercado);
                        if(indicemercado != 1 && indicemercado!=2){
                            printf("\nOpcao nao valida \n");
                            system("pause");
                        }
                    }while((indicemercado != 1 && indicemercado != 2));
                    indicemercado--;
                    if(contadorLista < 10){
                            if(indicemercado == 0){
                                if(indicefolheto > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }else{
                                    erro=Inicializar_LS (&ini);
                                    if(erro == 0){
                                            printf("Lista %d inializada\n",contadorLista+1);
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto,ini);
                                    if(erro == 0){
                                        printf("Folheto Novo Adicionado no Mercado 1\n");
                                        system("pause");
                                    }
                                    indicefolheto++;
                                }
                            }else{
                                if(indicefolheto2 > 4){
                                    printf("Quantidade maxima de folhetos adicionados\n");
                                    system("pause");
                                }else{
                                    erro=Inicializar_LS (&ini);
                                    if(erro == 0){
                                            printf("Lista %d inializada\n",contadorLista+1);
                                            contadorLista++;
                                    }
                                    erro = cadastrarNovoFolheto(&mtrFolhetos,indicemercado,indicefolheto2,ini);
                                    if(erro == 0){
                                        printf("Folheto Novo Adicionado no Mercado 2\n");
                                        system("pause");
                                    }
                                    indicefolheto2++;
                                }
                            }    
                    }
                    else{
                        printf("Todos os folhetos dos dois mercados ja foram cadastrados\n");
                        system("pause");
                    }
                    break;
                case 2:
                    do
                    {
                        system("cls");
                        printf("\nModificando Folheto Existente: \n\n");
                        printf("1 - Inserir novo produto\n");
                        printf("2 - Remover produto\n");
                        printf("3 - Consultar todos produtos cadastrados de um folheto\n");
                        printf("0 - Voltar \n\n");
                        scanf("%d", &opcaosubmenu3);
                        switch (opcaosubmenu3)
                        {
                        case 1:
                            do{
                                printf("\nDigite para qual mercado o folheto que voce ira adicionar o produto esta (1 ou 2): ");
                                scanf("%d", &indicemercado);
                                if(indicemercado != 1 && indicemercado!=2){
                                    printf("\nOpcao nao valida \n");
                                    system("pause");
                                }
                            }while(indicemercado != 1 && indicemercado != 2);
                            

                            if(indicemercado-1 == 0){
                                do{
                                    printf("\nDigite para qual folheto do mercado %d voce ira adicionar o produto (1 ao 5): ",indicemercado+1);
                                    scanf("%d", &col);
                                    if(col>indicefolheto){
                                        printf("Esse folheto ainda nao foi inserido!\n");
                                    }
                                }while(col>indicefolheto);
                            }
                            else{
                                 do{
                                    printf("\nDigite para qual folheto do mercado %d voce ira adicionar o produto (1 ao 5): ",indicemercado+1);
                                    scanf("%d", &col);
                                    if(col>indicefolheto2){
                                        printf("Esse folheto ainda nao foi inserido!\n");
                                    }
                                }while(col>indicefolheto2);
                            }
                            flush_in();//limpa buffer do teclado
                            printf("\nDigite o nome do produto que sera inserido: ");
                            fgets(dado,100,stdin);
                           // scanf("%s",&dado);
                            erro = Inserir_fim_LS(&mtrFolhetos[indicemercado-1][col-1],dado);
                            if(erro == 0){
                                printf("\nInsercao de produto bem sucedida!\n");
                                system("pause");
                            }
                            break;
                        case 2:
                            do{
                                printf("\nDigite para qual mercado o folheto que voce ira remover o produto esta (1 ou 2): ");
                                scanf("%d", &indicemercado);
                                if(indicemercado != 1 && indicemercado!=2){
                                    printf("\nOpcao nao valida \n");
                                    system("pause");
                                }
                            }while(indicemercado != 1 && indicemercado != 2);
                            
                            if(indicemercado-1 == 0){
                                do{
                                    printf("\nDigite para qual folheto do mercado %d voce ira remover o produto (1 ao 5): ",indicemercado);
                            scanf("%d", &col);
                                    if(col>indicefolheto){
                                        printf("Esse folheto ainda nao foi inserido!\n");
                                    }
                                }while(col>indicefolheto);
                            }
                            else{
                                 do{
                                    printf("\nDigite para qual folheto do mercado %d voce ira remover o produto (1 ao 5): ",indicemercado);
                                    scanf("%d", &col);
                                    if(col>indicefolheto2){
                                        printf("Esse folheto ainda nao foi inserido!\n");
                                    }
                                }while(col>indicefolheto2);
                            }
                            flush_in();//limpa buffer do teclado

                            printf("\nDigite a posicao do produto que sera excluido: ");
                            scanf("%d", &posExclusao);
                            erro = Remover_meio_LS(&mtrFolhetos[indicemercado-1][col-1],posExclusao);
                            if(erro == 0){
                                printf("\nRemocao de produto bem sucedida!\n");
                                system("pause");
                            }else if(erro == 1){
                                printf("\nPosicao invalida!\n");
                                system("pause");
                            }else if(erro == 2){
                                printf("\nPosicao invalida! Acima do tamanho da lista\n");
                                system("pause");
                            }
                            break;
                        case 3:
                            do{
                                printf("\nDigite em qual mercado o folheto que voce ira consultar esta (1 ou 2): ");
                                scanf("%d", &indicemercado);
                                if(indicemercado != 1 && indicemercado!=2){
                                    printf("\nOpcao nao valida \n");
                                    system("pause");
                                }
                            }while(indicemercado != 1 && indicemercado != 2);
                            if(indicemercado-1 == 0){
                                do{
                                    printf("\nDigite qual folheto do mercado %d voce ira listar os produtos (1 ao 5): ",indicemercado);
                            scanf("%d", &col);
                                    if(col>indicefolheto){
                                        printf("Esse folheto ainda nao foi inserido!\n");
                                    }
                                }while(col>indicefolheto);
                            }
                            else{
                                 do{
                                    printf("\nDigite qual folheto do mercado %d voce ira listar os produtos (1 ao 5): ",indicemercado);
                                    scanf("%d", &col);
                                    if(col>indicefolheto2){
                                        printf("Esse folheto ainda nao foi inserido!\n");
                                    }
                                }while(col>indicefolheto2);
                            }
                            erro = Listar_LS(mtrFolhetos[indicemercado-1][col-1],col);
                            if(erro == 0){
                                printf("\nFim da listagem dos produtos!\n");
                                system("pause");
                            }
                            break;
                        case 0:
                            break;
                        default:
                            printf("\nOpcao nao valida \n");
                            system("pause");
                        }
                    } while ((opcaosubmenu3 != 0));
                    break;
                case 3:
                    do{
                        printf("\nDigite qual mercado voce deseja listar todos os folhetos (1 ou 2): ");
                        scanf("%d", &indicemercado);
                        if(indicemercado != 1 && indicemercado!=2){
                            printf("\nOpcao nao valida \n");
                            system("pause");
                        }
                    }while(indicemercado != 1 && indicemercado != 2);

                    indicemercado--;
                    int cont;
                    printf("\n");
                    if(indicemercado == 0){
                        for(cont = 0; cont < indicefolheto; cont++){
                            erro = Listar_LS(mtrFolhetos[indicemercado][cont],cont+1);
                            printf("----------------------------------------------\n");
                        }
                        printf("\nFim da listagem dos folhetos!\n");
                        system("pause");
                    }
                    else{
                        for(cont = 0; cont < indicefolheto2; cont++){
                            erro = Listar_LS(mtrFolhetos[indicemercado][cont],cont);
                            printf("----------------------------------------------\n");
                        }
                        printf("\nFim da listagem dos folhetos!\n");
                        system("pause");
                    }
                    break;
                case 4:
                    do{
                        printf("\nDigite de qual mercado voce deseja excluir o folheto (1 ou 2): ");
                        scanf("%d", &indicemercado);
                        if(indicemercado != 1 && indicemercado!=2){
                            printf("\nOpcao nao valida \n");
                            system("pause");
                        }
                    }while(indicemercado != 1 && indicemercado != 2);
                    if(indicemercado-1 == 0){
                        do{
                            printf("\nDigite qual folheto do mercado %d voce ira remover (1 ao 5): ",indicemercado);
                            scanf("%d", &col);
                            if(col>indicefolheto){
                                printf("Esse folheto ainda nao foi inserido!\n");
                            }
                        }while(col>indicefolheto);
                    }
                    else{
                         do{
                            printf("\nDigite qual folheto do mercado %d voce ira remover (1 ao 5): ",indicemercado);
                            scanf("%d", &col);
                            if(col>indicefolheto2){
                                printf("Esse folheto ainda nao foi inserido!\n");
                            }
                        }while(col>indicefolheto2);
                    }
                    erro = removerLista(&mtrFolhetos[indicemercado-1][col-1]);
                    if(erro == 1){
                        printf("\nFolheto removido com sucesso!\n");
                        system("pause");
                    }
                    break;
                case 5:
                    do{
                        printf("\nDigite qual mercado voce deseja remover todos os folhetos (1 ou 2): ");
                        scanf("%d", &indicemercado);
                        if(indicemercado != 1 && indicemercado!=2){
                            printf("\nOpcao nao valida \n");
                            system("pause");
                        }
                    }while(indicemercado != 1 && indicemercado != 2);
                    indicemercado--;
                    int cont2;

                    if(indicemercado == 0){
                        for(cont2 = 0; cont2 < indicefolheto; cont2++){
                            erro = removerLista(&mtrFolhetos[indicemercado][cont2]);
                        }
                        printf("\nTodos os folhetos do mercado 1 foram removidos!\n");
                        system("pause");
                    }
                    else{
                        for(cont2 = 0; cont2 < indicefolheto2; cont2++){
                            erro = removerLista(&mtrFolhetos[indicemercado][cont2]);
                        }
                        printf("\nTodos os folhetos do mercado 2 foram removidos!\n");
                        system("pause");
                    }   
                    break;
                case 6:
                    //inicializando a fila de mercados com folhetos para impressão
                    if(indicefolheto > 0 && indicefolheto2 > 0){
                        erro=inicializa (&s);
                        if(erro == 0){
                            printf("\nInicializacao da Fila realizada com sucesso !\n");
                        }
                    
                        //montando as pilhas de cada dia da semana para mercado 1 -> a primeira inserida vai ficar no topo da pilha
                        erro = Inicializar_pilha(&iniPilhaMercado1);
                        if(erro == 0){
                            printf("Inicializacao da Pilha 1 realizada com sucessso\n");
                        }

                        //populando pilha com todos os folhetos da semana do mercado 1
                        for(cont2 = indicefolheto-1; cont2 >= 0; cont2--){
                            erro = Inserir_topo(&iniPilhaMercado1,mtrFolhetos[0][cont2]);
                            if(erro == 0){
                                printf("Listas do mercado 1 inseridas com sucesso na pilha 1!\n");
                        }
                        }
                        //inserindo pilha 1 na fila
                        erro=insere(&s,iniPilhaMercado1);
                        if (erro==1){
                            printf("\nFila cheia. Overflow\n");
                        }else if(erro==0){
                            printf("Adicionada pilha 1 na fila com sucesso!\n");
                        }
  
                        //montando as pilhas de cada dia da semana para mercado 2 -> a primeira inserida vai ficar no topo da pilha
                        erro = Inicializar_pilha(&iniPilhaMercado2);
                        if(erro == 0){
                            printf("\nInicializacao da Pilha 2 realizada com sucessso\n");
                        }

                        //populando pilha com todos os folhetos da semana do mercado 2
                        for(cont2 = indicefolheto2-1; cont2 >= 0; cont2--){
                            erro = Inserir_topo(&iniPilhaMercado2,mtrFolhetos[1][cont2]);
                            if(erro == 0){
                                printf("Listas do mercado 2 inseridas com sucesso na pilha 2!\n");
                            }
                        }
                        //inserindo pilha 2 na fila
                        erro=insere(&s,iniPilhaMercado2);
                        if (erro==1){
                            printf("\nFila cheia. Overflow\n");
                        }else if(erro==0){
                            printf("Adicionada pilha 2 na fila com sucesso!\n");
                        }

                        //imprimindo a fila
                        erro = listar(s);
    			        if (erro == 1)
	    		           printf("\nA fila esta vazia.\n");
		    	        system("pause");
                    }
                    else{
                        printf("Eh necessario ter inserido ao menos 1 folheto em cada um dos mercados\n");
                        system("pause");
                    }
                    break;
                case 0:
                break;
                default:
                    printf("\nOpcao nao valida \n");
                    system("pause");
                }
            } while ((opcaosubmenu2 != 0));
            break;
        case 0:
            break;
        default:
            printf("\nOpcao nao valida \n");
            system("pause");
        }
    } while ((opcaoMenu != 0));
    return 0;
}

int Inicializar_LS (Tno_ls **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */

int removerLista(Tno_ls **inicio)
{
    Tno_ls *percorre, *aux;
    if(*inicio != NULL)
    {
        percorre = *inicio;
        do{
            aux = percorre;
            percorre = percorre->prox;
            free(aux);
        }while (percorre != NULL);
        *inicio = NULL;
        return 1; /* inicializa apagando tudo da lista */
    }
    else
    {
        return 0;
    }
}

int cadastrarNovoFolheto(Tno_ls *mtrFolhetos[tamanho][tamanho2], int lin, int col, Tno_ls *inicio){
    mtrFolhetos[lin][col] = inicio;
    return 0;
}

int Inserir_fim_LS (Tno_ls **inicio, char info[100])
{
    Tno_ls *no_novo, *percorre;
    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    strcpy (no_novo -> dado, info);
    no_novo -> prox = NULL;
    if (*inicio==NULL)
	{ /* lista vazia. */
	    *inicio = no_novo;
        puts((*inicio)->dado);
	}
	else { /* lista nao vazia */
	     percorre = *inicio;
	     while (percorre->prox != NULL)
	     {
	         percorre = percorre -> prox;
	     }
	    percorre->prox = no_novo;
	}
	return 0;
}

int Obter_Tamanho_LS(Tno_ls *inicio, int *tam)
{
    Tno_ls *percorre;
    *tam = 0;
    if(inicio != NULL)
    {
        percorre = inicio;
        while (percorre != NULL)
        {
            (*tam)++;
            percorre = percorre -> prox;
        }
    }
    else
    {
        *tam = 0;
    }
}

int Remover_inicio_LS (Tno_ls **inicio)
{
    Tno_ls *aux;
    if (*inicio == NULL)
    {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}

int Remover_fim_LS (Tno_ls **inicio)
{
    Tno_ls *aux, *percorre;
    int tamanholista=0;
    if (*inicio == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover ultimo */
    }
    else
    {
        Obter_Tamanho_LS(*inicio, &tamanholista);
        if (tamanho == 1)
        {
            Remover_inicio_LS(inicio);
        }
        else
        {
            percorre = *inicio;
            while (percorre->prox != NULL)
            {
                aux = percorre;
                percorre = percorre -> prox;
            }
            aux->prox = NULL;
            free(percorre);
            return 0;
        }
    }
}

int Remover_meio_LS (Tno_ls **inicio, int pos)
{
    int tam;
    Tno_ls *aux, *percorre;

    /* Tratamento de erros ======================================= */
    if (pos<= 0)
        return 1;  /*) posicao invalida para remocao */

    Obter_Tamanho_LS(*inicio, &tam);
    if (pos > tam)
        return 2;   /* posicao invalida. Acima do tamanho da lista */
    /* ================================================= */
    /* procura pela posicao de remocao */
    if (pos==1)
    {
        /* remocao no fim */
        Remover_inicio_LS(inicio);
    }
    else
    {
        if (pos == tam)
        {
            Remover_fim_LS(inicio);
        }
        else
        {
            int pos_aux=1;
            percorre = *inicio;
            while (pos_aux!=pos) /* parar uma posicao antes */
            {
                aux = percorre;
                percorre = percorre -> prox;
                pos_aux++;
            }
            aux -> prox = percorre -> prox;
            free(percorre);
        }
    }
    return 0;
}
int Listar_LS (Tno_ls *inicio, int posicao)
{
	int i;
    int contador = 1;
	Tno_ls *aux;

	if (inicio == NULL)
	{
        return 1;  /* lista vazia */
	}
    if(posicao != 900){
        printf("Folheto selecionado: %d\n\n", posicao);
    }
    aux = inicio;
	do {
           printf("Posicao do produto no folheto => %d | Valor => ",contador);
           contador++;
           puts(inicio -> dado);
		   inicio = inicio->prox;
    } while (inicio != NULL);

	return 0; /* sem erro */
}

int  inicializa (T_FILA *f)
{
  (*f).inicio = -1;
  (*f).fim = -1;
  return 0;
}

int Inicializar_pilha (Tno_pilha **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */

int Inserir_topo (Tno_pilha **inicio, Tno_ls *folheto)
{
    Tno_pilha *no_novo;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_pilha *) malloc(sizeof(Tno_pilha));
    no_novo -> folheto = folheto;
	if (*inicio==NULL)
	{    // insercao em pilha vazia
	    no_novo -> prox = NULL;
	    *inicio = no_novo;
	}
	else { // insercao em pilha nao vazia
	     no_novo -> prox = *inicio;
	    *inicio = no_novo;
	}
    return 0;
}
int verifica_cheio(T_FILA f)
{
    if (f.fim == tamanho-1 ){
        return 1;   // fila cheia
    }else{
        return 2;  // fila n�o cheia
    }
}
int insere(T_FILA *f, Tno_pilha *inicio)
{
    int erro = verifica_cheio(*f);
    if (erro != 1)
    {
       (*f).fim++;
       (*f).pilhas[(*f).fim]=inicio;// inser��o efetuada
       if ((*f).inicio == -1)
          (*f).inicio = 0;
       return 0;
    }
    else
       return 1; // impossivel inser��o. overflow
}

int Remover_topo (Tno_pilha **inicio)
{
    Tno_pilha *aux;
    if (*inicio == NULL)
    {
         return 1;  /* pilha vazia, impossivel remover topo */
    }
    else {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}
int Obter_topo(Tno_pilha *inicio)
{
    if (inicio != NULL)
    {
        Listar_LS((inicio->folheto), 900);
        printf("--------------------------------------------\n");
        Remover_topo(&inicio);
        Obter_topo(inicio);
       return 0;
    }
    else
       return 1; // Pilha Vazia
}
int verifica_vazio(T_FILA f)
{
    if(f.inicio==f.fim+1){
       return 0;  // fila vazia
    }else {
        return -1;
    }
}
int listar(T_FILA f)
{  int i,erro;
    erro=verifica_vazio(f);
    if (erro!=0)
    {
       for (i=f.inicio; i<=f.fim; i++)
            Obter_topo(f.pilhas[i]);
            printf("fim da impressão do mercado %d\n",i);
       printf("\n");
       return 0;
    }
    else return 1;  // nao possivel listar pois a fila esta vazia
}