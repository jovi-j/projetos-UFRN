
public class Transferencia {

    private Conta remetente;
    private Conta destinatario;
    private Double valor;
    private Integer numAgencia;

    public Transferencia(Conta remetente, Conta destinatario, Double valor) {
        this.remetente = remetente;
        this.destinatario = destinatario;
        this.valor = valor;
    }

    public Double getValor() {
        return valor;
    }

    public void setValor(Double valor) {
        this.valor = valor;
    }

    public Integer getNumAgencia() {
        return numAgencia;
    }

    public void setNumAgencia(Integer numAgencia) {
        this.numAgencia = numAgencia;
    }

    public Conta getRemetente() {
        return remetente;
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

    @Override
    public String toString() {

        if (this.getRemetente() == null) {
            return "Depósito] " + " [Conta: " + this.getDestinatario().getNumConta() + " Valor: R$ "
                    + getValor().toString() + "] \n[";
        }

        return "Transferencia: [\nRemetente: [" + this.getRemetente().getNumConta() + "|"
                + this.getRemetente().getTitular().getNome() + "]\n Destinatário: ["
                + this.getDestinatario().getNumConta() + "|"
                + this.getDestinatario().getTitular().getNome() + "] Valor:" + this.getValor().toString() + "]";
    }

}
