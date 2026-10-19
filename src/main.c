#include <snes.h>

typedef struct {
    int x, y;
    int hp;
    int hasWeapon;
} Entity;

Entity player = {128, 112, 200, 0};
Entity bot = {60, 60, 100, 1};

void drawHUD(void) {
    consoleDrawText(1, 1, "HP: 200/200");
    consoleDrawText(1, 2, "ARMA: NENHUMA");
    consoleDrawText(1, 26, "BATTLE ROYALE 2D");
}

int main(void) {
    consoleInit();
    
    // Cor de fundo e elementos do mapa (Casas e Árvores)
    setPaletteColor(0, RGB15(2, 10, 2)); // Fundo verde (Terreno)

    drawHUD();
    
    // Elementos visuais do mapa
    consoleDrawText(10, 4, "[ CASA 1 ]");
    consoleDrawText(20, 18, "( ARVORE )");
    consoleDrawText(5, 15, "( ARVORE )");
    
    // Posições iniciais
    consoleDrawText(player.x / 8, player.y / 8, "P");
    consoleDrawText(bot.x / 8, bot.y / 8, "B");

    setScreenOn();

    while (1) {
        u16 pad = padsCurrent();

        // Movimento do Jogador (D-PAD)
        if (pad & KEY_UP) player.y--;
        if (pad & KEY_DOWN) player.y++;
        if (pad & KEY_LEFT) player.x--;
        if (pad & KEY_RIGHT) player.x++;

        // Apanhar arma dentro/perto da "CASA 1"
        if (player.x >= 75 && player.x <= 95 && player.y >= 25 && player.y <= 45) {
            if (!player.hasWeapon) {
                player.hasWeapon = 1;
                consoleDrawText(1, 2, "ARMA: RIFLE   ");
            }
        }

        // IA do Bot: persegue o jogador
        if (bot.hp > 0) {
            if (bot.x < player.x) bot.x++;
            if (bot.x > player.x) bot.x--;
            if (bot.y < player.y) bot.y++;
            if (bot.y > player.y) bot.y--;

            // Jogador ataca o bot com o Botão A (se tiver arma)
            if ((pad & KEY_A) && player.hasWeapon) {
                if (abs(player.x - bot.x) < 16 && abs(player.y - bot.y) < 16) {
                    bot.hp -= 50;
                    if (bot.hp <= 0) {
                        consoleDrawText(bot.x / 8, bot.y / 8, " ");
                    }
                }
            }
        }

        WaitForVBlank();
    }

    return 0;
}
