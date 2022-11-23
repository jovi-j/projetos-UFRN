package br.imd.dominio.models;

import java.util.Date;
import java.util.Objects;

public class ProdutoNaoDuravel extends Produto{
	Date dataValidade;
	String genero;

	public Date getDataValidade() {
		return dataValidade;
	}

	public void setDataValidade(Date dataValidade) {
		this.dataValidade = dataValidade;
	}

	public String getGenero() {
		return genero;
	}

	public void setGenero(String genero) {
		this.genero = genero;
	}

	@Override
	public int hashCode() {
		return Objects.hash(dataValidade, genero);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		ProdutoNaoDuravel other = (ProdutoNaoDuravel) obj;
		return Objects.equals(dataValidade, other.dataValidade) && Objects.equals(genero, other.genero);
	}

	@Override
	public String toString() {
		return "Nome do Produto: " + getNome() + ", Preço:R$ " + getPreco();
	}
}
