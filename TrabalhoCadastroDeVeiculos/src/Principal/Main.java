package Principal;

/*
 * ATIVIDADE FINAL — CADASTRO DE VEÍCULOS
 * 		Aluno: José Otávio Ribeiro Baggio;

Utilizando Java, manipulação de arquivos e orientação a objetos, desenvolva um sistema de cadastro de veículos.
O sistema deverá exibir um menu em laço infinito com as seguintes opções:

1 - Cadastrar veículo
2 - Alterar quilometragem do veículo
3 - Excluir veículo pelo número da placa
4 - Sair do sistema

Requisitos:
O sistema deve seguir as boas práticas de programação com orientação a objetos.
A manipulação deve ser feita através de objetos da classe Veiculo e de uma lista de veículos.
Antes de gravar os dados no arquivo, o veículo deve ser instanciado como objeto, adicionado à lista e 
a lista deve ser atualizada no arquivo.
O armazenamento dos dados deve ser feito em um arquivo texto. Será considerado um diferencial se o aluno utilizar 
serialização. A classe Veiculo deve conter os seguintes atributos privados:
	placa (String)
	modelo (String)
	marca (String)
	ano de fabricação (int)
	quilometragem (double)
	
Todos os atributos devem ter métodos get.
Apenas a quilometragem poderá ter um método set.
 */

import java.util.Scanner;

import Entities.Veiculo;
import Entities.VeiculoMais;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		VeiculoMais vm = new VeiculoMais();
		
		System.out.println("\tBEM-VINDO AO SISTEMA DE CADASTRO DO DETRAN - RS !");
		System.out.println("\t\t\tPowered by: UFN Systems");
		while(true) {
			System.out.println("\n1 - Cadastrar veículo");
			System.out.println("2 - Alterar quilometragem do veículo");
			System.out.println("3 - Excluir veículo pelo número da placa");
			System.out.println("4 - Listar veículos");
			System.out.println("5 - Sair");
			System.out.println("Escolha uma opção: ");
			int op;
			try{	// Tive que colocar esse tryCatch, pois depois do item 4 ser selecionada estava parando o programa.
				op = Integer.parseInt(sc.nextLine());
			}catch(NumberFormatException e) {
				System.out.println("Entrada inválida! Digite um número entre 1 e 5.");
				continue;
			}
			
			switch(op) {
			case 1:
				System.out.println("Informe os dados do veículo..");
				System.out.println("Placa: ");
				String placa = sc.nextLine();
				System.out.println("Modelo");
				String modelo = sc.nextLine();
				System.out.println("Marca: ");
				String marca = sc.nextLine();
				System.out.println("Ano de fabricação: ");
				int ano = sc.nextInt();
				System.out.println("Quilometragem do carro: ");
				double km = sc.nextDouble();
				sc.nextLine();
				
				vm.cadastrarVeiculo(new Veiculo(placa, modelo, marca, ano, km));
				System.out.println("Veículo cadastrado com sucesso!");
				break;
			
			case 2:
				System.out.println("Placa do Veículo: ");
				String placaAlt = sc.nextLine();
				System.out.println("Nova quilometragem: ");
				double novaKm = sc.nextDouble();
				sc.nextLine();
				
				if(vm.alterarQuilometragem(placaAlt, novaKm))
					System.out.println("Quilometragem atualizada.");
				else
					System.out.println("Veículo não encontrado.");
				break;
			
			case 3:
				System.out.println("informe a placa do veículo que deseja excluir: ");
				String placaExcl = sc.nextLine();
				if(vm.excluirVeiculo(placaExcl))
					System.out.println("Veículo excluído com sucesso!");
				else
					System.out.println("Veículo não encontrado na base de dados.");
				break;
				
			case 4:
				vm.listarVeiculos();
				break;
			
			case 5:
				System.out.println("Programa Encerrado..");
				System.out.println("Obrigado por utilizar o nosso sistema!");
				sc.close();
				return;
			
			default:
				System.out.println("Opção Inválida!");
			}
		}
		
	}

}
