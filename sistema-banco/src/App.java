import java.util.ArrayList;
import java.util.List;

public class App {

    public static List<Pessoa> pessoas = new ArrayList<>();
    public static List<Conta> contas = new ArrayList<>();
    public static List<Agencia> agencias = new ArrayList<>();
    public static Interface ui = new Interface();

    public static String[] mainOpts = { "Fazer um depósito", "Fazer uma transferência",
            "Checar saldo", "Ver todas as transferências" };

    public static void main(String[] args) throws Exception {
        /* Gerando dados pra não ter que digitar na mão */
        pessoas.add(new Pessoa("Joao Victor", "1234567"));
        pessoas.add(new Pessoa("Gabriela Silva", "89101112"));
        contas.add(new Conta(pessoas.get(0), "33331", 1111));
        contas.add(new Conta(pessoas.get(1), "12345", 1234));
        agencias.add(new Agencia(0761));
        Agencia agencia1 = agencias.get(0);
        associarContaAgencia(contas.get(0), agencia1);
        associarContaAgencia(contas.get(1), agencia1);

        int opt = 1;
        while (opt != 0) {
            opt = ui.askOpt(mainOpts, "Bem vindo, selecione uma operação:");
            switch (opt) {
                case 1:
                    iniciarDeposito();
                    break;
                case 2:
                    iniciarTransferencia();
                    break;
                case 3:
                    verSaldo();
                    break;
                case 4:
                    verTransferencias();
                    break;
            }
        }

    }

    private static void verTransferencias() {
        agencias.get(0).imprimirTransferencias();
        ui.pause();
    }

    private static void verSaldo() {
        String numConta = ui.askString("Digite o número da conta");
        Conta c = agencias.get(0).findContaByNum(numConta);
        if (c != null) {
            c.imprimirDados();
            ui.pause();
            return;
        }
        ui.err("Conta não encontrada!");
    }

    private static void iniciarTransferencia() {
        String numContaRem = ui.askString("Digite o número da conta remetente");
        String numContaDest = ui.askString("Digite o número da conta destinatária");
        Double valor = ui.askNumber("Digite o valor a ser transferido");

        Conta remetente = agencias.get(0).findContaByNum(numContaRem);
        Conta destinatario = agencias.get(0).findContaByNum(numContaDest);

        Transferencia transferencia = new Transferencia(remetente, destinatario, valor);

        agencias.get(0).fazerTransferencia(transferencia);

        ui.sucesso("Transferência realizada com sucesso!");

    }

    private static void iniciarDeposito() {
        String numConta = ui.askString("Digite o número da conta que se deseja depositar");
        Double valor = ui.askNumber("Digite o valor do depósito");
        Conta destinatario = agencias.get(0).findContaByNum(numConta);

        agencias.get(0).fazerDeposito(valor, destinatario);

        ui.sucesso("Depósito realizado com sucesso!");

    }

    private static boolean associarContaAgencia(Conta conta, Agencia agencia) {
        if (conta.getNumAgencia() == 0) {
            conta.setNumAgencia(agencia.getNumeroAgencia());
            agencia.addConta(conta);
            return true;
        }
        return false;

    }

}
