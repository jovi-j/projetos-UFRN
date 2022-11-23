package br.com.imd.dominio;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static List<Pessoa> dbPessoas = new ArrayList<Pessoa>();
    public static List<Conta> dbContas = new ArrayList<Conta>();
    public static List<Agencia> dbAgencias = new ArrayList<Agencia>();
    public static Interface ui = new Interface();
    public static String[] mainOpts = { "Criar Pesssoa", "Criar Conta", "Fazer Transferência", "Exibir Extrato" };

    public static void main(String[] args) {
        boolean executando = true;
        while (executando) {
            Integer op;
            op = ui.askOpt(mainOpts);

            try {
                switch (op) {
                case 1:
                    criarPessoa();
                    ui.flush();
                    break;
                case 2:
                    criarConta();
                    break;
                case 3:
                    iniciarTransferencia();
                    break;
                case 4:
                    exibirExtrato();
                    break;
                default:
                    executando = false;
                    System.out.println("Adeus :)");
                }

            } catch (Throwable e) {
                ui.err();
            }
        }

    }

    private static Agencia selecionarAgencia() {
        return null;
    }

    private static void exibirExtrato() {
        System.out.print("Digite o número da conta para exibir o extrato: ");
        Integer numConta = ui.askNumber("Digite o número da conta para exibir o extrato: ").intValue();
        Conta conta = procurarConta(numConta);
        if (conta.equals(null)) {
            ui.err("ERRO: CONTA NAO ENCONTRADA");
            return;
        } else {
            conta.imprimirExtrato();
            ui.pause();
        }
    }

    private static Conta procurarConta(Integer numConta) {
        for (Conta c : dbContas) {
            if (c.getNumConta() == numConta)
                return c;
        }
        return null;
    }

    private static void criarPessoa() {
        String nome, cpf, dataNasc;
        ui.flush();
        nome = ui.askString("Digite seu nome: ");
        cpf = ui.askString("Digite seu CPF: ");
        dataNasc = ui.askString("Digite sua data de nascimento(formato: dia/mes/ano com 4 digitos): ");

        dbPessoas.add(new Pessoa(nome, cpf, dataNasc));
        System.out.println("Bem vindo ao sistema :)");
        ui.pause();
    }

    private static void criarConta() {
        String cpfTitular = ui.askString("Digite o cpf do titular da nova conta: ");
        for (Pessoa p : dbPessoas) {
            if (p.getCPF().equals(cpfTitular)) {
                Conta c = new Conta(p);
                dbContas.add(c);
                System.out.println("Conta adicionada com sucesso!");
                System.out.println("O número da sua conta é: " + c.getNumConta());
                ui.pause();
                return;
            }
        }
        System.out.println("Cpf não encontrado.");
        ui.pause();
    }

    private static void iniciarTransferencia() {
        Integer numRemet = ui.askNumber("Digite o número da conta remetente: ").intValue();

        Conta remetente = procurarConta(numRemet);
        if (remetente.equals(null)) {
            ui.err("ERRO: CONTA NÃO ENCONTRADA");
            ui.pause();
            return;
        } else {
            System.out.println("Remetente: " + remetente.getTitular().getNome());
        }

        Integer numDest = ui.askNumber("Digite o número da conta destinatária: ").intValue();

        Conta destinatario = procurarConta(numDest);
        if (destinatario.equals(null)) {
            ui.err("ERRO: CONTA NÃO ENCONTRADA");
            ui.pause();
            return;
        } else {
            System.out.println("Destinatário: " + destinatario.getTitular().getNome());
        }

        Double valor = ui.askNumber("Digite um valor até R$ " + remetente.getSaldo() + ": ");
        realizarTransferencia(remetente, destinatario, valor);

    }

    public static void realizarTransferencia(Conta remetente, Conta destinatario, Double valor) {
        Codigo resposta = remetente.realizarTransferencia(destinatario, valor);
        switch (resposta) {
        case OK:
            System.out.println("Valor transferido com sucesso :)");
            ui.pause();
            break;
        case TRANSF_ERR_DEST_OU_REM_INVAL:
            ui.err("ERRO: DESTINATÁRIO OU REMETENTE DA TRANSFERÊNCIA INVÁLIDOS.");
            break;
        case TRANSF_ERR_SEM_SALDO:
            ui.err("ERRO: SALDO INSUFICIENTE.");
            break;
        case TRANSF_ERR_MESMA_CONTA:
            ui.err("ERRO: TENTATIVA DE TRANSFERÊNCIA PARA A MESMA CONTA.");
            break;
        case TRANSF_ERR_VALOR_INVAL:
            ui.err("ERRO: VALOR DA TRANSFERÊNCIA INVÁLIDO.");
            break;
        }

        ui.pause();
    }

}
