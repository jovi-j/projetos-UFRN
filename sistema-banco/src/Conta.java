public class Conta {
    private Pessoa titular;
    private Double saldo = 0.0;
    private boolean isBloqueada = false;
    private String numConta = "";
    private Integer senha = 0000;
    private Integer numAgencia = 0000;

    public Conta(Pessoa titular, String numConta, Integer senha) {
        this.titular = titular;
        this.numConta = numConta;
        this.senha = senha;
    }

    public void addSaldo(Double valor) {
        this.saldo += valor;
    }

    public void subSaldo(Double valor) {
        this.saldo -= valor;
    }

    public Boolean canRemoveSaldo(Double valor) {
        if ((this.saldo - valor) < 0) {
            return false;
        }
        return true;
    }

    public Pessoa getTitular() {
        return this.titular;
    }

    public void setTitular(Pessoa titular) {
        this.titular = titular;
    }

    public Double getSaldo() {
        return this.saldo;
    }

    public void setSaldo(Double saldo) {
        this.saldo = saldo;
    }

    public boolean isBloqueada() {
        return this.isBloqueada;
    }

    public void bloquear() {
        this.isBloqueada = true;
    }

    public void setSenha(Integer senha) {
        this.senha = senha;
    }

    public void setNumConta(String numConta) {
        this.numConta = numConta;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((titular == null) ? 0 : titular.hashCode());
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Conta other = (Conta) obj;
        if (titular == null) {
            if (other.titular != null)
                return false;
        } else if (!titular.equals(other.titular))
            return false;
        return true;
    }

    public void setBloqueada(boolean isBloqueada) {
        this.isBloqueada = isBloqueada;
    }

    public Integer getNumAgencia() {
        return numAgencia;
    }

    public void setNumAgencia(Integer numAgencia) {
        this.numAgencia = numAgencia;
    }

    public String getNumConta() {
        return numConta;
    }

    public Integer getSenha() {
        return senha;
    }

    public void imprimirDados() {
        System.out.println(this.toString());
    }

    @Override
    public String toString() {
        String bloqueioBanner = this.isBloqueada ? "!!CONTA BLOQUEADA!!" : "";
        return bloqueioBanner + "\n"
                + "Nome do titular: "
                + this.titular.getNome() + "\nCPF: "
                + this.titular.getCpf() + "\nSaldo da conta: R$ "
                + this.saldo + "\n-----\n";

    }

}
