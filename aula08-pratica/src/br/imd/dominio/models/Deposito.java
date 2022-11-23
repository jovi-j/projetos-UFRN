package br.imd.dominio.models;

import java.util.ArrayList;
import java.util.List;

public class Deposito {
	private List<Produto> produtos = new ArrayList<Produto>();

	public void createProduto(Produto produto) {
		produtos.add(produto);
	}

	public List<Produto> findAllProdutos() {
		return produtos;
	}

	public List<Produto> findAllProdutosByNome(String nome) {
		List<Produto> qtdProdutos = new ArrayList<Produto>();
		for (Produto produto : qtdProdutos) {
			if (produto.getNome() == nome) {
				qtdProdutos.add(produto);
			}
		}
		return qtdProdutos;
	}

	public Produto findProdutoByNome(String nome) {
		for (Produto p : produtos) {
			if (p.getNome() == nome) {
				return p;
			}
		}
		return null;
	}

	public Produto deleteProdutoByNome(String nome) {
		Produto produto = findProdutoByNome(nome);
		if (produto.equals(null)) {
			return null;
		}
		produtos.remove(produto);
		return produto;
	}

	public Boolean isDepositoEmpty() {
		return produtos.size() == 0;
	}

	public Produto findProdutoByMaiorPreco() {
		if (isDepositoEmpty()) {
			return null;
		}

		Produto produtoMaiorPreco = produtos.get(0);
		for (Produto produto : produtos) {
			if (produto.getPreco() > produtoMaiorPreco.getPreco()) {
				produtoMaiorPreco = produto;
			}
		}
		return produtoMaiorPreco;
	}

}
