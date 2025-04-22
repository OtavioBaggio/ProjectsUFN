package application;

// CORREÇÃO DA PROVA 1 - Programação Orientado a Objetos;

import java.util.Scanner;

import entities.Produto;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        Produto produto = null;	  //Inicializa o produto como null, para que o objeto só seja criado no switch, de acordo com a opção 1 ou 2;
        						  //Ou seja, declara mas não cria nada;

        int opcao;

        //Menu de opções:
        do {
            System.out.println("\n\tBem-vindo ao Sistema Gerenciador de Produtos da UFN Market!\n");
            System.out.println("MENU:");
            System.out.println("1 - Criar produto informando nome");
            System.out.println("2 - Criar produto informando nome e preço");
            System.out.println("3 - Exibir informações do produto");
            System.out.println("4 - Atribuir nome do produto");
            System.out.println("5 - Obter nome do produto");
            System.out.println("6 - Atribuir preço do produto");
            System.out.println("7 - Obter preço do produto");
            System.out.println("8 - Atribuir quantidade em estoque");
            System.out.println("9 - Obter quantidade em estoque");
            System.out.println("0 - Sair");
            System.out.print("Escolha uma opção: ");
            opcao = sc.nextInt();
            sc.nextLine(); // consumir quebra de linha

            switch (opcao) {
                case 1:
                    System.out.print("\nDigite o nome do produto: ");
                    String nome1 = sc.nextLine();
                    produto = new Produto(nome1);
                    System.out.println("Produto criado com sucesso!");
                    break;
                case 2:
                    System.out.print("\nDigite o nome do produto: ");
                    String nome2 = sc.nextLine();
                    System.out.print("Digite o preço do produto: ");
                    double preco = sc.nextDouble();
                    produto = new Produto(nome2, preco);
                    System.out.println("Produto criado com sucesso!");
                    break;
                case 3:
                    if (produto != null) {
                        System.out.println();
                    	produto.exibirInformacoes();
                    } else {
                        System.out.println("\nNenhum produto foi criado ainda.");
                    }
                    break;
                case 4:
                    if (produto != null) {
                        System.out.print("\nDigite o novo nome: ");
                        String novoNome = sc.nextLine();
                        produto.setNome(novoNome);
                        System.out.println("Nome alterado com sucesso!");
                    } else {
                        System.out.println("\nNenhum produto foi criado ainda.");
                    }
                    break;
                case 5:
                    if (produto != null) {
                        System.out.println("\nNome do produto: " + produto.getNome());
                    } else {
                        System.out.println("\nNenhum produto foi criado ainda.");
                    }
                    break;
                case 6:
                    if (produto != null) {
                        System.out.print("\nDigite o novo preço: ");
                        double novoPreco = sc.nextDouble();
                        produto.setPreco(novoPreco);
                        System.out.println("Preço alterado com sucesso!");
                    } else {
                        System.out.println("\nNenhum produto foi criado ainda.");
                    }
                    break;
                case 7:
                    if (produto != null) {
                        System.out.printf("\nPreço do produto: R$ %.2f\n", produto.getPreco());
                    } else {
                        System.out.println("\nNenhum produto foi criado ainda.");
                    }
                    break;
                case 8:
                    if (produto != null) {
                        System.out.print("\nDigite a nova quantidade em estoque: ");
                        int novaQtd = sc.nextInt();
                        produto.setQuantidadeEstoque(novaQtd);
                        System.out.println("Quantidade alterada com sucesso!");
                    } else {
                        System.out.println("\nNenhum produto foi criado ainda.");
                    }
                    break;
                case 9:
                    if (produto != null) {
                        System.out.println("\nQuantidade em estoque: " + produto.getQuantidadeEstoque());
                    } else {
                        System.out.println("\nNenhum produto foi criado ainda.");
                    }
                    break;
                case 0:
                    System.out.println("\nPROGRAMA ENCERRADO!");
                    System.out.println("Obrigado por utilizar o SGP da UFN Market!");
                    break;
                default:
                    System.out.println("\nOpção inválida! Tente novamente.");
            }

        } while (opcao != 0);

        sc.close();

	}

}
