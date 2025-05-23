# Tutorial SGDK #01 - Hello World: Exibindo Texto no Mega Drive

**Objetivo:** Este tutorial demonstra como exibir texto na tela do Mega Drive usando o SGDK (Sistema de Desenvolvimento do Gênesis).

**Pré-requisitos:**

*   SGDK instalado e configurado em seu ambiente de desenvolvimento.
*   Conhecimento básico de programação em C.

**Passo 1: Criando o arquivo `main.c`**

Crie um arquivo chamado `main.c` com o seguinte código:

```c
#include <genesis.h>

int main() {
    VDP_drawText("Hello Genesis", 10, 20);

    while(1) {
        SYS_doVBlankProcess();
    }
    return (0);
}
```

## Explicação:
Explicação Detalhada:
#include <genesis.h>:

Esta linha inclui o arquivo de cabeçalho genesis.h. Este arquivo contém todas as definições de funções, estruturas e constantes necessárias para programar o Mega Drive usando o SGDK. Ele é essencial para qualquer projeto SGDK.
int main() { ... }:

Esta é a função principal do seu programa em C. A execução do programa sempre começa aqui.
int indica que a função retorna um valor inteiro.
As chaves {} delimitam o bloco de código que pertence à função main.
VDP_drawText("Hello Genesis", 10, 20);:

Esta é a função que realmente exibe o texto na tela.
VDP_drawText é uma função fornecida pela biblioteca SGDK.
"Hello Genesis" é a string de texto que você quer exibir.
10 é a coordenada X (horizontal) onde o texto começará (coluna).
20 é a coordenada Y (vertical) onde o texto começará (linha).
Essa função escreve diretamente na memória de vídeo do Mega Drive.
while(1) { ... }:

Este é um loop infinito. Em jogos de Mega Drive (e em muitos sistemas embarcados), você geralmente precisa de um loop principal que rode para sempre.
while(1) significa "enquanto 1 for verdadeiro" (e 1 é sempre verdadeiro), então o loop nunca termina.
SYS_doVBlankProcess();:

Esta é uma função crucial para evitar problemas de flickering (cintilação) e tearing (rasgos) na tela.
SYS_doVBlankProcess() lida com a sincronização com o VBlank (Vertical Blanking Interval). O VBlank é um pequeno período de tempo entre o final de um frame e o começo do próximo, quando o hardware de vídeo não está ativamente desenhando na tela.
É durante o VBlank que você deve atualizar a memória de vídeo (por exemplo, mudar as posições dos sprites, atualizar o mapa de tiles, etc.). Fazer isso enquanto o hardware está desenhando pode causar artefatos visuais.
Essa função também lida com outras tarefas de sistema, como leitura de controles.
return (0);:

Em teoria, esta linha retornaria o valor 0 para o sistema operacional quando o programa terminasse. No entanto, como o programa está preso em um loop infinito (while(1)), esta linha nunca é alcançada.
Em resumo:

O código inicializa o sistema gráfico, escreve o texto "Hello Genesis" na tela e, em seguida, entra em um loop infinito que sincroniza as atualizações da tela com o VBlank. Isso garante que a tela seja atualizada de forma suave e sem artefatos visuais.