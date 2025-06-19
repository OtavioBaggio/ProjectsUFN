package Entities;

// Importações de arquivos e listas:
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class VeiculoMais {
	private List<Veiculo> veiculos;	 				 // Lista que armazena os objetos do tipo Veiculo
	private final String arquivo = "veiculos.ser";   // Nome do arquivo onde os dados serão salvos
	
	public VeiculoMais() {
		veiculos = carregarVeiculos();	 // Inicializa a lista carregando os dados do arquivo.
	}
	
	private List<Veiculo> carregarVeiculos(){
		// Tenta ler a lista de veículos já salva no arquivo e retorna ela:
		try(ObjectInputStream objetoEntrada = new ObjectInputStream(new FileInputStream(arquivo))){
			return (List<Veiculo>) objetoEntrada.readObject();
		// Se o arquivo não existir ou der erro, retorna uma lista nova e vazia:
		}catch(Exception e) {
			return new ArrayList<>();
		}
	}
	
	private void salvarVeiculos() {
		// Grava a lista atualizada no arquivo, sobrescrevendo o conteúdo anterior:
		try(ObjectOutputStream objetoSaida = new ObjectOutputStream(new FileOutputStream(arquivo))){
			objetoSaida.writeObject(veiculos);
		// Caso ocorra erro ao gravar, exibe a mensagem:
		}catch(IOException e) {
			System.out.println("Erro ao salvar os dados.");
		}
	}
	
	//Metodo para cadastrar que adiciona, e chama a função salvar veiculo:
	public void cadastrarVeiculo(Veiculo v) {
		veiculos.add(v);
		salvarVeiculos();
	}
	
	public boolean alterarQuilometragem(String placa, double novaKm) {
		for(Veiculo v : veiculos) {
			if(v.getPlaca().equalsIgnoreCase(placa)) {	// ignora a diferença entre letras minusculas e maiusculas
				v.setQuilometragem(novaKm);
				salvarVeiculos();
				return true;
			}
		}
		return false;  // Retorna falso se o veículo não for encontrado
	}
	
	public boolean excluirVeiculo(String placa) {
		Iterator<Veiculo> it = veiculos.iterator();	 // iterator para percorrer a lista
		while(it.hasNext()) {
			if(it.next().getPlaca().equalsIgnoreCase(placa)) {
				it.remove();
				salvarVeiculos();
				return true;
			}
		}
		return false;  // Retorna falso se o veículo não for encontrado
	}
	
	public void listarVeiculos() {
		if(veiculos.isEmpty()) {	// Verifica se a lista de veículos está vazia
			System.out.println("Nenhum veículo cadastrado.");
		}else {
			System.out.println("--- Lista de Veículos ---");
			int cont = 1;
			for(Veiculo v : veiculos) {
				System.out.println("Veículo " + cont + ": ");
				System.out.println(v);  // Usa o toString() do objeto
				System.out.println();   // separa os veículos
				cont++;
			}
		}
	}
	
}
