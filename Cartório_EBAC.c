#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
  	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string 
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w");
	fprintf(file,cpf); // salvo o valor da variavel 
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	

	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo A ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
	
}

int consulta() //Fun��o responsavel pela consulta do usu�rio no sistema
{ 
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
	char cpf[40]; 
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��es para a consulta do usu�rio
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!");
       
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as inform��es do usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
     
    system("pause");
    
}

int deletar() //Fun��o responsavel por deletar o usu�rio do sistema
{
		char cpf[40];
		
		printf("Digite o CPF do usu�rio a ser deletado: ");
		scanf("%s",cpf);
		
		
		FILE *file;
		file = fopen(cpf,"r");
		fclose(file);
		
		if(file == NULL)
		{
			printf("\nO usu�rio n�o se encontra no sistema!.\n\n");	
			system("pause");
		}
		
		else
		{
	    	if(remove(cpf) == 0)
	    {
			
	    	printf("O usu�rio foi deletado com sucesso!\n ");
			system("pause");		
		}
		
	 	}
}



int main() //Fun��o principal do projeto
    {  
    int opcao=0; //Definindo vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)
	{
	
		system("cls");
		
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
    	printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("\t4 - Sair do sistema\n\n");
    	printf("Op��o: "); //Fim do menu

        scanf("%d", &opcao); //Armazenando a esolha do usu�rio
    
        system("cls"); //responsavel por limpar a tela
    
        switch(opcao) //inicio da sele��o
        {
        	case 1:
        	registro(); //chamada de fun��es 
        	break;
        	
        	case 2:
        	consulta();
        	break;
        	
        	case 3:
        	deletar();
    	    break;
    	    
    	    case 4:
    	    printf("Obrigado por utilizar o sistema!\n");
    	    return 0;
    	    break;
    	    
    	    
    	    default:
    	  	printf("Essa op��o n�o est� disponivel!\n");
    		system("pause");
    		break;
    		
		} //fim da sele��o
		
   }
}
