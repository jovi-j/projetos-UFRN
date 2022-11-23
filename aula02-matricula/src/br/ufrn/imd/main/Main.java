package br.ufrn.imd.main;

import java.time.Year;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import br.ufrn.imd.domino.Aluno;
import br.ufrn.imd.domino.Curso;
import br.ufrn.imd.domino.Disciplina;
import br.ufrn.imd.domino.Professor;
import br.ufrn.imd.ui.Interface;
import java.time.Year;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Random;

public class Main {
	/* "Banco de dados" */
	public static List<Aluno> alunos = new ArrayList<>();
	public static List<Professor> professores = new ArrayList<>();
	public static List<Disciplina> disciplinas = new ArrayList<>();
	public static List<Curso> cursos = new ArrayList<>();

	/* Classe responsável pela interface do programa */

	public static Interface ui = new Interface();
	public static String[] mainOpts = { "Cadastro no Sistema", "Matrícula" };
	public static String[] cadastroOpts = { "Cadastrar Aluno", "Cadastrar Professor", "Cadastrar Disciplina",
			"Cadastrar Curso" };

	/* Numeros que vão dar ordem aos Ids gerados no programa */
	private static Integer matriculacounter = (Year.now().getValue() * 10000);
	private static Integer matriculaServidorcounter = (Year.now().getValue() * 100);
	private static Integer cursoCounter = (Year.now().getValue() * 10);
	private static Integer disciplinaCounter = (Year.now().getValue() * 100);

  public static void main(String[] args) {
    iniciarPrograma();
  }

	private static void iniciarPrograma() {
		int opt;
		do {
			opt = ui.askOpt(mainOpts);
			switch (opt) {
				case 1:
					opt = moduloCadastro();
					break;
				case 2:
					opt = moduloMatricula();
					break;
				default:
					ui.err();
					opt = -1;
					break;
			}

    } while (opt != 0);
    System.out.println("Adeus :)");
  }

	/* Módulos */

	private static int moduloCadastro() {
		int opt;
		do {
			opt = ui.askOpt(cadastroOpts);
			switch (opt) {
				case 1:
					opt = submoduloCriarAluno();
					break;
				case 2:
					opt = submoduloCriarProfessor(null);
					break;
				case 3:
					opt = submoduloCriarDisciplina();
					break;
				default:
					ui.err();
					opt = -1;
					break;
			}

    } while (opt != 0);
    return 0;
  }

	private static int moduloMatricula() {
		while (true) {
			String matricula = ui.askString("Digite a matrícula do aluno a ser enturmado");
			Aluno aluno = new Aluno();
			aluno = procurarAluno(matricula);
			if (aluno.equals(null)) {
				if (ui.askYN("Aluno não encontrado, deseja criá-lo?")) {
					submoduloCriarAluno();
					continue;
				} else {
					return -1;
				}
			}
			Disciplina disciplina = new Disciplina();
			String nomeDisciplina = ui.askString("Nome da Disciplina");
			disciplina = procurarDisciplina(nomeDisciplina);
			if (disciplina.equals(null)) {
				if (ui.askYN("Disciplina não encontrada, deseja criá-la?")) {
					submoduloCriarDisciplina();
					continue;
				} else {
					return -1;
				}
			}

			if (!aluno.solicitarMatricula(disciplina)) {
				ui.err("Erro, aluno já está matriculado na disciplina!");
			}
			return 1;
		}

	}

	/* Submódulos - Criação */

	private static int submoduloCriarAluno() {
		boolean op = true;
		while (op) {
			Aluno a = new Aluno();
			String nome = ui.askString("Nome do aluno");
			String cpf = ui.askString("CPF do aluno");
			String dataNascimento = ui.askString("Data de nascimento do aluno");
			a.setNome(nome);
			a.setCpf(cpf);
			a.setDataNascimento(dataNascimento);
			a.setMatricula(gerarMatricula());
			System.out.println("DADOS DO ALUNO:");
			System.out.println(a);
			op = ui.askYN("Está correto?");
		}
		System.out.println("Aluno criado com sucesso!");
		return 1;
	}

	private static int submoduloCriarDisciplina() {
		boolean op = true;
		while (op) {
			Disciplina d = new Disciplina();
			String nomeCurso = ui.askString("Nome do curso");
			Curso cursoDisc = procurarCurso(nomeCurso);
			if (cursoDisc.equals(null)) {
				if (ui.askYN("Curso " + nomeCurso + " não encontrado, deseja cadastrá-lo?")) {
					submoduloCriarCurso(nomeCurso);
				} else {
					continue;
				}
			}
			String descricao = ui.askString("Descrição da disciplina");
			d.setDescricao(descricao);
			d.setCurso(cursoDisc);
			String nomeProf = ui.askString("Nome do professor");
			Professor profDisc = procurarProfessor(nomeProf);
			if (profDisc.equals(null)) {
				if (ui.askYN("Professor " + nomeProf + " não encontrado, deseja cadastrá-lo?")) {
					submoduloCriarProfessor(nomeProf);
				} else {
					continue;
				}
			}
			d.setProfessor(profDisc);
			disciplinaCounter++;
			d.setId(disciplinaCounter);
		}

		System.out.println("Disciplina criada com sucesso!");
		return 1;
	}

	private static void submoduloCriarCurso(String nomeCurso) {
		Curso c = new Curso();
		if (nomeCurso.equals(null))
			nomeCurso = ui.askString("Nome do curso");

		c.setNome(nomeCurso);

		cursoCounter++;
		c.setId(cursoCounter);
		System.out.println("Curso criado com sucesso!");
		return;
	}

	private static int submoduloCriarProfessor(String nomeProf) {
		boolean op = true;
		while (op) {
			Professor p = new Professor();
			if (nomeProf.isEmpty()) {
				nomeProf = ui.askString("Nome do professor");
			}

			String cpf = ui.askString("CPF do professor");
			String dataNascimento = ui.askString("Data de nascimento do professor");
			p.setNome(nomeProf);
			p.setCpf(cpf);
			p.setDataNascimento(dataNascimento);
			p.setSiape(gerarMatriculaServidor());
			System.out.println("DADOS DO PROFESSOR:");
			System.out.println(p);
			op = ui.askYN("Está correto?");
		}
		System.out.println("Professor criado com sucesso!");
		return 1;
	}

	/* Geração (de Ids) */
	private static String gerarMatriculaServidor() {
		matriculaServidorcounter++;
		return matriculaServidorcounter.toString() + new Random().nextInt(9999);
	}

	private static String gerarMatricula() {
		matriculacounter++;
		return matriculacounter.toString();
	}

	/* Funções auxiliares para pesquisa */
	private static Curso procurarCurso(String nomeCurso) {
		for (Curso curso : cursos) {
			if (curso.getNome() == nomeCurso) {
				return curso;
			}
		}
		return null;
	}

	private static Disciplina procurarDisciplina(String nomeDisciplina) {
		for (Disciplina disciplina : disciplinas) {
			if (disciplina.getDescricao() == nomeDisciplina) {
				return disciplina;
			}
		}
		return null;
	}

	private static Aluno procurarAluno(String matricula) {
		for (Aluno aluno : alunos) {
			if (aluno.getMatricula() == matricula) {
				return aluno;
			}
		}
		return null;
	}

	private static Professor procurarProfessor(String nomeProf) {
		for (Professor professor : professores) {
			if (professor.getNome() == nomeProf) {
				return professor;
			}
		}
		return null;
	}

}
