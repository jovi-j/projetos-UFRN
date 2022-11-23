package br.ufrn.imd.domino;

import java.util.ArrayList;
import java.util.List;

public class Aluno extends Pessoa {

	private String matricula;
	private Curso curso;
	private double ira;
	private List<Disciplina> disciplinas;

	public Aluno() {
		disciplinas = new ArrayList<Disciplina>();
	}

	public String getMatricula() {
		return matricula;
	}

	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}

	public Curso getCurso() {
		return curso;
	}

	public void setCurso(Curso curso) {
		this.curso = curso;
	}

	public double getIra() {
		return ira;
	}

	public void setIra(double ira) {
		this.ira = ira;
	}

	@Override
	public String toString() {
		return getNome() + " matr�cula: " + matricula + "\nCPF: " + getCpf() + "\nData de Nascimento: "
				+ getDataNascimento();
	}

	public boolean solicitarMatricula(Disciplina disciplina) {
		if (!disciplinas.contains(disciplina)) {
			disciplinas.add(disciplina);
			return true;
		}
		return false;
	}

	public void trancarMatricula(Disciplina disciplina) {
		disciplinas.remove(disciplina);
	}

	public List<Disciplina> listarDisciplinas() {
		List<Disciplina> disciplinasRetornadas = new ArrayList<Disciplina>();
		disciplinasRetornadas.addAll(disciplinas);
		return disciplinasRetornadas;
	}

	public int qtdDisciplinas() {
		return disciplinas.size();
	}

}
