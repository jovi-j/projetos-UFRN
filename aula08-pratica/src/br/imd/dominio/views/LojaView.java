package br.imd.dominio.views;

import br.imd.dominio.models.Deposito;
import br.imd.dominio.models.ProdutoDuravel;
import br.imd.dominio.models.ProdutoNaoDuravel;

public class LojaView {
	public static void main(String[] args) {
		ProdutoDuravel pd1 = new ProdutoDuravel();
		ProdutoDuravel pd2 = new ProdutoDuravel();
		ProdutoDuravel pd3 = new ProdutoDuravel();
		
		ProdutoNaoDuravel pnd1 = new ProdutoNaoDuravel();
		ProdutoNaoDuravel pnd2 = new ProdutoNaoDuravel();
		ProdutoNaoDuravel pnd3 = new ProdutoNaoDuravel();
		
		
		pd1.setNome("Carro");
		pd1.setPreco(100000.00);
		
		pd2.setNome("Moto");
		pd2.setPreco(10000.00);
		
		pd3.setNome("Casa");
		pd3.setPreco(10000000.00);
		
		
		pnd1.setNome("Maça");
		pnd1.setPreco(1.00);
		
		pnd2.setNome("Chocolate");
		pnd2.setPreco(5.00);
		
		pnd3.setNome("Pão");
		pnd3.setPreco(0.75);
		
		Deposito d = new Deposito();
		
		System.out.println(d.isDepositoEmpty() ? "Depósito vazio." : "Depósito com produtos.");
		
		d.createProduto(pd1);
		d.createProduto(pd2);
		d.createProduto(pd3);
		d.createProduto(pnd1);
		d.createProduto(pnd2);
		d.createProduto(pnd3);
		d.deleteProdutoByNome(pnd1.getNome());
		System.out.println("Qtd. produtos: " + d.findAllProdutos().size());
		System.out.println(d.isDepositoEmpty() ? "Depósito vazio." : "Depósito com produtos.");
		System.out.println("Produto de maior preço: " + d.findProdutoByMaiorPreco());
		
		
	}
	
}
