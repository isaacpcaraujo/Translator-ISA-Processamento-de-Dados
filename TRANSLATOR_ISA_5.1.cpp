// INCLUSÃO DAS BIBLIOTECAS
#include <iostream> // Biblioteca padrão, utilizada para habilitar as entradas e saídas do programa.
#include <string> // Biblioteca utilizada para fazer manipulação em strings.
#include <cctype> // Biblioteca utilizada para fazer manipulação em caracteres, como converter em maiúsculas ou verificar se é um número.
#include <vector> // Biblioteca utilizada para fazer manipulação dos vetores, alterando seu tamanho.
#include <algorithm> // Biblioteca utilizada para remoção de um elemento de um vetor específico.
#include <locale.h> // Biblioteca utilizada para incluir caracteres não existentes no texto padrão do programa, como acentos, por exemplo.
 
 
using namespace std;

/* FUNÇÃO PARA CONVERTER EM MAIÚSCULAS: Essa função percorre a string, caractere por caractere, convertendo cada um deles em letras maiúsculas, através do 
comando toupper. */
string maiusculas (string entrada, int tamanhoentrada) {
    for(int i=0; i<tamanhoentrada; i++) {
    	entrada[i]=toupper(entrada[i]);
	}
	return entrada;
}

/* FUNÇÃO PARA BUSCA BINÁRIA TIPO VETOR DE CHAR: Essa função utiliza a busca binária para localizar um caractere específico pré-determinado em um vetor de 
caracteres. Para isso, o vetor de caracteres deve estar ordenado. Então, são realizadas sucessivas divisões do espaço de busca, comparando o elemento 
buscado com o elemento do meio do vetor. Se o elemento do meio do vetor for o elemento buscado, a busca termina com sucesso. Caso contrário, se o elemento 
buscado vier antes do elemento do meio, então a busca continua na metade da esqueda do vetor. E finalmente, se o elemento buscado vier depois do elemento do
meio do vetor, a busca continua na metade da direita do vetor. E assim sucessivamente. Ao final da busca, a função retorna a posição em que o elemento foi
encontrado, ou retorna -1 caso o elemento não seja encontrado. */
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

/* FUNÇÃO PARA BUSCA BINÁRIA TIPO VETOR DE INT: Essa função utiliza a busca binária, através da mesma lógica descrita na função anterior, porém para 
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


/* FUNÇÃO PARA BUSCA BINÁRIA TIPO VECTOR DE STRINGS: Essa função utiliza a busca binária, através da mesma lógica descrita na função anterior, porém para 
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

/* FUNÇÃO PARA EXIBIR CÓDIGO DE ERRO CASO O USUÁRIO FORNEÇA UMA ENTRADA ERRADA: Essa função é utilizada para quando é perguntado se o usuário deseja voltar
ao menu principal. Caso o usuário digite 1, o programa irá repetir a ação feita anteriormente por ele (isso está dentro do while de cada ação do usuário no
int main). Caso o usuário digite 0, o programa irá voltar ao menu principal. Caso ele digite algo diferente de 0, aparecerá a seguinte mensagem de erro, que
irá se repetir, até que o usuário aperte 0 para voltar oa menu principal. */
void codigodeerro (string retorno2) {
	while (retorno2!="0") {
		cout << "Comando inválido. Para voltar ao menu principal, digite 0." << endl;
		cout << ">> ";
		getline(cin,retorno2);
		cout << endl;
	}
}

/* FUNÇÃO PARA VERIFICAR SE A ENTRADA (STRING) É UM NÚMERO E CONVERTÊ-LA EM UM INT: Essa função percorre a string, caractere por caractere, verificando se 
cada um deles é um número. Se todos os caracteres forem números, a variável edigito continuará com valor 0. Caso algum deles não seja número, edigito 
assumirá um valor diferente de 0 e será solicitado que o usuário forneça uma nova entrada até que ela seja um número (e edigito seja igual a 0). Quando 
isso ocorrer, a string que contém apenas números será armazenada em um vetor de char, e por fim, o comando atoi será utilizada para converter esse vetor 
de char em um int. */
int converterconsultaparainteiro (string consulta) {
	int edigito=0;
	for (int i=0; i<consulta.size(); i++) {
		if (isdigit(consulta[i]) == 0) {
			edigito = edigito + 1;
		}
	}

	while (edigito != 0) {
		cout << "A entrada digitada não é válida. Tente novamente." << endl;
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

/* FUNÇÃO PARA CAPTURA DE STRINGS: Essa função é utilizada para promover a interação do usuário com o programa, nela o usuário digita uma string que é armazenada e 
manipulada pelo restante do programa. */
string entrada(){
	
	string saida;
	cout << ">> ";
	getline(cin,saida);
	cout << endl;

return saida;
}


int main() {
	
	setlocale(LC_ALL,"portuguese"); // Função da biblioteca locale.h para implementação de novas caracteres na programação.

	// Declaração de variáveis 
	vector<string> Tags,TagsCopy,Instrumentos,InstrumentosCopy;
	string funcao, consultaTAG, saidaconsultaTAG, variavelanalisada, retorno, consultainst, saidaconsultainst, auxtags, auxinstrumentos;
	string ordenacaotags, ordenacaotagscopy, ordenacaoinstrumentos, ordenacaoinstrumentoscopy, descadastramentoTag, descadastramentoInstrumentos;
	int posTag, posInstrumento, posTagCad, posInstrumentoCad, escolher, posconsultaTAG, posconsultainst, consultainst2; 
    char referenciavariavel[21] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L', 'M', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Z'};
	string variavel[21] = {"ANÁLISE", "CHAMA DE QUEIMADOR", "CONDUTIVIDADE ELÉTRICA", "DENSIDADE OU MASSA ESPECÍFICA", "TENSÃO ELÉTRICA", "VAZÃO", "MEDIDA DIMENSIONAL", "COMANDO MANUAL", "CORRENTE ELÉTRICA", "POTÊNCIA", "NÍVEL", "UMIDADE", "PRESSÃO", "QUANTIDADE", "RADIOATIVIDADE", "VELOCIDADE OU FREQUÊNCIA", "TEMPERATURA", "MULTIVARIÁVEIS", "VISCOSIDADE", "PESO OU FORÇA", "POSIÇÃO"};
	string referenciafuncao[33] = {"A", "C", "CV", "E", "G", "I", "IC", "IR", "IRC", "IRT", "IT", "JS", "JY", "L", "O", "P", "R", "RC", "RT", "S", "SA", "SE", "SS", "SU", "SV", "SY", "SZ", "T", "U", "V", "W", "Y", "Z"};	
	string funcaoinstrumento[33] = {"ALARME", "CONTROLADOR", "VÁLVULA DE CONTROLE", "ELEMENTO PRIMÁRIO", "VISOR", "INDICADOR", "CONTROLADOR INDICADOR", "REGISTRADOR INDICADOR", "CONTROLADOR REGISTRADOR INDICADOR", "TRANSMISSOR REGISTRADOR INDICADOR", "TRANSMISSOR INDICADOR", "CHAVE SELETORA", "RELÉ SELETOR", "LÂMPADA PILOTO", "ORIFÍCIO DE RESTRIÇÃO", "PONTO DE TESTE", "REGISTRADOR", "CONTROLADOR REGISTRADOR", "TRANSMISSOR REGISTRADOR", "CHAVE", "ALARME DE SEGURANÇA", "ELEMENTO PRIMÁRIO DE SEGURANÇA", "CHAVE DE SEGURANÇA", "INSTRUMENTO MULTIFUNÇÃO DE SEGURANÇA", "VÁLVULA DE SEGURANÇA", "RELÉ DE SEGURANÇA", "ELEMENTO FINAL DE CONTROLE CLASSIFICADO DE SEGURANÇA", "TRANSMISSOR", "INSTRUMENTO MULTIFUNÇÃO", "VÁLVULA", "POÇO", "RELÉ", "ELEMENTO FINAL DE CONTROLE CLASSIFICADO"};
	// Criação de um vetor numerado de 1 a 21
	int referenciavariavelinst[21];
	for (int i=0; i<21; i++) {
		referenciavariavelinst[i]=i+1;
	}
	
	// Criação de um vetor numerado de 1 a 33
	int referenciafuncaoinst[33];
	for (int i=0; i<33; i++) {
		referenciafuncaoinst[i]=i+1;
	}	
	
	// Mensagem inicial do programa
    cout << "Seja bem-vindo ao TRANSLATOR ISA 5.1. O TRANSLATOR  ISA 5.1 é um software cuja finalidade principal é converter TAG's definidas pela norma ISA 5.1 nos nomes dos instrumentos correspondentes e vice-versa. As TAG's mais usuais que a norma ISA 5.1 abrange já estão cadastradas no sistema. Além disso, caso deseje, também é possível cadastrar novas TAG's e associá-las a instrumentos, de acordo com sua necessidade." << endl;
    cout << "ATENÇÃO: Ao fechar o programa, todas as informações cadastradas, inclusive os TAG's personalizados, serão perdidas." << endl;
    cout << endl;
	
	// Criação de um loop infinito
    for (int forever=0; forever==0; forever=0) {
    	
    	// Menu principal
		cout << "_____________________________________________________________________________________________________________" << endl;
		cout << endl;    
        cout << "Digite o número correspondente à função que deseja acessar:" << endl;
        cout << "1 - Converter uma TAG em um nome de instrumento." << endl;
        cout << "2 - Converter o nome de um instrumento em uma TAG." << endl;
        cout << "3 - Listar todas as TAG's cadastradas pelo usuário." << endl;
        cout << "4 - Listar todos os instrumentos cadastrados pelo usuário com uma TAG personalizada." << endl;
        cout << "5 - Cadastrar uma nova TAG e associá-la a um instrumento." << endl;
        cout << "6 - Descadastrar um TAG/instrumento cadastrado pelo usuário." << endl;
		cout << "_____________________________________________________________________________________________________________" << endl;
		cout << endl;
		funcao = entrada();
        
        if (funcao=="1") { // Consultar instrumento a partir da TAG.
                
        	retorno="1";
			while (retorno=="1") { // Loop para caso o usuário deseje voltar à funcão 1.
 	            
				// Inserção pelo usuário da TAG a ser consultada.
				cout << "Digite a TAG que deseja consultar." << endl;
    	    	consultaTAG = entrada();
        	    
        	    // Conversão da TAG para letras maiúsculas.
				consultaTAG = maiusculas(consultaTAG, consultaTAG.size());
                
				// Procura por espaços na TAG.	
	            size_t posEsp1 = consultaTAG.find(32);
					
				// Caso haja espaços na TAG, voltar para o começo da função 1.
				if (posEsp1 != string::npos) {
					cout << "Tag inválida. Verifique a existência de espaços em sua TAG. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
					retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
					continue;
				
				// Caso não haja espaços na TAG.
				} else {
    	                
					// Procura da TAG no vector de TAG's pré-cadastradas pelo usuário.       
	        	    posconsultaTAG = buscabinariavector (consultaTAG, Tags, Tags.size());
		            	
					// Caso a TAG já tenha sido cadastrada pelo usuário, imprimir o instrumento correspondente.	                
	                if (posconsultaTAG!=-1) {	
						cout << InstrumentosCopy[posconsultaTAG] << endl;
					
					// Caso a TAG não tenha sido cadastrada pelo usuário.		
					} else {    				
		    				
						// Busca da primeira letra da TAG no vetor que tem a letra correspondente a cada variável.									
						posconsultaTAG = buscabinariachar (consultaTAG[0], referenciavariavel, 21);	    
				    
						// Caso a primeira letra da TAG não cosnte no vetor que tem as letras de referência, voltar para o começo da função 1.
						if (posconsultaTAG == -1) {
							cout << "A TAG digitada não está cadastrada no sistema. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
							retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
							continue;
						
						// Caso a primeira letra da TAG cosnte no vector que tem as letras de referência.
						} else {
							
							/* Caso a primeira letra da TAG corresponda à variável análise, deve-se perguntar ao usuário qual a variável que está sendo 
							analisada (por exemplo, CO2, O2 etc.), pois essa variável não deve constar na TAG, mas consta no nome do instrumento que 
							será impresso. */
							if (posconsultaTAG == 0) {
								consultaTAG = consultaTAG.substr(1,consultaTAG.size()-1); // A primeira letra da TAG é removida, pois já foi associada a uma variável.
								cout << "Qual a variável analisada?" << endl;
								variavelanalisada = entrada(); // Inserção pelo usuário da variável analisada.
								variavelanalisada = maiusculas(variavelanalisada, variavelanalisada.size()); // Conversão da variável analisada para letras maiúsculas.
								saidaconsultaTAG = variavel[posconsultaTAG] + " DE " + variavelanalisada; // A saída fica da forma "análise de [variavelanalisada]".
							
							/* Caso a primeira letra da TAG não seja análise, a primeira letra da TAG é removida, pois já foi associada a uma variável, e a saída 
							recebe a informação sobre a variável do instrumento. */
							} else {
								consultaTAG = consultaTAG.substr(1,consultaTAG.size()-1);
								saidaconsultaTAG = variavel[posconsultaTAG];
							}
						}
			
						/* Caso a variável tenha apenas duas letras (sendo que uma já foi removida), e a segunda letra seja D, F, J ou Q (que são letras 
						utilizadas apenas como modificadoras da variável), a TAG é inválida, pois o instrumento não possui nenhuma função de fato, e a 
						TAG representaria apenas uma variável e uma letra modificadora, como, por exemplo "pressão diferencial". Então, o programa deve 
						dizer que a TAG não está cadastrada e voltar para o começo da função 1. */
						if ((consultaTAG.size()==1) && (consultaTAG[0]=='D' || consultaTAG[0]=='F' || consultaTAG[0]=='J' || consultaTAG[0]=='Q')) {
							cout << "A TAG digitada não está cadastrada no sistema. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
							retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
							continue;
						
						/* Caso contrário, a segunda letra deverá ser analisada, para ver se corresponde a alguma das possíveis letras modificadoras. Caso
						corresponda, a segunda letra da TAG é removida, pois já foi associada a uma característica modificadora da variável, e será incluída
						na saída a informação sobre a característica modificadora. */
						} else {
							if (consultaTAG[0]=='D') {
								consultaTAG = consultaTAG.substr(1,consultaTAG.size()-1);
								saidaconsultaTAG = saidaconsultaTAG + " DIFERENCIAL";
							} else if (consultaTAG[0]=='F') {
								consultaTAG = consultaTAG.substr(1,consultaTAG.size()-1);
								saidaconsultaTAG = "RAZÃO DE " + saidaconsultaTAG;
							} else if (consultaTAG[0]=='J' && consultaTAG[1]!='S' && consultaTAG[1]!='Y') {
								consultaTAG = consultaTAG.substr(1,consultaTAG.size()-1);
								saidaconsultaTAG = "VARREDURA DE " + saidaconsultaTAG;
							} else if (consultaTAG[0]=='Q') {
								consultaTAG = consultaTAG.substr(1,consultaTAG.size()-1);
								saidaconsultaTAG = "INTEGRAÇÃO DE " + saidaconsultaTAG;
							}

						}
			
						/* Análise das demais letras da TAG a fim de encontrar a função do instrumento. Para isso, há um vetor cadastrado previamente
						com todas as combinações de letras possíveis para representar a(s) função(ões) do instrumento (referenciafuncao). Esse vetor 
						será percorrido da última posição até a primeira, e será buscado na TAG inserida pelo usuário cada uma dessas combinações de 
						letras para ver se a TAG possui alguma dessas possibilidades de funções. Caso seja encontrada alguma função, a letra ou as 
						letras correspondentes à(s) função(ões) do instrumento será(ão) removida(s) da TAG, pois já foram associadas às funções, a 
						saída receberá a informação sobre a função do instrumento, e a variável funcaovalida assumirá valor 1. */
						int funcaovalida=0;
						for (int i=32; i>=0; i--) {
							if (consultaTAG.find(referenciafuncao[i]) == 0){
								consultaTAG = consultaTAG.substr(referenciafuncao[i].size(), consultaTAG.size() - referenciafuncao[i].size());
								saidaconsultaTAG = funcaoinstrumento[i] + " DE " + saidaconsultaTAG;
								funcaovalida=1;
								break;
							}
						}
				
						/* Caso no passo anterior não tenha sido encontrada nenhuma das possibilidades de funções na TAG inserida pelo usuário, 
						a variável funcaovalida terá valor 0 e o programa deve voltar ao ínicio da função 1. */
						if (funcaovalida==0) {
							cout << "A TAG digitada não está cadastrada no sistema. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
							retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
							continue;
						}
						
						/* Por fim, será analisado o que restou na variável consultaTAG para verificar se corresponde a alguma das possibilidades
						de letras modificadoras do final da TAG. Se sim, a variável consultaTAG ficará "vazia" e a saída receberá a informação
						sobre as letras modificadoras do final da TAG. */
						if (consultaTAG=="HH") {
							consultaTAG = "";
							saidaconsultaTAG = saidaconsultaTAG + " MUITO ALTO(A)";
						} else if (consultaTAG=="H") {
							consultaTAG = "";
							saidaconsultaTAG = saidaconsultaTAG + " ALTO(A)";
						} else if (consultaTAG=="M") {
							consultaTAG = "";
							saidaconsultaTAG = saidaconsultaTAG + " INTERMEDIÁRIO(A)";
						} else if (consultaTAG=="L") {
							consultaTAG = "";
							saidaconsultaTAG = saidaconsultaTAG + " BAIXO(A)";
						} else if (consultaTAG=="LL") {
							consultaTAG = "";
							saidaconsultaTAG = saidaconsultaTAG + " MUITO BAIXO(A)";
						} 
						
						/* Caso a TAG tenha passado por todos os passos anteriores com sucesso, ao final a variável consultaTAG deve estar "vazia".
						Caso ela não esteja, é porque a TAG possui alguma outra letra que não é válida. Então, o programa deve voltar ao início da
						função 1. */
						if (consultaTAG.size()!=0) {
							cout << "A TAG digitada não está cadastrada no sistema. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
							retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
							continue;
						}
						
						// Ao final do processo, saída do instrumento correspondente à TAG inserida pelo usuário.
						cout << saidaconsultaTAG << endl;
						cout << endl;
							
					}
				}
				
				/* Caso o usuário deseje repetir a função 1, ele deve digitar 1 e voltará para o ínicio do while. Caso deseje voltar ao menu principal,
				ele deve digitar 0. */				
				cout << "Para voltar ao menu principal, digite 0. Para consultar outra TAG, digite 1." << endl;
				retorno = entrada();				
            }
             
			// Função de códgo de erro caso o usuário não digite 1 nem 0.           
   			codigodeerro(retorno);
               
    	} else if (funcao=="2") { // Consultar TAG a partir do instrumento.
			
			retorno="1";
			while (retorno=="1") { // Loop para caso o usuário deseje voltar à funcão 2.
				
				// Caso haja instrumentos cadastrados previamente pelo usuário.
				if (Instrumentos.size()!=0) {
					
					// Criação de um vetor numerado de 1 até a quantidade de instrumentos pré-cadastrados pelo usuário.
					int referencianst[Instrumentos.size()];			
					for (int i=0; i<Instrumentos.size(); i++) {
						referencianst[i]=i+1;
					}
					
					// Usuário escolhe o número correspondente ao instrumento que deseja consultar.
					cout << "Digite o número correspondente ao instrumento que deseja consultar, caso ele esteja nessa lista: " << endl;
					
					// Mostra todos os instrumentos pré-cadastrados e seu número correspondente.
					for (int i=0; i<Instrumentos.size(); i++) {
						cout << referencianst[i] << " - " << Instrumentos[i] << endl;
					}
					
					// Usuário escolhe 0 caso o intrumento a ser consultado não esteja na lista.
					cout << "0 - O intrumento a ser consultado não está nessa lista." << endl;
					cout << endl;
					
					// Entrada do usuário
					consultainst = entrada();
					
					// Função para conversão da entrada do usuáario de string para inteiro, caso a entrada seja um número.					
					consultainst2 = converterconsultaparainteiro(consultainst);
					
					// Caso o usuário NÃO informe que o intrumento a ser consultado não está na lista.
					if (consultainst2!=0) {
						
						/* Procura do número inserido pelo usuário no vetor numerado de 1 até a quantidade de instrumentos pré-cadastrados pelo usuário,
						para ver se o número é válido. */
						posconsultainst = buscabinariaint (consultainst2, referencianst, Instrumentos.size());
					
						/* Caso o número não esteja entre as possibilidades do vetor, será solicitado que o usuário entre novamente com outro número e o 
						processo se repetirá até que o usuário digite um número válido. */
						while (posconsultainst==-1) {
	
							cout << "A entrada digitada não é válida. Tente novamente." << endl;
							consultainst=entrada();
							consultainst2 = converterconsultaparainteiro(consultainst);
												
							if (consultainst2==0) {
								break;
							}
							
							posconsultainst = buscabinariaint (consultainst2, referencianst, Instrumentos.size());
						} 
										
						// Caso a entrada seja um número válido, será impressa a TAG correspondente ao número que o usuário digitou.	
						if (posconsultainst!=-1) {
							cout << TagsCopy[posconsultainst] << endl;
							cout << endl;					
						}
					}
				} 
				
				// Caso não haja instrumentos cadastrados previamente ou caso o usuário informe que o intrumento a ser consultado não está na lista.
				if (Instrumentos.size()==0 || consultainst2==0) {
					
					// Escolha da variável
					cout << "Digite o número correspondente à variável do instrumento." << endl;
		    		
		    		// Mostra todas as possibilidades de variáveis e seu número correspondente.
				    for (int i=0; i<21; i++) {
		 			   	cout << referenciavariavelinst[i] << " - " << variavel[i] << endl;
		 			}
					cout << endl;
					
					// Entrada do usuário e função para conversão da entrada do usuáario de string para inteiro, caso a entrada seja um número.
					consultainst = entrada();
			    	consultainst2 = converterconsultaparainteiro(consultainst);
			    	
			    	// Procura do número inserido pelo usuário no vetor numerado de 1 até 21 (quantidade de variáveis possíveis), para ver se o número é válido.
			    	posconsultainst = buscabinariaint (consultainst2, referenciavariavelinst, 21);
			
					/* Caso o número não esteja entre as possibilidades do vetor, será solicitado que o usuário entre novamente com outro número e o 
					processo se repetirá até que o usuário digite um número válido. */
					while (posconsultainst==-1) {
						cout << "A entrada digitada não é válida. Tente novamente." << endl;
						consultainst = entrada();	
						consultainst2 = converterconsultaparainteiro(consultainst);
			    		posconsultainst = buscabinariaint (consultainst2, referenciavariavelinst, 21);
					}	
					
					// Caso a entrada seja um número válido, a saída receberá a letra correspondente à variável escolhida pelo usuário.	
					if (posconsultainst!=-1) {
						saidaconsultainst = referenciavariavel[posconsultainst];
					}
		
					// Escolha da segunda letra (modificadora), no caso diferencial.
					cout << "A variável é diferencial?" << endl;
		    		cout << "1 - Sim" << endl;
		    		cout << "2 - Não" << endl;
					cout << endl;
					
					consultainst = entrada();
			    	
					/* Caso a entrada não esteja entre as possibilidades dadas, será solicitado que o usuário forneça novamente uma entrada e o 
					processo se repetirá até que o usuário digite uma entrada válida. */
					while (consultainst!="1" && consultainst!="2") {
						cout << "A entrada digitada não é válida. Tente novamente." << endl;
						consultainst = entrada();
					}	
					
					// Caso a entrada seja 1, a saída receberá a letra correspondente à característica escolhida pelo usuário (diferencial).
					if (consultainst=="1") {
						saidaconsultainst = saidaconsultainst + "D";
						
					// Caso a entrada seja 0, escolha entre as possibilidades da segunda letra (modificadora), se for o caso.
					} else {
						
						cout << "O instrumento é de: " << endl;
			    		cout << "1 - Razão (fração) da variável?" << endl;
		    			cout << "2 - Varredura da variável?" << endl;
		    			cout << "3 - Integração da variável?" << endl;
						cout << "0 - Nenhuma das opções." << endl;
						cout << endl;
						
						consultainst = entrada();
			    	
						/* Caso a entrada não esteja entre as possibilidades dadas, será solicitado que o usuário forneça novamente uma entrada e o 
						processo se repetirá até que o usuário digite uma entrada válida. */
						while (consultainst!="1" && consultainst!="2" && consultainst!="3" && consultainst!="0") {
							cout << "A entrada digitada não é válida. Tente novamente." << endl;
							consultainst = entrada();
						}	
					
						// Caso a entrada seja válida, a saída receberá a letra correspondente à característica escolhida pelo usuário.
						if (consultainst=="1") {
							saidaconsultainst = saidaconsultainst + "F";
						} else if (consultainst=="2") {
							saidaconsultainst = saidaconsultainst + "J";
						} else if (consultainst=="3") {
							saidaconsultainst = saidaconsultainst + "Q";
						}
					}			
					
					// Escolha da(s) função(ões) do instrumento.
					cout << "Digite o número correspondente à(s) função(ões) do instrumento." << endl;
		    		
		    		// Mostra todas as possibilidades de funções do instrumento e seu número correspondente.
				    for (int i=0; i<33; i++) {
		 			   	cout << referenciafuncaoinst[i] << " - " << funcaoinstrumento[i] << endl;
		 			}
					cout << endl;
					
					// Entrada do usuário e função para conversão da entrada do usuáario de string para inteiro, caso a entrada seja um número
					consultainst = entrada();
					consultainst2 = converterconsultaparainteiro(consultainst);
					
					/* Procura do número inserido pelo usuário no vetor numerado de 1 até 33 (quantidade de funções do instrumento possíveis), para ver se o 
					número é válido. */
			    	posconsultainst = buscabinariaint (consultainst2, referenciafuncaoinst, 33);
			    	
					/* Caso o número não esteja entre as possibilidades do vetor, será solicitado que o usuário entre novamente com outro número e o 
					processo se repetirá até que o usuário digite um número válido. */
					while (posconsultainst==-1) {
						cout << "A entrada digitada não é válida. Tente novamente." << endl;
						consultainst = entrada();
						consultainst2 = converterconsultaparainteiro(consultainst);
						posconsultainst = buscabinariaint (consultainst2, referenciafuncaoinst, 33);
						
					}	
					
					// Caso a entrada seja um número válido, a saída receberá a letra correspondente à(s) função(ões) do instrumento escolhida(s) pelo usuário.	
					if (posconsultainst!=-1) {
						
						/* Caso o usuário selecione anteriormente a opção "varredura" e escolha a função do instrumento como chave ou como relé, será 
						mostrado que o instrumento é inválido e o programa retornará para o início da função 2, pois a letra "J" pode significar "varredura"
						ou "seletor", porém no caso de chave ou relé, a letra "J" obrigatoriamente deve significar "seletor", impossibilitanto a existência
						de um "relé de varredura" ou "chave de varredura". */	
						if ((posconsultainst==19 || posconsultainst==31) && (saidaconsultainst[saidaconsultainst.size()-1]=='J')) {
							cout << "Instrumento inválido. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
							retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
							continue;
						}
						
						saidaconsultainst = saidaconsultainst + referenciafuncao[posconsultainst];
					}
					
					
					// Escolha das últimas letras (modificadora), se for o caso.
					cout << "O instrumento é relativo à variável em nível: " << endl;
			    	cout << "1 - Muito alto?" << endl;
		    		cout << "2 - Alto?" << endl;
		    		cout << "3 - Intermediário?" << endl;
		    		cout << "4 - Baixo?" << endl;
		    		cout << "5 - Muito baixo?" << endl;
					cout << "0 - Nenhuma das opções." << endl;
					cout << endl;
					
					consultainst=entrada();
			    	
					/* Caso a entrada não esteja entre as possibilidades dadas, será solicitado que o usuário forneça novamente uma entrada e o 
					processo se repetirá até que o usuário digite uma entrada válida. */
					while (consultainst!="1" && consultainst!="2" && consultainst!="3" && consultainst!="4" && consultainst!="5" && consultainst!="0") {
						cout << "A entrada digitada não é válida. Tente novamente." << endl;
						consultainst = entrada();
					}	
					
					// Caso a entrada seja válida, a saída receberá a(s) letra(s) correspondente(s) à característica escolhida pelo usuário.
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
					
					// Ao fim do processo, saída da TAG correspondente ao instrumento escolhido pelo usuário.
					cout << saidaconsultainst << endl;
					cout << endl;
						
				}
		        
				/* Caso o usuário deseje repetir a função 2, ele deve digitar 1 e voltará para o ínicio do while. Caso deseje voltar ao menu principal,
				ele deve digitar 0. */
				cout << "Para voltar ao menu principal, digite 0. Para consultar outro instrumento TAG, digite 1." << endl;
				retorno = entrada();
					
			}
			
			// Função de códgo de erro caso o usuário não digite 1 nem 0. 
			codigodeerro(retorno);	
			       
    	} else if (funcao=="3") { /* Listar TAGs cadastradas: Quando esse comando é chamado pelo usuário, são listadas as TAGs ordenadas em ordem alfabética e os instrumentos 
		armazenados anteriormente pelo usuário. */

			if(Tags.size()==0){ /* Caso não exista nenhuma TAG/Instrumento cadastrado pelo usuário, retorna-se "NENHUMA TAG CADASTRADA". A verificação da existência de uma 
			TAG/Instrumento se dá pela análise do tamanho da string em que elas estão armazenadas. Caso esse tamanho seja 0, não existe TAG/Instrumento cadastrado. */
					
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
				cout << "NENHUMA TAG CADASTRADA" << endl;
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
			
			}else{ /* Caso exista alguma TAG/Instrumento cadastrado pelo usuario, o programa lista as TAGs em ordem alfabética seguidas de seus respectivos instrumentos. A
			verificação da existência de uma TAG/Instrumento se dá pela análise do tamanho da string em que elas estão armazenadas. Caso esse tamanho seja maior que zero, existe pelo menos
			uma TAG/Instrumento cadastrado. */
			
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
				cout << "TAGS EM ORDEM ALFABÉTICA:" << endl;
				
				for(int i=0; i<Tags.size(); i++) // Loop para listagem das strings Tags e InstrumentosCopy.
				cout << Tags[i] << " | " << InstrumentosCopy[i] << endl;
		
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
								
			}	
			
			// Para voltar ao menu principal, o usuário deve digitar 0.	
			cout << "Para voltar ao menu principal, digite 0." << endl;
			retorno = entrada();
			
			// Função de códgo de erro caso o usuário não digite 0.
			codigodeerro(retorno);
                
        } else if (funcao=="4") { /* Listar instrumentos cadastradas: Quando esse comando é chamado pelo usuário, retornam-se os instrumentos ordenados em ordem alfabética precedidos 
		de suas respectivas TAGs armazenados anteriormente pelo usuário. Esse comando segue a mesma lógica do comando 3, porem ao contrário dele, os instrumentos são a prioridade na 
		ordenação da lista. */

			if(Tags.size()==0){ 
					
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
				cout << "NENHUM INSTRUMENTO CADASTRADO" << endl;
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
						
			}else{ 

				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
				cout << "INSTRUMENTOS EM ORDEM ALFABÉTICA:" << endl;
					
				for(int i=0; i<Tags.size(); i++) // Loop para listagem das strings TagsCopy e Instrumentos.
				cout << TagsCopy[i] << " | " << Instrumentos[i] << endl;
				
				cout << "_____________________________________________________________________________________________________________" << endl;
				cout << endl;
	
			}
			
			// Para voltar ao menu principal, o usuário deve digitar 0.	
			cout << "Para voltar ao menu principal, digite 0." << endl;
			retorno = entrada();
			
			// Função de códgo de erro caso o usuário não digite 0.	
			codigodeerro(retorno);
                
				                
        } else if (funcao=="5") { // Cadastrar nova TAG/instrumento.
					
			retorno="1";
			while (retorno=="1") { // Loop para caso o usuário deseje voltar à funcão 5
					
				/*	A função de cadastrar uma TAG/Instrumento consiste no armazenamento dos dados de entrada do usuario numa string. Primeiramente, utilizamos uma string auxiliar(auxtags e auxinstrumentos) 
				para capturar as entradas dadas, depois manipulamos essas strings, de modo a tornar todas as letras em maiusculas através da função "maiusculas", com o intuito de padronizar as TAGs e os Instrumentos
 				e facilitar na busca e organização dos mesmos. Após a transformação, aplicamos uma busca binária através da função "buscabinariavector" para analisar a existência prévia de uma TAG/Instrumento ja 
				cadastrados anteriormente. Por último armazena-se as strings auxiliares num vetor de strings de tamanho indefinido, que incrementa seu tamanho a cada armazenamento de uma nova TAG/Instrumento, 
				ou seja, a cada iteração dessas strings(Tags e Instrumentos). */

				// Armazenamento da TAG e cópia:

				cout << "Digite a TAG do instrumento." << endl;
				auxtags = entrada(); // Utilização da função "entrada" para capturar a TAG que o usuário deseja cadastrar.
				auxtags = maiusculas (auxtags, auxtags.size()); // Utilização da função "maiusculas" para conversão de todas as letras da string "auxtags" em maiusculas.
				posTagCad = buscabinariavector(auxtags, Tags, Tags.size()); /* Utilização da função "buscabinariavector" para encontrar a posição da string "auxtags" no vetor "Tags", com o intuito de
				constatar a existência de uma TAG já cadastrada pelo usuário. */

	            size_t posEsp2 = auxtags.find(32); // Busca por "espaços" dentro da string "auxtags" e armazena como inteiro em "posEsp2". 
	            					
				if (posEsp2 != string::npos) { // Caso exista "espaço" em alguma posição da string, é considerado que existe um erro. Já que o padrão para escrita das TAGs não é seguido.
					cout << "Tag inválida. Verifique a existência de espaços em sua TAG. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
					retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
					continue; // Continua para a próxima iteração do loop.

				}else{ // Caso não exista "espaço" em alguma posição da string, segue-se para os próximos procedimentos para o cadastramento da Tag/Instrumento. 

					if (posTagCad!=-1){ /* Caso a posição concedida pela busca binária seja diferente de -1, significa que a TAG já existe na string de vetores "Tags", o programa sugere o retorno para 
					interface ou uma nova tentativa para cadastrar uma TAG. */
								
						cout << "Tag já cadastrada. Para voltar ao menu principal, digite 0. Para tentar novamente, digite 1." << endl;
						retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
						continue; 
						
					}else{ /* Caso a posição concedida pela busca binária seja igual a -1, significa que a TAG não existe na string de vetores "Tags", então elas são armazenadas nos vetores "Tags" e "TagsCopy".
					O vetor TagsCopy é utilizado como suporte para a listagem dos Instrumentos em ordem alfabéticas, como será visto posteriormente. */			 
								
						Tags.push_back(auxtags); // Utilização da função .push_back da biblioteca vector para expandir o tamanho do vetor "Tags" dinãmicamente a cada iteração, ou armazenamento de "auxtags".
						TagsCopy.push_back(auxtags); // Também é utilizada a função acima para "TagsCopy".
					}						
						
					//Armazenamento dos Instrumentos e cópia:
					
					cout << "Digite o NOME do instrumento." << endl;
					auxinstrumentos = entrada(); // Utilização da função "entrada" para capturar o instrumento que o usuário deseja associar a TAG escolhida no passo anterior.
					auxinstrumentos = maiusculas (auxinstrumentos, auxinstrumentos.size()); // Utilização da função "maiusculas" para conversão de todas as letras da string "auxinstumentos" em maiusculas.
					posInstrumentoCad = buscabinariavector(auxinstrumentos, InstrumentosCopy, InstrumentosCopy.size()); /* Utilização da função "buscabinariavector" para encontrar a posição da string "auxinstrumentos" no 
					vetor "Intstrumentos", com o intuito de constatar a existência de um instrumento já cadastrado pelo usuário. */
	
					if(posInstrumentoCad!=-1){ /* Similar ao cadastro de TAGs, caso o instrumento exista no vetor de string "Instrumentos", o programa sugere o retorno para interfaze ou uma nova tentativa
					para cadastrar uma nova TAG e Instrumento, reiniciando o processo. Nessa fase também é excluída a TAG armazenada no vetor "Tags" no processo anterior. */
										
						cout << "Instrumento já cadastrado. Para voltar ao menu principal, digite 0. Para tentar novamente, digite 1." << endl;
						Tags.erase(std::remove(Tags.begin(),Tags.end(),auxtags),Tags.end()); // Função da biblioteca Algorithms utilizada para remover uma string específica de um vetor de strings.
						TagsCopy.erase(std::remove(TagsCopy.begin(),TagsCopy.end(),auxtags),TagsCopy.end()); // Também é utilizada a função acima para o "TagsCopy".
						retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
						continue; 
	
					}else{
								
						Instrumentos.push_back(auxinstrumentos); // Similar ao "Tags.push_back(auxtags)" e "TagsCopy.pus_back(auxtags)".
						InstrumentosCopy.push_back(auxinstrumentos); 
						
						cout << "TAG e instrumento cadastrados com sucesso. ";  
								
					}	
	
					/* ORDENAÇÃO DAS TAGS E INSTRUMENTOS:	Nessa étapa, foi utilizado o metódo de ordenação aprendido nas aulas. Para ordenar os Instrumentos em ordem alfabética, utilizou-se uma 
					cópia das TAGs("TagsCopy") cadastradas pelo usuário, que seguia o processo de ordenação dos instrumentos(Instrumentos). Já no processo para ordenar as TAGs("Tags") em ordem alfabetica, 
					utilizou-se uma cópia dos instrumentos("InstrumentosCopy") cadastrados pelo usuario, que seguia o processo de ordenação das TAGs. */

						
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

				/* Caso o usuário deseje repetir a função 5, ele deve digitar 1 e voltará para o ínicio do while. Caso deseje voltar ao menu principal,
				ele deve digitar 0. */	
				cout << "Para retornar ao menu principal, digite 0. Para cadastrar outro instrumento, digite 1." << endl;
				retorno = entrada();
			}
			
			// Função de códgo de erro caso o usuário não digite 1 nem 0 	
			codigodeerro(retorno);
               

		} else if (funcao=="6") { // Descadastrar novo TAG/instrumento
			    
			retorno="1";
			while (retorno=="1") { // Loop para caso o usuário deseje voltar à funcão 6
					
				cout << "Digite a TAG do instrumento que deseja descadastrar." << endl;
				descadastramentoTag = entrada(); // Utilização da função "entrada" para captura da TAG que o usuário deseja descadastrar.
				descadastramentoTag = maiusculas (descadastramentoTag, descadastramentoTag.size()); // Utilização da função "maiusculas" para conversão de todas as letras da string "descadastramentoTag" em maiusculas.
				posTag = buscabinariavector(descadastramentoTag, Tags, Tags.size());
				size_t posEsp2 = descadastramentoTag.find(32); /* Utilização da função "buscabinariavector" para encontrar a posição da string "descadastramentoTag" no vetor "Tags", com o intuito de constatar 
				a existência da TAG já cadastrada pelo usuário. */
			
					if(posEsp2 != string::npos){ // Caso exista "espaço" em alguma posição da string, é considerado que existe um erro. Já que o padrão para escrita das TAGs não é seguido.
						cout << "Tag inválida. Verifique a existência de espaços em sua TAG. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
						retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
						continue;

					}else{ // Caso não exista "espaço" em alguma posição da string, segue-se para os próximos procedimentos para o descadastramento da Tag/Instrumento.
												
						cout << "Digite o NOME do instrumento que deseja descadastrar para confirmar." << endl;
						descadastramentoInstrumentos = entrada(); // Utilização da função "entrada" para capturar o instrumento que o usuário deseja associar a TAG escolhida no passo anterior.
						descadastramentoInstrumentos = maiusculas (descadastramentoInstrumentos, descadastramentoInstrumentos.size()); /* Utilização da função "maiusculas" para conversão de todas as letras da string 
						"descadastramentoInstrumentos" em maiusculas. */
						posInstrumento= buscabinariavector(descadastramentoInstrumentos, InstrumentosCopy, InstrumentosCopy.size()); /* Utilização da função "buscabinariavector" para encontrar a posição da string "descadastramentoInstrumentos" no 
						vetor "IntstrumentosCopy", com o intuito de constatar a existência de um instrumento já cadastrado pelo usuário. Foi utilizada a string "InstrumentosCopy", porque essa string está associada diretamente a string "Tags". */
						
						if(posInstrumento!=-1 && posTag!=-1 && posInstrumento==posTag){ /* Caso exista o instrumento e a tag nos vetores de strings, e a posição do instrumento no vetor "InstrumentosCopy" seja compátivel com a posição da Tag no vetor "Tags
						Ambas serão removidas dos seus respectivos vetores, também nos seus vetores paralelos. */
							
							Tags.erase(std::remove(Tags.begin(),Tags.end(),descadastramentoTag),Tags.end());
							TagsCopy.erase(std::remove(TagsCopy.begin(),TagsCopy.end(),descadastramentoTag),TagsCopy.end());
							
							Instrumentos.erase(std::remove(Instrumentos.begin(),Instrumentos.end(),descadastramentoInstrumentos),Instrumentos.end());
							InstrumentosCopy.erase(std::remove(InstrumentosCopy.begin(),InstrumentosCopy.end(),descadastramentoInstrumentos),InstrumentosCopy.end());
								
							cout << "TAG e instrumento descadastrados com sucesso. ";
							
								
						}else if(posTag==-1 && posInstrumento!=-1){ // Caso o instrumento não exista no vetor de armazenamento da Instrumentos do usuário, a operação é considerada inválida. (Tags, Instrumentos, TagsCopy e InstrumentosCopy).
		
					 		cout << "Operação Inválida. Tag não cadastrada. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
					 		retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
					 		continue;
						
						}else if(posTag!=-1 && posInstrumento==-1){ // Caso a TAG não exista no vetor de armazenamento das TAGs do usuário, a operação é considerada inválida. (Tags e TagsCopy).
		
					 		cout << "Operação Inválida. Instrumento não cadastrado. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
					 		retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
					 		continue;
						
						}else if(posTag==-1 && posInstrumento==-1){ // Caso o instrumento e a tag não existam nos vetores de armazenamento da Instrumentos/TAGs do usuário, a operação é considerada inválida. (Instrumentos e InstrumentosCopy).
		
					 		cout << "Operação Inválida. Tag e Instrumento não cadastradados. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
					 		retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
					 		continue;
						
						}else{ // Caso a instrumento e a TAG existam, mas as suas posições nos vetores de armazenamento paralelos não sejam compatíveis, a operação é considerada inválida. POSIÇÃO(Tags!=InstrumentosCopy e Instrumentos !=TagsCopý)
			
							cout << "Operação Invalida. Tag incompátivel com Instrumento. Para retornar ao menu principal, digite 0. Tentar novamente, digite 1. " << endl;
							retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
					 		continue;
		
						}
					}	
				
				/* Caso o usuário deseje repetir a função 6, ele deve digitar 1 e voltará para o ínicio do while. Caso deseje voltar ao menu principal,
				ele deve digitar 0. */	
				cout << "Para voltar ao menu principal, digite 0. Para descadastrar outro instrumento, digite 1." << endl;
				retorno = entrada(); // Utilização da função entrada para capturar a escolha do usuário.
			
			}

			// Função de códgo de erro caso o usuário não digite 1 nem 0 	
			codigodeerro(retorno);
			
			
        } else { // Código de erro caso o usuário tente acessar uma função inválida
            cout << "O comando digitado não correspondente a nenhuma função válida. Tente novamente." << endl;        
			cout << endl;
		}
		
	}
   				    
    return 0;
}
