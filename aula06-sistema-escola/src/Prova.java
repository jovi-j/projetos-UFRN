public class Prova {
    private double notaParte1;
    private double notaParte2;

    public Prova(double n1, double n2) {
        setNotaParte1(n1);
        setNotaParte2(n2);
    }

    public double getNotaParte1() {
        return notaParte1;
    }

    public void setNotaParte1(double notaParte1) {
        if ((this.notaParte2 + notaParte1) > 10.0)
            return;

        this.notaParte1 = notaParte1;
    }

    public double getNotaParte2() {
        return notaParte2;
    }

    public void setNotaParte2(double notaParte2) {
        if ((this.notaParte1 + notaParte2) > 10.0)
            return;

        this.notaParte2 = notaParte2;
    }

    public double calculaNotaTotal() {
        return notaParte1 + notaParte2;
    }

}
