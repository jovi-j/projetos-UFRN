public class Aluno {

    private Prova prova1;
    private Prova prova2;

    public Aluno(Prova prova1, Prova prova2) {
        this.prova1 = prova1;
        this.prova2 = prova2;
    }

    public Prova getProva1() {
        return prova1;
    }

    public void setProva1(Prova prova1) {
        this.prova1 = prova1;
    }

    public Prova getProva2() {
        return prova2;
    }

    public void setProva2(Prova prova2) {
        this.prova2 = prova2;
    }

    public double calcularMedia() {
        return (this.prova1.calculaNotaTotal() + this.prova2.calculaNotaTotal()) / 2.0;
    }
}
