package Entities;

import java.io.Serializable;

public class Veiculo implements Serializable{
	private String placa;
	private String modelo;
	private String marca;
	private int anoFabricacao;
	private double quilometragem;

	// Construtor:
	public Veiculo(String placa, String modelo, String marca, int anoFabricacao, double quilometragem) {
		super();
		this.placa = placa;
		this.modelo = modelo;
		this.marca = marca;
		this.anoFabricacao = anoFabricacao;
		this.quilometragem = quilometragem;
	}

	// Métodos Getters e Set:
	public double getQuilometragem() {
		return quilometragem;
	}

	public void setQuilometragem(double quilometragem) {
		this.quilometragem = quilometragem;
	}

	public String getPlaca() {
		return placa;
	}

	public String getModelo() {
		return modelo;
	}

	public String getMarca() {
		return marca;
	}

	public int getAnoFabricacao() {
		return anoFabricacao;
	}

	@Override
	public String toString() {
		return "Placa: " + placa + ", Modelo: " + modelo + ", Marca: " + marca + ", Ano: " + anoFabricacao + ", KM: "
				+ quilometragem;
	}

}
