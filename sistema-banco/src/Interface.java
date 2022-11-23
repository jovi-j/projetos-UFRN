import java.util.Scanner;

public class Interface {

    private static Scanner sc = new Scanner(System.in);

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
        System.out.println(headerOptions);
        for (int i = 0; i < options.length; i++) {
            System.out.println((i + 1) + " - " + options[i]);
        }
        System.out.println("0 - Voltar");
        int opt = 0;
        try {
            opt = Integer.parseInt(sc.nextLine());
            if (opt < 1 || opt > options.length) {
                return 0;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return 0;
        }
        return opt;
    }

    /**
     * @param question Pergunta que será feita.
     */
    public boolean askYN(String question) {
        System.out.print(question + "[S/n]: ");
        String input = sc.nextLine();
        if (input.isBlank() || input.isEmpty() || input.equals("") || input.equals("S") || input.equals("s")
                || input.equals("sim") || input.equals("SIM")) {
            return true;
        } else {
            return false;
        }
    }

    public Double askNumber(String question) {
        return askNumber(question, false);
    }

    public Double askNumber(String question, boolean confirm) {
        System.out.print(question + ": ");
        Double res;
        try {
            res = Double.parseDouble(sc.nextLine());
            if (confirm) {
                while (!askYN("[ " + res + " ] Está correto?")) {
                    res = Double.parseDouble(sc.next());
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
            return -1.0;
        }
        return res;
    }

    public String askString(String question) {
        return askString(question, false);
    }

    public String askString(String question, boolean confirm) {
        System.out.print(question + ": ");
        String res = sc.nextLine();
        if (confirm) {
            while (!askYN("[ " + res + " ] Está correto?")) {
                res = sc.nextLine();
            }
        }
        return res;
    }

    public void err() {
        err("Digite uma opção válida.");
        pause();
    }

    public void err(String msg) {
        System.out.println(msg);
    }

    public static void close() {
        sc.close();
    }

    public void sucesso(String msg) {
        System.out.println(msg);
        pause();
    }

    public void pause() {
        System.out.println("Pressione ENTER para continuar...");
        sc.nextLine();
    }
}
