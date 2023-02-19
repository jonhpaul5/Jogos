#include<iostream>
#include<cstdlib>
#include<time.h>

#define PEDRA 1
#define PAPEL 2
#define TESOURA 3

using namespace std;

/* Classe Principal do Programa, responsável por fazer
 * a comparação entre as jogadas do jogador e da CPU
 * e exibir a mensagem de acordo com o resultado.
 */

class JogoPPT {
public:

    /*Iniciar o jogo e fazer a comparação*/
    void Jogar(int palpiteJogador) {
        int palpiteCPU = SorteioCPU();

        switch(palpiteCPU){
            case PEDRA:
                if (palpiteJogador == PEDRA) {
                    msgEmpatou("pedra", "pedra");
                }
                else if (palpiteJogador == PAPEL) {
                    msgGanhou("pedra", "papel");
                }
                else if (palpiteJogador == TESOURA) {
                    msgPerdeu("pedra", "tesoura");
                }
                break;

            case PAPEL:
                if (palpiteJogador == PEDRA) {
                    msgPerdeu("papel", "pedra");
                }
                else if (palpiteJogador == PAPEL) {
                    msgEmpatou("papel", "papel");
                }
                else if (palpiteJogador == TESOURA) {
                    msgGanhou("papel", "tesoura");
                }
                break;
            
            case TESOURA:
                if (palpiteJogador == PEDRA) {
                    msgGanhou("tesoura", "pedra");
                }
                else if (palpiteJogador == PAPEL) {
                    msgPerdeu("tesoura", "papel");
                }
                else if (palpiteJogador == TESOURA) {
                    msgEmpatou("tesoura", "tesoura");
                }
                break;
            
        }
    }

    /* Mensagens para o jogador, indicando se ele ganhou, perdeu ou empatou
     * e mostrando a jogada do computador.*/
    void msgGanhou(string jogadaCPU, string jogadaJogador) {
        cout << "Parabéns! Você ganhou!" << endl;
        cout << "Voucê jogou " << jogadaJogador << " e o computador jogou " << jogadaCPU << "." << endl;
    }

    void msgPerdeu(string jogadaCPU, string jogadaJogador) {
        cout << "Que pena! Você perdeu!" << endl;
        cout << "Voucê jogou " << jogadaJogador << " e o computador jogou " << jogadaCPU << "." << endl;
    }

    void msgEmpatou(string jogadaCPU, string jogadaJogador) {
        cout << "Oops! o jogo empatou!" << endl;
        cout << "Voucê jogou " << jogadaJogador << " e o computador jogou " << jogadaCPU << "." << endl;
    }

    private:
        /*Soteio do computador*/
        int SorteioCPU() {
            srand(time(NULL));
            return rand() % 3 + 1;
        }
};

/* Função responsável por iniciar o jogo, pedindo
* o palpite do jogador e iniciando o jogo. */
void IniciarJogo(void) {
    JogoPPT jogador;
    int palpiteJogador;

    cout << "(1) Pedra" << endl << "(2) Papel" << endl << "(3) Tesoura" << endl;
    cout << "Insira o seu palpite (qualquer outra tecla para sair):";
    cin >> palpiteJogador;

    if (palpiteJogador != 1 && palpiteJogador !=2 && palpiteJogador !=3) {
        cout << "Saindo..." << endl;
        exit(0);
    }
    else {
        jogador.Jogar(palpiteJogador);
    }

}

/* Função principal do programa, responsável por
 * iniciar o jogo e perguntar se o jogador deseja
 * jogar novamente.
 */
int main(void) {
    string versao = "1.0";
    string escolha;

    cout << "===================================" << endl;
    cout << "Pedra, Papel e Tesoura - Versão " << versao << endl;
    cout << "===================================" << endl;

    while (true) {
        IniciarJogo();

        cout << endl << "Deseja jogar novamente? [S/N]: ";
        cin >> escolha;

        if (escolha == "n" || escolha == "N") {
            cout << "Saindo..." << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}