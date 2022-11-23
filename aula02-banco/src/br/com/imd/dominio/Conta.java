package br.com.imd.dominio;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Conta {
    private Pessoa titular;
    private List<Transacao> extrato = new ArrayList<Transacao>();
    private Double saldo;
    private int numConta;

    public Conta(Pessoa titular) {
        this.numConta = new Random().nextInt(10000, 99999);
        this.titular = titular;
        this.saldo = 1000.00;
    }

    public Conta() {
        this.saldo = 1000.00;
    }

    public void setTitular(Pessoa titular) {
        this.titular = titular;
    }

    public void setSaldo(Double saldo) {
        this.saldo = saldo;
    }

    public int getNumConta() {
        return numConta;
    }

    public void setNumConta(int numConta) {
        this.numConta = numConta;
    }

    public Pessoa getTitular() {
        return titular;
    }

    public Double getSaldo() {
        return saldo;
    }

    public Codigo receberTransferencia(Transacao transfRecebida) {
        if (transfRecebida.getRemetente().getTitular() == this.titular
                && transfRecebida.getDestinatario().getTitular() == this.titular)
            return Codigo.TRANSF_ERR_MESMA_CONTA;
        if (transfRecebida.getRemetente().equals(null) || transfRecebida.getDestinatario().equals(null))
            return Codigo.TRANSF_ERR_DEST_OU_REM_INVAL;
        if (transfRecebida.getValor() <= 0)
            return Codigo.TRANSF_ERR_VALOR_INVAL;

        this.saldo += transfRecebida.getValor();
        this.extrato.add(transfRecebida);

        return Codigo.OK;
    }

    public Codigo realizarTransferencia(Conta destinatario, Double valor) {
        Transacao t = new Transacao();
        t.setDestinatario(destinatario);
        t.setRemetente(this);
        t.setValor(valor);
        Codigo res = destinatario.receberTransferencia(t);
        if (res == Codigo.OK) {
            this.saldo -= valor;
            this.extrato.add(t);
        }
        return res;

    }

    public void imprimirExtrato() {
        System.out.println("-- EXTRATO DA CONTA --");
        System.out.println("SALDO ATUAL: R$" + this.saldo);
        for (Transacao t : this.extrato) {
            System.out.println(t);
        }

    }

    @Override
    public String toString() {
        return "--- DADOS DA CONTA ---\n" + "Titular: " + this.titular.getNome() + "\nConta: " + this.numConta
                + "\nSaldo: " + this.saldo;
    }

}
