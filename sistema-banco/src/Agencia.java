import java.util.ArrayList;
import java.util.List;

public class Agencia {
    private List<Pessoa> clientes = new ArrayList<>();
    private List<Conta> contas = new ArrayList<>();
    private int numeroAgencia;
    private List<Transferencia> transferenciasRealizadas = new ArrayList<>();

    public Agencia(int numeroAgencia) {
        this.numeroAgencia = numeroAgencia;
    }

    public Conta findContaByNum(String numConta) {
        for (Conta conta : contas) {
            if (conta.getNumConta().equals(numConta)) {
                return conta;
            }
        }
        return null;

    }

    public Boolean addConta(Conta c) {
        for (Conta conta : contas) {
            if (conta == c) {
                return false;
            }
        }
        clientes.add(c.getTitular());
        return contas.add(c);
    }

    public Boolean fazerDeposito(Double valor, Conta conta) {
        if (!contas.isEmpty() && contas.contains(conta)) {
            Transferencia tr = new Transferencia(null, conta, valor);
            return fazerTransferencia(tr);
        }
        return false;

    }

    public Boolean fazerTransferencia(Transferencia transferencia) {
        Double valor = transferencia.getValor();
        transferencia.setNumAgencia(this.numeroAgencia);

        if (transferencia.getRemetente() == null) {
            transferencia.getDestinatario().addSaldo(valor);
        } else if (transferenciaValida(transferencia, valor)) {
            transferencia.getRemetente().subSaldo(valor);
            transferencia.getDestinatario().addSaldo(valor);
        } else {
            return false;
        }
        this.transferenciasRealizadas.add(transferencia);
        return true;
    }

    private boolean transferenciaValida(Transferencia transferencia, Double valor) {
        return !transferencia.getDestinatario().isBloqueada() && !transferencia.getDestinatario().isBloqueada()
                && valor > 0 && transferencia.getRemetente().canRemoveSaldo(valor);
    }

    public List<Pessoa> getClientes() {
        return clientes;
    }

    public void setClientes(List<Pessoa> clientes) {
        this.clientes = clientes;
    }

    public List<Conta> getContas() {
        return contas;
    }

    public void setContas(List<Conta> contas) {
        this.contas = contas;
    }

    public int getNumeroAgencia() {
        return numeroAgencia;
    }

    public void setNumeroAgencia(int numeroAgencia) {
        this.numeroAgencia = numeroAgencia;
    }

    public List<Transferencia> getTransferenciasRealizadas() {
        return transferenciasRealizadas;
    }

    public void setTransferenciasRealizadas(List<Transferencia> transferenciasRealizadas) {
        this.transferenciasRealizadas = transferenciasRealizadas;
    }

    public void imprimirTransferencias() {

        for (Transferencia transferencia : transferenciasRealizadas) {
            if (transferencia.getRemetente() == null) {
                System.out.println("[Depósito] Conta: "
                        + transferencia.getDestinatario().getNumConta() + "("
                        + transferencia.getDestinatario().getTitular().getNome() + ") Valor: R$ "
                        + transferencia.getValor().toString());
            } else {
                System.out.println("[Transferência] Remetente: "
                        + transferencia.getRemetente().getNumConta() + " ("
                        + transferencia.getRemetente().getTitular().getNome() + ") >>> Destinatário: "
                        + transferencia.getDestinatario().getNumConta() + " ("
                        + transferencia.getDestinatario().getTitular().getNome() + ") Valor: R$ "
                        + transferencia.getValor().toString());
            }
        }
    }
}
