package br.com.imd.dominio;

import java.util.Date;
import java.util.Random;

public class Transacao {
    private Conta remetente;
    private Conta destinatario;
    private Double valor;
    private Long identificador;

    public Transacao() {
        Long salt = new Random().nextLong(0, 300);
        Long dateLong = new Date().getTime();
        this.identificador = dateLong + salt;
    }

    public Conta getRemetente() {
        return remetente;
    }

    public Long getIdentificador() {
        return identificador;
    }

    public void setRemetente(Conta remetente) {
        this.remetente = remetente;
    }

    public Conta getDestinatario() {
        return destinatario;
    }

    public void setDestinatario(Conta destinatario) {
        this.destinatario = destinatario;
    }

    public Double getValor() {
        return valor;
    }

    public void setValor(Double valor) {
        this.valor = valor;
    }

    @Override
    public String toString() {
        return "Transação T" + identificador + " : -> Dest.: " + this.destinatario.getTitular().getNome() + "\tRem.: "
                + this.remetente.getTitular().getNome() + "\tVALOR: R$ " + this.valor;
    }

}
