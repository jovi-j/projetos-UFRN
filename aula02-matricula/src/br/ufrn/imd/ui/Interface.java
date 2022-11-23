package br.ufrn.imd.ui;

import java.util.Scanner;

public class Interface {

    public Interface() {
        printBanner();
    }

    private void printBanner() {
        System.out.println("Bem vindo ao sistema de matrículas!");
    }

    public int askOpt(String[] options) {
        return askOpt(options, "Digite uma opção:");
    }

    public int askOpt(String[] options, String headerOptions) {
        Scanner sc = new Scanner(System.in);
        System.out.println(headerOptions);
        for (int i = 0; i < options.length; i++) {
            System.out.println((i + 1) + "- " + options[i]);
        }
        System.out.println("0 - Voltar");
        int opt = 0;
        try {
            opt = sc.nextInt();
            if (opt < 1 || opt > options.length) {
                sc.close();
                return 0;
            }
        } catch (Exception e) {
            sc.close();
            return 0;
        } finally {
            sc.close();
        }
        return opt;
    }

    /**
     * @param question Pergunta que será feita.
     */
    public boolean askYN(String question) {
        Scanner sc = new Scanner(System.in);
        System.out.print(question + "[S/n]:");
        String input = sc.nextLine();
        while (true) {
            if (input == "" || input == "S" || input == "s" || input == "sim" || input == "SIM") {
                sc.close();
                return true;
            } else if (input == "n" || input == "N" || input == "nao" || input == "NAO") {
                sc.close();
                return false;
            }
        }
    }

    public Double askNumber(String question) {
        return askNumber(question, false);
    }

    public Double askNumber(String question, boolean confirm) {
        Scanner sc = new Scanner(System.in);
        System.out.print(question + ": ");
        Double res;
        try {
            res = sc.nextDouble();
            if (confirm) {
                while (!askYN("[ " + res + " ] Está correto?")) {
                    res = sc.nextDouble();
                }
            }
        } catch (Exception e) {
            sc.close();
            return -1.0;
        } finally {
            sc.close();
        }
        return res;
    }

    public String askString(String question) {
        return askString(question, false);
    }

    public String askString(String question, boolean confirm) {
        Scanner sc = new Scanner(System.in);
        System.out.print(question + ": ");
        String res = sc.nextLine();
        if (confirm) {
            while (!askYN("[ " + res + " ] Está correto?")) {
                res = sc.nextLine();
            }
        }
        sc.close();
        return res;
    }

    public void err() {
        err("Digite uma opção válida.");
    }

    public void err(String msg) {
        System.out.println(msg);
    }
}
