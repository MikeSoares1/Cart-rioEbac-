#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
  	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string 
	
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

int consulta() //Função responsavel pela consulta do usuário no sistema
{ 
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
	char cpf[40]; 
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Coletando informações para a consulta do usuário
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!");
       
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas são as informções do usuário: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
     
    system("pause");
    
}

int deletar() //Função responsavel por deletar o usuário do sistema
{
		char cpf[40];
		
		printf("Digite o CPF do usuário a ser deletado: ");
		scanf("%s",cpf);
		
		
		FILE *file;
		file = fopen(cpf,"r");
		fclose(file);
		
		if(file == NULL)
		{
			printf("\nO usuário não se encontra no sistema!.\n\n");	
			system("pause");
		}
		
		else
		{
	    	if(remove(cpf) == 0)
	    {
			
	    	printf("O usuário foi deletado com sucesso!\n ");
			system("pause");		
		}
		
	 	}
}



int main() //Função principal do projeto
    {  
    int opcao=0; //Definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
	{
	
		system("cls");
		
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
    	printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("Opção: "); //Fim do menu

        scanf("%d", &opcao); //Armazenando a esolha do usuário
    
        system("cls"); //responsavel por limpar a tela
    
        switch(opcao) //inicio da seleção
        {
        	case 1:
        	registro(); //chamada de funções 
        	break;
        	
        	case 2:
        	consulta();
        	break;
        	
        	case 3:
        	deletar();
    	    break;
    	    
    	    
    	    
    	    default:
    	  	printf("Essa opção não está disponivel!\n");
    		system("pause");
    		break;
    		
		} //fim da seleção
		
   }
}
