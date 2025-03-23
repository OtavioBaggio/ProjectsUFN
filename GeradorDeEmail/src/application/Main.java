package application;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import Entities.Pessoa;

// Aluno: José Otávio Ribeiro Baggio;

/*
  Atividade Avaliativa - Estrutura de Dados:
 
	Fazer um programa em Java, C# ou C++ que receba nomes completos de pessoas (validar se nome foi digitado completo). 
	A partir disso, gerar email da pessoa combinando o primeiro nome com o último nome, separados por '.', mais '@ufn.edu.br'. 
	Por exemplo, João Pedro Garcia -> joao.garcia@ufn.edu.br. Uma vez que o email foi gerado, adicionar o par (nome completo e email) em uma lista. 
	Essa lista pode ser composta por dicionários (email será a chave e nome completo o valor) ou por objetos (da classe Pessoa, com atributos nome e email). 
	Contudo, não pode haver emails repetidos. Ao final, exibir a lista com os dados (nomes e emails).	*/

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);	//Scanner sc criado
		
		//Dicionário:
		Map<String, Pessoa> listaUsuarios = new HashMap<>();
		
		System.out.println("\tBem-vindo ao Gerador de emails da UFN!\n");
		
		//Utilizei while para que o usuário possa gerar quantos emails quiser até, quando queira sair.
		while(true) {		
			System.out.println("Digite o nome COMPLETO da pessoa: ('sair' para encerrar o programa)");
			String nomeCompleto = sc.nextLine().trim();		//trim remove os possíveis espaços em branco 
			if(nomeCompleto.equalsIgnoreCase("sair")) {		
				break;
			}
			
			String[] contemNome = nomeCompleto.split("\\s+");	//Variavel contemNome = partes de todo o nome da pessoa
			if(contemNome.length < 2) {
				System.out.println("ERRO: só será aceito nomes com PELO MENOS um primeiro nome e um sobrenome");
				continue;
			}
			
			//Gerar email:
            String primeiroNome = contemNome[0].toLowerCase();
            String sobreNome = contemNome[contemNome.length - 1].toLowerCase();
            String emailBase = primeiroNome + "." + sobreNome;
            String email = emailBase + "@ufn.edu.br";

			/*
			Depois de fazer o código e rodar, me deparei com algo engraçado:
				Cadastrei o meu nome: José Otávio Ribeiro Baggio;
						e do meu pai: José Renato Gasparetto Baggio;
			E houve um erro de cadastro pois o nosso primeiro nome e o ultimo sobrenome são iguais, então decidi colocar que caso haja essa recorrencia
			ele pegasse o nome antes do ultimo sobrenome, e caso haja outra recorrencia, como por exemplo:
						1ª Recorrencia -->	José Renato Gasparetto Baggio;
						2ª Recorrencia -->	José Carlos Gasparetto Baggio;
			Aí o programa irá utilizar um contador int adicionando um número antes do @ da ufn.	
            */
            
            //Se o email já existir, adiciona o nome do sobrenome do meio:
			if(listaUsuarios.containsKey(email) && contemNome.length > 2) {
				String sobrenomeMeio = contemNome[contemNome.length - 2].toLowerCase();
				emailBase = primeiroNome + "." + sobrenomeMeio;
				email = emailBase + "@ufn.edu.br";
			}
			
			//Se ainda assim houver duplicação, adiciona a numeração:
            int contador = 1;
            while (listaUsuarios.containsKey(email)) {
                email = emailBase + contador + "@ufn.edu.br";
                contador++;
            }
			
			Pessoa usuario = new Pessoa(nomeCompleto, email);
			listaUsuarios.put(email, usuario);
			System.out.println("Email gerado: \n" + email);
		}
		
		//Exibe a lista de pessoas com emails cadastrados
		System.out.println("\nLista de usuários: ");
		for(Pessoa usuario : listaUsuarios.values()) {
			System.out.println(usuario);
		}
		
		
		sc.close();

	}

}
