package entities;

public class Produto {
	private String nome;
	private double preco;
	private int quantidadeEstoque;
	
	//Construtor apenas com o nome:
	public Produto(String nome) {
		super();
		this.nome = nome;
		this.preco = 0;
		this.quantidadeEstoque = 0;
	}
	
	//Construtor com o nome e o preço:
	public Produto(String nome, double preco) {
		super();
		this.nome = nome;
		this.preco = preco;
		this.quantidadeEstoque = 0;
	}
	
	
	//Métodos getters e setters:
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getPreco() {
		return preco;
	}

	public void setPreco(double preco) {
		this.preco = preco;
	}

	public int getQuantidadeEstoque() {
		return quantidadeEstoque;
	}

	public void setQuantidadeEstoque(int quantidadeEstoque) {
		this.quantidadeEstoque = quantidadeEstoque;
	}
	
	//Método para exibir informações do produto
    public void exibirInformacoes() {
        System.out.println("\n----------- DADOS DO PRODUTO -----------");
        System.out.println("Nome: " + nome);
        System.out.printf("Preço: R$ %.2f\n", preco);
        System.out.println("Quantidade em estoque: " + quantidadeEstoque);
    }
	
	
	
	
	
	

}
