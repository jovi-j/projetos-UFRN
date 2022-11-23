package br.imd.dominio.models;

import java.util.Date;
import java.util.Objects;

public class Produto {
	private String nome;
	private Double preco;
	private String marca;
	private String descricao;
	private Date dataFabricacao;
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	@Override
	public int hashCode() {
		return Objects.hash(dataFabricacao, descricao, marca, nome, preco);
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Produto other = (Produto) obj;
		return Objects.equals(dataFabricacao, other.dataFabricacao) && Objects.equals(descricao, other.descricao)
				&& Objects.equals(marca, other.marca) && Objects.equals(nome, other.nome)
				&& Objects.equals(preco, other.preco);
	}
	public Double getPreco() {
		return preco;
	}
	public void setPreco(Double preco) {
		this.preco = preco;
	}
	public String getMarca() {
		return marca;
	}
	public void setMarca(String marca) {
		this.marca = marca;
	}
	public String getDescricao() {
		return descricao;
	}
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
	public Date getDataFabricacao() {
		return dataFabricacao;
	}
	public void setDataFabricacao(Date dataFabricacao) {
		this.dataFabricacao = dataFabricacao;
	}
	
	
}
