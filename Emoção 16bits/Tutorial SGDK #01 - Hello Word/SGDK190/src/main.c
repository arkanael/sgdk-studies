#include <genesis.h> // Inclui a biblioteca SGDK, que fornece as funções para programar o Mega Drive.

int main() // Função principal do programa, onde a execução começa.
{
    VDP_drawText("Hello Genesis", 10, 20); // Chama a função VDP_drawText para exibir o texto "Hello Genesis" na tela.
                                            // O texto será exibido na coluna 10 e linha 20.

    while(1) // Loop infinito, que mantém o programa rodando continuamente.
    {
        SYS_doVBlankProcess(); // Esta função é importante para sincronizar a atualização da tela com o VBlank (Vertical Blanking Interval).
                                // O VBlank é o período em que o feixe do tubo de imagem está retornando para o topo da tela,
                                // e é o momento ideal para atualizar a memória de vídeo, evitando "rasgos" na imagem.
    }
    return (0); // Nunca será executado neste caso, pois o loop `while(1)` é infinito.
}