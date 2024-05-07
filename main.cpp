#include <stdio.h>  //bivlioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //responsavel por cuidar das string

int registro()  //função responsavel por cadastrar os usuários no sistema 
{
    //inicio criação de variaveis/string
	   char arquivo[40];
	   char cpf[40];
	   char nome[40];
	   char sobrenome[40];
	   char cargo[40];
	//final da criação de variaveis/string
	   
	   printf("Digite o cpf a ser cadastrado: "); //solicita o cpf a ser cadastraddo/coletando informações do usuário
	   scanf("%s", cpf);                          //%s refere-se a string
	   
	   strcpy(arquivo, cpf);                      //reponsavel por copiar os valores da strings
	   
	   FILE *file;                                //cria o arquivo
	   file = fopen(arquivo, "w");                //cria o arquivo e o "w" significa escrever 
	   fprintf(file,cpf);                         //salvo o valor da variavel
	   fclose(file);                              //fecha o arquivo
	   
	   file = fopen(arquivo, "a");                //acessa o aquivo e o "a" atualiza as informações
	   fprintf(file,",");                         //salva o espaço para separar a variavel por linha 
	   fclose(file);                              //fecha o arquivo
	   
	   printf("Digite o nome a ser cadastrado: ");
	   scanf("%s", nome);                         //%s refere-se a string
	   
	   file = fopen(arquivo, "a");                //acessa o aquivo e o "a" atualiza as informações
	   fprintf(file,nome);                        //salvo o valor da variavel
	   fclose(file);                              //fecha o arquivo
	   
	   file = fopen(arquivo, "a");                //acessa o aquivo e o "a" atualiza as informações
	   fprintf(file,",");                         //salva o espaço para separar a variavel por linha 
	   fclose(file);                              //fecha o arquivo
	   
	   printf("Digite o sobrenome a ser cadastrado: ");
	   scanf("%s",sobrenome);
	   file = fopen(arquivo, "a");                //acessa o aquivo e o "a" atualiza as informações
	   fprintf(file,sobrenome);                   //salvo o valor da variavel
	   fclose(file);                              //fecha o arquivo
	   
	   file = fopen(arquivo, "a");                //acessa o aquivo e o "a" atualiza as informações
	   fprintf(file,",");                         //salva o espaço para separar a variavel por linha 
	   fclose(file);                              //fecha o arquivo
	   
	   printf("Digite o cargo a ser cadastrado: ");
	   scanf("%s", cargo);                        //%s refere-se a string
	   
	   file = fopen(arquivo, "a");                //acessa o aquivo e o "a" atualiza as informações
	   fprintf(file,cargo);                       //salvo o valor da variavel
	   fclose(file);                              //fecha o arquivo
	   
	   system("pause");
	   
}

int cunsulta()
{
	   setlocale(LC_ALL, "Portuguese");
	   
	   //inicio criação de variaveis/string
	   char cpf[40];
	   char conteudo[200];
	   //final da criação de variaveis/string
	   
	   printf("Digite seu CPF a ser consultado: "); //solicita o cpf a ser consultado 
	   scanf("%s",cpf);                          //%s refere-se a string
	   
	   FILE *file;
	   file = fopen(cpf, "r");                   //abri o arquivo e o "r" responsavel por ler o arquivo
	   
	   if(file == NULL)                          //responsavel por trazer as informações de usuário
	   {
	     printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	   }
	   
	   while(fgets(conteudo, 200, file) != NULL) 
	   {
	   printf("\nEssas são as informações do usuário: ");
	   printf("%s", conteudo);                   //%s refere-se a string
	   printf("\n\n");
	   }
	   
	   system("pause");
	   
	   
}

int deletar()
{
	   //inicio criação de variaveis/string
	   char cpf[40];
	   //final da criação de variaveis/string
	   
	   printf("Digite o CPF do usuário a ser deletado: ");  //solicitando o cpf a ser deletado 
	   scanf("%s",cpf);      //%s refere-se a string
	   
	   FILE *file;
	   file = fopen(cpf,"r");  //abre o arquivo e o "r" le o arquivo
	   
	   remove(cpf);
	   
	   if(file == NULL)     //responsavel por trazer as informações de usuário
	   {
	       printf("O CPF do usuário não foi encontrado no sistema!.\n\n"); //informa que o cpf não foi encontrado
	       system("pause");
	   }

	   
}

int main()
		{
		int opcao=0; //Definindo variáveis
		int laco=1;

		for(laco=1;laco=1;)
		{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar no nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n");
		printf("\t4 - Sair do sistema!\n");
		printf("Opção:"); //fim do menu

		scanf("%d", &opcao); //armazenando a escolha so usuário
	
		system("cls");    //responsavel por limpar a tela 
		
		switch(opcao)  //inicio da seleção do menu
		{
		    case 1:
		    registro();   //chamada de funções
		    break;

		    case 2:
		    cunsulta();
	        break;
	
	  		case 3:
	        deletar();
	        break;
	        
	        case 4:
	        printf("Obrigado por utilizar o sistema!");
	        return 0;
	        break;
	        

		    default:
            printf("Essa opção não está disponivel!\n");
    	    system("pause");
    	    break;
		}
    }			
}





