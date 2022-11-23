package br.imd.dominio.models;

import java.util.Objects;

public class ProdutoDuravel extends Produto {
	
	private int durabilidade;

	public int getDurabilidade() {
		return durabilidade;
	}

	public void setDurabilidade(int durabilidade) {
		this.durabilidade = durabilidade;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = super.hashCode();
		result = prime * result + Objects.hash(durabilidade);
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (!super.equals(obj))
			return false;
		if (getClass() != obj.getClass())
			return false;
		ProdutoDuravel other = (ProdutoDuravel) obj;
		return durabilidade == other.durabilidade;
	}

	@Override
	public String toString() {
		return "Nome do Produto: " + getNome() + ", Preço:R$ " + getPreco();
	}
	
	

}
