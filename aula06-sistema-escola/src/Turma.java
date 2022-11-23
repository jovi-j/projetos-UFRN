import java.util.ArrayList;
import java.util.List;

public class Turma {
    private List<Aluno> alunos = new ArrayList<Aluno>();

    public List<Aluno> getAlunos() {
        return alunos;
    }

    public void setAlunos(List<Aluno> alunos) {
        this.alunos = alunos;
    }

    public double calcularMedia() {
        double mediaDaTurma = 0;
        for (Aluno aluno : alunos) {
            mediaDaTurma += aluno.calcularMedia();
        }
        return mediaDaTurma / (double) alunos.size();
    }
}
