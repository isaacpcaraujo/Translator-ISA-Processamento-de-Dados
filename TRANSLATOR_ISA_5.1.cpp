// INCLUS�O DAS BIBLIOTECAS
#include <iostream> // Biblioteca padr�o, utilizada para habilitar as entradas e sa�das do programa.
#include <string> // Biblioteca utilizada para fazer manipula��o em strings.
#include <cctype> // Biblioteca utilizada para fazer manipula��o em caracteres, como converter em mai�sculas ou verificar se � um n�mero.
#include <vector> // Biblioteca utilizada para fazer manipula��o dos vetores, alterando seu tamanho.
#include <algorithm> // Biblioteca utilizada para remo��o de um elemento de um vetor espec�fico.
#include <locale.h> // Biblioteca utilizada para incluir caracteres n�o existentes no texto padr�o do programa, como acentos, por exemplo.
 
 
using namespace std;

/* FUN��O PARA CONVERTER EM MAI�SCULAS: Essa fun��o percorre a string, caractere por caractere, convertendo cada um deles em letras mai�sculas, atrav�s do 
comando toupper. */
string maiusculas (string entrada, int tamanhoentrada) {
    for(int i=0; i<tamanhoentrada; i++) {
    	entrada[i]=toupper(entrada[i]);
	}
	return entrada;
}

/* FUN��O PARA BUSCA BIN�RIA TIPO VETOR DE CHAR: Essa fun��o utiliza a busca bin�ria para localizar um caractere espec�fico pr�-determinado em um vetor de 
caracteres. Para isso, o vetor de caracteres deve estar ordenado. Ent�o, s�o realizadas sucessivas divis�es do espa�o de busca, comparando o elemento 
buscado com o elemento do meio do vetor. Se o elemento do meio do vetor for o elemento buscado, a busca termina com sucesso. Caso contr�rio, se o elemento 
buscado vier antes do elemento do meio, ent�o a busca continua na metade da esqueda do vetor. E finalmente, se o elemento buscado vier depois do elemento do
meio do vetor, a busca continua na metade da direita do vetor. E assim sucessivamente. Ao final da busca, a fun��o retorna a posi��o em que o elemento foi
encontrado, ou retorna -1 caso o elemento n�o seja encontrado. */
int buscabinariachar (char busca, char vetor[], int tamanhovetor) {
    int esq=0, dir=tamanhovetor-1, meio, posicaobuscabinaria=-1;
    while (esq<=dir) {
        meio=(esq+dir)/2;
        if (busca<vetor[meio]) {
            dir=meio-1;
            posicaobuscabinaria=-1;
        } else if (busca==vetor[meio]) {
            posicaobuscabinaria=meio;
            break;
        } else {
            esq=meio+1;
			posicaobuscabinaria=-1;
        }
    }
    return posicaobuscabinaria;
}

/* FUN��O PARA BUSCA BIN�RIA TIPO VETOR DE INT: Essa fun��o utiliza a busca bin�ria, atrav�s da mesma l�gica descrita na fun��o anterior, por�m para 
localizar um inteiro em um vetor de inteiros. */
int buscabinariaint (int busca, int vetor[], int tamanhovetor) {
    int esq=0, dir=tamanhovetor-1, meio, posicaobuscabinaria=-1;
    while (esq<=dir) {
        meio=(esq+dir)/2;
        if (busca<vetor[meio]) {
            dir=meio-1;
            posicaobuscabinaria=-1;
        } else if (busca==vetor[meio]) {
            posicaobuscabinaria=meio;
            break;
        } else {
            esq=meio+1;
			posicaobuscabinaria=-1;
        }
    }
    return posicaobuscabinaria;
}


/* FUN��O PARA BUSCA BIN�RIA TIPO VECTOR DE STRINGS: Essa fun��o utiliza a busca bin�ria, atrav�s da mesma l�gica descrita na fun��o anterior, por�m para 
localizar uma string em um vector de strings. */
int buscabinariavector (string busca, vector<string> vetor, int tamanhovetor) {
    int esq=0, dir=tamanhovetor-1, meio, posicaobuscabinaria=-1;
    while (esq<=dir) {
        meio=(esq+dir)/2;
        if (busca<vetor[meio]) {
            dir=meio-1;
            posicaobuscabinaria=-1;
        } else if (busca==vetor[meio]) {
            posicaobuscabinaria=meio;
            break;
        } else {
            esq=meio+1;
			posicaobuscabinaria=-1;
        }
    }
    return posicaobuscabinaria;
}

/* FUN��O PARA EXIBIR C�DIGO DE ERRO CASO O USU�RIO FORNE�A UMA ENTRADA ERRADA: Essa fun��o � utilizada para quando � perguntado se o usu�rio deseja voltar
ao menu principal. Caso o usu�rio digite 1, o programa ir� repetir a a��o feita anteriormente por ele (isso est� dentro do while de cada a��o do usu�rio no
int main). Caso o usu�rio digite 0, o programa ir� voltar ao menu principal. Caso ele digite algo diferente de 0, aparecer� a seguinte mensagem de erro, que
ir� se repetir, at� que o usu�rio aperte 0 para voltar oa menu principal. */
void codigodeerro (string retorno2) {
	while (retorno2!="0") {
		cout << "Comando inv�lido. Para voltar ao menu principal, digite 0." << endl;
		cout << ">> ";
		getline(cin,retorno2);
		cout << endl;
	}
}

/* FUN��O PARA VERIFICAR SE A ENTRADA (STRING) � UM N�MERO E CONVERT�-LA EM UM INT: Essa fun��o percorre a string, caractere por caractere, verificando se 
cada um deles � um n�mero. Se todos os caracteres forem n�meros, a vari�vel edigito continuar� com valor 0. Caso algum deles n�o seja n�mero, edigito 
assumir� um valor diferente de 0 e ser� solicitado que o usu�rio forne�a uma nova entrada at� que ela seja um n�mero (e edigito seja igual a 0). Quando 
isso ocorrer, a string que cont�m apenas n�meros ser� armazenada em um vetor de char, e por fim, o comando atoi ser� utilizada para converter esse vetor 
de char em um int. */
int converterconsultaparainteiro (string consulta) {
	int edigito=0;
	for (int i=0; i<consulta.size(); i++) {
		if (isdigit(consulta[i]) == 0) {
			edigito = edigito + 1;
		}
	}

	while (edigito != 0) {
		cout << "A entrada digitada n�o � v�lida. Tente novamente." << endl;
		cout << ">> ";
		getline (cin, consulta);
		cout << endl;	
		edigito=0;
		for (int i=0; i<consulta.size(); i++) {
			if (isdigit(consulta[i]) == 0) {
				edigito = edigito + 1;
			}
		}	
	}
			
	char auxconsulta[100];
	for (int i=0; i<100; i++) {
		auxconsulta[i] = consulta[i];
	}
			
	int consulta2 = atoi(auxconsulta);
	return consulta2;
}

/* FUN��O PARA CAPTURA DE STRINGS: Essa fun��o � utilizada para promover a intera��o do usu�rio com o programa, nela o usu�rio digita uma string que � armazenada e 
manipulada pelo restante do programa. */
string entrada(){
	
	string saida;
	cout << ">> ";
	getline(cin,saida);
	cout << endl;

return saida;
}


int main() {
	
	setlocale(LC_ALL,"portuguese"); // Fun��o da biblioteca locale.h para implementa��o de novas caracteres na programa��o.

	// Declara��o de vari�veis 
	vector<string> Tags,TagsCopy,Instrumentos,InstrumentosCopy;
	string funcao, consultaTAG, saidaconsultaTAG, variavelanalisada, retorno, consultainst, saidaconsultainst, auxtags, auxinstrumentos;
	string ordenacaotags, ordenacaotagscopy, ordenacaoinstrumentos, ordenacaoinstrumentoscopy, descadastramentoTag, descadastramentoInstrumentos;
	int posTag, posInstrumento, posTagCad, posInstrumentoCad, escolher, posconsultaTAG, posconsultainst, consultainst2; 
    char referenciavariavel[21] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L', 'M', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Z'};
	string variavel[21] = {"AN�LISE", "CHAMA DE QUEIMADOR", "CONDUTIVIDADE EL�TRICA", "DENSIDADE OU MASSA ESPEC�FICA", "TENS�O EL�TRICA", "VAZ�O", "MEDIDA DIMENSIONAL", "COMANDO MANUAL", "CORRENTE EL�TRICA", "POT�NCIA", "N�VEL", "UMIDADE", "PRESS�O", "QUANTIDADE", "RADIOATIVIDADE", "VELOCIDADE OU FREQU�NCIA", "TEMPERATURA", "MULTIVARI�VEIS", "VISCOSIDADE", "PESO OU FOR�A", "POSI��O"};
	string referenciafuncao[33] = {"A", "C", "CV", "E", "G", "I", "IC", "IR", "IRC", "IRT", "IT", "JS", "JY", "L", "O", "P", "R", "RC", "RT", "S", "SA", "SE", "SS", "SU", "SV", "SY", "SZ", "T", "U", "V", "W", "Y", "Z"};	
	string funcaoinstrumento[33] = {"ALARME", "CONTROLADOR", "V�LVULA DE CONTROLE", "ELEMENTO PRIM�RIO", "VISOR", "INDICADOR", "CONTROLADOR INDICADOR", "REGISTRADOR INDICADOR", "CONTROLADOR REGISTRADOR INDICADOR", "TRANSMISSOR REGISTRADOR INDICADOR", "TRANSMISSOR INDICADOR", "CHAVE SELETORA", "REL� SELETOR", "L�MPADA PILOTO", "ORIF�CIO DE RESTRI��O", "PONTO DE TESTE", "REGISTRADOR", "CONTROLADOR REGISTRADOR", "TRANSMISSOR REGISTRADOR", "CHAVE", "ALARME DE SEGURAN�A", "ELEMENTO PRIM�RIO DE SEGURAN�A", "CHAVE DE SEGURAN�A", "INSTRUMENTO MULTIFUN��O DE SEGURAN�A", "V�LVULA DE SEGURAN�A", "REL� DE SEGURAN�A", "ELEMENTO FINAL DE CONTROLE CLASSIFICADO DE SEGURAN�A", "TRANSMISSOR", "INSTRUMENTO MULTIFUN��O", "V�LVULA", "PO�O", "REL�", "ELEMENTO FINAL DE CONTROLE CLASSIFICADO"};
	// Cria��o de um vetor numerado de 1 a 21
	int referenciavariavelinst[21];
	for (int i=0; i<21; i++) {
		referenciavariavelinst[i]=i+1;
	}
	
	// Cria��o de um vetor numerado de 1 a 33
	int referenciafuncaoinst[33];
	for (int i=0; i<33; i++) {
		referenciafuncaoinst[i]=i+1;
	}	
	
	// Mensagem inicial do programa
    cout << "Seja bem-vindo ao TRANSLATOR ISA 5.1. O TRANSLATOR  ISA 5.1 � um software cuja finalidade principal � converter TAG's definidas pela norma ISA 5.1 nos nomes dos instrumentos correspondentes e vice-versa. As TAG's mais usuais que a norma ISA 5.1 abrange j� est�o cadastradas no sistema. Al�m disso, caso deseje, tamb�m � poss�vel cadastrar novas TAG's e associ�-las a instrumentos, de acordo com sua necessidade." << endl;
    cout << "ATEN��O: Ao fechar o programa, todas as informa��es cadastradas, inclusive os TAG's personalizados, ser�o perdidas." << endl;
    cout << endl;
	
	// Cria��o de um loop infinito
    for (int forever=0; forever==0; forever=0) {
    	
    	// Menu principal
		cout << "_____________________________________________________________________________________________________________" << endl;
		cout << endl;    
        cout << "Digite o n�mero correspondente � fun��o que deseja acessar:" << endl;
        cout << "1 - Converter uma TAG em um nome de instrumento." << endl;
        cout << "2 - Converter o nome de um instrumento em uma TAG." << endl;
        cout << "3 - Listar todas as TAG's cadastradas pelo usu�rio." << endl;
        cout << "4 - Listar todos os instrumentos cadastrados pelo usu�rio com uma TAG personalizada." << endl;
        cout << "5 - Cadastrar uma nova TAG e associ�-la a um instrumento." << endl;
        cout << "6 - Descadastrar um TAG/instrumento cadastrado pelo usu�rio." << endl;
		cout << "_____________________________________________________________________________________________________________" << endl;
		cout << endl;
		funcao = entrada();
        
        if (funcao=="1") { // Consultar instrumento a partir da TAG.
                
        	retorno="1";
			while (retorno=="1") { // Loop para caso o usu�rio deseje voltar � func�o 1.
 	            
				// Inser��o pelo usu�rio da TAG a ser consultada.
				cout << "Digite a TAG que deseja consultar." << endl;
    	    	consultaTAG = entrada();
        	    
        	    // Convers�o da TAG para letras mai�sculas.
				consultaTAG = maiusculas(consultaTAG, consultaTAG.size());
                
				// Procura por espa�os na TAG.	
	            size_t posEsp1 = consultaTAG.find(32);
					
				// Caso haja espa�os na TAG, voltar para o come�o da fun��o 1.
				if (posEsp1 != string::npos) {
					cout << "Tag inv�lida. Verifique a exist�ncia de espa�os em sua TAG. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
					retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
					continue;
				
				// Caso n�o haja espa�os na TAG.
				} else {
    	                
					// Procura da TAG no vector de TAG's pr�-cadastradas pelo usu�rio.       
	        	    posconsultaTAG = buscabinariavector (consultaTAG, Tags, Tags.size());
		            	
					// Caso a TAG j� tenha sido cadastrada pelo usu�rio, imprimir o instrumento correspondente.	                
	                if (posconsultaTAG!=-1) {	
						cout << InstrumentosCopy[posconsultaTAG] << endl;
					
					// Caso a TAG n�o tenha sido cadastrada pelo usu�rio.		
					} else {    				
		    				
						// Busca da primeira letra da TAG no vetor que tem a letra correspondente a cada vari�vel.									
						posconsultaTAG = buscabinariachar (consultaTAG[0], referenciavariavel, 21);	    
				    
						// Caso a primeira letra da TAG n�o cosnte no vetor que tem as letras de refer�ncia, voltar para o come�o da fun��o 1.
						if (posconsultaTAG == -1) {
							cout << "A TAG digitada n�o est� cadastrada no sistema. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
							retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
							continue;
						
						// Caso a primeira letra da TAG cosnte no vector que tem as letras de refer�ncia.
						} else {
							
							/* Caso a primeira letra da TAG corresponda � vari�vel an�lise, deve-se perguntar ao usu�rio qual a vari�vel que est� sendo 
							analisada (por exemplo, CO2, O2 etc.), pois essa vari�vel n�o deve constar na TAG, mas consta no nome do instrumento que 
							ser� impresso. */
							if (posconsultaTAG == 0) {
								consultaTAG = consultaTAG.substr(1,consultaTAG.size()-1); // A primeira letra da TAG � removida, pois j� foi associada a uma vari�vel.
								cout << "Qual a vari�vel analisada?" << endl;
								variavelanalisada = entrada(); // Inser��o pelo usu�rio da vari�vel analisada.
								variavelanalisada = maiusculas(variavelanalisada, variavelanalisada.size()); // Convers�o da vari�vel analisada para letras mai�sculas.
								saidaconsultaTAG = variavel[posconsultaTAG] + " DE " + variavelanalisada; // A sa�da fica da forma "an�lise de [variavelanalisada]".
							
							/* Caso a primeira letra da TAG n�o seja an�lise, a primeira letra da TAG � removida, pois j� foi associada a uma vari�vel, e a sa�da 
							recebe a informa��o sobre a vari�vel do instrumento. */
							} else {
								consultaTAG = consultaTAG.substr(1,consultaTAG.size()-1);
								saidaconsultaTAG = variavel[posconsultaTAG];
							}
						}
			
						/* Caso a vari�vel tenha apenas duas letras (sendo que uma j� foi removida), e a segunda letra seja D, F, J ou Q (que s�o letras 
						utilizadas apenas como modificadoras da vari�vel), a TAG � inv�lida, pois o instrumento n�o possui nenhuma fun��o de fato, e a 
						TAG representaria apenas uma vari�vel e uma letra modificadora, como, por exemplo "press�o diferencial". Ent�o, o programa deve 
						dizer que a TAG n�o est� cadastrada e voltar para o come�o da fun��o 1. */
						if ((consultaTAG.size()==1) && (consultaTAG[0]=='D' || consultaTAG[0]=='F' || consultaTAG[0]=='J' || consultaTAG[0]=='Q')) {
							cout << "A TAG digitada n�o est� cadastrada no sistema. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
							retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
							continue;
						
						/* Caso contr�rio, a segunda letra dever� ser analisada, para ver se corresponde a alguma das poss�veis letras modificadoras. Caso
						corresponda, a segunda letra da TAG � removida, pois j� foi associada a uma caracter�stica modificadora da vari�vel, e ser� inclu�da
						na sa�da a informa��o sobre a caracter�stica modificadora. */
						} else {
							if (consultaTAG[0]=='D') {
								consultaTAG = consultaTAG.substr(1,consultaTAG.size()-1);
								saidaconsultaTAG = saidaconsultaTAG + " DIFERENCIAL";
							} else if (consultaTAG[0]=='F') {
								consultaTAG = consultaTAG.substr(1,consultaTAG.size()-1);
								saidaconsultaTAG = "RAZ�O DE " + saidaconsultaTAG;
							} else if (consultaTAG[0]=='J' && consultaTAG[1]!='S' && consultaTAG[1]!='Y') {
								consultaTAG = consultaTAG.substr(1,consultaTAG.size()-1);
								saidaconsultaTAG = "VARREDURA DE " + saidaconsultaTAG;
							} else if (consultaTAG[0]=='Q') {
								consultaTAG = consultaTAG.substr(1,consultaTAG.size()-1);
								saidaconsultaTAG = "INTEGRA��O DE " + saidaconsultaTAG;
							}

						}
			
						/* An�lise das demais letras da TAG a fim de encontrar a fun��o do instrumento. Para isso, h� um vetor cadastrado previamente
						com todas as combina��es de letras poss�veis para representar a(s) fun��o(�es) do instrumento (referenciafuncao). Esse vetor 
						ser� percorrido da �ltima posi��o at� a primeira, e ser� buscado na TAG inserida pelo usu�rio cada uma dessas combina��es de 
						letras para ver se a TAG possui alguma dessas possibilidades de fun��es. Caso seja encontrada alguma fun��o, a letra ou as 
						letras correspondentes �(s) fun��o(�es) do instrumento ser�(�o) removida(s) da TAG, pois j� foram associadas �s fun��es, a 
						sa�da receber� a informa��o sobre a fun��o do instrumento, e a vari�vel funcaovalida assumir� valor 1. */
						int funcaovalida=0;
						for (int i=32; i>=0; i--) {
							if (consultaTAG.find(referenciafuncao[i]) == 0){
								consultaTAG = consultaTAG.substr(referenciafuncao[i].size(), consultaTAG.size() - referenciafuncao[i].size());
								saidaconsultaTAG = funcaoinstrumento[i] + " DE " + saidaconsultaTAG;
								funcaovalida=1;
								break;
							}
						}
				
						/* Caso no passo anterior n�o tenha sido encontrada nenhuma das possibilidades de fun��es na TAG inserida pelo usu�rio, 
						a vari�vel funcaovalida ter� valor 0 e o programa deve voltar ao �nicio da fun��o 1. */
						if (funcaovalida==0) {
							cout << "A TAG digitada n�o est� cadastrada no sistema. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
							retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
							continue;
						}
						
						/* Por fim, ser� analisado o que restou na vari�vel consultaTAG para verificar se corresponde a alguma das possibilidades
						de letras modificadoras do final da TAG. Se sim, a vari�vel consultaTAG ficar� "vazia" e a sa�da receber� a informa��o
						sobre as letras modificadoras do final da TAG. */
						if (consultaTAG=="HH") {
							consultaTAG = "";
							saidaconsultaTAG = saidaconsultaTAG + " MUITO ALTO(A)";
						} else if (consultaTAG=="H") {
							consultaTAG = "";
							saidaconsultaTAG = saidaconsultaTAG + " ALTO(A)";
						} else if (consultaTAG=="M") {
							consultaTAG = "";
							saidaconsultaTAG = saidaconsultaTAG + " INTERMEDI�RIO(A)";
						} else if (consultaTAG=="L") {
							consultaTAG = "";
							saidaconsultaTAG = saidaconsultaTAG + " BAIXO(A)";
						} else if (consultaTAG=="LL") {
							consultaTAG = "";
							saidaconsultaTAG = saidaconsultaTAG + " MUITO BAIXO(A)";
						} 
						
						/* Caso a TAG tenha passado por todos os passos anteriores com sucesso, ao final a vari�vel consultaTAG deve estar "vazia".
						Caso ela n�o esteja, � porque a TAG possui alguma outra letra que n�o � v�lida. Ent�o, o programa deve voltar ao in�cio da
						fun��o 1. */
						if (consultaTAG.size()!=0) {
							cout << "A TAG digitada n�o est� cadastrada no sistema. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
							retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
							continue;
						}
						
						// Ao final do processo, sa�da do instrumento correspondente � TAG inserida pelo usu�rio.
						cout << saidaconsultaTAG << endl;
						cout << endl;
							
					}
				}
				
				/* Caso o usu�rio deseje repetir a fun��o 1, ele deve digitar 1 e voltar� para o �nicio do while. Caso deseje voltar ao menu principal,
				ele deve digitar 0. */				
				cout << "Para voltar ao menu principal, digite 0. Para consultar outra TAG, digite 1." << endl;
				retorno = entrada();				
            }
             
			// Fun��o de c�dgo de erro caso o usu�rio n�o digite 1 nem 0.           
   			codigodeerro(retorno);
               
    	} else if (funcao=="2") { // Consultar TAG a partir do instrumento.
			
			retorno="1";
			while (retorno=="1") { // Loop para caso o usu�rio deseje voltar � func�o 2.
				
				// Caso haja instrumentos cadastrados previamente pelo usu�rio.
				if (Instrumentos.size()!=0) {
					
					// Cria��o de um vetor numerado de 1 at� a quantidade de instrumentos pr�-cadastrados pelo usu�rio.
					int referencianst[Instrumentos.size()];			
					for (int i=0; i<Instrumentos.size(); i++) {
						referencianst[i]=i+1;
					}
					
					// Usu�rio escolhe o n�mero correspondente ao instrumento que deseja consultar.
					cout << "Digite o n�mero correspondente ao instrumento que deseja consultar, caso ele esteja nessa lista: " << endl;
					
					// Mostra todos os instrumentos pr�-cadastrados e seu n�mero correspondente.
					for (int i=0; i<Instrumentos.size(); i++) {
						cout << referencianst[i] << " - " << Instrumentos[i] << endl;
					}
					
					// Usu�rio escolhe 0 caso o intrumento a ser consultado n�o esteja na lista.
					cout << "0 - O intrumento a ser consultado n�o est� nessa lista." << endl;
					cout << endl;
					
					// Entrada do usu�rio
					consultainst = entrada();
					
					// Fun��o para convers�o da entrada do usu�ario de string para inteiro, caso a entrada seja um n�mero.					
					consultainst2 = converterconsultaparainteiro(consultainst);
					
					// Caso o usu�rio N�O informe que o intrumento a ser consultado n�o est� na lista.
					if (consultainst2!=0) {
						
						/* Procura do n�mero inserido pelo usu�rio no vetor numerado de 1 at� a quantidade de instrumentos pr�-cadastrados pelo usu�rio,
						para ver se o n�mero � v�lido. */
						posconsultainst = buscabinariaint (consultainst2, referencianst, Instrumentos.size());
					
						/* Caso o n�mero n�o esteja entre as possibilidades do vetor, ser� solicitado que o usu�rio entre novamente com outro n�mero e o 
						processo se repetir� at� que o usu�rio digite um n�mero v�lido. */
						while (posconsultainst==-1) {
	
							cout << "A entrada digitada n�o � v�lida. Tente novamente." << endl;
							consultainst=entrada();
							consultainst2 = converterconsultaparainteiro(consultainst);
												
							if (consultainst2==0) {
								break;
							}
							
							posconsultainst = buscabinariaint (consultainst2, referencianst, Instrumentos.size());
						} 
										
						// Caso a entrada seja um n�mero v�lido, ser� impressa a TAG correspondente ao n�mero que o usu�rio digitou.	
						if (posconsultainst!=-1) {
							cout << TagsCopy[posconsultainst] << endl;
							cout << endl;					
						}
					}
				} 
				
				// Caso n�o haja instrumentos cadastrados previamente ou caso o usu�rio informe que o intrumento a ser consultado n�o est� na lista.
				if (Instrumentos.size()==0 || consultainst2==0) {
					
					// Escolha da vari�vel
					cout << "Digite o n�mero correspondente � vari�vel do instrumento." << endl;
		    		
		    		// Mostra todas as possibilidades de vari�veis e seu n�mero correspondente.
				    for (int i=0; i<21; i++) {
		 			   	cout << referenciavariavelinst[i] << " - " << variavel[i] << endl;
		 			}
					cout << endl;
					
					// Entrada do usu�rio e fun��o para convers�o da entrada do usu�ario de string para inteiro, caso a entrada seja um n�mero.
					consultainst = entrada();
			    	consultainst2 = converterconsultaparainteiro(consultainst);
			    	
			    	// Procura do n�mero inserido pelo usu�rio no vetor numerado de 1 at� 21 (quantidade de vari�veis poss�veis), para ver se o n�mero � v�lido.
			    	posconsultainst = buscabinariaint (consultainst2, referenciavariavelinst, 21);
			
					/* Caso o n�mero n�o esteja entre as possibilidades do vetor, ser� solicitado que o usu�rio entre novamente com outro n�mero e o 
					processo se repetir� at� que o usu�rio digite um n�mero v�lido. */
					while (posconsultainst==-1) {
						cout << "A entrada digitada n�o � v�lida. Tente novamente." << endl;
						consultainst = entrada();	
						consultainst2 = converterconsultaparainteiro(consultainst);
			    		posconsultainst = buscabinariaint (consultainst2, referenciavariavelinst, 21);
					}	
					
					// Caso a entrada seja um n�mero v�lido, a sa�da receber� a letra correspondente � vari�vel escolhida pelo usu�rio.	
					if (posconsultainst!=-1) {
						saidaconsultainst = referenciavariavel[posconsultainst];
					}
		
					// Escolha da segunda letra (modificadora), no caso diferencial.
					cout << "A vari�vel � diferencial?" << endl;
		    		cout << "1 - Sim" << endl;
		    		cout << "2 - N�o" << endl;
					cout << endl;
					
					consultainst = entrada();
			    	
					/* Caso a entrada n�o esteja entre as possibilidades dadas, ser� solicitado que o usu�rio forne�a novamente uma entrada e o 
					processo se repetir� at� que o usu�rio digite uma entrada v�lida. */
					while (consultainst!="1" && consultainst!="2") {
						cout << "A entrada digitada n�o � v�lida. Tente novamente." << endl;
						consultainst = entrada();
					}	
					
					// Caso a entrada seja 1, a sa�da receber� a letra correspondente � caracter�stica escolhida pelo usu�rio (diferencial).
					if (consultainst=="1") {
						saidaconsultainst = saidaconsultainst + "D";
						
					// Caso a entrada seja 0, escolha entre as possibilidades da segunda letra (modificadora), se for o caso.
					} else {
						
						cout << "O instrumento � de: " << endl;
			    		cout << "1 - Raz�o (fra��o) da vari�vel?" << endl;
		    			cout << "2 - Varredura da vari�vel?" << endl;
		    			cout << "3 - Integra��o da vari�vel?" << endl;
						cout << "0 - Nenhuma das op��es." << endl;
						cout << endl;
						
						consultainst = entrada();
			    	
						/* Caso a entrada n�o esteja entre as possibilidades dadas, ser� solicitado que o usu�rio forne�a novamente uma entrada e o 
						processo se repetir� at� que o usu�rio digite uma entrada v�lida. */
						while (consultainst!="1" && consultainst!="2" && consultainst!="3" && consultainst!="0") {
							cout << "A entrada digitada n�o � v�lida. Tente novamente." << endl;
							consultainst = entrada();
						}	
					
						// Caso a entrada seja v�lida, a sa�da receber� a letra correspondente � caracter�stica escolhida pelo usu�rio.
						if (consultainst=="1") {
							saidaconsultainst = saidaconsultainst + "F";
						} else if (consultainst=="2") {
							saidaconsultainst = saidaconsultainst + "J";
						} else if (consultainst=="3") {
							saidaconsultainst = saidaconsultainst + "Q";
						}
					}			
					
					// Escolha da(s) fun��o(�es) do instrumento.
					cout << "Digite o n�mero correspondente �(s) fun��o(�es) do instrumento." << endl;
		    		
		    		// Mostra todas as possibilidades de fun��es do instrumento e seu n�mero correspondente.
				    for (int i=0; i<33; i++) {
		 			   	cout << referenciafuncaoinst[i] << " - " << funcaoinstrumento[i] << endl;
		 			}
					cout << endl;
					
					// Entrada do usu�rio e fun��o para convers�o da entrada do usu�ario de string para inteiro, caso a entrada seja um n�mero
					consultainst = entrada();
					consultainst2 = converterconsultaparainteiro(consultainst);
					
					/* Procura do n�mero inserido pelo usu�rio no vetor numerado de 1 at� 33 (quantidade de fun��es do instrumento poss�veis), para ver se o 
					n�mero � v�lido. */
			    	posconsultainst = buscabinariaint (consultainst2, referenciafuncaoinst, 33);
			    	
					/* Caso o n�mero n�o esteja entre as possibilidades do vetor, ser� solicitado que o usu�rio entre novamente com outro n�mero e o 
					processo se repetir� at� que o usu�rio digite um n�mero v�lido. */
					while (posconsultainst==-1) {
						cout << "A entrada digitada n�o � v�lida. Tente novamente." << endl;
						consultainst = entrada();
						consultainst2 = converterconsultaparainteiro(consultainst);
						posconsultainst = buscabinariaint (consultainst2, referenciafuncaoinst, 33);
						
					}	
					
					// Caso a entrada seja um n�mero v�lido, a sa�da receber� a letra correspondente �(s) fun��o(�es) do instrumento escolhida(s) pelo usu�rio.	
					if (posconsultainst!=-1) {
						
						/* Caso o usu�rio selecione anteriormente a op��o "varredura" e escolha a fun��o do instrumento como chave ou como rel�, ser� 
						mostrado que o instrumento � inv�lido e o programa retornar� para o in�cio da fun��o 2, pois a letra "J" pode significar "varredura"
						ou "seletor", por�m no caso de chave ou rel�, a letra "J" obrigatoriamente deve significar "seletor", impossibilitanto a exist�ncia
						de um "rel� de varredura" ou "chave de varredura". */	
						if ((posconsultainst==19 || posconsultainst==31) && (saidaconsultainst[saidaconsultainst.size()-1]=='J')) {
							cout << "Instrumento inv�lido. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
							retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
							continue;
						}
						
						saidaconsultainst = saidaconsultainst + referenciafuncao[posconsultainst];
					}
					
					
					// Escolha das �ltimas letras (modificadora), se for o caso.
					cout << "O instrumento � relativo � vari�vel em n�vel: " << endl;
			    	cout << "1 - Muito alto?" << endl;
		    		cout << "2 - Alto?" << endl;
		    		cout << "3 - Intermedi�rio?" << endl;
		    		cout << "4 - Baixo?" << endl;
		    		cout << "5 - Muito baixo?" << endl;
					cout << "0 - Nenhuma das op��es." << endl;
					cout << endl;
					
					consultainst=entrada();
			    	
					/* Caso a entrada n�o esteja entre as possibilidades dadas, ser� solicitado que o usu�rio forne�a novamente uma entrada e o 
					processo se repetir� at� que o usu�rio digite uma entrada v�lida. */
					while (consultainst!="1" && consultainst!="2" && consultainst!="3" && consultainst!="4" && consultainst!="5" && consultainst!="0") {
						cout << "A entrada digitada n�o � v�lida. Tente novamente." << endl;
						consultainst = entrada();
					}	
					
					// Caso a entrada seja v�lida, a sa�da receber� a(s) letra(s) correspondente(s) � caracter�stica escolhida pelo usu�rio.
					if (consultainst=="1") {
						saidaconsultainst = saidaconsultainst + "HH";
					} else if (consultainst=="2") {
						saidaconsultainst = saidaconsultainst + "H";
					} else if (consultainst=="3") {
						saidaconsultainst = saidaconsultainst + "M";
					} else if (consultainst=="4") {
						saidaconsultainst = saidaconsultainst + "L";
					} else if (consultainst=="5") {
						saidaconsultainst = saidaconsultainst + "LL";
					}
					
					// Ao fim do processo, sa�da da TAG correspondente ao instrumento escolhido pelo usu�rio.
					cout << saidaconsultainst << endl;
					cout << endl;
						
				}
		        
				/* Caso o usu�rio deseje repetir a fun��o 2, ele deve digitar 1 e voltar� para o �nicio do while. Caso deseje voltar ao menu principal,
				ele deve digitar 0. */
				cout << "Para voltar ao menu principal, digite 0. Para consultar outro instrumento TAG, digite 1." << endl;
				retorno = entrada();
					
			}
			
			// Fun��o de c�dgo de erro caso o usu�rio n�o digite 1 nem 0. 
			codigodeerro(retorno);	
			       
    	} else if (funcao=="3") { /* Listar TAGs cadastradas: Quando esse comando � chamado pelo usu�rio, s�o listadas as TAGs ordenadas em ordem alfab�tica e os instrumentos 
		armazenados anteriormente pelo usu�rio. */

			if(Tags.size()==0){ /* Caso n�o exista nenhuma TAG/Instrumento cadastrado pelo usu�rio, retorna-se "NENHUMA TAG CADASTRADA". A verifica��o da exist�ncia de uma 
			TAG/Instrumento se d� pela an�lise do tamanho da string em que elas est�o armazenadas. Caso esse tamanho seja 0, n�o existe TAG/Instrumento cadastrado. */
					
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
				cout << "NENHUMA TAG CADASTRADA" << endl;
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
			
			}else{ /* Caso exista alguma TAG/Instrumento cadastrado pelo usuario, o programa lista as TAGs em ordem alfab�tica seguidas de seus respectivos instrumentos. A
			verifica��o da exist�ncia de uma TAG/Instrumento se d� pela an�lise do tamanho da string em que elas est�o armazenadas. Caso esse tamanho seja maior que zero, existe pelo menos
			uma TAG/Instrumento cadastrado. */
			
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
				cout << "TAGS EM ORDEM ALFAB�TICA:" << endl;
				
				for(int i=0; i<Tags.size(); i++) // Loop para listagem das strings Tags e InstrumentosCopy.
				cout << Tags[i] << " | " << InstrumentosCopy[i] << endl;
		
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
								
			}	
			
			// Para voltar ao menu principal, o usu�rio deve digitar 0.	
			cout << "Para voltar ao menu principal, digite 0." << endl;
			retorno = entrada();
			
			// Fun��o de c�dgo de erro caso o usu�rio n�o digite 0.
			codigodeerro(retorno);
                
        } else if (funcao=="4") { /* Listar instrumentos cadastradas: Quando esse comando � chamado pelo usu�rio, retornam-se os instrumentos ordenados em ordem alfab�tica precedidos 
		de suas respectivas TAGs armazenados anteriormente pelo usu�rio. Esse comando segue a mesma l�gica do comando 3, porem ao contr�rio dele, os instrumentos s�o a prioridade na 
		ordena��o da lista. */

			if(Tags.size()==0){ 
					
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
				cout << "NENHUM INSTRUMENTO CADASTRADO" << endl;
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
						
			}else{ 

				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
				cout << "INSTRUMENTOS EM ORDEM ALFAB�TICA:" << endl;
					
				for(int i=0; i<Tags.size(); i++) // Loop para listagem das strings TagsCopy e Instrumentos.
				cout << TagsCopy[i] << " | " << Instrumentos[i] << endl;
				
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
	
			}
			
			// Para voltar ao menu principal, o usu�rio deve digitar 0.	
			cout << "Para voltar ao menu principal, digite 0." << endl;
			retorno = entrada();
			
			// Fun��o de c�dgo de erro caso o usu�rio n�o digite 0.	
			codigodeerro(retorno);
                
				                
        } else if (funcao=="5") { // Cadastrar nova TAG/instrumento.
					
			retorno="1";
			while (retorno=="1") { // Loop para caso o usu�rio deseje voltar � func�o 5
					
				/*	A fun��o de cadastrar uma TAG/Instrumento consiste no armazenamento dos dados de entrada do usuario numa string. Primeiramente, utilizamos uma string auxiliar(auxtags e auxinstrumentos) 
				para capturar as entradas dadas, depois manipulamos essas strings, de modo a tornar todas as letras em maiusculas atrav�s da fun��o "maiusculas", com o intuito de padronizar as TAGs e os Instrumentos
 				e facilitar na busca e organiza��o dos mesmos. Ap�s a transforma��o, aplicamos uma busca bin�ria atrav�s da fun��o "buscabinariavector" para analisar a exist�ncia pr�via de uma TAG/Instrumento ja 
				cadastrados anteriormente. Por �ltimo armazena-se as strings auxiliares num vetor de strings de tamanho indefinido, que incrementa seu tamanho a cada armazenamento de uma nova TAG/Instrumento, 
				ou seja, a cada itera��o dessas strings(Tags e Instrumentos). */

				// Armazenamento da TAG e c�pia:

				cout << "Digite a TAG do instrumento." << endl;
				auxtags = entrada(); // Utiliza��o da fun��o "entrada" para capturar a TAG que o usu�rio deseja cadastrar.
				auxtags = maiusculas (auxtags, auxtags.size()); // Utiliza��o da fun��o "maiusculas" para convers�o de todas as letras da string "auxtags" em maiusculas.
				posTagCad = buscabinariavector(auxtags, Tags, Tags.size()); /* Utiliza��o da fun��o "buscabinariavector" para encontrar a posi��o da string "auxtags" no vetor "Tags", com o intuito de
				constatar a exist�ncia de uma TAG j� cadastrada pelo usu�rio. */

	            size_t posEsp2 = auxtags.find(32); // Busca por "espa�os" dentro da string "auxtags" e armazena como inteiro em "posEsp2". 
	            					
				if (posEsp2 != string::npos) { // Caso exista "espa�o" em alguma posi��o da string, � considerado que existe um erro. J� que o padr�o para escrita das TAGs n�o � seguido.
					cout << "Tag inv�lida. Verifique a exist�ncia de espa�os em sua TAG. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
					retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
					continue; // Continua para a pr�xima itera��o do loop.

				}else{ // Caso n�o exista "espa�o" em alguma posi��o da string, segue-se para os pr�ximos procedimentos para o cadastramento da Tag/Instrumento. 

					if (posTagCad!=-1){ /* Caso a posi��o concedida pela busca bin�ria seja diferente de -1, significa que a TAG j� existe na string de vetores "Tags", o programa sugere o retorno para 
					interface ou uma nova tentativa para cadastrar uma TAG. */
								
						cout << "Tag j� cadastrada. Para voltar ao menu principal, digite 0. Para tentar novamente, digite 1." << endl;
						retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
						continue; 
						
					}else{ /* Caso a posi��o concedida pela busca bin�ria seja igual a -1, significa que a TAG n�o existe na string de vetores "Tags", ent�o elas s�o armazenadas nos vetores "Tags" e "TagsCopy".
					O vetor TagsCopy � utilizado como suporte para a listagem dos Instrumentos em ordem alfab�ticas, como ser� visto posteriormente. */			 
								
						Tags.push_back(auxtags); // Utiliza��o da fun��o .push_back da biblioteca vector para expandir o tamanho do vetor "Tags" din�micamente a cada itera��o, ou armazenamento de "auxtags".
						TagsCopy.push_back(auxtags); // Tamb�m � utilizada a fun��o acima para "TagsCopy".
					}						
						
					//Armazenamento dos Instrumentos e c�pia:
					
					cout << "Digite o NOME do instrumento." << endl;
					auxinstrumentos = entrada(); // Utiliza��o da fun��o "entrada" para capturar o instrumento que o usu�rio deseja associar a TAG escolhida no passo anterior.
					auxinstrumentos = maiusculas (auxinstrumentos, auxinstrumentos.size()); // Utiliza��o da fun��o "maiusculas" para convers�o de todas as letras da string "auxinstumentos" em maiusculas.
					posInstrumentoCad = buscabinariavector(auxinstrumentos, InstrumentosCopy, InstrumentosCopy.size()); /* Utiliza��o da fun��o "buscabinariavector" para encontrar a posi��o da string "auxinstrumentos" no 
					vetor "Intstrumentos", com o intuito de constatar a exist�ncia de um instrumento j� cadastrado pelo usu�rio. */
	
					if(posInstrumentoCad!=-1){ /* Similar ao cadastro de TAGs, caso o instrumento exista no vetor de string "Instrumentos", o programa sugere o retorno para interfaze ou uma nova tentativa
					para cadastrar uma nova TAG e Instrumento, reiniciando o processo. Nessa fase tamb�m � exclu�da a TAG armazenada no vetor "Tags" no processo anterior. */
										
						cout << "Instrumento j� cadastrado. Para voltar ao menu principal, digite 0. Para tentar novamente, digite 1." << endl;
						Tags.erase(std::remove(Tags.begin(),Tags.end(),auxtags),Tags.end()); // Fun��o da biblioteca Algorithms utilizada para remover uma string espec�fica de um vetor de strings.
						TagsCopy.erase(std::remove(TagsCopy.begin(),TagsCopy.end(),auxtags),TagsCopy.end()); // Tamb�m � utilizada a fun��o acima para o "TagsCopy".
						retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
						continue; 
	
					}else{
								
						Instrumentos.push_back(auxinstrumentos); // Similar ao "Tags.push_back(auxtags)" e "TagsCopy.pus_back(auxtags)".
						InstrumentosCopy.push_back(auxinstrumentos); 
						
						cout << "TAG e instrumento cadastrados com sucesso. ";  
								
					}	
	
					/* ORDENA��O DAS TAGS E INSTRUMENTOS:	Nessa �tapa, foi utilizado o met�do de ordena��o aprendido nas aulas. Para ordenar os Instrumentos em ordem alfab�tica, utilizou-se uma 
					c�pia das TAGs("TagsCopy") cadastradas pelo usu�rio, que seguia o processo de ordena��o dos instrumentos(Instrumentos). J� no processo para ordenar as TAGs("Tags") em ordem alfabetica, 
					utilizou-se uma c�pia dos instrumentos("InstrumentosCopy") cadastrados pelo usuario, que seguia o processo de ordena��o das TAGs. */

						
					//Ordenacao em ordem alfabetica para os Instrumentos; 
					for(int i=0;i<Instrumentos.size();i++){
						for(int j=i+1; j<Instrumentos.size(); j++){
							if(Instrumentos[i]>Instrumentos[j]){
								ordenacaoinstrumentos = Instrumentos[j];
								Instrumentos[j]=Instrumentos[i];
								Instrumentos[i]=ordenacaoinstrumentos;
		
								ordenacaotagscopy = TagsCopy[j];
								TagsCopy[j]=TagsCopy[i];
								TagsCopy[i]=ordenacaotagscopy;
							}
						}
					}
	
					//Ordenacao em ordem alfabetica para as TAGs;
					for(int i=0;i<Tags.size();i++) {
						for(int j=i+1; j<Tags.size(); j++){
							if(Tags[i]>Tags[j]){
								ordenacaoinstrumentoscopy = InstrumentosCopy[j];
								InstrumentosCopy[j]=InstrumentosCopy[i];
								InstrumentosCopy[i]=ordenacaoinstrumentoscopy;
		
								ordenacaotags = Tags[j];
								Tags[j]=Tags[i];
								Tags[i]=ordenacaotags;
							}
						}
					}
				}

				/* Caso o usu�rio deseje repetir a fun��o 5, ele deve digitar 1 e voltar� para o �nicio do while. Caso deseje voltar ao menu principal,
				ele deve digitar 0. */	
				cout << "Para retornar ao menu principal, digite 0. Para cadastrar outro instrumento, digite 1." << endl;
				retorno = entrada();
			}
			
			// Fun��o de c�dgo de erro caso o usu�rio n�o digite 1 nem 0 	
			codigodeerro(retorno);
               

		} else if (funcao=="6") { // Descadastrar novo TAG/instrumento
			    
			retorno="1";
			while (retorno=="1") { // Loop para caso o usu�rio deseje voltar � func�o 6
					
				cout << "Digite a TAG do instrumento que deseja descadastrar." << endl;
				descadastramentoTag = entrada(); // Utiliza��o da fun��o "entrada" para captura da TAG que o usu�rio deseja descadastrar.
				descadastramentoTag = maiusculas (descadastramentoTag, descadastramentoTag.size()); // Utiliza��o da fun��o "maiusculas" para convers�o de todas as letras da string "descadastramentoTag" em maiusculas.
				posTag = buscabinariavector(descadastramentoTag, Tags, Tags.size());
				size_t posEsp2 = descadastramentoTag.find(32); /* Utiliza��o da fun��o "buscabinariavector" para encontrar a posi��o da string "descadastramentoTag" no vetor "Tags", com o intuito de constatar 
				a exist�ncia da TAG j� cadastrada pelo usu�rio. */
			
					if(posEsp2 != string::npos){ // Caso exista "espa�o" em alguma posi��o da string, � considerado que existe um erro. J� que o padr�o para escrita das TAGs n�o � seguido.
						cout << "Tag inv�lida. Verifique a exist�ncia de espa�os em sua TAG. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
						retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
						continue;

					}else{ // Caso n�o exista "espa�o" em alguma posi��o da string, segue-se para os pr�ximos procedimentos para o descadastramento da Tag/Instrumento.
												
						cout << "Digite o NOME do instrumento que deseja descadastrar para confirmar." << endl;
						descadastramentoInstrumentos = entrada(); // Utiliza��o da fun��o "entrada" para capturar o instrumento que o usu�rio deseja associar a TAG escolhida no passo anterior.
						descadastramentoInstrumentos = maiusculas (descadastramentoInstrumentos, descadastramentoInstrumentos.size()); /* Utiliza��o da fun��o "maiusculas" para convers�o de todas as letras da string 
						"descadastramentoInstrumentos" em maiusculas. */
						posInstrumento= buscabinariavector(descadastramentoInstrumentos, InstrumentosCopy, InstrumentosCopy.size()); /* Utiliza��o da fun��o "buscabinariavector" para encontrar a posi��o da string "descadastramentoInstrumentos" no 
						vetor "IntstrumentosCopy", com o intuito de constatar a exist�ncia de um instrumento j� cadastrado pelo usu�rio. Foi utilizada a string "InstrumentosCopy", porque essa string est� associada diretamente a string "Tags". */
						
						if(posInstrumento!=-1 && posTag!=-1 && posInstrumento==posTag){ /* Caso exista o instrumento e a tag nos vetores de strings, e a posi��o do instrumento no vetor "InstrumentosCopy" seja comp�tivel com a posi��o da Tag no vetor "Tags
						Ambas ser�o removidas dos seus respectivos vetores, tamb�m nos seus vetores paralelos. */
							
							Tags.erase(std::remove(Tags.begin(),Tags.end(),descadastramentoTag),Tags.end());
							TagsCopy.erase(std::remove(TagsCopy.begin(),TagsCopy.end(),descadastramentoTag),TagsCopy.end());
							
							Instrumentos.erase(std::remove(Instrumentos.begin(),Instrumentos.end(),descadastramentoInstrumentos),Instrumentos.end());
							InstrumentosCopy.erase(std::remove(InstrumentosCopy.begin(),InstrumentosCopy.end(),descadastramentoInstrumentos),InstrumentosCopy.end());
								
							cout << "TAG e instrumento descadastrados com sucesso. ";
							
								
						}else if(posTag==-1 && posInstrumento!=-1){ // Caso o instrumento n�o exista no vetor de armazenamento da Instrumentos do usu�rio, a opera��o � considerada inv�lida. (Tags, Instrumentos, TagsCopy e InstrumentosCopy).
		
					 		cout << "Opera��o Inv�lida. Tag n�o cadastrada. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
					 		retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
					 		continue;
						
						}else if(posTag!=-1 && posInstrumento==-1){ // Caso a TAG n�o exista no vetor de armazenamento das TAGs do usu�rio, a opera��o � considerada inv�lida. (Tags e TagsCopy).
		
					 		cout << "Opera��o Inv�lida. Instrumento n�o cadastrado. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
					 		retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
					 		continue;
						
						}else if(posTag==-1 && posInstrumento==-1){ // Caso o instrumento e a tag n�o existam nos vetores de armazenamento da Instrumentos/TAGs do usu�rio, a opera��o � considerada inv�lida. (Instrumentos e InstrumentosCopy).
		
					 		cout << "Opera��o Inv�lida. Tag e Instrumento n�o cadastradados. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
					 		retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
					 		continue;
						
						}else{ // Caso a instrumento e a TAG existam, mas as suas posi��es nos vetores de armazenamento paralelos n�o sejam compat�veis, a opera��o � considerada inv�lida. POSI��O(Tags!=InstrumentosCopy e Instrumentos !=TagsCop�)
			
							cout << "Opera��o Invalida. Tag incomp�tivel com Instrumento. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
							retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
					 		continue;
		
						}
					}	
				
				/* Caso o usu�rio deseje repetir a fun��o 6, ele deve digitar 1 e voltar� para o �nicio do while. Caso deseje voltar ao menu principal,
				ele deve digitar 0. */	
				cout << "Para voltar ao menu principal, digite 0. Para descadastrar outro instrumento, digite 1." << endl;
				retorno = entrada(); // Utiliza��o da fun��o entrada para capturar a escolha do usu�rio.
			
			}

			// Fun��o de c�dgo de erro caso o usu�rio n�o digite 1 nem 0 	
			codigodeerro(retorno);
			
			
        } else { // C�digo de erro caso o usu�rio tente acessar uma fun��o inv�lida
            cout << "O comando digitado n�o correspondente a nenhuma fun��o v�lida. Tente novamente." << endl;        
			cout << endl;
		}
		
	}
   				    
    return 0;
}
