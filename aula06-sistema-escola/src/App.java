import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class App {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        List<Aluno> alunos = new ArrayList<>();
        Prova prova11 = new Prova(3.0, 10.0);
        Prova prova12 = new Prova(4.0, 4.0);

        alunos.add(new Aluno(prova11, prova12));

        Prova prova21 = new Prova(10.0, 9.0);
        Prova prova22 = new Prova(2.0, 4.0);

        alunos.add(new Aluno(prova21, prova22));

        Prova prova31 = new Prova(5.0, 10.0);
        Prova prova32 = new Prova(9.0, 8.0);

        alunos.add(new Aluno(prova31, prova32));

        Turma t = new Turma();

        t.setAlunos(alunos);

        for (int i = 0; i < alunos.size(); i++) {
            System.out.println("----\t Média do aluno " + (i + 1) + "\t----");
            System.out.println("\t\t" + new DecimalFormat("##.#").format(alunos.get(i).calcularMedia()));
            System.out.println();
        }
        System.out.println("--------------------------");
        String media = new DecimalFormat("##.#").format(t.calcularMedia());
        System.out.println("Media da turma:\t" + media);

    }
}
