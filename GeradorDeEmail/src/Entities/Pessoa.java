package Entities;

public class Pessoa {
	private String nomeCompleto;	//Utilizando private para não gerar conflito com outras classes;
	private String email;
	
	public Pessoa(String nomeCompleto, String email) {
		this.nomeCompleto = nomeCompleto;
		this.email = email;
	}
	
	public String getNomeComp(String nomeCompleto) {
		return nomeCompleto;
	}
	
	public String getEm(String email) {
		return email;
	}
	
	public String toString() {
		return "Nome: " + nomeCompleto + " || Email: " + email;
	}

}
